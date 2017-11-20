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
void addObj(HashTable& ht, BST<Book>& bst);
void removeObj(HashTable& ht, BST<Book>& bst);
void searchObj(HashTable &ht);




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
    			//cin.ignore();
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
    				cin.ignore();
    				addObj(ht, bst);
    				break;
    			}
    			case 3:
    			{
    				cin.ignore();
    				removeObj(ht, bst);
    				break;
    			}
    			case 4:
    			{
    				cin.ignore();
    				searchObj(ht);
    				break;
    			}
    			case 5:
    			{
    				bst.inOrderPrint(cout);
    				cout << endl << "Happy Reading!!!" << endl;
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



void addObj(HashTable& ht, BST<Book>& bst)
{

    string title, author, buf;
    double price;
    unsigned isbn;

	cout << "Enter the title: ";
	getline(cin, title);

	cout << "Enter the author: ";
	getline(cin, author);

	cout << "Enter the price: ";
	getline(cin, buf);

	price = stod(buf);
	cout << "Enter the isbn: ";
	getline(cin, buf);

	isbn = stoi(buf);

	Book newBook(title, author, price, isbn);
	ht.insert(newBook);
	bst.insert(newBook);
	cout << title << " has been added to the catalogue" << endl << endl;
}



void removeObj(HashTable& ht, BST<Book>& bst)
{
    string title, author, buf;
	cout << "Enter the title of the book to remove: ";
	getline(cin, title);
	cout << "Enter the author: ";
	getline(cin, author);

	Book bookToBeRemoved(title, author, 1, 1234567);
	ht.remove(bookToBeRemoved);
	bst.remove(bookToBeRemoved);
	cout << title << " has been removed from the catalogue" << endl << endl;
}

void searchObj(HashTable& ht)
{
	string title, author;
	cout << "Enter the title of the book to search: ";
	getline(cin, title);
	cout << "Enter the author: ";
	getline(cin, author);
	Book bookToBeSearchedFor(title, author, 1, 1234567);
	int searchResult = ht.search(bookToBeSearchedFor);
	if (searchResult == -1)
	{
		cout << title << " is not in the catalogue." << endl;
	}
	else cout << title << " is found at group " << searchResult+1 << " (or index " << searchResult << ")"<< endl;
	cout << endl;
}



/*
Welcome to the Best Reads App!

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1
Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Agatha Christie by Murder on the Orient Express
$2.99
ISBN#: 9837583

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789



What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 4
Enter the title of the book to search: a a
Enter the author: b b
a a is not in the catalogue.
Here


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 2
Enter the title: a a
Enter the author: b b
Enter the price: 1
Enter the isbn: 1
a a has been added to the catalogue


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 4
Enter the title of the book to search: a a
Enter the author: b b
a a is found at group 5 (or index 4)
Here


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1
Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Agatha Christie by Murder on the Orient Express
$2.99
ISBN#: 9837583

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789

a a by b b
$1.00
ISBN#: 1



What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 3
Enter the title of the book to remove: a a
Enter the author: b b
a a has been removed from the catalogue


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1
Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Agatha Christie by Murder on the Orient Express
$2.99
ISBN#: 9837583

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789



What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 4
Enter the title of the book to search: a a
Enter the author: b b
a a is not in the catalogue.
Here


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 5

Happy Reading!!!

*/


