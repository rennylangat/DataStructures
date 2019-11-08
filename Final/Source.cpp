#include<iostream>
#include<string>
#include"Bst.h"
#include"Tree_Node.h"
#include"Song.h"
#include"hash.h"
#include<fstream>
using namespace std;


int main() {

	ifstream in("input.txt");

	Song test;
	while (in.good()) {
		in >> test;
	}
	cout << test;
	system("pause");
		return 0;
}
