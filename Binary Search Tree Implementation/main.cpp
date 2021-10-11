#include <iostream>
#include "avl_tree.h"
using namespace std;

void MENU();
int main(int argc, char** argv) {

  AVLTree tree;

  char option;
  int key;

  do {
    MENU();
    cin >> option;
    switch(option) {
      case 'i':
        cin >> key;
        tree.insert(key);
        break;
      case 'r':
        cin >> key;
        tree.remove(key);
        break;
      case 'h':
         tree.print('h');
        break;
      case 'p':
         tree.print('p');
        break;
      default:
        break;
    }
  } while(option != 'q');
}

//Menu Function to show user their options
void MENU(){
  cout << "Please choose an option" << endl;
  cout << " i k: Insert node with key value k into tree " << endl;
  cout << "r k: Remove Node with key value K from tree " << endl;
  cout << "h: pring the height of each node " << endl;
  cout << "p: print the key value of each node" << endl;
  cout << "q: quit the program" << endl;
  cout << endl;
}