#include<iostream>
using namespace std;
/*
    Linked list : A linear data structure that stores a 
    collection of items called nodes which are stored 
    randomly in the memory(Dynamically) and are chained/linked together 
    by storing the address of the next node int the previous node.
    
    Each Node contains two fields : The information stored and the address of the next node.
        |__Value__|__Next__| : Node with the value and the address of the next node


*/

struct node{
    int value;
    node* next;
};
class Linkedlist{
    private:
    int size;
    node* head;
    public:
    Linkedlist(){
        head = NULL;
        size=0;
    }
    node* createNode(int value){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    } 
    // Adding new Element 
        //Add element at beginning
    void addAtBeg(int value){
        node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
        size+=1;
        cout<<"Inserted a new node at the beginning!"<<endl;
    }
        //Add element at nth position
    void addAt(int index,int value){
        int count=0;
        node* newNode = createNode(value);
        node*temp = head;
        int flag =0;
        if(index==0){
            addAtBeg(value);
            flag=1;
        }
        else{
            while(temp!=NULL){
                if(count+1==index){
                    newNode->next=temp->next;
                    temp->next = newNode;
                    flag = 1;
                    size+=1;
                    cout<<"Inserted a new Node at "<<index<<endl;
                }
                count+=1;
                temp=temp->next;

            }
            if(temp==NULL && count+1==index){
                addAtEnd(value);
                flag=1;
            }
            if(flag==0){
                cout<<"Invalid index!!"<<endl;
            }
        }
        
    }
        //Add element at the end
    void addAtEnd(int value){
        node* newNode = createNode(value);
        node*temp = head;
        while(temp->next!=NULL) 
            temp=temp->next;
        temp->next=newNode;
        size+=1;
        cout<<"Inserted a new node at end ! "<<endl;
    }

    //Removing existing element

        //Remove element at the beginning
    void removeAtBeg(){
        if(size==0){
            cout<<"The linkedlist is empty!"<<endl;
        }
        else{
            node* temp=head;
            head=head->next;
            free(temp);
            size-=1;
            cout<<"Removed the Element at the beginning!"<<endl;
        }
    }
        //Remove element at the nth position
    void removeAt(int n){
        node* temp = head;
        if(n==0){
            removeAtBeg();
        }
        else{
            int count=0;
            int flag=0;
            while(temp!=NULL){
                if(count+1==n){
                    node* deleteNode = temp->next;
                    temp->next = temp->next->next;
                    free(deleteNode);
                    flag=1;
                    size-=1;
                    cout<<"Removed the node at "<<n<<endl;
                }
                count+=1;
                temp=temp->next;
            }
            if(flag==0){
                cout<<"Invalid index!";
            }
        }
    }
        //Remove element at the end
    void removeAtEnd(){
        if(size==0){
            cout<<"The linkedlist is empty!"<<endl;
        }
        else{
            node* temp = head;
            if(temp->next==NULL){
                head=NULL;
                size-=1;

            }
            else{
                while(temp->next->next!=NULL){
                    temp=temp->next;
                }
                temp->next = NULL;
                size-=1;
            }
            cout<<"Removed the node at the end."<<endl;
        }
    }
    // Display the linkedlist
    void display(){
        if(size == 0){
            cout<<"Linked List is empty!"<<endl;
        }
        else{
            node* temp = head;
            cout<<"The size of the linkedlist is : "<<size<<endl;
            cout<<"head";
            while(temp!=NULL){

                cout<<"-> "<<temp->value<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    Linkedlist list1;
    string menu = "---------------------------------------------------- \n 1. Enter a node at the beginning. \n 2. Enter a node at nth position. \n 3. Enter a node at the end. \n 4. Remove a node from the beginning. \n 5. Remove a node from the nth position. \n 6. Remove a node from the end. \n 7. Display \n 8. Exit. \n ----------------------------------------------------\n";
    while(true){
        cout<<menu;
        int choice;
        cout<<" : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int val;
            cout<<"Enter the value : ";
            cin>>val;
            list1.addAtBeg(val);
            break;
        case 2:
            int n2,val2;
            cout<<"Enter the position at which you want to insert the node : ";
            cin>>n2;
            cout<<"Enter the value : ";
            cin>>val2;
            list1.addAt(n2,val2);
            break;
        case 3:
            cout<<"Enter the value : ";
            int val1;
            cin>>val1;
            list1.addAtEnd(val1);
            break;
        case 4:
            list1.removeAtBeg();
            break;
        case 5:
            int n;
            cout<<"Enter the position from which you want to remove a node : ";
            cin>>n;
            list1.removeAt(n);
            break;
        case 6:
            list1.removeAtEnd();
            break;
        case 7:
            list1.display();
            break;
        default:
            exit(0);
            break;
        }
    }
 
}
