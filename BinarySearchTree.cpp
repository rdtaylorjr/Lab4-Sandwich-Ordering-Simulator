/**
 Lab4
 CSC 240 C++ Data Structures (Summer 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BinarySearchTree.cpp
 @author Russell Taylor
 @date 6/22/20
*/

#include <iostream>
#include <iomanip>
#include "BinarySearchTree.hpp"
using namespace std;

/**
 Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/**
 Copy constructor
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree&) {
}

/**
 Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

/**
 Determines whether the tree is empty
 @return true if the tree is empty, otherwise false
 */
bool BinarySearchTree::isEmpty() const {
    return (root == nullptr);
}

/**
 Inserts a node into the tree
 @param sandwichNum the number of the sandwich to be added to the tree
 @param sandwichName the name of the sandwich to be added to the tree
 */
void BinarySearchTree::insert(int sandwichNum, string sandwichName) {
    int count = 1;
    Node *current = root;
    Node *trailCurrent = root;
    Node *newNode = new Node;
    newNode->data = {sandwichNum, sandwichName, count};
    newNode->left = nullptr;
    newNode->right = nullptr;
    
    if (root == nullptr) {
        root = newNode;
        return;
    }
    
    if (isFound(sandwichNum)) {
        find(sandwichNum)->data.count++;
        return;
    }
    
    while (current != nullptr) {
        trailCurrent = current;
        if (current->data.sandwichNum > sandwichNum)
            current = current->left;
        else
            current = current->right;
    }
    
    if (trailCurrent->data.sandwichNum > sandwichNum)
        trailCurrent->left = newNode;
    else
        trailCurrent->right = newNode;
}

/**
 Finds a node in the tree
 @param sandwichNum the number of the sandwich to be found in the tree
 @return pointer to node if found, or pointer to nullptr if not found
 */
Node* BinarySearchTree::find(int sandwichNum) {
    Node *current = root;
    
    while (current != nullptr) {
        if (current->data.sandwichNum == sandwichNum)
            return current;
        else if (current->data.sandwichNum > sandwichNum)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

/**
 Determines whether a node has been found in the tree
 @param sandwichNum the number of the sandwich to be found in the tree
 @return true if node is in the tree, otherwise  false
 */
bool BinarySearchTree::isFound(int sandwichNum) {
    return find(sandwichNum) != nullptr;
}

/**
 Displays the data in the tree in order from smallest to largest sandwich number
 */
void BinarySearchTree::display() {
    inorder(root);
}

/**
 Decreases counter by one for each sandwich served
 @param sandwichNum the number of the sandwich to be removed from the tree
 @param sandwichName the name of the sandwich to be removed from the tree
 */
void BinarySearchTree::remove(int sandwichNum, string sandwichName) {
    Node *current = root;
    Node *trailCurrent = root;
    bool lastSandwich = false;
    
    if (root == nullptr)
        return;

    while (current != nullptr && !lastSandwich) {
        if (current->data.sandwichNum == sandwichNum) {
            if (current->data.count > 1) {
                current->data.count--;
                return;
            }
            else
                lastSandwich = true;
        }
        else {
            trailCurrent = current;
            if (current->data.sandwichNum > sandwichNum)
                current = current->left;
            else
                current = current->right;
        }
    }
        
    if (current == nullptr) {
        insert(sandwichNum, sandwichName);
        find(sandwichNum)->data.count--;
    }
    else if (lastSandwich) {
        if (current == root)
            deleteNode(root);
        else if (trailCurrent->data.sandwichNum > sandwichNum)
            deleteNode(trailCurrent->left);
        else
            deleteNode(trailCurrent->right);
    }
}

/**
 Recursive helper function for the class destructor
 @param p a pointer to a node in the tree
 */
void BinarySearchTree::destroy(Node* &p) {
    if (p != nullptr) {
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = nullptr;
    }
}

/**
 Recursive helper function to traverse the binary tree inorder
 @param p a pointer to a node in the tree
 */
void BinarySearchTree::inorder(Node* p) const {
    if (root == nullptr)
        cout << "No sandwiches have been ordered" << endl;
    
    else if (p != nullptr) {
        inorder(p->left);
        string sandwich = to_string(p->data.sandwichNum) + " - " + p->data.sandwichName;
        int count = p->data.count;
        
        if (p->data.count == 0)
            cout << sandwich << " has not been ordered" << endl;
        else {
            cout << setw(34) << left << sandwich << count << " order";
            if (p->data.count > 1)
                cout << "s";
            cout << endl;
        }
        inorder(p->right);
    }
}

/**
 Helper function that deletes a node from the tree
 @param p a node to be removed from the tree
 */
void BinarySearchTree::deleteNode(Node* &p) {
    Node *current;
    Node *trailCurrent = nullptr;
    Node *temp = p;

    if (p == nullptr)
        cout << "It is not possible to serve a sandwich that was not ordered" << endl;
    
    else if (p->left == nullptr && p->right == nullptr) {
        p = nullptr;
        delete temp;
    }
    
    else if (p->left == nullptr) {
        p = temp->right;
        delete temp;
    }
   
    else if (p->right == nullptr) {
        p = temp->left;
        delete temp;
    }
   
    else {
        current = p->left;
        trailCurrent = nullptr;

        while (current->right != nullptr) {
            trailCurrent = current;
            current = current->right;
        }

        p->data.sandwichNum = current->data.sandwichNum;
        p->data.sandwichName = current->data.sandwichName;
        p->data.count = current->data.count;

        if (trailCurrent == nullptr)
            p->left = current->left;
        else
            trailCurrent->right = current->left;
 
        delete current;
    }
}
