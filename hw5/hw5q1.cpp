#ifndef __BTNODE_CPP__
#define __BTNODE_CPP__

#include "hw5q1.h"

template <class Process, class Item>
void inorder(Process f, btNode<Item>* nodePtr){//left - root - right
	if(nodePtr!=NULL){
		inorder(f,nodePtr->getLeft());
		f(nodePtr->getData());
		inorder(f,nodePtr->getRight());
	}
}

template <class Process, class Item>
void preorder(Process f, btNode<Item>* nodePtr){//root - left - right
	if(nodePtr!=NULL){
		f(nodePtr->getData());
		preorder(f,nodePtr->getLeft());
		preorder(f,nodePtr->getRight());
	}	
}

template <class Process, class Item>
void postorder(Process f, btNode<Item>* nodePtr){//left - right - root
	if(nodePtr!=NULL){
		postorder(f,nodePtr->getLeft());
		postorder(f,nodePtr->getRight());
		f(nodePtr->getData());
	}
}

template <class Item, class SizeType>
void print(btNode<Item>* nodePtr, SizeType depth){//prints in preorder
	cout<<setw(4*depth);//indentation based on depth
	if(nodePtr==NULL)
		cout<<"Empty"<<"\n";
	else if(nodePtr->isLeaf())
		cout<<nodePtr->getData()<<"[leaf]"<<"\n";
	else{
		cout<<nodePtr->getData()<<"\n";
		print(nodePtr->getRight(),depth+1);
		print(nodePtr->getLeft(),depth+1);
	}
}

template <class Item>
void clearTree(btNode<Item>*& rootPtr){//clears tree in postorder
	if(rootPtr!=NULL){
		btNode<Item>* leftPtr=rootPtr->getLeft();
		btNode<Item>* rightPtr=rootPtr->getRight();
		clearTree(leftPtr);
		clearTree(rightPtr);
		delete rootPtr;
		rootPtr = NULL;
	}
}

template <class Item>
btNode<Item>* copyTree(const btNode<Item>* rootPtr){//copies tree in postorder
	btNode<Item>* newLeftPtr;
	btNode<Item>* newRightPtr;
	if(rootPtr==NULL){
		return NULL;
	}
	else{
		newLeftPtr=copyTree(rootPtr->getLeft());
		newRightPtr=copyTree(rootPtr->getRight());
		return new btNode<Item>(rootPtr->getData(),newLeftPtr,newRightPtr);
	}
}

template <class Item>
size_t treeSize(const btNode<Item>* nodePtr){
	if(nodePtr==NULL)
		return 0;
	else
		return 1 + treeSize(nodePtr->getLeft()
				+treeSize(nodePtr->getRight()));
}
#endif