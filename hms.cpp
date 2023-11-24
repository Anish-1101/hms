//
//  hms.cpp
//
//
//  Created by Anish Reddy Athmakoor
//
#include "hms.h"

using namespace std;
#include <iostream>
#include <string>
#include <limits>

Hotel::Node* Hotel::findReservationByName(const std::string& name) {
    Node* startptr = head;
    Node* endptr = tail;
    while (startptr!= nullptr && endptr != nullptr) {
        if (startptr->name == name) {
            return startptr;
        }
        startptr = startptr->next;
        if (endptr->name == name) {
            return endptr;
        }
        endptr = endptr->prev;
    }
    return nullptr;
}

Hotel::~Hotel() {
    Node*p = head;
    while(p!=nullptr) {
        Node*n = p->next;
        delete p;
        p =n;
    }
}

void Hotel::menu(){
    int choice;
    cout << "Welcome to the Hotel Management System!" << endl;
    cout << "What would you like to do: " << endl;
    cout << "1. Make Reservation" << endl;
    cout << "2. Search Reservation" << endl;
    cout << "3. Delete Reservation" << endl;
    cout << "4. Update Reservation" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    if (choice == 1) {
        insertreservation();
    }
    if (choice == 2) {
        searchbyname();
    }
    if (choice == 3) {
        deletereservation();
    }
    if (choice == 4) {
        updatereservation();
    }
}

void Hotel::insertreservation() {
    Node* reservation = new Node;
    cout << "Enter start of reservation date: ";
    cin >> reservation->start_date;
    cout << "Enter end of reservation date: ";
    cin >> reservation->end_date;
    cout << "Enter name: ";
    cin >> reservation->name;
    do {
        cout << "Enter room type, choose from Single or Double: ";
        cin >> reservation->roomtype;
        if (reservation->roomtype != "Single" && reservation->roomtype != "Double") {
            cout << "Invalid Input. Please enter 'Single' or 'Double'." << endl;
        }
    } while (reservation->roomtype != "Single" && reservation->roomtype != "Double");
    
    cout << "Enter room type, choose from Single or Double: ";
    
    reservation->next = nullptr;
    reservation->prev = tail;
    
    if (head == nullptr) {
        head = reservation;
        tail = reservation;
        reservation-> prev = nullptr;
    }
    else {
        tail->next = reservation;
        tail = reservation;
    }
}


void Hotel::searchbyname(){
    string namesearch;
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, namesearch);
    Node* namenode = findReservationByName(namesearch);
    if (namenode != nullptr) {
        cout << "Reservation found for " << namesearch << endl;
        cout << "Reservation start date is " << namenode->start_date << endl;
        cout << "Reservation end date is " << namenode->end_date << endl;
        cout << "Reservation room type is " << namenode->roomtype << endl;
    }
    else {
        cout << "No reservation found" ;
        return;
    }
}
        

void Hotel::updatereservation() {
    string name;
        int choice;
        cout << "Please enter your name: " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);
        
        cout << "What part of your reservation would you like to update: " << endl;
        cout << "1. Start Date" << endl;
        cout << "2. End Date" << endl;
        cout << "3. Room Type" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
    
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    
    if (choice == 1) {
        string newstartdate;
        cout << "What would you like to change the start date to?" << endl;
        getline(cin,newstartdate);
        Node* namenode = findReservationByName(name);
        if (namenode != nullptr) {
            namenode->start_date = newstartdate;
            cout << "Reservation start date has been updated!" << endl;
            return;
        }
        else {
            cout << "No reservation found" ;
            return;
        }
        
    } else if (choice == 2) {
        string newenddate;
        cout << "What would you like to change the end date to?" << endl;
        getline(cin,newenddate);
        Node* namenode = findReservationByName(name);
        if (namenode != nullptr) {
            namenode->end_date = newenddate;
            cout << "Reservation end date has been updated!" << endl;
            return;
        }
        else {
            cout << "No reservation found" ;
            return;
        }
        
    } else if (choice == 3) {
        string newroomtype;
        cout << "What would you like to change the room type to?" << endl;
        getline(cin,newroomtype);
        Node* namenode = findReservationByName(name);
        if (namenode != nullptr) {
            namenode->roomtype = newroomtype;
            cout << "Reservation room type has been updated!" << endl;
            return;
        }
        else {
            cout << "No reservation found" ;
            return;
        }
    } else {
        cout << "Invalid choice";
    }
}

void Hotel::deletereservation() {
    string name;
    cout << "Enter your name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    Node* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            if (current == head) {
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }
            }
            else if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
            cout << "Reservation for " << name << " has been cancelled." << endl;
            return;
        }
        current = current->next;
    }
    cout << "No reservation found"<< endl;
}
    





