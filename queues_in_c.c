#include<stdio.h>


#define size 5
int front=-1;
int rear=-1;
// 12 31 45 67 89 // front = 0 rear = 4
// 31 45 67 89 // front = 1 rear = 4
// rear = 4
// insertion into queue -> enqueue
void enqueue(int arr[],int data){
    if(rear == size-1){
        printf("Overflow!");
        return;
    }
    if(front == rear && rear==-1){
        front=front+1;
    }
    rear = rear+1;
    arr[rear] = data;
}

// removal from queue -> dequeue
void dequeue(int arr[]){
    if(front==rear && front==-1){
        printf("Underflow!\n");
        return;
    }
    front=front+1;
    if(front>rear){
        front=-1;
        rear=-1;
    }
}

void display(int arr[]){
    if(front==rear && front==-1){
        printf("Queue is empty !\n");
        return;
    }
    printf("front-> ");
    for(int i=front;i<=rear;i++){
        printf("%d ",arr[i]);
    }
    printf(" <-rear \n");
}

int main(){
    int arr[size];

    enqueue(arr,5);
    enqueue(arr,9);
    enqueue(arr,2);

    display(arr); // 5 9 2

    dequeue(arr);

    display(arr); // 9 2



}