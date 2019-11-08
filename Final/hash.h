#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include"Song.h"
//typedef unsigned char uint32_t;
#define FORCE_INLINE	__forceinline

#define	FORCE_INLINE inline __attribute__((always_inline))

using namespace std;


//calculate the next prime number based on hash table size.

int NextPrime(int a)
{
	int i, j, count, num;
	for (i = a + 1; 1; i++)
	{
		count = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				count++;
				break;
			}
		}
		if (count == 0)
		{
			return i;
		}
	}
}

/**
*Attached from line 13 is another method to accomplish this in case the chaining efficiency method does not bode well with the rest of the code you guys wrote.
*In case the code from line 158 works just delete the comment after line 5 down to where a constant variable of TABLE_SIZE is defined

*/


/**

//template for generic type
template<typename K, typename V>
class HashNode
{
public:
	V value;
	K key;

	//constructor
	HashNode(K key, V value)
	{
		this->value = value;
		this->key = key;
	}
};
template<typename K,typename V>
class HashMap
{
	HashNode<K, V> **arr;
	int capacity;
	//current size
	int size;
	HashNode<K, V> *dummy;

public:
	HashMap()
	{
		capacity = 25;
		size = 0;
		arr = new HashNode<K, V>*[capacity];

		for (int i = 0; i < capacity; i++)
		{
			arr[i] = NULL;
			dummy = new HashNode<K, V>(-1, -1);
		}
	}
		//implement hash function to find index of a certain key
	int hashCode(K key)
	{
			return key % capacity;
	}
	void insertNode(K key, V value)
	{
			HashNode<K, V>*temp = new HashNode<K, V>(key, value);
			int hashIndex = hashCode(key);
			while (arr[hashIndex] !=NULL && arr[hashIndex]->key !=key && arr[hashIndex]->key !=-1)
			{

				hashIndex++;
				hashIndex %= capacity;
			}
			if (arr[hashIndex] == NULL && arr[hashIndex]->key == -1)
			{
				size++
				arr[hashIndex] = temp;

			}
	}
	void deleteNode(int key)
	{
			int hashIndex = hashCode(key);
			while (arr[hashIndex]->key != NULL)
			{
				//if the node is found;
				if (arr[hashIndex]->key==key)
				{
					HashNode<K, V> *temp = arr[hashIndex];
					arr[hashIndex] = dummy;
					//we save the current state of the node temporarily
					int hold = temp->value;
					undoDel(key,hold);
					size--;
					return temp->value;
				}
				hashIndex++;
				hashIndex %= capacity;
			}
			return NULL;
	}

	void undoDel(int hold,V)
	{
		cout << "Are you sure you want to undo Delete (Y/N)?";
		cin >> ch;
		if (ch!='Y')
		{
			HashNode<K, V> *temp = arr[hashIndex];
			arr[hashIndex] = dummy;
			size--;
			return temp->value;
		}
		else
		{
			insertNode(arr[hasIndex]->key, hold)
		}
	}
		//searching function
	V get(int key)
	{
		int hashIndex = hashCode(key);
		int counter = 0;
		while (arr[hashIndex] != NULL)
		{
			inr counter = 0;
			if (counter++ > capacity)
			{
				return NULL;
			}
			if (arr[hashIndex]->key == key)
			{
				return arr[hashIndex]->value;
				hashIndex++;
				hashIndex %= capacity;

			}
			return NULL;
		}
	}
	int sizeofMap()
	{
		return size;
	}
	bool isEmpty()
	{
		return size == 0;
	}
	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i]!=NULL && arr[i]->key !=1)
			{
				cout << "key = " << array[i]->key
					<<" value = "<<arr[i]->value <<endl;
			}
		}
	}

};

**/

const int TABLE_SIZE = 0;

/*
 * Let us declare Hash Node class.
 */

class HashNode
{
private:


public:
	int key;
	int value;
	HashNode* next;

	HashNode(int key, int value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

/*
 * Declaration of Hash Map
 */
class HashMap
{
private:
	HashNode** htable;
public:
	HashMap()
	{
		htable = new HashNode*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			htable[i] = NULL;
	}
	~HashMap()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			HashNode* entry = htable[i];
			while (entry != NULL)
			{
				HashNode* prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
		delete[] htable;
	}
	/*
	 * Hash Function
	 */
	int HashFunc(int key)
	{
		return key % TABLE_SIZE;
	}

	/*
	 * Insert Element
	 */
	void Insert(int key, int value)
	{
		//setting hash_val to the value obtained after running NextPrime function.
		int hash_val = NextPrime(key);
		HashNode* prev = NULL;
		HashNode* entry = htable[hash_val];
		while (entry != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (entry == NULL)
		{
			entry = new HashNode(key, value);
			if (prev == NULL)
			{
				htable[hash_val] = entry;
			}
			else
			{
				prev->next = entry;
			}
		}
		else
		{
			entry->value = value;
		}
	}
	/*
	 * Delete Element
	 */
	void Remove(int key)
	{
		int hash_val = HashFunc(key);
		HashNode* entry = htable[hash_val];
		HashNode* prev = NULL;
		if (entry == NULL || entry->key != key)
		{
			cout << "No Element found at key " << key << endl;
			return;
		}
		while (entry->next != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (prev != NULL)
		{
			prev->next = entry->next;
		}
		delete entry;
		cout << "Element Deleted" << endl;
	}
	/*
	 * Search Element
	 */
	int Search(int key)
	{
		bool flag = false;
		int hash_val = HashFunc(key);
		HashNode* entry = htable[hash_val];
		while (entry != NULL)
		{
			if (entry->key == key)
			{
				cout << entry->value << " ";
				flag = true;
			}
			entry = entry->next;
		}
		if (!flag)
			return -1;
	}
	void display()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (htable[i] != NULL && htable[i]->key != 1)
			{
				cout << "key = " << htable[i]->key
					<< " value = " << htable[i]->value << endl;
			}
		}
	}

	uint32_t jenkins_one_at_a_time_hash(int *key1, size_t length) {
		size_t i = 0;
		uint32_t hash1 = 0;
		while (i != length) {
			hash1 += key1[i++];
			hash1 += hash1 << 10;
			hash1 ^= hash1 >> 6;
		}
		hash1 += hash1 << 3;
		hash1 ^= hash1 >> 11;
		hash1 += hash1 << 15;
		return hash1;
	}
};

//Main Contains Menu please cut and paste in main file.

int main()
{
	HashMap hash;
	int key, *value;
	int choice;
	while (1)
	{
		cout << "\n----------------------" << endl;
		cout << "Operations on Hash Table" << endl;
		cout << "\n----------------------" << endl;
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key" << endl;
		cout << "3.Delete element at a key" << endl;
		cout << "4.Display Hash Table" << endl;
		cout << "5.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> *value;
			cout << "Enter key at which element to be inserted: ";
			cin >> key;
			hash.Insert(key, *value);
			//load factor
			hash.jenkins_one_at_a_time_hash(value, key);
			break;
		case 2:
			cout << "Enter key of the element to be searched: ";
			cin >> key;
			cout << "Element at key " << key << " : ";
			if (hash.Search(key) == -1)
			{
				cout << "No element found at key " << key << endl;
				continue;
			}
			break;
		case 3:
			cout << "Enter key of the element to be deleted: ";
			cin >> key;
			hash.Remove(key);
			break;
		case 4:
			hash.display();
			break;

		case 5:
			exit(1);
		default:
			cout << "\nEnter correct option\n";
		}
	}
	return 0;
}
