#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    int key;
    struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;


void printList();                   // Print the list
void insertFirst(int key, int data);// Insert link at the first location
struct node* deleteFirst();         // Delete first item
bool isEmpty();                     // Is list empty
int length();                       // Return the length of the list
struct node* find(int key);         // Find a link with given key
struct node* delete(int key);       // Delete a link with given key
void sort();                        // Sort the list
void reverse(struct node** head);   // Reverse the list
void info();                        // Print the info about me


int main() {
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);

    info();
    printf("Original List: ");

    printList();
    while(!isEmpty()) {
        struct node *temp = deleteFirst();
        printf("\nDeleted value: ");
        printf("(%d,%d) ", temp->key, temp->data);
    }

    printf("\nList after deleting all items: ");
    printList();
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);

    printf("\nRestored List: ");
    printList();
    printf("\n");

    struct node *foundLink = find(4);

    if(foundLink != NULL) {
        printf("Element found: ");
        printf("(%d,%d) ", foundLink->key, foundLink->data);
        printf("\n");
    } else { printf("Element not found."); }

    delete(4);
    printf("List after deleting an item: ");
    printList();
    printf("\n");
    foundLink = find(4);

    if(foundLink != NULL) {
        printf("Element found: ");
        printf("(%d,%d) ", foundLink->key, foundLink->data);
        printf("\n");
    } else { printf("Element not found."); }

    printf("\n");
    sort();

    printf("List after sorting the data: ");
    printList();

    reverse(&head);
    printf("\nList after reversing the data: ");
    printList();

    return 0;
}


void printList() {
    struct node *ptr = head;
    printf("\n[ ");

    while(ptr != NULL) {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }

    printf(" ]\n");
}

void insertFirst(int key, int data) {
    struct node *link = (struct node*) malloc(sizeof(struct node)); // create a link
    link->key = key;
    link->data = data;
    link->next = head;  // point it to old first node
    head = link;        // point first to new first node
}

struct node* deleteFirst() {
    struct node *tempLink = head;   // save reference to first link
    head = head->next;              // mark next to first link as first
    return tempLink;                // return the deleted link
}

bool isEmpty() { return head == NULL; }

int length() {
    int length = 0;
    struct node *current;

    for(current = head; current != NULL; current = current->next) { length++; }

    return length;
}

struct node* find(int key) {
    struct node* current = head;        // start from the first link
    
    if(head == NULL) { return NULL; }   // if list is empty, return NULL
    
    while(current->key != key) {        // navigate through list
        if(current->next == NULL) { return NULL; }  // if it is the last node
        else { current = current->next; }           // go to next link
    }

    return current;                    // if data found, return the current Link
}

struct node* delete(int key) {
    struct node* current = head;
    struct node* previous = NULL;
    
    if(head == NULL) { return NULL; }   // if list is empty, return NULL
    
    while(current->key != key) {        // navigate through list
        if(current->next == NULL) { return NULL; }  // if it is the last node
        else {
            previous = current;                 // store reference to current link
            current = current->next;            // move to next link
        }
    }

    if(current == head) { head = head->next; }  // found a match, update the link
    else { previous->next = current->next; }

    return current;
}

void sort() {
    int i, j, k, tempKey, tempData;
    struct node *current;
    struct node *next;

    int size = length();
    k = size;

    for(i = 0; i < size - 1; i++, k--) {
        current = head;
        next = head->next;

        for(j = 1; j < k; j++) {
            if(current->data > next->data) {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }

            current = current->next;
            next = next->next;
        }
    }
}

void reverse(struct node** head) {
    struct node* prev   = NULL;
    struct node* current = *head;
    struct node* next;

    while(current != NULL) {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}



void info() {
    printf("\tName: %s\n", "Akbar Tangirov");
    printf("\tID:   %d\n", 202290398);
}
