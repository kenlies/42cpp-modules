#include "Point.hpp"
/*
static Fixed   absl(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

static Fixed   area( Point const a, Point const b, Point const c ) {
    return ( ( ( a.getX() * ( b.getY() - c.getY() ) ) +
             ( b.getX() * ( c.getY() - a.getY() ) ) +
             ( c.getX() * ( a.getY() - b.getY() ) ) ) / 2 );
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed   abcArea = absl(area( a, b, c ));
    Fixed   pabArea = absl(area( point, a, b ));
    Fixed   pbcArea = absl(area( point, b, c ));
    Fixed   pcaArea = absl(area( point, c, a ));

    return  ( abcArea == pabArea + pbcArea + pcaArea );
}
*/

static bool edge(Fixed A1, Fixed A2, Fixed A3)
{
	return (A1 == Fixed( 0 ) || A2 == Fixed( 0 ) || A3 == Fixed( 0 ));
}

static Fixed absl(Fixed num)
{
	if (num < Fixed( 0 ))
		return num * Fixed( -1 );
	else
		return num;
}
static Fixed area(Point const a, Point const b, Point const c)
{
	return absl((((a.getX() * (b.getY() - c.getY())) + 
			(b.getX() * (c.getY() - a.getY())) + 
			(c.getX() * (a.getY() - b.getY()))) / Fixed( 2.0f )));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = area(a, b, c);
	Fixed A1 = area(point, a, b);
	Fixed A2 = area(point, b, c);
	Fixed A3 = area(point, c, a);

	if (edge(A1, A2, A3))
		return false;
	return (A == A1 + A2 + A3);
}