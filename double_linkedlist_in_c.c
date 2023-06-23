// Double Linked List in c 
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createNode(int n){
    struct node*newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = n;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

struct node* insertAtBeg(struct node*head,int n){
    
    struct node*newNode = createNode(n);
    if(head==NULL){
        head = newNode;
        return head;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
    return head;
}

struct node*insertAtEnd(struct node*head,int n){
    struct node*newNode = createNode(n);
    struct node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct node*removeAtBeg(struct node*head){
    struct node*temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct node*removeAtEnd(struct node*head){
    struct node*temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    struct node* temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
    return head;
}

void display(struct node*head){
    struct node*temp = head;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){

    struct node*head = NULL;

    head = insertAtBeg(head,5);
    head = insertAtBeg(head,1);
    head = insertAtBeg(head,50);
    head = insertAtEnd(head,59);
    head = insertAtEnd(head,45);
    // 50 1 5 59 45
    display(head);
    head = removeAtBeg(head);
    // 1 5 59 45
    display(head);
    // 1 5 59
    head = removeAtEnd(head);
    display(head);
}
