#include "geometry.hpp"

Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4)
{
	side1.first = p1;
	side1.last = p2;
	
	side2.first = p2;
	side2.last = p3;
	
	side3.first = p3;
	side3.last = p4;
	
	side4.first = p4;
	side4.last = p1;
};

Vect::Vect(Line line)
{
	i = line.last.x - line.first.x;
	j = line.last.y - line.first.y;
	k = 0;
};

Vect::Vect(Point first, Point last)
{
	i = last.x - first.x;
	j = last.y - first.y;
	k = 0;
};

Vect::Vect(double i_, double j_, double k_) 
			: i(i_), j(j_), k(k_)
{
	
};

Vect operator*( const Vect& lhs, const Vect& rhs)
{
	double i = (lhs.j*rhs.k)-(rhs.j*lhs.k);
	double j = -1*(lhs.i*rhs.k)-(rhs.i*lhs.k);
	double k = (lhs.i*rhs.j)-(rhs.i*lhs.j);
	
	return Vect(i, j, k);
};

bool midVect (const Vect& mid, const Vect& left, const Vect& right)
{
	Vect AB = mid*left;
	Vect AC = mid*right;
	
	if(	(AB.k > 0 && AC.k < 0) || (AB.k < 0 && AC.k > 0)	)
		return true;
	else
		return false;
};

bool intersectionLine(const Line& A, const Line& B)
{
	bool intersectionA = midVect(Vect(A), Vect(A.first, B.first), Vect(A.first, B.last));
	bool intersectionB = midVect(Vect(B), Vect(B.first, A.first), Vect(B.first, A.last));
	
	if( intersectionA == true && intersectionB == true)
		return true;
	else
		return false;
};

bool intersectionLineRectangle(const Line& first, const Rectangle& second)
{
	bool a1 = intersectionLine(first, second.side1);
	bool a2 = intersectionLine(first, second.side2);
	bool a3 = intersectionLine(first, second.side3);
	bool a4 = intersectionLine(first, second.side4);
	
	if( a1 == true || a2 == true || a3 == true || a4 == true)
		return true;
	else
		return false;
};

bool intersectionRectangle(const Rectangle& first, const Rectangle& second)
{
	bool a1 = intersectionLineRectangle(first.side1, second);
	bool a2 = intersectionLineRectangle(first.side2, second);
	bool a3 = intersectionLineRectangle(first.side3, second);
	bool a4 = intersectionLineRectangle(first.side4, second);
	
	if( a1 == true || a2 == true || a3 == true || a4 == true)
		return true;
	else
		return false;
};

