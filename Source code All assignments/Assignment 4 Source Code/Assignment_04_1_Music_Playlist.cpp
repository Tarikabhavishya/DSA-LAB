#include <iostream>
#include <string>
using namespace std;
struct Node
{
        string song;
        Node *next;
};
Node *last = NULL;
Node *current = NULL;
// Add a song
void addSong()
{
        Node *newNode = new Node;
        cout << "Enter song name: ";
        cin >> newNode->song;
        if (last == NULL)
        {
           last = newNode;
           newNode->next = newNode;
    }
    else
    {
           newNode->next = last->next;
           last->next = newNode;
           last = newNode;
    }
    cout << "Song added successfully.\n";
}
// Display songs
void display()
{
    if (last == NULL)
    {
           cout << "Playlist is empty.\n";
           return;
    }
    Node *temp = last->next;
    cout << "\nPlaylist:\n";
    do
    {
           cout << temp->song << endl;
           temp = temp->next;
    }
    while (temp != last->next);
}
// Delete a song
void deleteSong()
{
    if (last == NULL)
    {
         cout << "Playlist is empty.\n";
         return;
    }
    string name;
    cout << "Enter song to delete: ";
    cin >> name;
    Node *temp = last->next;
    Node *prev = last;
    do
    {
         if (temp->song == name)
         {
             if (temp == last && temp->next == last)
             {
                    last = NULL;
             }
             else
            {
                  prev->next = temp->next;
                  if (temp == last)
                       last = prev;
            }
            if (current == temp) {
                current = (last == NULL) ? NULL : prev;
            }
            delete temp;
            cout << "Song deleted successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    while (temp != last->next);
    cout << "Song not found.\n";
}
// Play next song
void playNext()
{
    if (last == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }
    if (current == NULL)
           current = last->next;
    else
           current = current->next;
    cout << "Now Playing: " << current->song << endl;
}
int main()
{
    int choice;
    do
    {
           cout << "\n--- MUSIC PLAYLIST ---\n";
           cout << "1. Add Song\n";
           cout << "2. Delete Song\n";
           cout << "3. Display Playlist\n";
           cout << "4. Play Next Song\n";
           cout << "5. Exit\n";
           cout << "Enter choice: ";
           cin >> choice;
           switch (choice)
           {
               case 1:
                   addSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3:
                display();
                break;
            case 4:
                playNext();
                break;
            case 5:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    while (choice != 5);
    return 0;
}
