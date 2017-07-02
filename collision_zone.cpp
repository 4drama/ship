#include "collision_zone.hpp"

#include <algorithm>
#include <cmath>

#include <iostream>

const double pi = 3.14159265358979323846;

void CollisionZone::createFourZones(Point centre, double azimuth, int height, int width, double cellSize)
{
	Zones.clear();
	Zones.reserve(4);
	
	Point x2y2 = centre;
	
	Point x2y1;
	Point x2y3;	
	double heightHptz = (height/2)*cellSize;
	double heightAngle = azimuth;	
	double x2y1x = heightHptz*sin((heightAngle)* pi / 180);
	double x2y1y = heightHptz*cos((heightAngle)* pi / 180);
	x2y1.x = centre.x + x2y1x;
	x2y1.y = centre.y + x2y1y;
	x2y3.x = centre.x - x2y1x;
	x2y3.y = centre.y - x2y1x;
	
	Point x1y2;
	Point x3y2;
	double widthHptz = (width/2)*cellSize;
	double widthAngle = 90-azimuth;
	double x1y2x = widthHptz*sin((widthAngle)* pi / 180);
	double x1y2y = widthHptz*cos((widthAngle)* pi / 180);
	x1y2.x = centre.x + x1y2x;
	x1y2.y = centre.y + x1y2y;
	x3y2.x = centre.x - x1y2x;
	x3y2.y = centre.y - x1y2y;
	
	Point x1y1;
	Point x3y1;
	Point x1y3;
	Point x3y3;
	x1y1.x = x2y1.x + x1y2x;
	x1y1.y = x2y1.y + x1y2y;
	x3y1.x = x2y1.x - x1y2x;
	x3y1.y = x2y1.y - x1y2y;
	x1y3.x = x2y3.x + x1y2x;
	x1y3.y = x2y3.y + x1y2y;
	x3y3.x = x2y3.x - x1y2x;
	x3y3.y = x2y3.y - x1y2y;
	
	Zones.push_back(Rectangle(x1y1, x2y1, x2y2, x1y2));
	Zones.push_back(Rectangle(x1y2, x2y2, x2y3, x1y3));
	Zones.push_back(Rectangle(x2y1, x3y1, x3y2, x2y2));
	Zones.push_back(Rectangle(x2y2, x3y2, x3y3, x2y3));
	
	std::cout << std::endl << "Rectangle one : (" 	<<  x1y1.x << "," << x1y1.y << ") (" 
													<<  x2y1.x << "," << x2y1.y << ") ("
													<<  x2y2.x << "," << x2y2.y << ") ("
													<<  x1y2.x << "," << x1y2.y << ")" << std::endl;
													
	std::cout << std::endl << "Rectangle two : (" 	<<  x1y2.x << "," << x1y2.y << ") (" 
													<<  x2y2.x << "," << x2y2.y << ") ("
													<<  x2y3.x << "," << x2y3.y << ") ("
													<<  x1y3.x << "," << x1y3.y << ")" << std::endl;
													
	std::cout << std::endl << "Rectangle three : (" <<  x2y1.x << "," << x2y1.y << ") (" 
													<<  x3y1.x << "," << x3y1.y << ") ("
													<<  x3y2.x << "," << x3y2.y << ") ("
													<<  x2y2.x << "," << x2y2.y << ")" << std::endl;
													
	std::cout << std::endl << "Rectangle four : (" 	<<  x2y2.x << "," << x2y2.y << ") (" 
													<<  x3y2.x << "," << x3y2.y << ") ("
													<<  x3y3.x << "," << x3y3.y << ") ("
													<<  x2y3.x << "," << x2y3.y << ")" << std::endl << std::endl;
};