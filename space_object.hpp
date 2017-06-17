#ifndef SPACE_OBJECT__
#define SPACE_OBJECT__

class SpaceObject
{
protected:
	typedef double Coordinate_type;
	typedef double Azimuth_type;
	
	Coordinate_type xCurrent = 0;
	Coordinate_type yCurrent = 0;
	
	Coordinate_type xChange = 0;
	Coordinate_type yChange = 0;	
	
	Azimuth_type azimuth = 0;
	
	double getSpeed();

public:
//	void nextStep(int); override in ship
};

#endif