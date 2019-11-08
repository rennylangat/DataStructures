#pragma once
#include<string>
#include<iostream>
#include"bst.h"
#include"hash.h"
#include"stack.h"
#include"Song.h"
#include<fstream>
class MusicLib
{
private:
	Bst* BSTree;
	HashMap* HTable;
	Stack<Song>* stack;


public:


	MusicLib() {
	
		BSTree = new Bst;
		HTable = new HashMap;
		stack = new Stack<Song>;
	}
	void insert(Song* a) {

		//std::string title;
		//std::string artist;
		//std::string album;
		//std::string genre;
		//int songLen;
		//int playCount;
		//cout << "Enter Song's Title: ";
		//getline(cin, title);
		//cout << "Enter Song's Artist ";
		//getline(cin, artist);
		//cout << "Enter Song's Album: ";
		//getline(cin, album);
		//cout << "Enter Song's Genre: ";
		//getline(cin, genre);
		//cout << "Enter Song's Length: ";
		//cin >> songLen;
		//cout << "Enter Song's Playcount: ";
		//cin >>playCount;
		//
		//Song* temp = new Song(title,artist,album,genre,songLen,playCount);
		//HTable->Insert(a);
		//BSTree->insert(a);
	
	
	}

	void remove() {
		std::string key;
	
		cout << "Please enter Key: ";
		getline(cin, key);
		Song* temp = HTable->Search(key);
		if (temp != nullptr)
		{
			stack->push(*temp);
		}
		try {
			// HTable->remove(key);
			//BSTree->Delete(BSTree->getRoot(),key);
		}
		catch (std::string e)
		{
			cout << e;
		}
	}
	Song* search(){
		std::string key;
		cout << "Please enter Key: ";
		Song* temp = HTable->Search(key);
	
		return temp;
	}

	bool buildLibrary(ifstream &in)
	{
		Song* test;
		while (in.good()) {
			test = new Song;
			in >> *test;
			insert(test);
		}
	
	}
	bool saveLibrary(ofstream &out)
	{

		while (!out)
		{
			//BST in-order traversal
		}

	}

	bool undoDelete()
	{
		Song* temp=new Song;
		try {
			if (!stack->isEmpty())
			{
				stack->pop(*temp);
			}
			cout << "Successfully reversed deletion" << endl;
				
		}
		catch (std::string e)
		{
			cout << e;
		}
		
	}
}; 
