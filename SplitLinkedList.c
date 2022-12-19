#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a new linked list
struct LinkedList* createLinkedList() {
    struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

// Add a node to the end of the linked list
void addNode(struct LinkedList* list, struct Node* newNode) {
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Split a linked list into two linked lists
void splitLinkedList(struct LinkedList* list, struct LinkedList* list1, struct LinkedList* list2) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* newNode = createNode(current->data);
        if (current->data % 2 == 0) {
            addNode(list1, newNode);
        } else {
            addNode(list2, newNode);
        }
        current = current->next;
    }
}
void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char** argv) {
    // Create a linked list
    struct LinkedList* list = createLinkedList();

    // Add some nodes to the linked list
    addNode(list, createNode(1));
    addNode(list, createNode(2));
    addNode(list, createNode(3));
    addNode(list, createNode(4));
    addNode(list, createNode(5));
    addNode(list, createNode(6));
    addNode(list, createNode(7));
    addNode(list, createNode(8));
    addNode(list, createNode(9));

    // Split the linked list into two linked lists
    struct LinkedList* list1 = createLinkedList();
    struct LinkedList* list2 = createLinkedList();
    splitLinkedList(list, list1, list2);

    // Print linked lists
    printf("List: ");
    printList(list);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    return 0;
}
