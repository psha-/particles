#ifndef QUADTREE_H
#define QUADTREE_H

#include "quadtreenode.h"
#include "boundable.h"
#include "quadrant.h"
#include <queue>

//TODO: Limit T to Boundable*
template<typename T>
class QuadTree
{

public:
    QuadTree(unsigned int width, unsigned int height, unsigned int maxDepth = _defaultMaxDepth)
        : _pRoot(new QuadTreeNode<T>(nullptr, 0, 0, width, height)),
          _maxDepth(maxDepth)
    {
    }
    ~QuadTree()
    {
        delete _pRoot;
    }

    bool add(T item);
    std::vector<T> findItemsBoundBy(Rectangle bounds);
    void update(T item, const Rectangle& prevBounds);

private:
    QuadTreeNode<T>* _pRoot;
    unsigned int _maxDepth;
    static unsigned int const _defaultMaxDepth = 10;

    bool _splitOne(QuadTreeNode<T>* node, unsigned int depth);
    bool _split(QuadTreeNode<T>* node, unsigned int depth);
    void _combineChildren(QuadTreeNode<T>* parent);
    QuadTreeNode<T>* _findNode(const Rectangle& bounds, QuadTreeNode<T>* node) const;
    inline bool _needsUpdate(const Rectangle& bounds, const Rectangle& prevBounds) const
    {
        return _findNode(bounds, _pRoot) != _findNode(prevBounds, _pRoot);
    }


    static bool _areChildrenEmpty(const QuadTreeNode<T>& node);
    static Quadrant _getQuadrant(const QuadTreeNode<T>& node, const Rectangle& bounds);
    static Rectangle _getQuadrantBounds(const QuadTreeNode<T>& node, Quadrant quadrant);

};


// Implementations
template<typename T>
bool QuadTree<T>::add(T item)
{
    if(!item->bounds().isInside((_pRoot->bounds()))) {
        return false;
    }

    QuadTreeNode<T>* node = _pRoot;
    unsigned int depth = 1;
    while(node->children().size() > 0) {
        Quadrant q = _getQuadrant(*node, item->bounds());
        if( q == QUADRANT_OUT) {
            break;
        }
        node = node->children()[q];
        depth++;
    }
    node->add(item);
    _split(node, depth);
    return true;
}

template<typename T>
bool QuadTree<T>::_areChildrenEmpty(const QuadTreeNode<T>& node)
{
    for(auto& child : node.children()) {
        if(!child->isEmpty()) {
            return false;
        }
    }
    return true;
}

template<typename T>
void QuadTree<T>::update(T item, const Rectangle& prevBounds)
{
    if(_needsUpdate(item->bounds(), prevBounds)) {
        QuadTreeNode<T>* node = _findNode(prevBounds, _pRoot);
        node->removeItem(&item);
        QuadTreeNode<T>* parent = const_cast<QuadTreeNode<T>*>(node->parent());
        if(_areChildrenEmpty(*parent)) {
            (*parent).resetChildren();
        }
        add(item);
    }
}

template<typename T>
QuadTreeNode<T>* QuadTree<T>::_findNode(const Rectangle& bounds, QuadTreeNode<T>* startNode) const
{
    for(auto& childNode : startNode->children()) {
        if( bounds.isInside(childNode->bounds())) {
            return _findNode(bounds, childNode);
        }
    }
}

template<typename T>
std::vector<T> QuadTree<T>::findItemsBoundBy(Rectangle bounds)
{
    if(!bounds.intersects(_pRoot->bounds())) {
        return std::vector<T>();
    }

    std::vector<T> items = std::vector<T>();
    std::vector<QuadTreeNode<T>*> boundNodes;
    std::queue<QuadTreeNode<T>*> intersectedNodes;
    intersectedNodes.push(_pRoot);

    while(intersectedNodes.size() > 0) {
        QuadTreeNode<T>* node = intersectedNodes.front();
        intersectedNodes.pop();
        items.insert(std::end(items), std::begin(node->items()), std::end(node->items()));

        if(node->children().size() == 0) {
            boundNodes.push_back(node);
            continue;
        }
        for(auto& child : node->children()) {
            if(child->bounds().isInside(bounds)) {
                boundNodes.push_back(child);
            }
            else if(bounds.intersects(child->bounds())) {
                intersectedNodes.push(child);
            }
        }
    }


    for(auto& boundNode : boundNodes) {
        std::vector<T> nodeItems = boundNode->itemsRecursive();
        items.insert(std::end(items), std::begin(nodeItems), std::end(nodeItems));
    }
    return items;
}

template<typename T>
bool QuadTree<T>::_splitOne(QuadTreeNode<T>* node, unsigned int depth)
{
    if(!node->shouldSplit() || depth > _maxDepth) {
        return false;
    }

    node->setChildren(std::vector<QuadTreeNode<T>*>({
        new QuadTreeNode<T>(node, _getQuadrantBounds(*node, QUADRANT_0)),
        new QuadTreeNode<T>(node, _getQuadrantBounds(*node, QUADRANT_1)),
        new QuadTreeNode<T>(node, _getQuadrantBounds(*node, QUADRANT_2)),
        new QuadTreeNode<T>(node, _getQuadrantBounds(*node, QUADRANT_3)),
    }));

    for (int i=0; i<node->items().size(); i++) {
        T item = node->items()[i];
        Quadrant q = _getQuadrant(*node, item->bounds());
        if( q == QUADRANT_OUT ) {
            continue;
        }
        node->children()[q]->add(item);
        node->removeItemAt(i);
        i--;
    }
    return true;
}

template<typename T>
bool QuadTree<T>::_split(QuadTreeNode<T>* node, unsigned int depth)
{
    if(!_splitOne(node, depth)) {
        return false;
    }

    for(auto& child: node->children()) {
        _split(child, depth+1);
    }
    return true;
}

template<typename T>
Quadrant QuadTree<T>::_getQuadrant(const QuadTreeNode<T>& node, const Rectangle& bounds)
{
    if (bounds.isInside(_getQuadrantBounds(node, QUADRANT_0)))
    {
        return QUADRANT_0;
    }
    if (bounds.isInside(_getQuadrantBounds(node, QUADRANT_1)))
    {
        return QUADRANT_1;
    }
    if (bounds.isInside(_getQuadrantBounds(node, QUADRANT_2)))
    {
        return QUADRANT_2;
    }
    if (bounds.isInside(_getQuadrantBounds(node, QUADRANT_3)))
    {
        return QUADRANT_3;
    }
    return QUADRANT_OUT;
}

template<typename T>
Rectangle QuadTree<T>::_getQuadrantBounds(const QuadTreeNode<T>& node, Quadrant quadrant)
{
    unsigned int x1 = node.bounds().x1();
    unsigned int y1 = node.bounds().y1();
    unsigned int x2 = node.bounds().x2();
    unsigned int y2 = node.bounds().y2();
    unsigned int xMid = node.bounds().xMid();
    unsigned int yMid = node.bounds().yMid();

    switch (quadrant)
    {
        case QUADRANT_0:
            return Rectangle(xMid, yMid, x2-xMid, y2-yMid);
        case QUADRANT_1:
            return Rectangle(x1, yMid, xMid-x1, y2-yMid);
        case QUADRANT_2:
            return Rectangle(x1, y1, xMid-x1, yMid-y1);
        case QUADRANT_3:
            return Rectangle(xMid, y1, x2-xMid, yMid-y1);
    }
}


#endif // QUADTREE_H
