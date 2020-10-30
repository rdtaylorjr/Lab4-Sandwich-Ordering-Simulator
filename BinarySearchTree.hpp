/**
 Lab4
 CSC 240 C++ Data Structures (Summer 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BinarySearchTree.hpp
 @author Russell Taylor
 @date 6/22/20
*/

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <iostream>

struct Sandwich {
    int sandwichNum;
    std::string sandwichName;
    int count;
};

typedef Sandwich Element;
struct Node {
    Element data;
    Node* left;
    Node* right;
};

class BinarySearchTree {
public:
    /**
     Default constructor
     */
    BinarySearchTree();
    
    /**
     Copy constructor
     */
    BinarySearchTree(const BinarySearchTree&);
    
    /**
     Destructor
     */
    ~BinarySearchTree();
    
    /**
     Determines whether the tree is empty
     @return true if the tree is empty, otherwise false
     */
    bool isEmpty() const;
    
    /**
     Inserts a node into the tree
     @param sandwichNum the number of the sandwich to be added to the tree
     @param sandwichName the name of the sandwich to be added to the tree
     */
    void insert(int, std::string);
    
    /**
     Finds a node in the tree
     @param sandwichNum the number of the sandwich to be found in the tree
     @return pointer to node if found, or pointer to nullptr if not found
     */
    Node* find(int);
    
    /**
     Determines whether a node has been found in the tree
     @param sandwichNum the number of the sandwich to be found in the tree
     @return true if node is in the tree, otherwise  false
     */
    bool isFound(int);
    
    /**
     Displays the data in the tree in order from smallest to largest sandwich number
     */
    void display();
    
    /**
     Decreases counter by one for each sandwich served
     @param sandwichNum the number of the sandwich to be removed from the tree
     @param sandwichName the name of the sandwich to be removed from the tree
     */
    void remove(int, std::string);
    
private:
    Node *root;
    
    /**
     Recursive helper function for the class destructor
     @param p a pointer to a node in the tree
     */
    void destroy(Node*&);
    
    /**
     Recursive helper function to traverse the binary tree inorder
     @param p a pointer to a node in the tree
     */
    void inorder(Node*) const;
    
    /**
     Helper function that deletes a node from the tree
     @param p a node to be removed from the tree
     */
    void deleteNode(Node*&);
};

#endif /* BinarySearchTree_hpp */
