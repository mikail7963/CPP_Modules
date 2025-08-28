#include "Fixed.hpp"
#include "Point.hpp"

float AreaCalculation(Point a, Point b, Point c)
{
	float area = 0.5f	* ((a.getX() * (b.getY() - c.getY()))
                   		+ (b.getX() * (c.getY() - a.getY()))
                		+ (c.getX() * (a.getY() - b.getY())));
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float pab = fabs(AreaCalculation(point, a, b));
	float pbc = fabs(AreaCalculation(point, b, c));
	float pca = fabs(AreaCalculation(point, c, a));
	float abc = fabs(AreaCalculation(a, b, c));

	if (pab == 0 || pbc == 0 || pca == 0)
		return false;
	if (fabs((pab + pbc + pca) - abc) < 0.00001f)
		return true;
	return false;
}
