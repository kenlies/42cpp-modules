#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main ( void )
{
	Point a( 0.0, 0.0 );
	Point b( 5.5, 15.2 );
	Point c( 10.5, 0.0);

	Point point1( 5.5, 15.15 );
	bsp(a, b, c, point1) ? std::cout << "INSIDE" << std::endl : std::cout << "OUTSIDE" << std::endl;

	Point point2 ( 7.14257, 10.2 ); // 7.14257 is inside && 7.14258 is outside
	bsp(a, b, c, point2) ? std::cout << "INSIDE" << std::endl : std::cout << "OUTSIDE" << std::endl;
	
	Point point3( 20.4, 7.6 );
	bsp(a, b, c, point3) ? std::cout << "INSIDE" << std::endl : std::cout << "OUTSIDE" << std::endl;
	
	std::cout << "<-------NEW TRIANGLE------->" << std::endl;

	Point d( 0.0, 0.0 );
	Point e( -7.5, -10.1 );
	Point f( 7.5, -6.2);

	Point point4( -7.5, -10.1 );
	bsp(d, e, f, point4) ? std::cout << "INSIDE" << std::endl : std::cout << "OUTSIDE" << std::endl;

	Point point5( -6.2, -9.5 );
	bsp(d, e, f, point5) ? std::cout << "INSIDE" << std::endl : std::cout << "OUTSIDE" << std::endl;
	return 0;
}