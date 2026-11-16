#include <iostream>
#include <string>
using namespace std;
struct Node
{
     string name;
     int trainNo;
     int seatNo;
     Node *prev;
     Node *next;
};
Node *head = NULL;
// Add passenger
void reserveSeat()
{
     Node *newNode = new Node;
     cout << "Enter passenger name: ";
     cin >> newNode->name;
     cout << "Enter train number: ";
     cin >> newNode->trainNo;
     cout << "Enter seat number: ";
     cin >> newNode->seatNo;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL)
    {
           head = newNode;
    }
    else
    {
           Node *temp = head;
           while (temp->next != NULL)
           {
               temp = temp->next;
           }
           temp->next = newNode;
           newNode->prev = temp;
    }
    cout << "Seat reserved successfully.\n";
}
// Display reservations
void display()
{
    if (head == NULL)
    {
           cout << "No reservations found.\n";
        return;
    }
    Node *temp = head;
    cout << "\n--- TRAIN RESERVATIONS ---\n";
    while (temp != NULL)
    {
        cout << "Passenger: " << temp->name << endl;
        cout << "Train No: " << temp->trainNo << endl;
        cout << "Seat No: " << temp->seatNo << endl;
        cout << "-------------------\n";
        temp = temp->next;
    }
}
// Cancel reservation
void cancelReservation()
{
    if (head == NULL)
    {
        cout << "No reservations found.\n";
        return;
    }
    int seat;
    cout << "Enter seat number to cancel: ";
    cin >> seat;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->seatNo == seat)
        {
             if (temp->prev != NULL)
                    temp->prev->next = temp->next;
             else
                    head = temp->next;
             if (temp->next != NULL)
                    temp->next->prev = temp->prev;
             delete temp;
             cout << "Reservation cancelled successfully.\n";
             return;
        }
        temp = temp->next;
    }
    cout << "Seat not found.\n";
}
int main()
{
    int choice;
do
{
     cout << "\n--- TRAIN RESERVATION SYSTEM ---\n";
     cout << "1. Reserve Seat\n";
     cout << "2. Display Reservations\n";
     cout << "3. Cancel Reservation\n";
     cout << "4. Exit\n";
     cout << "Enter choice: ";
     cin >> choice;
     switch (choice)
     {
         case 1:
             reserveSeat();
             break;
         case 2:
             display();
             break;
         case 3:
             cancelReservation();
             break;
         case 4:
             cout << "Exit\n";
             break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}
