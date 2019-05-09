#ifndef LINE_CLASS_CPP
#ifndef LINE_CLASS_CPP

#include "line.h"

template <class Item>
line<Item>::line(point point1,point point2,Item slope,Item length){
	p1=point1;
	p2=point2;
	slope=(p2.get_y()-p2.get_x())/(p1.get_y()-p1.get_x());
	length=distance(p1,p2);
}

template <class Item>
line<Item>::line(const line<Item>& source){
	p1=source.p1;
	p2=source.p2;
	slope=source.slope;
	length=source.length;
}

template <class Item>
point line<Item>::setPoint1(point point1){
	p1=point1;
}

template <class Item>
point line<Item>::setPoint2(point point2){
	p2=point2;
}

template <class Item>
Item line<Item>::setSlope(Item s1){
	slope=s1;
}

template <class Item>
Item line<Item>::setLength(Item l1){
	length=l1;
}

template <class Item>
line<Item> line<Item>::parallel(line<Item> line1){
	line<Item> line2;
	line2.setLength(line1.getLength());
	line2.setSlope(line1.getSlope());
	line2.setPoint1(line1.getPoint1());
	line2.setPoint2(line1.getPoint2());
	line2.p1.shift(1,1);
	line2.p2.shift(1,1);
}

template <class Item>
bool parallel(line<Item> line1,line<Item> line2){
	return line1.getSlope()==line2.getSlope();
}
#endif