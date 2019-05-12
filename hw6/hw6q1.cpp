#ifndef __GRAPHM_CPP__
#define __GRAPHM_CPP__

#include "hw6q1.h"

template <class Item>
graphM<Item>::graphM(){
	capacity=DEF_CAP;
	matrix=new int*[capacity];
    for(size_t i=0;i<capacity;i++)//matrix points to dynamic array of pointers,
 //which each point to their own dynamic array
        matrix[i]=new int[capacity];
    label=new Item[capacity];//vertex label list in the shape of a dynamic array
    count=0;	
}

template <class Item>
graphM<Item>::graphM(const graphM<Item>& source){
    capacity=source.capacity;
    count=source.count;
    matrix=new int*[capacity];
    for(size_t i=0;i<capacity;i++){
        matrix[i]=new int[capacity];
        for(size_t j=0;j<count;j++)//copy source matrix array;copying edges
            matrix[i][j]=source.matrix[i][j];
    }
    label=new Item[capacity];
    for(size_t k=0;k<capacity;k++)//copy source label array;copying vertex list
        label[k]=source.label[k];
}

template <class Item>
void graphM<Item>::addVertex(const Item& inLabel){
    if(count<capacity){
    	label[count]=inLabel;//add inLabel to vertex list
    	count++;
    }
}

template <class Item>
void graphM<Item>::addEdge(size_t source, size_t target, int weight){
    if((source<capacity)&&(target<capacity)&&(count>=2)&&weight>0){
    	matrix[source][target]=weight;//set weight of edge from source to target
    }
}

template <class Item>
void graphM<Item>::removeEdge(size_t source, size_t target){
  if(count>=2)
  	matrix[source][target]=0;
}

template <class Item>
void graphM<Item>::print() const{
    if(count>0){
    	cout<<setw(2)<<"";
    	for(size_t i=0;i<count;i++){//prints vertex list row
        	cout<<label[i];
        	cout<<setw(1)<<"";
    	}
    	cout<<"\n";
    	for(size_t j=0;j<count;j++){
        	cout<<label[j];//prints vertex list column
        	cout<<setw(1)<<"";
        	for(size_t k=0;k<count;k++){//prints edges
            	cout<<matrix[j][k];
            	cout<<setw(1)<<"";
        	}
        	cout<<"\n";
    	}
    }    
}

template <class Item>
size_t graphM<Item>::numVertices() const{
	return count;
}

template <class Item>
size_t graphM<Item>::numEdges() const{
    if(count>0){
    	size_t edgesCount=0;
    	for(size_t i=0;i<capacity;i++){
        	for(size_t j=0;j<capacity;j++){
            	if(matrix[i][j]!=0){//checks each weight that isn't 0;
                edgesCount++;
            	}
        	}
    	}
    	return edgesCount;
	}
}

template <class Item>
bool graphM<Item>::isEdge(size_t source, size_t target) const{
    return (matrix[source][target]!=0);
}

template <class Item>
Item* graphM<Item>::neighbors(size_t vertex) const{
    if(count>0){
    	Item* track=new Item[count];
    	size_t trackSize=0;
        	for(size_t i=0;i<count;i++){
            	if(matrix[vertex][i]!=0){
                	track[trackSize]=label[i];
                	trackSize++;
            	}
        	}
        return track;
	}
}
#endif