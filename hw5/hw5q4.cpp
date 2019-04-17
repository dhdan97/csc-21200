#ifndef __BST_CPP__
#define __BST_CPP__

#include "hw5q4.h"
//found on pg 518
template <class Item>
BST<Item>::BST(){
	count=0;
}

template <class Item>
void BST<Item>::insert(const Item& entry){
	tree.shiftToRoot();
	btNode<Item>* entryNode = new btNode<Item>(entry);
	btNode<Item>* prev=NULL;
	btNode<Item>* curr=tree.getNode();
	while(curr!=NULL){
		prev=curr;
		if(entry<curr->getData())//entry or entryNode->getData()? Should be the same thing
			curr=curr->getLeft();
		else
			curr=curr->getRight();
	}
	entryNode->setParent(prev);
	if(prev==NULL)//If tree T was empty
		tree.createFirstNode(entry);
	else if(entry<prev->getData()){//entry or entryNode->getData()? Should be the same thing
		//tree.addLeft(entry);
		prev->setLeft(entryNode);
	 }
	else /*tree.addRight(entry);*/prev->setRight(entryNode);
	count++;
}

template <class Item>
void BST<Item>::remove(const Item& target){
	btNode<Item>* curr=tree.search(target);
	btNode<Item>* currSuccessor;
	if(curr->getLeft()==NULL)
		tree.transplant(curr,curr->getRight());
	else if(curr->getRight()==NULL)
		tree.transplant(curr,curr->getLeft());
	else{
		currSuccessor=tree.minimum(curr->getRight());
		if(currSuccessor->getParent()!=curr){
			tree.transplant(currSuccessor,currSuccessor->getRight());
			currSuccessor->setRight(curr->getRight());
			currSuccessor->getRight->setParent(currSuccessor);
		}
		transplant(curr,currSuccessor);
		currSuccessor->setLeft(curr->getLeft());
		currSuccessor->getLeft->setParent(currSuccessor);
	}

}

template <class Item>
void BST<Item>::transplant(btNode<Item>*& u, btNode<Item>*& v){
	if(u->getParent()==NULL){
		tree.shiftToRoot();
		tree.getNode()=v;
	}
	else if(u==u->getParent()->getLeft())
		u->getParent()->setLeft(v);
	else u->getParent()->setRight(v);
	if(v!=NULL)
		v->setParent(u.getParent);
}

template <class Item>
btNode<Item>* BST<Item>::minimum(){//test failed; check insert?
	tree.shiftToRoot();
	btNode<Item>* curr=tree.getNode();
	while(curr->getLeft()!=NULL)
		curr=curr->getLeft();
	return curr;
}

template <class Item>
btNode<Item>* BST<Item>::maximum(){//test failed; check insert?
	tree.shiftToRoot();
	btNode<Item>* curr=tree.getNode();
	while(curr->getRight()!=NULL)
		curr=curr->getRight();
	return curr;	
}

template <class Item>
btNode<Item>* BST<Item>::search(const Item& target){
	tree.shiftToRoot();
	btNode<Item>* curr=tree.getNode();
	while(curr!=NULL&&target!=curr->getData()){
		if(target<curr->getData())
			curr=curr->getLeft();
		else curr=curr->getRight();
	}
	return curr;	
}
#endif

