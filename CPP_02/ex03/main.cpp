#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

int main() 
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    Point insidePoint(3.0f, 3.0f);
    Point outsidePoint(4.9f, 9.1f);
    Point edgePoint(5.0f, 0.0f);
    Point vertexPoint(5.0f, 10.0f);

    std::cout << "Point inside triangle?         " << (bsp(a, b, c, insidePoint) ? "Yes" : "No") << std::endl;
    std::cout << "Point outside triangle?        " << (bsp(a, b, c, outsidePoint) ? "Yes" : "No") << std::endl;
    std::cout << "Point on edge of triangle?     " << (bsp(a, b, c, edgePoint) ? "Yes" : "No") << std::endl;
    std::cout << "Point is a vertex of triangle? " << (bsp(a, b, c, vertexPoint) ? "Yes" : "No") << std::endl;

    return 0;
}
