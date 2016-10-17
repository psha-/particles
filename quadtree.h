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
        : _pRoot(new QuadTreeNode<T>(0, 0, width, height)),
          _maxDepth(maxDepth)
    {
    }
    ~QuadTree()
    {
        delete _pRoot;
    }

    bool add(T item)
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

    QuadTreeNode<T> findNode(T item)
    {
        //TODO: implement
    }

    std::vector<T> findItemsBoundBy(Rectangle bounds)
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

    void remove(T item);
    void update(T item);

private:
    unsigned int _maxDepth;
    static unsigned int const _defaultMaxDepth = 10;
    QuadTreeNode<T>* _pRoot;

    bool _splitOne(QuadTreeNode<T>* node, unsigned int depth)
    {
        if(!node->shouldSplit() || depth > _maxDepth) {
            return false;
        }

        node->setChildren(std::vector<QuadTreeNode<T>*>({
            new QuadTreeNode<T>(_getQuadrantBounds(*node, QUADRANT_0)),
            new QuadTreeNode<T>(_getQuadrantBounds(*node, QUADRANT_1)),
            new QuadTreeNode<T>(_getQuadrantBounds(*node, QUADRANT_2)),
            new QuadTreeNode<T>(_getQuadrantBounds(*node, QUADRANT_3)),
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

    bool _split(QuadTreeNode<T>* node, unsigned int depth)
    {
        if(!_splitOne(node, depth)) {
            return false;
        }

        for(auto& child: node->children()) {
            _split(child, depth+1);
        }
        return true;
    }

    void _combineChildren(QuadTreeNode<T>* parent)
    {
        //TODO: implement
    }


    static Quadrant _getQuadrant(const QuadTreeNode<T>& node, const Rectangle& bounds)
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

    static Rectangle _getQuadrantBounds(const QuadTreeNode<T>& node, Quadrant quadrant)
    {
        unsigned int midX = node.bounds().midX();
        unsigned int midY = node.bounds().midY();
        unsigned int width = node.bounds().width();
        unsigned int height = node.bounds().height();

        switch (quadrant)
        {
            case QUADRANT_0:
                return Rectangle(0, 0, midX, midY);
            case QUADRANT_1:
                return Rectangle(midX, 0, width - midX, midY);
            case QUADRANT_2:
                return Rectangle(0, midY, midX, height - midY);
            case QUADRANT_3:
                return Rectangle(midX, midY, width - midX, height - midY);
        }
    }

};

#endif // QUADTREE_H
