#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
public:
    Rectangle(unsigned int x1, unsigned int y1, unsigned int width, unsigned int height);

    unsigned int x1() const
    {
        return _x1;
    }

    void setX1(unsigned int x1)
    {
        _x1 = x1;
    }

    unsigned int y1() const
    {
        return _y1;
    }

    void setY1(unsigned int y1)
    {
        _y1 = y1;
    }

    unsigned int x2() const
    {
        return _x2;
    }

    void setX2(unsigned int x2)
    {
        _x2 = x2;
    }

    unsigned int y2() const
    {
        return _y2;
    }

    void setY2(unsigned int y2)
    {
        _y2 = y2;
    }

    inline unsigned int width() const
    {
        return _x2 - _x1;
    }

    inline unsigned int height() const
    {
        return _y2 - _y1;
    }

    inline float midX() const
    {
        return width() / 2;
    }

    inline float midY() const
    {
        return height() / 2;
    }

    bool intersects(const Rectangle& other) const;
    bool isInside(const Rectangle& other) const;



private:
    unsigned int _x1;
    unsigned int _y1;
    unsigned int _x2;
    unsigned int _y2;
};

#endif // RECTANGLE_H
