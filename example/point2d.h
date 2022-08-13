#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

#include <pimpl.h>

class Point2DPrivate;
class Point2D : public Pimpl<Point2D, Point2DPrivate>
{
public:
    Point2D();
    Point2D(int x, int y);
    Point2D(const Point2D &other);
    ~Point2D();

    int x() const;
    int y() const;

    void set(int x, int y);
    void add(int dx, int dy);
};

std::ostream &operator<<(std::ostream &os, const Point2D &obj);

#endif // POINT2D_H
