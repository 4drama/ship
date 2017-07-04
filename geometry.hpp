#ifndef GEOMETRY__
#define GEOMETRY__

struct Point
{
	double x;
	double y;
};

struct Distance
{
	double x;
	double y;
};

Point operator+( const Point& lhs, const Distance& rhs);

class Azimuth
{
private:
	double value;
public:
	Azimuth(const double&);
	void set(const double&);
	double get() const;
};



struct Line
{	
	Point first;
	Point last;	
};

struct Rectangle
{
	Line side1;
	Line side2;
	Line side3;
	Line side4;
	
	Rectangle(Point, Point, Point, Point);
};

struct Vect
{
	double i;
	double j;
	double k;
	
	Vect(Line);
	Vect(Point, Point);
	Vect(double, double, double);
};

Vect operator*( const Vect& lhs, const Vect& rhs);

bool midVect (const Vect& mid, const Vect& left, const Vect& right);

Point pointFromDistance(const Point&, const Azimuth&, const Distance&);

bool intersectionLine(const Line& first, const Line& second);

bool intersectionRectangle(const Rectangle& first, const Rectangle& second);

#endif