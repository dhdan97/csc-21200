#ifndef KEY_TREE_NODE_H
#define KEY_TREE_NODE_H

#include <iostream>

using namespace std;

class treeData
{
public:
	treeData() {;}
	treeData(const size_t& inID, const int& inW) {ID = inID; weight = inW;}
	void setID(const size_t& inID) {ID = inID;}
	void setW(const int& inW) {weight = inW;}
	size_t getID() const {return ID;}
	int getW() const {return weight;}
	void operator=(const graphData& entry) {ID = entry.ID; weight = entry.ID;}
	bool operator== (const size_t& target) {return ID == target;}

private:
	char ID;
	size_t weight;
};

class BTNode
{
public:
	BTNode(treeData initData=treeData(),initleft=NULL,initRight=NULL,initParent=NULL){
		data=initData;
		left=initleft;
		right=initRight;
		parent=initParent;
	}

	

private:
	treeData data;
	BTNode<treeData>* left;
	BTNode<treeData>* right;
	BTNode<treeData>* parent;	
}