#include <iostream>

#include <global.h>

#include "point2d.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    UNUSED(argc)
    UNUSED(argv)

    Point2D a;
    a.set(1, 1);

    Point2D b(a);
    b.add(2, 2);

    Point2D c = b;
    c.add(3, 3);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}
