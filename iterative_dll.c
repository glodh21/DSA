#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to reverse the doubly linked list iteratively
Node* reverseIterative(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    // Swap the next and prev pointers for each node
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (which was previous)
    }

    // Reset the head to the new front of the list
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the doubly linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, data;
    Node *head = NULL, *tail = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of nodes must be greater than 0.\n");
        return 1;
    }

    // Input the data for each node
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        
        Node* newNode = createNode(data);
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("Original list:\n");
    printList(head);
    
    head = reverseIterative(head);
    
    printf("Reversed list:\n");
    printList(head);
    
    // Free the allocated memory
    freeList(head);
    
    return 0;
}
