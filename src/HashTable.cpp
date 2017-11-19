/*
 * HashTable.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: KVTran, Tri Doan
 */
# include "HashTable.h"





/************* Access Functions *************/
int HashTable::hash(string key) const
{
	int sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    return sum % SIZE;  //dividing the summed ASCII values by 35 && storing remainder as my index
}

int HashTable::countBucket(int index) const
{
	assert(0 <= index && index < SIZE);
	return Table[index].getSize();
}

int HashTable::search(Book b) const
{
	string key = b.get_title() + b.get_author();
	int index = hash(key);

	if (Table[index].isEmpty()) return -1;
	else if (!Table[index].search(b)) return -1;
	else return index;
}





/************* Manipulation Procedures *************/

void HashTable::insert(Book b)
{
	string key = b.get_title() + b.get_author();
	int index = hash(key);
	Table[index].insert(b);
}

void HashTable::remove(Book b)
{
//removes b from the table
//calls the hash function on the key to determine
//the correct bucketƒ
//pre: b is in the table
	int index = search(b);
	assert(index != -1);   // if b is not in the table, search(b) return -1
	Table[index].remove(b);
}





/************* Additional Functions *************/
void HashTable::printBucket(ostream& out, int index) const
{
	assert(0 <= index && index <= SIZE);
	Table[index].inOrderPrint(cout);
}


void HashTable::printTable(ostream& out) const
{
	out << "Books in the Catalogue:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (!Table[i].isEmpty())
		{
			out << "Group " << i+1 << endl;
			out << Table[i].getRoot() << endl;
			out << "+" << countBucket(i) - 1 <<" more similar book(s)" << endl << endl << endl;
			//cout << "+" << Table.countBucket(i) - 1 <<" more similar book(s)" << endl << endl << endl;
		}
	}
}
