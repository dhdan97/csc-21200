#ifndef __HEAP_CPP__
#define __HEAP_CPP__

#include "hw5q5.h"
//in section 11.1(pg 540) of book
template <class Item>
Heap<Item>::Heap(){
    capacity=DEF_CAP;
    data=new Item[capacity];
    count=0;
}

template <class Item>
void Heap<Item>::increaseKey(size_t i, const Item& entry){
	if(data[i]<entry){
		data[i]=entry;
		maxHeapify(i);
	}
}

template <class Item>
Item Heap<Item>::removeMax(){
	return data[0];
}

template <class Item>
void maxHeapify(const size_t& i){
	size_t l=2*i+1;//left() dont work
	size_t r=2*i+2;//right() dont work
	if(l<=count&&data[l]>data[i])//data not defined?? Is supposed to be private member variable
	 	size_t largest=l;
	 else size_t largest=i;
	if(r<=count&&data[r]>data[largest])
		largest=r;
	if(largest!=i){
		swap(data[i],data[largest]);
		maxHeapify(largest);
	}
}

template <class Item>
void Heap<Item>::buildMaxHeap(){
	count=capacity;
	for(int i=floor(capacity/2),i==0,i--)
		maxHeapify(i);
}

template <class Item>
Item* Heap<Item>::heapsort(){
	buildMaxHeap();
	for(int i=capacity,i==1,i--){
		swap(data[0],data[i]);
		count--;
		maxHeapify(0);
	}

}

template <class Item>
Item Heap<Item>::minimum(){

}

template <class Item>
Item Heap<Item>::maximum(){
	
}
#endif
