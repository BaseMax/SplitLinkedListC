# Split Linked-List C

This is a simple implementation of a linked-list in C with a few of helper functions for merging two or three linked-lists, spliting a linkedlist to two or three parts, and sorting a linked-list (recursive and non-recursive)

There are a lot of functions in this project. You can use them in your project:

- Add a node to the linked-list
- Create a node
- Create a linked-list
- Split a linked-list into two linked-lists
- Split a linked-list into three linked-lists
- Merge two linked-lists into one linked-list
- Merge three linked-lists into one linked-list
- Sort a linked-list
- Sort a linked-list (recursive)
- Print a linked-list

## How to use

```c
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
```

## License

This project is licensed under the GPL-3.0 License - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2022, Max Base
