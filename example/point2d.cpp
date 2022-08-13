#include "point2d.h"
#include "point2d_p.h"

Point2DPrivate::Point2DPrivate()
    : x(0)
    , y(0)
{

}

Point2D::Point2D() : Pimpl()
{

}

Point2D::Point2D(int x, int y) : Pimpl()
{
    d_func()->x = x;
    d_func()->y = y;
}

Point2D::Point2D(const Point2D &other) : Pimpl(other)
{

}

Point2D::~Point2D()
{

}

int Point2D::x() const
{
    return d_func()->x;
}

int Point2D::y() const
{
    return d_func()->y;
}

void Point2D::set(int x, int y)
{
    d_func()->x = x;
    d_func()->y = y;
}

void Point2D::add(int dx, int dy)
{
    d_func()->x += dx;
    d_func()->y += dy;
}

std::ostream &operator<<(std::ostream &os, const Point2D &obj)
{
    os << "(" << obj.x() << ", " << obj.y() << ")";
    return os;
}
