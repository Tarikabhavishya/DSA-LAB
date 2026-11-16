#include <iostream>
using namespace std;

class HashTable {
private:
  int* table;
  int tableSize;

public:
  // Constructor
  HashTable(int size) {
    tableSize = size;
    table = new int[tableSize];

    // Initialize all slots as empty
    for (int i = 0; i < tableSize; i++) {
      table[i] = -1;
    }
}

// Insert an ISBN into the hash table
void insert(int isbn) {
    int index = isbn % tableSize;
    int startIndex = index;

    // Find the next available slot
    while (table[index] != -1) {
        index = (index + 1) % tableSize;

        // Table is full
        if (index == startIndex) {
            cout << "Hash table is full. Cannot insert " << isbn << endl;
            return;
        }
    }

    table[index] = isbn;
    cout << "ISBN " << isbn << " inserted at index " << index << endl;
}

// Search for an ISBN
bool search(int isbn) {
    int index = isbn % tableSize;
    int startIndex = index;

    while (table[index] != -1) {
        if (table[index] == isbn) {
            cout << "ISBN " << isbn << " found at index "
              << index << endl;
            return true;
        }

        index = (index + 1) % tableSize;

        // We have checked the entire table
        if (index == startIndex) {
            break;
        }
    }

    cout << "ISBN " << isbn << " not found." << endl;
    return false;
}

// Display the hash table
void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < tableSize; i++) {
             cout << "Index " << i << ": ";

             if (table[i] == -1)
               cout << "Empty";
             else
               cout << table[i];

             cout << endl;
         }
     }

     // Destructor
     ~HashTable() {
         delete[] table;
     }
};

int main() {
     int tableSize;
     int n;

     cout << "Enter table size: ";
     cin >> tableSize;

     HashTable ht(tableSize);
 cout << "Enter number of books: ";
 cin >> n;

 cout << "Enter ISBN numbers:\n";

 for (int i = 0; i < n; i++) {
     int isbn;
     cin >> isbn;
     ht.insert(isbn);
 }

 // Display the final table
 ht.display();

 // Search operation
 int searchISBN;
 cout << "\nEnter ISBN to search: ";
 cin >> searchISBN;

 ht.search(searchISBN);

 return 0;
}
