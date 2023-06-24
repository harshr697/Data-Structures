#include<stdio.h>


int top=-1; //GLOBAL VARIABLE   
#define size 5

void isFull(int arr[]){
    if(top==size-1){
        printf("Stack is full.\n");
    }
}

void isEmpty(int arr[]){
    if(top==-1){
        printf("Stack is empty.\n");
    }
}

void count(int arr[]){
    printf("count: %d\n",top+1);
}
void push(int arr[],int data){
    top=top+1;
    arr[top] = data;
}
void pop(int arr[]){
    top = top-1;
}
void peek(int arr[]){
    printf("element at top: %d \n",arr[top]);
}

int main(){
    int arr[size];
    isEmpty(arr);
    push(arr,15);
    push(arr,12); // <-
    push(arr,3);
    count(arr);
    push(arr,89); // <-
    push(arr,0);
    isFull(arr);
    peek(arr); // 0
    pop(arr);
    peek(arr); // 89

}