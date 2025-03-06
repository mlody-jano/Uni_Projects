#include <iostream>

using namespace std;

struct student {
    long int index;
    string FirstName;
    string LastName;
    char sex{0};
    string dateOfBirth;
};

struct Node {
    int data;
    Node *next;
};
void menu_show(char &choice) {
    cout << "Hello! List of actions:\n";
    cout << "1. Add node.\n";
    cout << "2. Show all nodes.\n";
    cout << "3. Shut program down.\n";
    cout << "Choose your action:\n";

    cin >> choice;
}
void push(Node **head) {
    int newData = 0;

    cout << "Enter new element data:\n";
    cin >> newData;

    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}
void element_show_all(Node *node) {

    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "nullptr\n";
}

int main() {

    Node *head = nullptr;

    char choice{0};

    while(true) {
        menu_show(choice);

        switch(choice) {
            case '1': {
                push(&head);
                break;
            }
            case '2': {
                element_show_all(head);
                break;
            }
            case '3': {
                cout << "Shutting program down!\n";
                return 0;
            }
            default: {
                cout << "Invalid input.\n";
            }
        }
        choice = 0;
    }
}