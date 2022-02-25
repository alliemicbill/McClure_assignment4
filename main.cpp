//main file

#include <fstream>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

char charSelect;
int data;

int main(int argc, char *argv[]){
  
  BinaryTree tree;
  int item; //figure out how to replace this
  int input;
  std::fstream fs;
  char choice;
  
  fs.open(argv[1], std::fstream::in);
  if(fs.is_open()){
    fs >> input;
    while(!fs.eof()){
      item.initialize(input);
      tree.insert(item);
      fs >> input;
    }//while
    
  }//if
  else{
    std::cout << "Failed to open the input file" << std::endl;
    return 0;
  }//else
  
  cout << "Commands: " << endl;
  cout << endl;
  cout << "insert (i), ";
  cout << "delete (d), ";
  cout << "retrieve (r), ";
  cout << "length (l), ";
  cout << "in-order (n)" << endl;
  cout << "pre-order (p), ";
  cout << "post-order (o), ";
  cout << "quit (q)";
  cout << endl;
  
  do{
    cout << endl;
    cout << "Enter a Command: ";
    cin  >> choice;
    switch(choice){

    case 'I':
    case 'i':
      {
	cout << "Item to Insert: ";
	cin >> data;
	item.initialize(data);
	tree.insert(item);
	cout << "In-Order: ";
	tree.inOrder();
	cout << endl;
	break;
      }

    case 'D':
    case 'd':
      {
	cout << "Item to Delete: ";
	cin >> data;
	item.initialize(data);
	tree.deleteItem(item);
	cout << "In-Order: ";
	tree.inOrder();
	cout << endl;
	break;
      }

    case 'R':
    case 'r':
      {
	bool found = false;
	cout << "Item to be retrieved: ";
	cin >> data;
	item.initialize(data);
	tree.retrieve(item, found);
	if(found == true){
	  cout << "Item found in tree" << endl;
	}//if
	else{
	  cout << "Item not in tree" << endl;
	}//else
	cout << endl;
	break;
      }

    case 'L':
    case 'l':
      {
	cout << "List Length: " << tree.getLength() << endl;
	break;
      }

    case 'N':
    case 'n':
      {
	cout << "In-Order: ";
	tree.inOrder();
	cout << endl;
	break;
      }

    case 'P':
    case 'p':
      {
	cout << "Pre-Order: ";
	tree.preOrder();
	cout << endl;
	break;
      }

    case 'O':
    case 'o':
      {
	cout << "Post-Order: ";
	tree.postOrder();
	cout << endl;
	break;
      }

    case 'Q':
    case 'q':
      {
	cout << "Quitting Program ... " << endl;
	break;
      }

    default:
      {
	cout << "Invalid Selection. Please try again." << endl;
      }//default

    }//switch
  }while(!((choice == 'Q') || (choice == 'q')));
  
  return EXIT_SUCCESS;
  
}// main
