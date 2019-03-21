#include "hw4q1.h"

template <class Item>
Stack<item>::Stack(){
	data = new Item[DEF_CAP];
	used=0;
}

template <class Item>
Stack<item>::Stack(const Stack& source){
	data = new Item[DEF_CAP];
	used=source.used;
	for(int i=0;i<_size;i++)
        data[i] = source.data[i];
}