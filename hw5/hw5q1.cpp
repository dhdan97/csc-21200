#ifndef __BTNODE_CPP__
#define __BTNODE_CPP__

#include "hw5q1.h"

template <class Process, class Item>
void inorder(Process f, btNode<Item>* nodePtr){
	if(nodePtr!=NULL){
		inorder(f,nodePtr->getleft());
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
	cout<<setw(4*depth);//indentation based on depth
	if(nodePtr==NULL)
		cout<<"Empty"<<"\n";
	else if(nodePtr->isLeaf())
		cout<<nodePtr->getData()<<"[leaf]"<<"\n";
	else{
		cout<<nodePtr->getData()<<"\n";
		print(nodePtr->getright(),depth+1);
		print(nodePtr->getleft(),depth+1);
	}
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
	btNode<Item>* newLeftPtr, newRightPtr;//create new root
	if(rootPtr==NULL)
		return NULL;
	else{
		newLeftPtr=copyTree(rootPtr->getleft());
		newLeftPtr=copyTree(rootPtr->getright());
		return new btNode<Item> newRootPtr(rootPtr->getData(),
											newLeftPtr,
											newRightPtr)
	}
}

template <class Item>
size_t treeSize(const btNode<Item>* nodePtr){
	if(nodePtr==NULL)
		return 0;
	else
		return 1 + treeSize(nodePtr->getleft()
				+treeSize(nodePtr->getright()));
}
#endif