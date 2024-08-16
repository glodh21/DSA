#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a circular singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Point to itself initially
    return newNode;
}

// Function to create a circular singly linked list
void createList(Node** head) {
    int data, numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    if (numNodes <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    *head = createNode(data);
    Node* tail = *head;

    for (int i = 1; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        Node* newNode = createNode(data);
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = *head; // Make the list circular
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to insert at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        newNode->next = *head;
        tail->next = newNode;
        *head = newNode;
    }
    printList(*head);
}

// Function to insert at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = *head;
    }
    printList(*head);
}

// Function to insert at Nth position
void insertAtPosition(Node** head, int data, int position) {
    int index = position - 1;
    Node* newNode = createNode(data);

    if (*head == NULL) {
        if (index == 0) {
            *head = newNode;
            newNode->next = *head;
        } else {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
    } else {
        Node* temp = *head;
        int count = 0;

        if (index == 0) {
            insertAtBeginning(head, data);
            return;
        }

        while (count < index - 1 && temp->next != *head) {
            temp = temp->next;
            count++;
        }

        if (count == index - 1) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Position out of bounds.\n");
            free(newNode);
        }
    }
    printList(*head);
}

// Function to insert after a value
void insertAfterValue(Node** head, int data, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    do {
        if (temp->data == value) {
            Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            printList(*head);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Value not found.\n");
}

// Function to insert before a value
void insertBeforeValue(Node** head, int data, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;
    do {
        if (temp->data == value) {
            Node* newNode = createNode(data);
            if (prev == NULL) {
                insertAtBeginning(head, data);
            } else {
                newNode->next = temp;
                prev->next = newNode;
            }
            printList(*head);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    printf("Value not found.\n");
}

// Function to delete at the beginning
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete at beginning.\n");
        return;
    }

    Node* temp = *head;
    if (temp->next == *head) { // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        Node* tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        *head = temp->next;
        tail->next = *head;
        free(temp);
    }
    printList(*head);
}

// Function to delete at the end
/*void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete at end.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    if (temp->next == *head) { // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
    printList(*head);
}*/

// Function to delete at Nth position
void deleteAtPosition(Node** head, int position) {
    int index = position - 1;

    if (*head == NULL) {
        printf("List is empty. Cannot delete at position.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;
    int count = 0;

    if (index == 0) {
        deleteAtBeginning(head);
        return;
    }

    while (count < index && temp->next != *head) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count == index) {
        if (temp->next == *head && prev == NULL) { // Only one node in the list
            free(temp);
            *head = NULL;
        } else {
            prev->next = temp->next;
            free(temp);
        }
    } else {
        printf("Position out of bounds.\n");
    }
    printList(*head);
}

// Function to delete after a value
void deleteAfterValue(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    do {
        if (temp->data == value) {
            Node* nodeToDelete = temp->next;
            if (nodeToDelete == *head) {
                printf("No node to delete after the given value.\n");
                return;
            }
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
            printList(*head);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Value not found.\n");
}

// Function to delete before a value
void deleteBeforeValue(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;
    do {
        if (temp->next->data == value) {
            Node* nodeToDelete = temp;
            if (nodeToDelete == *head) {
                printf("No node to delete before the given value.\n");
                return;
            }
            if (prev == NULL) {
                deleteAtBeginning(head);
            } else {
                prev->next = temp->next;
                free(nodeToDelete);
            }
            printList(*head);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    printf("Value not found.\n");
}

// Function to search for a value
void search(Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    int position = 1;
    do {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    printf("Value %d not found in the list.\n", value);
}

// Menu-driven interface
int main() {
    Node* head = NULL;
    int choice, data, position, value;

    createList(&head);

    do {
        printf("\nCircular Singly Linked List Operations\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Nth Position\n");
        printf("4. Insert After a Value\n");
        printf("5. Insert Before a Value\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Nth Position\n");
        printf("9. Delete After a Value\n");
        printf("10. Delete Before a Value\n");
        printf("11. Print List\n");
        printf("12. Search for a Value\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter value after which to insert: ");
                scanf("%d", &value);
                insertAfterValue(&head, data, value);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter value before which to insert: ");
                scanf("%d", &value);
                insertBeforeValue(&head, data, value);
                break;
            case 6:
                deleteAtBeginning(&head);
                break;
            case 7:
                //deleteAtEnd(&head);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 9:
                printf("Enter value after which to delete: ");
                scanf("%d", &value);
                deleteAfterValue(&head, value);
                break;
            case 10:
                printf("Enter value before which to delete: ");
                scanf("%d", &value);
                deleteBeforeValue(&head, value);
                break;
            case 11:
                printList(head);
                break;
            case 12:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 13);

    // Clean up
    while (head != NULL) {
        deleteAtBeginning(&head);
    }

    return 0;
}
