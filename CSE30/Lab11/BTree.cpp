#include <iostream>
#include "BTree.h"
using namespace std;

BTree::BTree(){
  root = NULL;
}

BTree::~BTree(){
  destroy_tree();
}

Node* BTree::BTree_root(){
  return root;
}

void BTree::destroy_tree(Node *leaf){
  //check the leaf first
  if (leaf != NULL){
    //destroy its left child
    destroy_tree(leaf->left);
    //destroy its right child
    destroy_tree(leaf->right);
    //delete leaf
    delete leaf;
  }
}

void BTree::insert(int key, Node *leaf){
  //if the key is less than value of leaf
  if (key < leaf->key_value){
    //if left child of leaf is NULL
    if (leaf->left == NULL){
      //create a new node
      leaf->left = new Node;
      //inserting
      leaf->left->key_value = key;
      //initialize child nodes of leaf->left
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }else{ //if left child of leaf is not NULL
      insert(key, leaf->left);
    }
  }else{
    if (leaf->right == NULL){
      //create a new node
      leaf->right = new Node;
      //inserting
      leaf->right->key_value = key;
      //initialize child nodes of leaf->right
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }else{
      insert(key, leaf->right);
    }
  }
}
      
void BTree::insert(int key){
  //if the tree is empty
  if(root == NULL){
    //create a new node
    root = new Node;
    //store key value into the new node
    root->key_value = key;
    //initialize left and right children node of root
    root->left = NULL;
    root->right = NULL;
  }else{ //if there is an existed node in the tree
    insert(key, root);
  }
}

Node* BTree::search(int key, Node *leaf){
  //if leaf is NULL
  if (leaf == NULL){
    return NULL;
  }else if (key == leaf->key_value){ //if leaf stores key value
    return leaf;
  }else if (key < leaf->key_value){ //search left child
    return search(key, leaf->left);
  }else{ //search right child
    return search(key, leaf->right);
  }
}

Node* BTree::search(int key){
  search(key, root);
}

void BTree::destroy_tree(){
  destroy_tree(root);
}
