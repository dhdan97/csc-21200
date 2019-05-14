#ifndef N_CHILD_NODE_H
#define N_CHILD_NODE_H

#include <iostream>

using namespace std;

template<class Item>
class nChildNode{
//Problems encountered:

//Should we give the constructor a parameter for it's children, and if so, how do we check
//the capacity and count of the given parameter so that we may assign these variables
//to our private variables?

//Similar problem with setChildren, how do we check the capacity and count of of the
//dynamic array given to us? 
public:
	const size_t DEF_CAP=30;

	nChildNode(const Item& initData=Item(),
			   nChildNode<Item>** initChildren=NULL,
			    nChildNode<Item>* initParent=NULL){
		data=initData;
		parent=initParent;
		children=initChildren;
		if(children==NULL){

			children=new 
		}


	}

				 Item& getData(){return data;}
	 nChildNode<Item>* getParent(){return parent;}
	nChildNode<Item>** getChildren(){return children;}
				size_t getCapacity(){return capacity;}

	void setData(Item newData){data=newData;}
	void setParent(nChildNode<Item>* newParent){parent=newParent;}
	void setChildren(nChildNode<Item>** newChildren){
		children=newChildren;}

				 const Item& getData() const{return data;}
	 const nChildNode<Item>* getParent() const{return parent;}
	const nChildNode<Item>** getChildren() const{return children;}

	bool isLeaf(){}

private:
	Item data;
	nChildNode<Item>** children;
	nChildNode<Item>* parent;
	size_t count;
	size_t capacity; 
};