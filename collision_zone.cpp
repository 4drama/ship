#include "collision_zone.hpp"

#include <algorithm>
#include <cmath>

#include <iostream>

const double pi = 3.14159265358979323846;

void CollisionZone::createFourZones(Point centre, double azimuth, int heightGen, int widthGen, double cellSize)
{
	size = 4;
	indexs.resize(4);
	
	xSize = (widthGen)/2;
	ySize = (heightGen)/2;
	
	indexs[0] = std::make_pair(Index{0, 0}, Index{heightGen-ySize-1, widthGen-xSize-1});
	indexs[1] = std::make_pair(Index{heightGen-ySize, 0}, Index{heightGen-1, widthGen-xSize-1});
	indexs[2] = std::make_pair(Index{0, widthGen-xSize}, Index{heightGen-ySize-1, widthGen-1});
	indexs[3] = std::make_pair(Index{heightGen-ySize, widthGen-xSize}, Index{heightGen-1, widthGen-1});
	
	Zones.clear();
	Zones.reserve(4);
		
	double height = (heightGen/2)*cellSize;
	double width = (widthGen/2)*cellSize;
	
	double halfDiagonal = sqrt(pow(height,2)+pow(width,2));
	
	Point x1y1, x2y1, x3y1;
	Point x1y2, x2y2, x3y2;
	Point x1y3, x2y3, x3y3;
	
	x2y2 = centre;
	
	x2y1.x = centre.x + height*sin((0+azimuth)* pi / 180);
	x2y1.y = centre.y + height*cos((0+azimuth)* pi / 180);
	
	x2y3.x = centre.x + height*sin((180+azimuth)* pi / 180);
	x2y3.y = centre.y + height*cos((180+azimuth)* pi / 180);
	
	x1y2.x = centre.x + width*sin((90+azimuth)* pi / 180);
	x1y2.y = centre.y + width*cos((90+azimuth)* pi / 180);
	
	x3y2.x = centre.x + width*sin((270+azimuth)* pi / 180);
	x3y2.y = centre.y + width*cos((270+azimuth)* pi / 180);	
	
	x1y1.x = centre.x + halfDiagonal*sin((315+azimuth)* pi / 180);
	x1y1.y = centre.y + halfDiagonal*cos((315+azimuth)* pi / 180);
	
	x3y1.x = centre.x + halfDiagonal*sin((45+azimuth)* pi / 180);
	x3y1.y = centre.y + halfDiagonal*cos((45+azimuth)* pi / 180);
	
	x1y3.x = centre.x + halfDiagonal*sin((135+azimuth)* pi / 180);
	x1y3.y = centre.y + halfDiagonal*cos((135+azimuth)* pi / 180);

	x3y3.x = centre.x + halfDiagonal*sin((225+azimuth)* pi / 180);
	x3y3.y = centre.y + halfDiagonal*cos((225+azimuth)* pi / 180);	
	
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
/*
void CollisionZone::createFourZones(Point centre, double azimuth, int height, int width, double cellSize)
{
	size = 4;
	indexs.resize(4);
	
	xSize = (width)/2;
	ySize = (height)/2;
	
	indexs[0] = std::make_pair(Index{width-1, 0}, Index{width-xSize, height-1-ySize});
	indexs[1] = std::make_pair(Index{width-1, height-ySize}, Index{width-xSize, height-1});
	indexs[2] = std::make_pair(Index{width-1-xSize, 0}, Index{0, height-1-ySize});
	indexs[3] = std::make_pair(Index{width-1-xSize, height-ySize}, Index{0, height-1});
	
	Zones.clear();
	Zones.reserve(4);
	
	Point x2y2 = centre;
	
	Point x2y1;
	Point x2y3;	
	double heightHptz = (height/2)*cellSize;
	double heightAngle = azimuth;	
	double x2y1x = heightHptz*sin((heightAngle)* pi / 180);
	double x2y1y = heightHptz*cos((heightAngle)* pi / 180);
//	if(azimuth > 90 && azimuth < 270)	x2y1y *= -1;
//	if(azimuth > 180 && azimuth < 0 )	x2y1x *= -1;
//	std:: cout << x2y1x << " " <<  x2y1y << std::endl;
	x2y1.x = centre.x + x2y1x;
	x2y1.y = centre.y + x2y1y;
	x2y3.x = centre.x - x2y1x;
	x2y3.y = centre.y - x2y1y;
	
	Point x1y2;
	Point x3y2;
	double widthHptz = (width/2)*cellSize;
	double widthAngle = 90-azimuth;
	double x1y2x = widthHptz*sin((widthAngle)* pi / 180);
	double x1y2y = widthHptz*cos((widthAngle)* pi / 180);
//	if(azimuth < 90 && azimuth > 270)	x1y2y *= -1;
//	if(azimuth > 180 && azimuth < 0 )	x1y2x *= -1;
//	std:: cout << x1y2x << " " <<  x1y2y << std::endl;
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
};*/

/*Rectangle& CollisionZone::operator[] (int x)
{
	return Zones[x];
};*/

/*std::vector<Rectangle>* CollisionZone::getVector()
{
	return &Zones;
};*/