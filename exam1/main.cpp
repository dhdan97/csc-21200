#ifndef LINE_MAIN
#define LINE_MAIN

#include <iostream>
#include "line.h"
using namespace std;

int main(int argc, char const *argv[])
{
	line<int> l1;
	cout<<l1.getPoint1()<<"\n";
	return 0;
}
#endif