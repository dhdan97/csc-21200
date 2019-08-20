#ifndef __GRAPHM_H__
#define __GRAPHM_H__
// Previous two lines are the start of the marco guard

// CSc 21200 - Spring 2019
// Homework 6 header file

// Try not to change this file

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>

using namespace std;

template <class Item>
class graphM
{
public:
    // MEMBER CONSTANTS
    const size_t DEF_CAP = 30;
    // CONSTRUCTOR
    graphM();
    graphM(const graphM<Item>& source);
    // MODIFICATION MEMBER FUNCTIONS
    void addVertex(const Item& inLabel);
    void addEdge(size_t source, size_t target, int weight);
    void removeEdge(size_t source, size_t target);
    Item& operator [ ] (size_t vertex) 
        { assert(vertex < count);
          return label[vertex]; }
    // CONSTANT MEMBER FUNCTIONS
    void print() const;
    size_t numVertices() const;
    size_t numEdges() const;
    bool isEdge(size_t source, size_t target) const;
    Item* neighbors(size_t vertex) const;
    size_t index(const Item& target) const 
        { for(size_t i = 0; i < count; i++) {
            if(label[i] == target)
                return i; } 
          return count; }
    Item operator[ ] (size_t vertex) const
        { assert(vertex < count);
          return label[vertex]; }

    bool hasCycle(graphM<Item> graph){
        int color[graph.numVertices()];//0=white;1=gray;2=black
        for(size_t i=0;i<graph.numVertices();i++)//make all vertices white
            color[i]=0;
        for(size_t i=0;i<graph.numVertices();i++){//for every vertex
            if(color[graph.index(label[i])]==0){//if vertex color is white
                if(dfs(graph,label[i],color))//dfs function actually checks for a cycle
                    return true;
            }
        }
        return false;
    }

    bool dfs(graphM<Item> graph,Item vertex,int& color[]){
        color[graph.index(vertex)]=1;//set to gray
        for(size_t i=0;i<count;i++){//for each neighbor of the vertex
            if(color[graph.index(graph.neighbors(vertex)[i])]==3)//if black, continue
                continue;
            if(color[graph.index(graph.neighbors(vertex)[i])]==2)//if gray, cycle found
                return true;
            if(dfs(graph,graph.neighbors(vertex)[i],color))//recusively checks the rest
                                                           //of vertex's neighbors
                return true;
        }
        return false;
    }
private:
    Item* label;
    int** matrix;
    size_t count;
    size_t capacity;
};

template <class Item>
Item* resize(Item* ar, size_t count) {
	Item* newAr = new Item[count];
	for(size_t i = 0; i < count; i++)
		newAr[i] = ar[i];
	return newAr;
}

#include "hw6q1.cpp"
#endif