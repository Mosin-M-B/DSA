#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=NULL;
    struct node *newnode=NULL;
    struct node *temp=NULL;
    int ch=1;
    while (ch==1)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data :");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if (head==NULL)
        {
            head=temp=newnode;
            newnode->next=NULL;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
            temp->next=NULL;
        }
        
        printf("Do you want to continue :");
        scanf("%d", & ch);
    }
    temp=head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");    
    temp=head;
    while (temp!=NULL)
    {
        struct node * next = temp->next;
        printf("\n %d this temp node is free ", temp->data);
        free(temp);
        temp=next;
    }
    return 0;
}