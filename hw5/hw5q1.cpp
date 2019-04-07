#ifndef __BTNODE_CPP__
#define __BTNODE_CPP__

#include "hw5q1.h"

template <class Process, class Item>
void inorder(Process f, btNode<Item>* nodePtr){
	if(nodePtr!=NULL){
		inorder(f,nodePtr->getleft());//ask if you need to have "f" in the parameter
		f(nodePtr->getData());
		inorder(f,nodePtr->getright());
	}
}

template <class Process, class Item>
void preorder(Process f, btNode<Item>* nodePtr){
	if(nodePtr!=NULL){
		f(nodePtr->getData());
		preorder(f,nodePtr->getleft());
		preorder(f,nodePtr->getright());
	}	
}

template <class Process, class Item>
void postorder(Process f, btNode<Item>* nodePtr){
	if(nodePtr!=NULL){
		postorder(f,nodePtr->getleft());
		postorder(f,nodePtr->getright());
		f(nodePtr->getData());
	}
}

template <class Item, class SizeType>
void print(btNode<Item>* nodePtr, SizeType depth){

}

template <class Item>
void clearTree(btNode<Item>*& rootPtr){
	if(rootPtr!=NULL){
		clearTree(rootPtr->getleft());
		clearTree(rootPtr->getright());
		delete rootPtr;
		rootPtr = NULL;
	}
}

template <class Item>
btNode<Item>* copyTree(const btNode<Item>* rootPtr){
	btNode<Item>* newRootPtr;//create new root
	newRootPtr->setLeft(rootPtr->getleft());//syntax wrong?? Idea might be wrong altogether
											//because this may link newRootPtr's left to
											//rootPtr's left. What we want to do is make a
											//copy of rootPtr's left and have 
											//newRootPtr->setleft() link to that.

}
#endif