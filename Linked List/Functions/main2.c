#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

// Function to display the linked list
void display(struct node *temp) {
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }  
    printf("NULL\n");
}

// Function to create the linked list
void create(struct node **head) {
    struct node *newnode = NULL, *temp = NULL;
    int ch = 1;
    while (ch == 1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        
        if (*head == NULL) {
            *head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0, 1): ");
        scanf("%d", &ch);
    }
}

int main() {
    struct node *head = NULL;
    
    // Create the linked list
    create(&head);
    
    // Display the linked list
    printf("The linked list is: ");
    display(head);
    
    return 0;
}
