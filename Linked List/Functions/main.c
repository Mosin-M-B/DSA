#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node * next;
};
void display(struct node *temp){
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }  
    printf("NULL\n");
}
int create (struct node *head){
    struct node *newnode = NULL , *temp = NULL;
    int ch =1;
    while (ch==1)
    {
        newnode = (struct node*)malloc (sizeof(struct node));
        printf("Enter The data :");
        scanf("%d",&newnode->data);
        if (head==NULL)
        {
            head=temp=newnode;
            temp->next=NULL;
        }
        else{
            temp->next=newnode;
            temp = newnode;
            temp->next= NULL;
        }
        printf("Do You Want To Continue : ");
        scanf("%d",&ch);
    }
    return temp=head;
}
void main () {
    struct node *head=NULL , *temp;
    temp = create(head);
    display(temp);
}