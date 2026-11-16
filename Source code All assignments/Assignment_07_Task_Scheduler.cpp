#include <iostream>
#include <string>
using namespace std;

struct Node {
    string task;
    int priority;
    Node *left, *right;

     Node(string t, int p) {
         task = t;
         priority = p;
         left = right = NULL;
     }
};

Node* insertTask(Node* root, string task, int priority) {
    if (root == NULL)
        return new Node(task, priority);

     if (priority < root->priority)
         root->left = insertTask(root->left, task, priority);
     else
         root->right = insertTask(root->right, task, priority);

     return root;
}

Node* findMax(Node* root) {
    while (root != NULL && root->right != NULL)
        root = root->right;
    return root;
}

Node* deleteTask(Node* root, int priority) {
    if (root == NULL)
        return NULL;

    if (priority < root->priority)
        root->left = deleteTask(root->left, priority);
    else if (priority > root->priority)
        root->right = deleteTask(root->right, priority);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMax(root->left);
        root->priority = temp->priority;
        root->task = temp->task;
        root->left = deleteTask(root->left, temp->priority);
    }

    return root;
}

void display(Node* root) {
    if (root == NULL)
        return;

    display(root->left);
    cout << root->task << " (Priority "
         << root->priority << ")\n";
    display(root->right);
}

int main() {
    Node* root = NULL;
    int choice, priority;
    string task;

    do {
        cout << "\n--- TASK SCHEDULER ---\n";
        cout << "1. Add task\n";
        cout << "2. Process highest-priority task\n";
        cout << "3. Display tasks\n";
   cout << "4. Exit\n";
   cout << "Enter choice: ";
   cin >> choice;

   switch (choice) {
       case 1:
           cout << "Enter task name (one word): ";
           cin >> task;

           cout <<"Enterpriority(highernumber      =higher   priority): ";
           cin >> priority;

           root = insertTask(root, task, priority);
           cout << "Task added successfully.\n";
           break;

       case 2: {
           if (root == NULL) {
               cout << "No tasks to process.\n";
           } else {
               Node* top = findMax(root);

               cout << "Processing: " << top->task
                    <<"(Priority"    <<top->priority<<")\n";

               root = deleteTask(root, top->priority);
           }
           break;
       }

       case 3:
           if (root == NULL) {
               cout << "No pending tasks.\n";
           } else {
               cout<<"Tasks   fromlowesttohighestpriority:\n";
               display(root);
           }
           break;

       case 4:
           cout << "Exiting scheduler.\n";
           break;

       default:
           cout << "Invalid choice. Try again.\n";
   }

} while (choice != 4);
    return 0;
}
