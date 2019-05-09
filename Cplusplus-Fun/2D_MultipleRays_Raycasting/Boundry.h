#pragma once
#include <SFML/Graphics.hpp>
#include "Line.h"


using namespace sf;

class Boundry : public Line{

	public:
		Boundry(float x1,float y1,float x2,float y2) : Line(x1,y1,x2,y2){}
		
};