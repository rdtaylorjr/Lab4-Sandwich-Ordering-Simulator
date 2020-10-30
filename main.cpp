/**
 Lab4
 CSC 240 C++ Data Structures (Summer 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file main.cpp
 @author Russell Taylor
 @date 6/22/20
 
 Assignment: Binary Search Tree
 "Assume that you are manager in Panera restaurant. Your restaurant offers some number of sandwiches.
 You want to keep track of what is ordered and is served yet. So you need to count the frequencies of
 sandwiches that are ordered and what is served. For simplicity, consider that your restaurant offers 10
 different sandwiches.
 
 Write a program that allow to increase counter of sandwich by one for each sandwich that is ordered and
 reduce counter for the sandwich that is already served."
 
 @pre Any number of integers from 1–10 input by user, representing sandwich numbers ordered and sandwich numbers served
 @post Ordered sandwich numbers and names are stored in a binary tree along with a count of how many of each sandwich is ordered. When a sandwich is served, the count is reduced by 1.
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include "BinarySearchTree.hpp"
using namespace std;

int main() {
    // Declare variables
    BinarySearchTree sandwich;
    int sandwichNum;
    string menu[] = {"", "Cuban", "Heritage Ham & Swiss", "Steak & Arugula", "Modern Caprese", "Steak & White Cheddar Panini", "BBQ Chicken Flatbread", "The Italian", "Frontega Chicken Panini", "BBQ Chicken Flatbread", "Bacon Turkey Bravo"};
    
    // Ask user to input sandiches ordered, then store data in binary tree
    cout << "Enter sandwiches ordered (then \"done\"):" << endl;
    while (cin >> sandwichNum && cin) {
        if (sandwichNum < 1 || sandwichNum > 10)
            cout << "Invalid Sandwich Number " << sandwichNum << endl;
        else
            sandwich.insert(sandwichNum, menu[sandwichNum]);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Display contents of binary tree
    cout << "\nSandwiches ordered but not yet served:" << endl;
    sandwich.display();
    cout << endl;
    
    // Ask user to input sandwiches served, then remove from binary tree
    cout << "Enter sandwiches served (then \"done\"):" << endl;
    while (cin >> sandwichNum && cin) {
        if (sandwichNum < 1 || sandwichNum > 10)
            cout << "Invalid Sandwich Number" << endl;
        else
            sandwich.remove(sandwichNum, menu[sandwichNum]);
    }
    
    // Display contents of binary tree
    cout << "\nSandwiches ordered but not yet served:" << endl;
    sandwich.display();
    cout << endl;
    
    return 0;
}







//    int orders = 2;
    
//    cout << "Currently ordered and not served yet:" << endl;
////    string menu[10] = {"1 - Cuban", "2 - Heritage Ham & Swiss", "3 – Steak & Arugula", "4 – Modern Caprese", "5 – Steak & White Cheddar Panini", "6 – BBQ Chicken Flatbread", "7 – The Italian", "8 – Frontega Chicken Panini", "9 – BBQ Chicken Flatbread", "10 – Bacon Turkey Bravo"};
//    for (int i = 0; i < 10; i++) {
//        if (orders == 0)
//            cout << menu[i] << " has not been ordered" << endl;
//        else if (orders == 1)
//            cout << setw(34) << left << menu[i] << orders << " order" << endl;
//        else
//            cout << setw(34) << left << menu[i] << orders << " orders" << endl;
//    }
