#include "Database.h"
#include <fstream>
#include <iostream>

using namespace std;

// Constructor to initiate LinkedList starting point
Database ::Database()
{
    length = 0;      // Initiated length
    listData = NULL; // Sets the start point to NULL as the list is empty
}

// Inserts a new node at the beginning of the list, with the user imputed data.
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
    location->item.setItemId(idCounter);

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
    
    cout << "\nYour request ID is: " << idCounter << endl;
    
    length++;
    idCounter++;
}

// Get list length function. Simply return the counter.
int Database ::GetLength() const
{
    return length;
}

// Destructor
Database ::~Database()
{
    Node* tempPtr;

    while(listData != NULL) {
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

string Database ::pass()
{
    return defaultPass;
}

void Database::searchByName(string productName)
{
    Node* currentptr;
    currentptr = listData;
    while(currentptr != NULL) {
        if(currentptr->item.getItemName() == productName) {
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
    while(currentptr != NULL) {
        if(currentptr->item.getItemId() == productId) {
            currentptr->item.printDescription();
            return;
        }
        currentptr = currentptr->next;
    }
    cout << "Product not found" << endl;
}

void Database::printFile()
{

    // Create file to read too
    ofstream outFile;
    outFile.open("C:\\Users\\vrola\\OneDrive\\Documents\\CPPWorkspace\\SummerClass\\Project\\printOut.out");

    // Writes the following information to file
    outFile << "---- Database Data ----" << endl << endl;

    Node* temp = new Node;
    temp = listData;

    while(temp != NULL) {
        outFile << temp->item.getItemName() << endl;
        outFile << temp->item.getQuantity() << endl;
        outFile << temp->item.getItemId() << endl;
        outFile << temp->item.getStateReq() << endl;

        outFile << temp->item.getUserName() << endl;
        outFile << temp->item.getPhoneNum() << endl << endl;

        temp = temp->next;
    }

    cout << "File has been created!" << endl;
    outFile.close();
}

void Database::Modify(long id)
{
    char answer;
    string name;
    string state;
    int quant;

    Node* currentptr;
    currentptr = listData;

    while(currentptr != NULL) {
        if(currentptr->item.getItemId() == id) {
            currentptr->item.printDescription();

            cout << endl;

            cout << "What would you like to modify?" << endl << endl;
            cout << "1. Name" << endl;
            cout << "2. Quantity" << endl;
            cout << "3. State" << endl;
            cout << "Enter: ";
            cin >> answer;

            if(answer == '1') {
                cout << "Enter new name: ";
                getline(cin, name);
                currentptr->item.setItemName(name);

            } else if(answer == '2') {
                cout << "Enter new Quantity: ";
                cin >> quant;
                currentptr->item.setQuantity(quant);

            } else if(answer == '3') {
                cout << "Enter new state [approve/deny]: ";
                cin >> state;
                currentptr->item.setStateReq(state);
            }

            cout << "Item modified" << endl;

            return;
        }
        currentptr = currentptr->next;
    }
    cout << "Product not found" << endl;
}

void Database ::deleteReq(long id)
{

    Node* current;
    // Node* first;
    Node* next;

    current = listData;

    next = current->next;

    while(current->item.getItemId() == id) {
        delete current;
        current = next;
        next = current->next;
    }

    // first = current;

    while(next != NULL) // This should be enough
    {
        if(current->item.getItemId() == id) {

            current->next = next->next;
            delete next;

            next = current->next;
        } else {
            current = next;
            next = next->next;
        }
    }
    
     length--;
}
