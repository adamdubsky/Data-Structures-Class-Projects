//Adam Dubsky
//September 2021
//CS 3610

#include <iostream>
#include "avl_tree.h"
using namespace std;

void AVLTree::insert(const int newValue) {

  bool isTaller = false;
  AVLNode *newNode;
  newNode = new AVLNode(newValue);
  insertIntoAVL(root,newNode,isTaller);
  
}

void AVLTree::insertIntoAVL(AVLNode* &root, AVLNode *newNode, bool& isTaller){
  if (root == NULL){
    root = newNode;
    isTaller = true;
  }
  else if (root->value == newNode->value){
    cout << "Duplicate" << endl;
  }
  else if (root->value > newNode->value){

    insertIntoAVL(root->left, newNode,isTaller);

    if (isTaller){
      switch (root->bf)
	{
	case -1:
	  balanceFromLeft(root);
	  isTaller = false;
	  break;

	case 0:
	  root->bf = -1;
	  isTaller = true;
	  break;

	case 1:
	  root->bf = 0;
	  isTaller = false;
	}
    }
  }
  else{

    insertIntoAVL(root->right, newNode, isTaller);

    if(isTaller){
      switch(root->bf)
	{
	case -1:
	  root->bf = 0;
	  isTaller = false;
	  break;
	  
	case 0:
	  root->bf = 1;
	  isTaller = true;
	  break;
	  
	case 1:
	  balanceFromRight(root);
	  isTaller = false;
	}
    }
  }
}

void AVLTree::rotateToLeft(AVLNode* &root){
  AVLNode *p;
  
  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->right == NULL)
    cout << "Error in the tree: No right subtree to rotate." << endl;
  else{
    p = root->right;
    root->right = p->left;
    p->left = root;
    root = p; 
  }
}

void AVLTree::rotateToRight(AVLNode* &root){
  AVLNode *p;

  if (root == NULL)
    cout << "Error in the tree" << endl;
  else if (root->left == NULL)
    cout << "Error in the tree: No left subtree to rotate." << endl;
  else{
    p = root->left;
    root->left = p->right; 
    p->right = root;
    root = p; 
  }
}

void AVLTree::balanceFromLeft(AVLNode* &root){

  AVLNode *p;
  AVLNode *w;

  p = root->left;

  switch (p->bf)
    {
    case -1:
      root->bf = 0;
      p->bf = 0;
      rotateToRight(root);
      break;

    case 0:  // You need to handle this case; possible in AVL deletion
      root -> bf = 1;
      p -> bf = -1;
      rotateToRight(root);
      break; 

    case 1:
      w = p->right;

      switch (w->bf)
	{
	case -1:
	  root->bf = 1;
	  p->bf = 0;
	  break;
	case 0:
	  root->bf = 0;
	  p->bf = 0;
	  break;
	case 1:
	  root->bf = 0;
	  p->bf = -1;
	}
      
      w->bf = 0;
      rotateToLeft(p);
      root->left = p;
      rotateToRight(root);
    }
}


void AVLTree::balanceFromRight(AVLNode* &root){
  AVLNode *p;
  AVLNode *w;

  
  p = root->right;
  switch (p->bf)
    {
    case -1:
      
      w = p->left;
      switch (w->bf)
	{
	case -1:
	  root->bf = 0;
	  p->bf = 1;
	  break;
	case 0:
	  root->bf = 0;
	  p->bf = 0;
	  break;
	case 1:
	  root->bf = -1;
	  p->bf = 0;
	}
      
      w->bf = 0;
      rotateToRight(p);
      root->right = p;
      rotateToLeft(root);
      break;

    case 0:  // You need to handle this case; possible in AVL deletion
      //same as Balance from left case, just different values
      root -> bf = 0;
      p -> bf = 0;
      rotateToLeft(root);
      break;
      
      
      break;

    case 1:
      root->bf = 0;
      p->bf = 0;
      rotateToLeft(root);
    }
}


void AVLTree::print(char letter){

  //check user input
  if (letter == 'p')
  {
    ordered_nodes(root);
    cout << endl;
  }

  //check user input
  if (letter == 'h')
  {
    ordered_height(root);
    cout << endl;
  }

  
}

//function used to output all the node values in the correct order
//Used in print() funciton
void AVLTree::ordered_nodes(AVLNode* &root){
  //check for NULL
  if (root != NULL)
  {
    ordered_nodes(root -> left);
    cout << root -> value << ' ';
    ordered_nodes(root -> right);
    //ends once root is NULL
  }
  
}


int AVLTree::height(AVLNode* &root){
  //temp variables
  int HEIGHT = 0;
  int right_height = 0;
  int left_height = 0;
  int max_height = 0;;

  if (root != NULL)
  {
    //find heights on each side
    right_height = height(root -> right);
    left_height = height(root -> left);
    //use max function to grab higher
    max_height = max(right_height, left_height);

    //add 1
    HEIGHT = max_height + 1;

  }
  return HEIGHT;
  

}

//function used to print the height for binary tree sections in correct order

void AVLTree::ordered_height(AVLNode* &root){
  //check for NULL
  if (root != NULL)
  {
    ordered_height(root -> left);
    cout << height(root) << ' ';
    ordered_height(root -> right);
    //ends once null
  }
  
}

//theory reference https://www.techiedelight.com/find-inorder-predecessor-given-key-bst/
//page 652 book reference
AVLNode* AVLTree::getPred(AVLNode* node){
  //check for null
  if (node == NULL)
  {
    return NULL;
  }
  else
  {
    node = node -> left;
    while (node -> right != NULL)
    {
      node = node -> right;
    }
    return(node);
  }

}

void AVLTree::remove(int badValue){
  bool isShorter = false;
  remove(root,badValue, isShorter);
}

//Possible cases
//Right subtree
//left subtree
//no children
//left child only
//right child only
//2 children

  //isShorter must be updated after every change
//reference https://www.geeksforgeeks.org/deletion-binary-tree/
void AVLTree::remove(AVLNode* &root, int badValue, bool& isShorter){

  //Check root to make sure that is not null
  if (root == NULL)
  {
    cout << "Error, Root is NULL " << endl;
    return;
  }

 

  //isShorter must be updated after every change

  //checkings right side of subtree
  else if (badValue > root -> value)
  {
    remove (root -> right, badValue, isShorter);
    if (isShorter)
    {
      switch (root -> bf)
      {
      case -1:
        
        //check for 0
        if (root -> left -> bf == 0)
        {
          isShorter = false;
        }
        else{
          isShorter = true;
        }
        balanceFromLeft(root);
        break;

      case 0:
          root -> bf = -1;
          isShorter = false;
          break;

          //only case where isShorter = true for right tree
      case 1:
          root -> bf = -1;
          isShorter = true;
          break;
      
      }
    }
    
  }
  //check the left subtree
  else if (badValue < root -> value)
  {
    switch(root -> bf)
    {
      case -1:

        root -> bf = 0;
        isShorter = true;
        break;

      case 0:

        root -> bf = 1;
        isShorter = false;
        break;

      case 1:

        if (root -> right -> bf == 0)
        {
          isShorter = false;
          
        }
        else{
          isShorter = true;
        }
        balanceFromRight(root);

    }
    }
  
  else
      //left only
      if (root -> right == NULL)
      {
        root = root -> left;
        isShorter = true;
        return;
      }

      //right only
      else if (root -> left == NULL)
      {
        root = root -> right;
        isShorter = true;
        return;
      }

      //no children
      else if (root->left == NULL && root->right == NULL)
      {
        root = NULL;
        isShorter = true;
        return;
      }
      //page 652 of book
      //two children
      else
      {
        root -> value = getPred(root) -> value;
        remove(root -> left, root -> value, isShorter);
        root -> bf = height(root -> right) - height(root -> left);

        //check value to determine if balance right or left
        // balance > 1 = right, balance < -1 = left
        if (root -> bf > 1)
        {
          balanceFromRight(root);
        }

        else if (root -> bf < -1)
        {
          balanceFromLeft(root);
        }
        
        


        
      }
      
      
    
  }

