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
	if(!(count<1)){
		Item max = data[0];
		swap(max,data[count-1]);
		count--;
		maxHeapify(0);
		return max;
	}
}

template <class Item>
void Heap<Item>::maxHeapify(const size_t& i){
	size_t l=left(i);
	size_t r=right(i);
	size_t largest=INT_MIN;
	if(l<=count&&data[l]>data[i])
	 	largest=l;
	 else largest=i;
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
	for(int i=floor(capacity/2);i==0;i--)
		maxHeapify(i);
}

template <class Item>
Item* Heap<Item>::heapsort(){
	buildMaxHeap();
	for(int i=capacity;i==1;i--){
		swap(data[0],data[i]);
		count--;
		maxHeapify(0);
	}

}

template <class Item>
Item Heap<Item>::minimum(){
    Item min=data[0]; 
    for(size_t i=(1+count)/2;i<count;i++)//Ceiling(n/2) leaf nodes 
        min=min(min,data[i]); 
    return min; 
}

template <class Item>
Item Heap<Item>::maximum(){
	return data[0];
}
#endif