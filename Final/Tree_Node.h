#pragma once
#include <iostream>
#include <string>

class TreeNode
{

public:
	int val;
	TreeNode * L_link;
	TreeNode * R_link;
	int balance_fact;

public:
	TreeNode() {
		//default value should be assigned by constructor for objects or zero if primitive
		val = 0;
		L_link = nullptr;
		R_link= nullptr;
		balance_fact = 0;
	}

	TreeNode(int a) {
		val = a;
		L_link = NULL;
		R_link = NULL;
		balance_fact = 0;
	}
	void setvlue(int a) { val = a; }
	void set_Llink(TreeNode* L) { L_link = L; }
	void set_Rlink(TreeNode* R) { R_link = R; }
	int getvlue() const { return val; }
	TreeNode* get_Llink() const { return L_link; }
	TreeNode* get_Rlink() const { return R_link; }
};