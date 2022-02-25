// Binary Tree Execution File

#include <iostream>
#include "NodeType.h"
#include "BinaryTree.h"

using namespace std;

/**
 * Constructor
 */
BinaryTree::BinaryTree(){
  root = NULL;
}// Constructor

/**
 * Destructor
 */

BinaryTree::~BinaryTree(){
  destroy(root);  
}//Destructor

/**
 * Insert
 */

void BinaryTree::insert(T key){
  bool found = false;
  retrieve(key, found);
  if(found == false){
    putItem(root, key);
  }//if
  else{
    cout << "Item already in tree." << endl;
  }//else
}//insert

/**
 * Delete
 */

void BinaryTree::deleteItem(T key){
  bool found = false;
  retrieve(key, found);
  if(found == true){
    deleteRec(root, key);
  }//if
  else{
    cout << "Item not in tree" << endl;
  }//else  

}//deleteItem

/**
 * Retrieve
 */

void BinaryTree::retrieve(T &item, bool &found) const{
  //  cout << "retrieve" << endl;
  getItem(root, item, found);

}//retrieve

/**
 * pre-order
 */

void BinaryTree::preOrder() const{
  //  cout << "preOrder" << endl;
  printPreOrder(root);
}//preOrder

/**
 * inOrder
 */

void BinaryTree::inOrder() const{
  //  cout << "inOrder" << endl;
  printInOrder(root);
}//inOrder

/**
 * postOrder
 */

void BinaryTree::postOrder() const{
  //  cout << "postOrder" << endl;
  printPostOrder(root);
}//postOrder

/**
 * getLength
 */

int BinaryTree::getLength() const{
  return countNodes(root);
}//getLength

/**
 * CountNodes
 */

int BinaryTree::countNodes(NodeType *tree) const{
  if(tree == NULL){
    return 0;
  }//if
  else{
    return countNodes(tree->left) + countNodes(tree->right) + 1;
  }//else
}//countNodes

/**
 * getItem
 */
void BinaryTree::getItem(NodeType *tree, T &item, bool &found) const{
  if(tree == NULL){
    found = false;
  }//if
  else{
    if(item.compareTo(tree->info) == LESS){
      getItem(tree->left, item, found);
    }//if
    else{
      if(item.compareTo(tree->info) == GREATER){
	getItem(tree->right, item, found);
      }//if
      else{
	item = tree->key;
	found = true;
      }//else
    }//else
  }//else
}//getItem


/**
 * putitem
 */

void BinaryTree::putItem(NodeType *&tree, T item){

  if(tree == NULL){
    tree = new NodeType;
    tree->right = NULL;
    tree->left = NULL;
    tree->key = item;
    }//if
  else{
    if(item.compareTo(tree->info) == LESS){
      putItem(tree->left, item);
    }//if
    else{
      putItem(tree->right, item);
    }//else
  }//else
}//putItem

/**
 * Delete
 */

void BinaryTree::deleteRec(NodeType*& tree, T item){
  if(item.compareTo(tree->key) == LESS){
    deleteRec(tree->left, item);
  }//if
  else{
    if(item.compareTo(tree->key) == GREATER){
      deleteRec(tree->right, item);
    }//if
    else{
      deleteNode(tree);
    }//else
  }//else
}// delete

/**
 * delete Node
 */

void BinaryTree::deleteNode(NodeType*& tree){
  T data;
  NodeType *tempPtr;

  tempPtr = tree;
  if(tree->left == NULL){
    tree = tree->right;
    delete tempPtr;
  }//if
  else{
    if(tree->right == NULL){
      tree = tree->left;
      delete tempPtr;
    }//if
    else{
      getPredecessor(tree->left, data);
      tree->key = data;
      deleteRec(tree->left, data);
    }//else
  }//else
}//deleteNode

/**
 * getPredecessor
 */

void BinaryTree::getPredecessor(NodeType* tree, T &data){
  while (tree->right != NULL){
    tree = tree->right;
  }//while
  data = tree->key;
}//getPredecessor

/**
 * printInOrder
 */

void BinaryTree::printInOrder(NodeType * tree) const{
  if(tree != NULL){
    printInOrder(tree->left);
    tree->key.print();
    printInOrder(tree->right);
  }//if
}//printInOrder

/**
 * printPreOrder
 */

void BinaryTree::printPreOrder(NodeType * tree) const{
  if(tree != NULL){
    tree->key.print();
    printPreOrder(tree->left);
    printPreOrder(tree->right);
  }//if
}//printPreOrder

/**
 * printPostOrder
 */

void BinaryTree::printPostOrder(NodeType * tree) const{
  if(tree != NULL){
    printPostOrder(tree->left);
    printPostOrder(tree->right);
    tree->key.print();
  }//if
}//printPostOrder

/**
 * destroy
 */

void BinaryTree::destroy(NodeType*& tree){
  if(tree != NULL){
    destroy(tree->left);
    destroy(tree->right);
    delete tree;
  }//if
}//destroy
template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;
