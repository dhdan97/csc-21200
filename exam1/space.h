#ifndef SPACE_CLASS_H
#ifndef SPACE_CLASS_H

#include "line.h"

template <class Item>
class line
{
public:
	const size_t DEF_CAP = 30;

	space();
	space(space<Item>& source);
	~space();



	void operator =(space<Item> rightSpace);

private:
	Item* pointArray;
	size_t used;
	size_t capacity;	
}
#endif
