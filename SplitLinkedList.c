/**
 * 
 * @file SplitLinkedList.c
 * @author Max Base (maxbasecode@gmail.com)
 * @brief Split a linked list into two or three linked lists, and merge them into one linked list.
 * @version 0.1
 * @date 2022-12-19
 * @copyright Copyright (c) 2022
 * 
 */

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
void split2LinkedList(struct LinkedList* list, struct LinkedList* list1, struct LinkedList* list2) {
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

// Split a linked list into three linked lists
void split3LinkedList(struct LinkedList* list, struct LinkedList* list1, struct LinkedList* list2, struct LinkedList* list3) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* newNode = createNode(current->data);
        if (current->data % 3 == 0) {
            addNode(list1, newNode);
        } else if (current->data % 3 == 1) {
            addNode(list2, newNode);
        } else {
            addNode(list3, newNode);
        }
        current = current->next;
    }
}

// Merge two linked lists into one linked list
void merge2LinkedList(struct LinkedList* list, struct LinkedList* list1, struct LinkedList* list2) {
    struct Node* current1 = list1->head;
    struct Node* current2 = list2->head;
    while (current1 != NULL) {
        addNode(list, createNode(current1->data));
        current1 = current1->next;
    }
    while (current2 != NULL) {
        addNode(list, createNode(current2->data));
        current2 = current2->next;
    }
}

// Merge three linked lists into one linked list
void merge3LinkedList(struct LinkedList* list, struct LinkedList* list1, struct LinkedList* list2, struct LinkedList* list3) {
    struct Node* current1 = list1->head;
    struct Node* current2 = list2->head;
    struct Node* current3 = list3->head;
    while (current1 != NULL) {
        addNode(list, createNode(current1->data));
        current1 = current1->next;
    }
    while (current2 != NULL) {
        addNode(list, createNode(current2->data));
        current2 = current2->next;
    }
    while (current3 != NULL) {
        addNode(list, createNode(current3->data));
        current3 = current3->next;
    }
}

// Sort a linked list
void sortLinkedList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* next = current->next;
        while (next != NULL) {
            if (current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

// Sort a linked list recursively
void sortLinkedListRecursive(struct Node* current) {
    if (current == NULL) {
        return;
    }
    struct Node* next = current->next;
    while (next != NULL) {
        if (current->data > next->data) {
            int temp = current->data;
            current->data = next->data;
            next->data = temp;
        }
        next = next->next;
    }
    sortLinkedListRecursive(current->next);
}

// Print a linked list
void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
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
    split2LinkedList(list, list1, list2);

    // Print linked lists
    printf("List: ");
    printList(list);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge two linked lists
    struct LinkedList* merge1 = createLinkedList();
    merge2LinkedList(merge1, list1, list2);

    printf("Merge 1: ");
    printList(merge1);

    // Split the linked list into three linked lists
    list1 = createLinkedList();
    list2 = createLinkedList();
    struct LinkedList* list3 = createLinkedList();
    split3LinkedList(list, list1, list2, list3);

    // Print linked lists
    printf("List: ");
    printList(list);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    printf("List 3: ");
    printList(list3);

    // Merge three linked lists
    struct LinkedList* merge2 = createLinkedList();
    merge3LinkedList(merge2, list1, list2, list3);

    printf("Merge 2: ");
    printList(merge2);

    printf("Sorted merge 1: ");
    sortLinkedListRecursive(merge2->head);
    printList(merge1);

    printf("Sorted merge 2: ");
    sortLinkedList(merge1);
    printList(merge2);

    return 0;
}
