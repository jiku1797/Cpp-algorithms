//  Created by Jimmy Kungsman on 2017-03-14.
//  Copyright © 2017 Jimmy Kungsman. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

class btree
{
public:
    btree();
    ~btree();
    
    void insert(int key);
    Node *search(int key);
    void destroy_tree();
    
private:
    void destroy_tree(Node *leaf);
    void insert(int key, Node *leaf);
    Node *search(int key, Node *leaf);
    
    Node *root;
};

btree::btree()
{
    root = NULL;
}

btree::~btree()
{
    destroy_tree();
}

void btree::destroy_tree(Node *leaf)
{
    if(leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key, Node *leaf)
{
    if(key < leaf->value)
    {
        if(leaf->left != NULL)
            insert(key, leaf->left);
        else
        {
            leaf->left = new Node;
            leaf->left->value = key;
            leaf->left->left = NULL;    //Sets the left child of the child node to null
            leaf->left->right = NULL;   //Sets the right child of the child node to null
        }
    }
    else if(key>=leaf->value)
    {
        if(leaf->right!=NULL)
            insert(key, leaf->right);
        else
        {
            leaf->right = new Node;
            leaf->right->value = key;
            leaf->right->left = NULL;  //Sets the left child of the child node to null
            leaf->right->right = NULL; //Sets the right child of the child node to null
        }
    }
}

Node* btree::search(int key, Node *leaf)
{
    if(leaf != NULL)
    {
        if(key == leaf->value)
            return leaf;
        if(key < leaf->value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}

void btree::insert(int key)
{
    if(root != NULL)
        insert(key, root);
    else
    {
        root = new Node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

Node* btree::search(int key)
{
    return search(key, root);
}

void btree::destroy_tree()
{
    destroy_tree(root);
}

int main(){
    btree myBinaryTree = btree();
    
    myBinaryTree.insert(3);
    myBinaryTree.insert(6);
    myBinaryTree.insert(4);
    myBinaryTree.insert(2);
    Node* ptr = myBinaryTree.search(5);
    
    if(ptr == NULL){
        cout << "Not found" << endl;
    }
    else{
        cout << "Found" << endl;
    }
}
