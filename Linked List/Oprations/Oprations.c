#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node **head) {
    struct node *newnode = NULL, *temp = NULL;
    int ch = 1;
    while (ch == 1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter The data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (*head == NULL) {
            *head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do You Want To Continue (0,1): ");
        scanf("%d", &ch);
    }
}

void display(struct node *temp) {
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert(struct node **head) {
    struct node *newnode = NULL, *temp = NULL;
    int position;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (position == 1) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("There is no node present at that position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void delete(struct node **head){
    struct node *temp = NULL, *temp1 = NULL;
    int position;
    printf("Enter the position: ");
    scanf("%d",&position);
    temp = *head;
    if (temp==NULL)
    {
        printf("List is empty\n");
    }
    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("There is no node present at that position\n");
        return;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    
}
int main() {
    struct node *head = NULL;
    int ch = 1;

    while (ch) {
        printf("Enter 1 for create, 2 for insert, 3 for display,4 for delete , 0 to exit: ");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            create(&head);
            break;
        case 2:
            insert(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            delete(&head);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
