#include<stdio.h>

/*
rear = (rear+1)%size
rear 4
5%5 = 0
rear = 0

if (front!=0 && front!=rear){
    insertion allowed
}
*/


#define size 5

int front = -1;
int rear = -1;


int isFull(){
    if((front == 0 && rear == size-1) || front==rear+1){
        return 1;
    }
    return 0;
}
int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}
void enqueue(int arr[],int data){
    if(isFull()){
        printf("Overflow!\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    rear = (rear+1)%size;
    arr[rear] = data;
   
}
void dequeue(int arr[]){
    if(isEmpty()){
        printf("Underflow!\n");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front = (front+1)%size;
    }

}

void display(int arr[]){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    printf("front -> ");
    for(int i=front;i!=rear;i=(i+1)%size){
        printf("%d ",arr[i]);
    }
    printf("%d ",arr[rear]);
    printf(" <- rear\n");
}
int main(){
    int arr[size];
    enqueue(arr,56);
    enqueue(arr,24);
    enqueue(arr,90);
    enqueue(arr,23);
    enqueue(arr,98);
    display(arr);
    enqueue(arr,78);
    dequeue(arr);
    display(arr);
    enqueue(arr,9000);
    display(arr);
    // front -> 24 90 23 98  <- rear
    //

}