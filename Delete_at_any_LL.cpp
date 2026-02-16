#include <iostream>
using namespace std;

struct list {
    int data;
    struct list *next;
};
typedef struct list node;

node *start = NULL;

void display(node *start) {
    node *temp = start;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void DeleteAny(int item) {
    node *temp = start;
    node *prev = NULL;

    while (temp != NULL) {
        if (temp->data == item) {
            if (prev != NULL) {
                prev->next = temp->next;
            } else {
                start = temp->next;  
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "NOT FOUND" << endl;
}

void insert(int value) {
    node *newNode = new node;
    newNode->data = value;
    newNode->next = start;
    start = newNode;
}

int main() {
    int item;
    cout << "Enter the value to delete: ";
    cin >> item;

    insert(10);
    insert(20);
    insert(30);

    cout << "Original List: ";
    display(start);

    DeleteAny(item);

    cout << "After Deletion: ";
    display(start);

    return 0;
}
