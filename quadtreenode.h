#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include "boundable.h"
#include "quadtree.h"

template<typename T>
class QuadTreeNode : public Boundable
{
public:
    QuadTreeNode(unsigned int x1, unsigned int y1, unsigned int width, unsigned int height )
        : Boundable(x1, y1, width, height),
          _children(),
          _items()
    {
    }
    QuadTreeNode(Rectangle bounds)
        : Boundable(bounds),
          _children(),
          _items()
    {
    }
    ~QuadTreeNode()
    {
        for(auto& child: _children) {
            delete child;
        }
    }

    inline std::vector<QuadTreeNode<T>*>& children()
    {
        return _children;
    }
    inline void setChildren(std::vector<QuadTreeNode<T>*> children)
    {
        _children = children;
    }
    inline std::vector<T>& items()
    {
        return _items;
    }
    inline std::vector<T> itemsRecursive()
    {
        std::vector<T> items = _items;
        for(auto& child : _children) {
            std::vector<T> childItems = child->itemsRecursive();
            items.insert(std::end(items), std::begin(childItems), std::end(childItems));
        }
        return items;
    }

    inline void add(T item)
    {
        _items.push_back(item);
    }
    inline void removeItemAt(unsigned int i)
    {
        _items.erase(_items.begin() + i);
    }

    inline bool shouldSplit()
    {
        return _children.size() == 0 && _items.size() >= _maxItemCount;
    }

private:
    std::vector<QuadTreeNode<T>*> _children;
    std::vector<T> _items;
    const unsigned int _maxItemCount = 2;
};

#endif // TREENODE_H
