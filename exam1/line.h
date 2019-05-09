#ifndef LINE_CLASS_H
#define LINE_CLASS_H

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "newpoint.h"

template <class Item>
class line
{
public:
	line();
	line(point point1,point point2);
	line(const line<Item>& source);

	point getPoint1() const{
		return p1;
	}
	point getPoint2() const{
		return p2;
	}
	Item getSlope() const{
		return slope;
	}
	Item getLength() const{
		return length;
	}

	point setPoint1(point point1);
	point setPoint2(point point2);
	Item setSlope(Item s1);
	Item setLength(Item l1);

	line<Item> parallel(line<Item> line1);

	bool operator <(line<Item> rightLine){
		return (length<rightLine.length);
	}
	bool operator >(line<Item> rightLine){
		return (length>rightLine.length);
	}


private:
	point p1;
	point p2;
	Item slope;
	Item length;
}; 

template <class Item>
bool parallel(line<Item> line1,line<Item> line2);

#include "line.cpp"
#endif