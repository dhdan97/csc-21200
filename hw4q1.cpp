#ifndef __HW4Q1_CPP__
#define __HW4Q1_CPP__

#include "hw4q1.h"

template <class Item>
Stack<Item>::Stack(){
	data=new Item[DEF_CAP];
	used=0;
}

template <class Item>
Stack<Item>::Stack(const Stack& source){
	data = new Item[DEF_CAP];
	used=source.used;
	for(int i=0;i<used;i++)
        data[i] = source.data[i];
}

template<class Item>
Stack<Item>::~Stack(){
	delete [] data;
}

template<class Item>
void Stack<Item>::push(const Item& entry){
	//assert(used<DEF_CAP);
	data[used]=entry;
	used++;
}

template<class Item>
void Stack<Item>::pop(){
	if(!empty())
		used--;
}

template<class Item>
void Stack<Item>::operator=(const Stack<Item>& source){
	if(this!=&source){
		data = new Item[DEF_CAP];
		used=source.used;
		for(size_t i=0;i<used;i++)
			data[i]=source.data[i];
	}
}

template<class Item>
size_t Stack<Item>::size() const{
	return used;
}

template<class Item>
bool Stack<Item>::empty() const{
	return(used==0);
}

template<class Item>
Item Stack<Item>::top() const{
	if(!empty())
		return data[used-1];
}

#endif