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


void display(struct node* head){
    if(head==NULL){
        printf("\n");
    }
    else{
        printf(head->data);
        display(head->next);
    }
}


void displayReverse(struct node* head){
    if(head==NULL){
        //cout<<endl;
        return;
    }
    else{
        displayReverse(head->next);
        printf(head->data);
    }
}


struct node* insertAtBeg(struct node*head,int n){
    struct node* newNode = createNode(n);
    newNode->next = head;
    head = newNode;
    return head;
}


struct node* insertAtEnd(struct node*head,int n){
    
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

struct node* removeAtBeg(struct node* head){
    if(head==NULL){
        printf("LinkedList is empty!");
        return NULL;
    }
    struct node*temp = head;
    head = head->next;
    free(temp);
    return head;
}

// 1 -> NULL
struct node* removeAtEnd(struct node*head){
    if(head->next == NULL){
        struct node*temp = head;
        head = NULL;
        free(temp);
        return head;
    }
    struct node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    struct node* temp1 = temp->next;
    temp->next = NULL;
    free(temp1);

    return head;
}

struct node* insertAtN(struct node*head,int n,int index){
    int count=0;
    struct node*temp = head;
    struct node*newNode = createNode(n);
    while(temp->next!=NULL){
        if(count+1==index){
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp=temp->next;
        count+=1;
    }
    return head;
}

struct node* removeAtN(struct node*head,int index){
    int count=0;
    struct node*temp = head;

    while(temp->next!=NULL){
        if(count+1==index){
            struct node*temp1 = temp->next;
            temp->next = temp->next->next;
            free(temp1);
        }
        count+=1;
        temp=temp->next;

    }
    return head;
}

// Insertion at nth position
// Deletion at nth position
// display in reverse order

int main(){
    struct node*head = NULL;
    head = insertAtBeg(head,5);
    head = insertAtBeg(head,1);
    head = insertAtBeg(head,50);
    head = insertAtEnd(head,59);
    head = insertAtEnd(head,45);
    display(head);
    head=insertAtN(head,5000,3);
    display(head);
    head = removeAtBeg(head);
    display(head);
    head = removeAtEnd(head);
    display(head);

    head = insertAtBeg(head,57);
    head = insertAtBeg(head,14);
    head = insertAtBeg(head,50);
    head=removeAtN(head,2);

    display(head);

}




