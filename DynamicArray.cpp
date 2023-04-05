#include<iostream>
using namespace std;
/* 
    Dynamic array : We use static arrays to implement dynamic arrays.
    - We create a static array of a fix size and we keep a track of the number of elements entered as and when this number surpasses the size of the static array
    we create a new array with double the size of the array as the previous and copy the elements of the previous array to the new array.
*/

template <typename T> class Array{
    private:
    T *arr;
    int len;
    int capacity;

    public:
    Array(){
        Array(1);
    }
    Array(int capacity){
        if(capacity<0){
            cout<<"Illegal Capacity : "<<capacity<<endl;
        }
        else{
            this->capacity = capacity;
        }
        this->len=0;
        arr = new T[capacity];
        cout<<capacity<<endl;
        cout<<len<<endl;
    }    
    
    int size(){
        return len;
    }

    bool isEmpty(){
        return (size()==0);
    }

    T get(int index){
        return arr[index];
    }

    void clear(){
        for(int i=0;i<capacity;i++){
            arr[i] = NULL;
        }
        len = 0;
    }

    void add(T elem) {
        if(len+1 >= capacity){
            if(capacity == 0){
                capacity = 1;
            }
            else{
                capacity *= 2;
            }
            T *new_arr = new T[capacity]; 
            for(int i=0;i<this->len;i++){
                cout<<this->len<<endl;
                new_arr[i] = arr[i];
            }
            arr = new_arr;
        }
        arr[len++] = elem;
        cout<<arr[0]<<endl;
    }

    T removeAt(int rm_index){
        try 
        {
            if(rm_index>= len && rm_index < 0) {
                throw rm_index;
            }
            T data = arr[rm_index];
            T *new_arr = new T[len-1];
            for(int i=0,j=0;i<len;i++,j++){
                if(i == rm_index){
                    j--;
                }
                else{
                    new_arr[j] = arr[i];
                }
            }
            arr = new_arr;
            capacity = --len;
            return data ; 
        }
        catch(int ind){
            cout<<"Index is out of the legal range !";
        }
    }

    bool remove(T obj){
        for(int i=0;i<len;i++){
            if(arr[i] == obj){
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    int indexOf(T obj){
        for(int i=0;i<len;i++){
            if(arr[i] == obj){
                return i;
            }
        }
        return -1;
    }

    bool contains(T obj){
        return indexOf(obj)!=-1;
    }

};
int main(){
    int n=10;
    Array<int> arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.add(ele);
        cout<<arr.size();
    }
    return 0;
}
