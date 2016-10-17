#include "boundable.h"

Boundable::Boundable(Rectangle bounds)
    :_bounds(bounds)
{
}
Boundable::Boundable(unsigned int x1, unsigned int y1, unsigned int width, unsigned int height)
    : _bounds(x1, y1, width, height)
{
}
