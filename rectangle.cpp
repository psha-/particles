#include "rectangle.h"

Rectangle::Rectangle(unsigned int x1, unsigned int y1, unsigned int width, unsigned int height)
    : _x1(x1), _x2(x1+width), _y1(y1), _y2(y1+height)
{
}

bool Rectangle::intersects(const Rectangle &other) const
{
    return _x1 <= other.x2() &&
            other.x1() <= _x2 &&
            _y1 <= other.y2() &&
            other.y1() <= _y2;
}

bool Rectangle::isInside(const Rectangle &other) const
{
    return _x2 <= other.x2() &&
            _x1 >= other.x1() &&
            _y1 >= other.y1() &&
            _y2 <= other.y2();
}

