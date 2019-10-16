#include<iostream>

#include "Database.h"

using namespace std;

// Constructor to initiate LinkedList starting point
Database ::Database()
{
    length = 0;  // Initiats length
    listData = NULL;  // Sets the start point to NULL as the list is empty
}

// Inserts a new node at the begining of the list, with the user inputed data.
void Database ::PutItem(int quantity, string itemName)
{
    
    string first; 
    string last;
    string name;
    string input;
    long userId;
    
    Node* location = new Node;
    location->item.setQuantity(quantity);
    location->item.setItemName(itemName);
    
    
    cout << "Please enter your first name: "; 
    cin >> first;
    
    cout << "Please enter your last name: "; 
    cin >> last;
    
    name = first + " " + last;
    
    location->item.setUserName(name);
    
    cout << "Please enter you phone number: "; 
    cin >> input;
    location->item.setPhoneNum(input);
    
    cout << "Please enter you User_Id: "; 
    cin >> userId;
    location->item.setUserId(userId);
    
    location->next = listData;
    listData = location;
    length++;
}

// Get list length function. Simply return the counter.
int Database ::GetLength() const {
    return length;
}

// Destructor
Database ::~Database(){
    Node* tempPtr;
    
    while(listData != NULL){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

// Created it for testing purposes
void Database ::display()
{
    cout << endl;
    
    Node* temp = new Node;
    temp = listData;
    while(temp != NULL) {
        cout << temp->item.getQuantity() << endl;
        cout << temp->item.getItemName() << endl;
        cout << temp->item.getUserName() << endl;
        cout << temp->item.getPhoneNum() << endl;
        
        temp = temp->next;
    }
}

string Database :: pass(){
    return defaultPass;
}

void Database::searchByName(string productName)
{
    Node* currentptr;
    currentptr = listData;
    while(currentptr != NULL){
        if(currentptr->item.getItemName() == productName){
            currentptr->item.printDescription();
            return;
        }
        currentptr = currentptr->next;
    }
    cout << "Product not found" << endl;
}

void Database::searchById(long productId)
{
    Node* currentptr;
    currentptr = listData;
    while(currentptr != NULL){
        if(currentptr->item.getItemId() == productId){
            currentptr->item.printDescription();
            return;
        }
        currentptr = currentptr->next;
    }
    cout << "Product not found" << endl;
}