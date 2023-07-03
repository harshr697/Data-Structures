#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};


struct node* createNode(int d){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}


// void display(struct node*head){
//     // struct node*temp = head;
//     // while(temp->next!=NULL){
//     //     printf("%d ",temp->data);
//     //     temp=temp->next;
//     // }

//     for(struct node*temp=head;temp!=NULL;temp=temp->next){
//         printf("%d  ",temp->data);
//     }
//     printf("\n");
// }


void peek(struct node* head){
    printf("Top element: %d \n",head->data);
}




struct node* push(struct node*head,int n){
    struct node* newNode = createNode(n);
    newNode->next = head;
    head = newNode;
    return head;
}



struct node* pop(struct node* head){
    if(head==NULL){
        printf("LinkedList is empty!");
        return NULL;
    }
    struct node*temp = head;
    head = head->next;

    printf("Element popped: %d\n", temp->data);
    free(temp);
    return head;
}


// 1 -> NULL

int main(){
    struct node*head = NULL;
    head = push(head,50);
    head = push(head,20);
    head = push(head,1);
    head = push(head,90);
    head = push(head,1000);
    peek(head); // 1000
    head = pop(head);
    head = pop(head);
    peek(head); // 1
}