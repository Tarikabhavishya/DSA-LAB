#include <iostream>
#include <string>
using namespace std;
struct Node
{
     string name;
     long long number;
     Node *next;
};
Node *head = NULL;
// Add call
void addCall()
{
     Node *newNode = new Node;
     cout << "Enter caller name: ";
     cin >> newNode->name;
     cout << "Enter phone number: ";
     cin >> newNode->number;
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
    }
    cout << "Call added successfully.\n";
}
// Display calls
void displayCalls()
{
    if (head == NULL)
    {
        cout << "Call log is empty.\n";
        return;
    }
    Node *temp = head;
    cout << "\n--- CALL LOG ---\n";
    while (temp != NULL)
    {
        cout << "Name: " << temp->name << endl;
        cout << "Number: " << temp->number << endl;
        cout << "----------------\n";
         temp = temp->next;
    }
}
// Delete first call
void deleteCall()
{
    if (head == NULL)
    {
         cout << "Call log is empty.\n";
         return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "Call deleted successfully.\n";
}
int main()
{
    int choice;
    do
    {
         cout << "\n--- CALL LOG MANAGEMENT ---\n";
         cout << "1. Add Call\n";
    cout << "2. Display Calls\n";
    cout << "3. Delete Call\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            addCall();
            break;
        case 2:
            displayCalls();
            break;
        case 3:
            deleteCall();
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
