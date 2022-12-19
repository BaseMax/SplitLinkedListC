# Split Linked-List C

This is a simple implementation of a linked-list in C. It is a simple example of how to use a linked-list in C. It's just a simple example to show how to use a linked-list in C.

## How to use

```c
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
```

## License

This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2022, Max Base
