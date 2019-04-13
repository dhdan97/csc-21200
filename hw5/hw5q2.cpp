#ifndef __BT_CLASS_CPP__
#define __BT_CLASS_CPP__

#include "hw5q2.h"
//bt class found on pg 536 of textbook

template <class Item>
binaryTree<Item>::binaryTree(){//Postcondition: The binary tree has been initialized 
//as an empty tree (with no nodes).
	root=NULL;
	curr=root;
	count=0; 
}

template <class Item>
binaryTree<Item>::binaryTree(const binaryTree& source){//Postcondition: The binary tree has
//been initalized as a tree that is a copy of it's source.
	root=copyTree(source.root);
	curr=root;
	count=source.size();
}

template <class Item>
binaryTree<Item>::~binaryTree(){//Postcondition: The binary tree has have all it's nodes
//removed, size has been reset and all pointers point to NULL
	clearTree(root);
	count=0;
	curr=NULL;
}

template <class Item>
void binaryTree<Item>::createFirstNode(const Item& entry){//Precondition: size() is zero.
//Postcondition: The tree now has one node (a root node), containing the
//specified entry. This new root node is the "current node."
	if(count=0){//size()?
		root->setData(entry);
		curr=root;
		count=1;
	}
}

template <class Item>
void binaryTree<Item>::shiftToRoot(){//Precondition: size() > 0.
//Postcondition: The "current node" is now the root of the tree.
	if(count>0)
		curr=root;
}

template <class Item>
void binaryTree<Item>::shiftUp(){//Precondition: hasParent() returns true.
//Postcondition: The "current node" has been shifted up to the parent of
//the old current node.
	if(hasParent())//wrong syntax?
		curr=curr->getParent();	
}

template <class Item>
void binaryTree<Item>::shiftLeft(){//Precondition: hasLeft() returns true.
//Postcondition: The "current node" been shifted down to the left child
//of the original current node.
	if(hasLeft())
		curr=curr->getLeft();
}


template <class Item>
void binaryTree<Item>::shiftRight(){//Precondition: hasRight() returns true.
//Postcondition: The "current node" been shifted down to the right child
//of the original current node.
	if(hasRight())
		curr=curr->getRight();	

}

template <class Item>
void binaryTree<Item>::change(const Item& newEntry){//precondition: size() > 0.
//postcondition: The data at the "current node" has been changed to the new entry.
	if(count>0)
		curr->getData()=newEntry;

}

template <class Item>
void binaryTree<Item>::addLeft(const Item& entry){//Precondition: size() > 0, and hasLeft() 
//returns false.
//Postcondition: A left child has been added to the "current node", with the given entry.
	if(count>0&&!hasLeft()){
		btNode<Item>* nleft;
		nleft->setData(entry);
		curr->setLeft(nleft);
	}
}

template <class Item>
void binaryTree<Item>::addRight(const Item& entry){//Precondition: size() > 0, and 
//hasRight() returns false.
//Postcondition: A right child has been added to the "current node", with the given entry.
	if(count>0&&!hasRight()){
		btNode<Item>* nright;
		nright->setData(entry);
		curr->setLeft(nright);
	}
}

template <class Item>
void binaryTree<Item>::removeLeft(){//Precondition: size() > 0, hasLeft() returns true,
//and getLeft()->isLeaf() return true.
//Postcondition: A left child has been removed from the "current node."
	if(count>0&&hasLeft()&&curr->getLeft()->isLeaf()){
		delete curr->getLeft();
		curr->setLeft(NULL);
	}

}


template <class Item>
void binaryTree<Item>::removeRight(){//Precondition: size( ) > 0, hasRight( ) returns true,
//and getRight( )->isLeaf( ) return true.
//Postcondition: A right child has been removed from the "current node."
	if(count>0&&hasRight()&&curr->getRight()->isLeaf()){
		delete curr->getRight();//necessary?
		curr->setRight(NULL);
	}
}

template <class Item>
void binaryTree<Item>::setRoot(btNode<Item>* newRoot){//Precondition: size() > 0.
//Postcondition: The root has been set to newRoot.
	if(count>0){
		root=newRoot;
		count=treeSize(root);
	}
}

template <class Item>
btNode<Item>* binaryTree<Item>::getNode(){//Precondition: size() > 0.
//Postcondition: The return value is the btNode from the "current node".
	if(count>0)
		return curr;

}

template <class Item>
size_t binaryTree<Item>::size() const{//Postcondition: The return value is the number
//of nodes in the tree.
	return count;
}

template <class Item>
Item binaryTree<Item>::retrieve() const{//Precondition: size()  > 0.
//Postcondition: The return value is the data from the "current node".
	if(count>0)
		return curr->getData();
}

template <class Item>
bool binaryTree<Item>::hasParent() const{//Postcondition: Returns true if size() > 0, 
//and the "current node" has a parent
	return (count>0&&(curr->getParent()!=NULL));//double check this
}

template <class Item>
bool binaryTree<Item>::hasLeft() const{//Postcondition: Returns true if size() > 0,
//and the "current node" has a left child.
	return (count>0&&(curr->getLeft()!=NULL));
}

template <class Item>
bool binaryTree<Item>::hasRight() const{//Postcondition: Returns true if size() > 0,
//and the "current node" has a right child.
	return (count>0&&(curr->getRight()!=NULL));
}
#endif 