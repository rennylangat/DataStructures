#pragma once
#include <iostream>
#include <string>
#include "Tree_Node.h"

using namespace std;

 class Bst
{
public:
	Bst() { root = NULL; }
	virtual ~Bst()
	{
		//clear();
	}
	TreeNode* getRoot() { return root; }
	TreeNode* insert(TreeNode *, int);
	TreeNode* search(TreeNode *, int);
	TreeNode* Delete(TreeNode *, int);
	TreeNode* Findmin_adr(TreeNode *);
	void balance_tree(TreeNode*);
	int Findmin(TreeNode *);
	int Findmax(TreeNode *);
	void preorder_Trv(TreeNode *);
	void postorder_Trv(TreeNode *);
	void inorder_Trv(TreeNode *);
	int get_height(TreeNode *);
	void calculateBalanceFactor();
private:
	TreeNode* root;
	
};

 TreeNode* Bst::insert(TreeNode* r, int a) {

	 if (root == NULL) {
		 TreeNode* temp_ptr = new TreeNode(a);
		 root = temp_ptr;
		 calculateBalanceFactor();
		 balance_tree(this->getRoot());
		 return root;
	 }
	 if (r->val > a) {
		 if (r->L_link == NULL) {
			 TreeNode* temp_ptr = new TreeNode(a);
			 r->L_link = temp_ptr;
			 calculateBalanceFactor();
			 balance_tree(this->getRoot());
			 return temp_ptr;
		 }
		 else {	 
			 return insert(r->L_link, a);
		 }
	 }
	 else {
		 if (r->R_link == NULL) {
			 TreeNode* temp_ptr = new TreeNode(a);
			 r->R_link = temp_ptr;
			 calculateBalanceFactor();
			 balance_tree(this->getRoot());
			 return temp_ptr;
		 }
		 else {
			 
			 return insert(r->R_link, a);
		 }
	 }
		 
 }

 TreeNode* Bst::search(TreeNode* r, int a) 
 {
	 if (r == NULL)
		 return NULL;
	 TreeNode* temp_ptr = r;
	 if (temp_ptr->val == a) 
	 {
		 return temp_ptr;
	 }

	 if (temp_ptr->val > a)
	 {
		 return search(r->L_link, a);
	 }
	 else
	 {
		 return search(r->R_link, a);
	 }

 }

 int Bst::Findmin(TreeNode *r) {
	 if (r == NULL)
	 {
		 cout << "Error!!!!" << endl;
		 return -1;
	 }
	 else if (r->L_link == NULL)
	 {
		 return r->val;
	 }
	 return Findmin(r->L_link);
 }

 TreeNode* Bst::Findmin_adr(TreeNode *r) {
	 if (r == NULL)
	 {
		 cout << "Error!!!!" << endl;
		 return r;
	 }
	 else if (r->L_link == NULL)
	 {
		 return r;
	 }
	 return Findmin_adr(r->L_link);
 }


 int Bst::Findmax(TreeNode *r) {
	 if (r == NULL)
	 {
		 cout << "Error!!!!" << endl;
		 return -1;
	 }
	 else if (r->R_link == NULL)
	 {
		 return r->val;
	 }
	 return Findmax(r->R_link);
 }

 void Bst::preorder_Trv(TreeNode *r) {
	 if (r == NULL)
		 return;
	 cout << r->val << " ";
	 preorder_Trv(r->L_link);
	 preorder_Trv(r->R_link);
 }

 void Bst::postorder_Trv(TreeNode *r) {
	 if (r == NULL)
		 return;
	 postorder_Trv(r->L_link);
	 postorder_Trv(r->R_link);
	 cout << r->val << " ";
 }
 void Bst::inorder_Trv(TreeNode *r) {
	 if (r == NULL)
		 return;
	 inorder_Trv(r->L_link);
	 cout << r->val << " ";
	 inorder_Trv(r->R_link);
 }

 TreeNode* Bst::Delete(TreeNode* r, int a) {
	 if (r == NULL) { cout << "Value not found" << endl; return r; }
	 else if (r->val > a) 
	 {
		 r->L_link= Delete(r->L_link,a); 
	 }
	 else if (r->val < a) 
	 { 
		 r->R_link = Delete(r->R_link, a); 
	 }
	 else
	 {
		 //case 1. No child
		 if (r->L_link == NULL && r->R_link == NULL) {
			 delete r;
			 calculateBalanceFactor();
			 balance_tree(this->getRoot());
			 r = NULL;
			 //return r;
		 }
		 //case 2. One child
		 else if (r->L_link == NULL) {
			 TreeNode* temp_ptr = r;
			 r = r->R_link;
			 delete temp_ptr;
			 calculateBalanceFactor();
			 balance_tree(this->getRoot());
			 //return r;
		 }
		 else if (r->R_link == NULL) {
			 TreeNode* temp_ptr = r;
			 r = r->L_link;
			 calculateBalanceFactor();
			 balance_tree(this->getRoot());
			 delete temp_ptr;
			 //return r;
		 }

		 //case 3. Two child
		 else {
			 TreeNode * temp_ptr = Findmin_adr(r->R_link);
			 r->val = temp_ptr->val;
			 r->R_link = Delete(r->R_link, temp_ptr->val);
		 } 
	 }
	 return r;
 }
 int Bst::get_height(TreeNode *r) {
	 int count_1 = 0;
	 int count_2 = 0;
	 int count = 0;
	 if (r == NULL)
		 return 0 ;
	 count_1 = get_height(r->L_link);
	 count_2 = get_height(r->R_link);
	 if (count_1 > count_2) {
		 count = count_1 + 1;
	 }
	 else
		 count = count_2 + 1;
	 //r->balance_fact = count_1 - count_2;
	 return count;
 }

 void Bst::calculateBalanceFactor()
 {
	 //get_height(this->getRoot());
 }

 void Bst::balance_tree(TreeNode *r) {
	 //if (r == NULL) return;
	 //// Left link of root
	 //if (r->L_link) {
		// // Right heavy
		// if (r->L_link->balance_fact < -1) {
		//	 TreeNode* parent = r;
		//	 TreeNode* child = r->L_link;
		//	 parent->L_link = child->R_link;
		//	 child->R_link = parent->L_link->L_link;
		//	 parent->L_link->L_link = child;
		//	 calculateBalanceFactor();
		// }
		// // Left Heavy
		// else if (r->L_link->balance_fact > 1) {

		// }
		// balance_tree(r->L_link);
	 //}
 }