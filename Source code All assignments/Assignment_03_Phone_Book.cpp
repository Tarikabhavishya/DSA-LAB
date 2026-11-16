#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 100;
//--------------------------------------------------
// Display Phone Book
//--------------------------------------------------
void display(string name[], string mobile[], int n)
{
    if (n == 0)
  {
       cout << "\nPhone book is empty.\n";
       return;
  }

        cout << "\n============================================\n";
        cout << "             FRIEND PHONE BOOK\n";
        cout << "============================================\n";
        cout << "Name\t\tMobile Number\n";
        cout << "--------------------------------------------\n";

        for (int i = 0; i < n; i++)
    {
           cout << name[i] << "\t\t" << mobile[i] << endl;
    }

        cout << "============================================\n";
}

//--------------------------------------------------
// Sentinel Search
//--------------------------------------------------
int sentinelSearch(string name[], int n, string key)
{
   // Cannotsearchanemptyarray
   if (n == 0)
      return -1;

        // Store the last element
        string last = name[n - 1];

        // Place search key at last position
        name[n - 1] = key;

        int i = 0;

        // Search
        while (name[i] != key)
    {
          i++;
    }

        // Restore original last element
        name[n - 1] =last;

        // Check whether key was actually present
        if (i < n - 1 || last == key)
           return i;

        return -1;
}

//--------------------------------------------------
// Merge Function for Merge Sort
//--------------------------------------------------
void merge(string name[], string mobile[],
         int left, int mid, int right)
{
   int n1 = mid - left + 1;
   int n2 = right - mid;

        // Temporary arrays
        vector<string> leftName(n1);
        vector<string> leftMobile(n1);

        vector<string> rightName(n2);
        vector<string> rightMobile(n2);

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
    {
            leftName[i] = name[left + i];
            leftMobile[i] = mobile[left + i];
    }

        for (int j = 0; j < n2; j++)
    {
            rightName[j] = name[mid + 1 +j];
            rightMobile[j] = mobile[mid + 1 +j];
    }

        int i = 0;
        int j = 0;
        int k = left;

        // Merge two sorted arrays
        while (i < n1 && j <n2)
    {
            if (leftName[i] <= rightName[j])
        {
              name[k] = leftName[i];
              mobile[k] = leftMobile[i];
              i++;
        }
            else
        {
              name[k] = rightName[j];
              mobile[k] = rightMobile[j];
              j++;
        }

            k++;
    }

        // Copy remaining elements from left array
        while (i <n1)
    {
            name[k] = leftName[i];
            mobile[k] = leftMobile[i];
            i++;
            k++;
    }

        // Copy remaining elements from right array
        while (j <n2)
    {
            name[k] = rightName[j];
            mobile[k] = rightMobile[j];
            j++;
            k++;
    }
}

//--------------------------------------------------
// Merge Sort
//--------------------------------------------------
void mergeSort(string name[], string mobile[],
             int left, int right)
{
    if (left < right)
  {
       int mid = left + (right - left) / 2;

            // Sort left half
            mergeSort(name, mobile, left,mid);

            // Sort right half
            mergeSort(name, mobile, mid + 1, right);

            // Merge both halves
            merge(name, mobile, left, mid, right);
    }
}

//--------------------------------------------------
// Insert Friend
//--------------------------------------------------
void insertFriend(string name[], string mobile[], int &n)
{
    if (n >=MAX)
  {
       cout << "\nPhone book is full. Cannot insert friend.\n";
       return;
  }

        string newName, newMobile;

        cout << "\nEnter friend's name: ";
        cin >> newName;

        // Check duplicate using Sentinel Search
        int position = sentinelSearch(name, n, newName);

        if (position != -1)
    {
          cout << "\nFriend already exists in the phone book.\n";
          return;
    }

        cout << "Enter mobile number: ";
        cin >> newMobile;

        // Addfriendattheend
        name[n] = newName;
        mobile[n] = newMobile;

        n++;

        // Sort using Merge Sort
        mergeSort(name, mobile, 0, n - 1);

        cout << "\nFriend inserted successfully.\n";
}

//--------------------------------------------------
// Delete Friend
//--------------------------------------------------
void deleteFriend(string name[], string mobile[], int &n)
{
    if (n == 0)
  {
       cout << "\nPhone book is empty. Nothing to delete.\n";
       return;
  }

        string deleteName;

        cout << "\nEnter name of friend to delete: ";
        cin >> deleteName;
        // Find friend using Sentinel Search
        int position = sentinelSearch(name, n, deleteName);

        if (position == -1)
    {
           cout << "\nFriend not found in phone book.\n";
           return;
    }

        // Shift elements to the left
        for (int i = position; i < n - 1; i++)
    {
          name[i] = name[i + 1];
          mobile[i] = mobile[i + 1];
    }

        n--;

        cout << "\nFriend deleted successfully.\n";
}

//--------------------------------------------------
// Search Friend
//--------------------------------------------------
void searchFriend(string name[], string mobile[], int n)
{
    if (n == 0)
  {
       cout << "\nPhone book is empty.\n";
       return;
  }

        string searchName;

        cout << "\nEnter name of friend to search: ";
        cin >> searchName;

        int position = sentinelSearch(name, n, searchName);

        if (position != -1)
    {
           cout << "\n============================================\n";
           cout << "       FRIEND FOUND\n";
           cout << "============================================\n";
           cout << "Name      : " << name[position] << endl;
           cout << "Mobile Number : " << mobile[position] << endl;
           cout << "============================================\n";
    }
        else
    {
           cout << "\nFriend not found in phone book.\n";
    }
}

//--------------------------------------------------
// Main Function
//--------------------------------------------------
int main()
{
   stringname[MAX];
   stringmobile[MAX];

        intn;

        cout << "Enter number of friends: ";
        cin >>n;

        if (n < 0 || n >MAX)
    {
           cout << "Invalid number of friends.\n";
           return 1;
    }

        // ----------------------------------------------
        // Initial Input
        // ----------------------------------------------
        for (int i = 0; i < n; i++)
    {
           cout << "\nEnter name of friend " << i + 1 << ": ";
           cin >> name[i];

           cout << "Enter mobile number: ";
           cin >> mobile[i];
    }

        // ----------------------------------------------
        // Initial Sorting using Merge Sort
        // ----------------------------------------------
        if (n > 1)
    {
           mergeSort(name, mobile, 0, n - 1);
    }

        cout << "\nPhone book after Merge Sort:";
        display(name,mobile,n);

        // ----------------------------------------------
        // Menu
        // ----------------------------------------------
        intchoice;

        do
    {
           cout << "\n\n============================================\n";
           cout << "      PHONE BOOK MENU\n";
    cout << "============================================\n";
    cout << "1. Insert Friend\n";
    cout << "2. Delete Friend\n";
    cout << "3. Search Friend (Sentinel Search)\n";
    cout << "4. Display Phone Book\n";
    cout << "5. Sort Phone Book (Merge Sort)\n";
    cout << "6. Exit\n";
    cout << "============================================\n";

    cout << "Enter your choice: ";
    cin >>choice;

    switch(choice)
{
        case 1:
          insertFriend(name,mobile,n);
          break;

        case 2:
          deleteFriend(name,mobile,n);
          break;

        case 3:
          searchFriend(name,mobile,n);
          break;

        case 4:
          display(name,mobile,n);
          break;

        case 5:
          if (n > 1)
    {
             mergeSort(name, mobile, 0, n - 1);
             cout << "\nPhone book sorted successfully using Merge Sort.\n";
    }
          else
    {
             cout << "\nNot enough friends to sort.\n";
    }
          break;

        case 6:
          cout << "\nExiting Phone Book. Goodbye!\n";
          break;

        default:
          cout << "\nInvalid choice. Please try again.\n";
}

} while (choice != 6);

return 0;
}
