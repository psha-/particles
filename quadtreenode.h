#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include "boundable.h"
#include "quadtree.h"

template<typename T>
class QuadTreeNode : public Boundable
{
public:
    QuadTreeNode(QuadTreeNode<T>* pParent, unsigned int x1, unsigned int y1, unsigned int width, unsigned int height )
        : _pParent(pParent),
          Boundable(x1, y1, width, height),
          _children(),
          _items()
    {
    }
    QuadTreeNode(QuadTreeNode<T>* pParent, Rectangle bounds)
        : _pParent(pParent),
          Boundable(bounds),
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
    inline const std::vector<QuadTreeNode<T>*>& children() const
    {
        return _children;
    }
//    void resetChildren()
//    {
//        for(auto& child : _children) {
//            delete child;
//        }
//        _children = std::vector<QuadTreeNode<T>*>();
//    }

    inline void setChildren(std::vector<QuadTreeNode<T>*> children)
    {
        _children = children;
    }
    inline const std::vector<T>& items() const
    {
        return _items;
    }
    inline const QuadTreeNode<T>* parent()
    {
        return _pParent;
    }
    std::vector<T> itemsRecursive() const
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

    void removeItem(T* item)
    {
        for(int i=0; i<_items.size(); i++) {
            if(item == &_items[i]) {
                _items.erase(_items.begin() + i);
                break;
            }
        }
    }

    inline bool shouldSplit() const
    {
        return _children.size() == 0 && _items.size() >= _maxItemCount;
    }
    inline bool isEmpty() const
    {
        return _children.size() == 0 && _items.size() == 0;
    }


private:
    QuadTreeNode<T>* _pParent;
    std::vector<QuadTreeNode<T>*> _children;
    std::vector<T> _items;
    const unsigned int _maxItemCount = 10;
};

#endif // TREENODE_H
