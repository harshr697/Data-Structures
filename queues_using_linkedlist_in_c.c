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


void display(struct node*head){
    printf("front-> ");

    for(struct node*temp=head;temp!=NULL;temp=temp->next){
        printf("%d  ",temp->data);
    }
    printf(" <-rear\n");
}





struct node* enqueue(struct node*head,int n){
    
    struct node* newNode = createNode(n);

    if(head==NULL){
        head = newNode;
        return head;
    }
    struct node*temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->next=NULL;
    return head;
}

struct node* dequeue(struct node* head){
    if(head==NULL){
        printf("LinkedList is empty!");
        return NULL;
    }
    struct node*temp = head;
    head = head->next;
    free(temp);
    return head;
}




// Insertion at nth position
// Deletion at nth position
// display in reverse order

int main(){
    struct node*head = NULL;
    head=enqueue(head,51);
    head=enqueue(head,1);
    head=enqueue(head,87);
    head=enqueue(head,1000);
    display(head); // 51 1 87 1000
    head=dequeue(head);
    display(head); // 1 87 1000

}




