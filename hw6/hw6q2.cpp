#ifndef __GRAPHL_CPP__
#define __GRAPHL_CPP__

#include "hw6q2.h"

template <class Item>
graphL<Item>::graphL(){
	capacity=DEF_CAP;
	list=new node<graphData>*[capacity];//list contains pointers to nodes
	for(size_t i=0;i<capacity;i++)
		list[i]=NULL;
	label=new Item[capacity];
	count=0;
}

template <class Item>
void graphL<Item>::addVertex(const Item& inLabel){
	label[count]=inLabel;//add vertex to label list
	count++;
}

template <class Item>
void graphL<Item>::addEdge(size_t source, size_t target, int weight){
	if(list[source]==NULL){//if this is the first edge coming from vertex;make head of linked list
		node<graphData>* newEdge;
		graphData EdgeData;
		EdgeData.setV(target);//To what vertex the edge is going to
		EdgeData.setW(weight);//edge weight
		list_head_insert(newEdge,EdgeData);
		newEdge->set_link(NULL);
		list[source]=newEdge;
	}
	else{//if edges coming from this vertex already exist;insert node to tail of linked list
		node<graphData>* newEdge=list[source];
		while(newEdge->link()!=NULL){
			if(newEdge->data().getV()==target){//if edge you want to add already exists;overwrite graphData variables
				newEdge->data().setW(weight);
				return;
			}
			newEdge=newEdge->link();
		}
		if(newEdge->data().getV()==target){//if edge you want to add already exists;overwrite graphData variables
			newEdge->data().setW(weight);
			return;
		}
		graphData EdgeData;
		EdgeData.setV(target);
		EdgeData.setW(weight);
		list_insert(newEdge,EdgeData);
	}
}

template <class Item>
void graphL<Item>::removeEdge(size_t source, size_t target){
	if(list[source]==NULL)
		return;	
	if(list[source]->data().getV()==target){
		list_head_remove(list[source]);
		return;
	}
	node<graphData>* headPtr=list[source];	
	while(headPtr->link()!=NULL){
		if(headPtr->data().getV()==target){
			list_remove(headPtr);
			return;
		}
		headPtr=headPtr->link();
	}	
}

template <class Item>
void graphL<Item>::print() const{
	node<Item>* printList;
	for(size_t i=0;i<count;i++){
		node<graphData>* graphDataList=list[i];
		if(graphDataList==NULL){
		cout<<label[i]<<"\n";
		continue;	
		}
		cout<<label[i];
		while(graphDataList!=NULL){
			cout<<"->";
			cout<<label[graphDataList->data().getV()];
			graphDataList=graphDataList->link();
		}
		cout<<"\n";
	}
}

template <class Item>
size_t graphL<Item>::numVertices() const{
	return count;
}

template <class Item>
size_t graphL<Item>::numEdges() const{
	size_t edgeCount=0;
	if(count>0){
		for(size_t i=0;i<capacity;i++){
			if(list[i]==NULL)
				continue;
			 node<graphData>* headPtr;
			 headPtr=list[i];
			 while(headPtr!=NULL){
			 	headPtr=headPtr->link();
			 	edgeCount++;
			}
		}
	}
	return edgeCount;
}

template <class Item>
bool graphL<Item>::isEdge(size_t source, size_t target) const{
	node<graphData>* headPtr;
	headPtr=list[source];
	while(headPtr!=NULL){
		if(headPtr->data().getV()==target)
			return true;
		headPtr=headPtr->link();
	}
	return false;
}

template <class Item>
node<Item>* graphL<Item>::neighbors(size_t vertex) const{
	node<graphData>* graphDataList=list[vertex];
	node<Item>* neighborList;
	list_head_insert(neighborList,label[graphDataList->data().getV()]);
	while(graphDataList->link()!=NULL){
		graphDataList=graphDataList->link();
		list_insert(neighborList,label[graphDataList->data().getV()]);
	}
	return neighborList;
}
#endif