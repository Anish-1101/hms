// hms.h
// Header file for the Hotel Management System


#ifndef HMS_H
#define HMS_H

#include <string>
class Hotel {
private:
    struct Node {
        std::string start_date, end_date, name, roomtype;
        Node *next;
        Node *prev;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* findReservationByName(const std::string& name);
    
public:
    ~Hotel();
    void menu();
    void insertreservation();
    void searchbyname();
    void updatereservation();
    void deletereservation();
};

#endif /* HMS_H */
