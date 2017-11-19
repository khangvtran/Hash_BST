//============================================================================
// Name        : Hash_BST.cpp
// Author      : Khang Vinh Tran, Tri Doan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

# include <iostream>
# include <fstream>
using namespace std;

# include "HashTable.h"

void readAndStore(ifstream& fin, HashTable& ht, BST<Book>& bst);
void promptUser();

int main(){

    HashTable ht;
    BST<Book> bst;
//rest of code

    // check file opening
    ifstream fin;
    fin.open("Catalogue.txt");
    if (fin.fail())
    {
    		cout << "Fail to open input file" << endl;
    		exit(-1);
    }

    // read in the txt file and store the result into ht and bst
    readAndStore(fin, ht, bst);

    //bst.inOrderPrint(cout);
    //ht.printTable(cout);

    // user interactive
    int userInput = 0;
    string buf;
    	cout << "Welcome to the Best Reads App!" << endl;
    do
    {
    		promptUser();
    		cin >> userInput;
    		if (cin.fail())
    		{
    		    cin.clear();
    		    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    			cout << endl << "Please enter numbers not letters" << endl;
    		}
    		else if (userInput < 1 || userInput > 5)
    		{
    			cout << endl << "Invalid input" << endl;
    		}

    		else
    		{
    			switch(userInput)
    			{
    			case 1:
    			{
    				cout << "Here is an alphabetical list of the books in our catalogue:" << endl << endl;
    				bst.inOrderPrint(cout);
    				break;
    			}
    			case 2:
    			{
    				break;
    			}
    			case 3:
    			{
    				break;
    			}
    			case 4:
    			{
    				break;
    			}
    			case 5:
    			{
    				cout << endl << "Happy Reading" << endl;
    				break;
    			}
    			}
    		}



    } while (userInput != 5);


    	// close the file
    fin.close();
    return 0;
}





void readAndStore(ifstream& fin, HashTable& ht, BST<Book>& bst)
{
    string title, author, buf;
    double price;
    unsigned isbn;
    while (getline(fin, title))
    {
    		getline(fin, author);
    		getline(fin, buf);
    		price = stod(buf);
    		getline(fin, buf);
    		isbn = stoi(buf);
    		getline(fin, buf); // read in blank space;
    		Book book(title, author, price, isbn);
    		ht.insert(book);
    		bst.insert(book);
    }

}

void promptUser()
{
	cout << endl;
	cout << "What would you like to do?" << endl;
	cout << "1. Browse catalogue by title" << endl;
	cout << "2. Insert a new book" << endl;
	cout << "3. Remove a book" << endl;
	cout << "4. Search for a book" << endl;
	cout << "5. Quit" << endl;
	cout << endl;
	cout << "Enter your choice: ";
}

