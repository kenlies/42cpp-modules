#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point( const float n1, const float n2 );
		Point( const Point &pnt );
		Point &operator=( const Point &pnt );
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};