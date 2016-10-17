#ifndef BOUNDABLE_H
#define BOUNDABLE_H

#include "rectangle.h"

class Boundable {
public:
    Boundable(Rectangle bounds);
    Boundable(unsigned int x1, unsigned int y1, unsigned int width, unsigned int height);

    inline const Rectangle& bounds() const
    {
        return _bounds;
    }

protected:
    Rectangle _bounds;
};

#endif // BOUNDABLE_H
