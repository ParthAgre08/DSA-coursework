// Insert 66, 80, 41, 44, 82, 89 and 45 in the given hash table using quadratic probing with
// table size 10.
#include<iostream>
using namespace std;

class hashtable{
    public:
int size;
int *arr;

hashtable(int s){
size = s;
arr = new int[size];
}

void initialize(){
    for(int i=0;i<size;i++){
        arr[i] = -1;
    }
}

int h(int key){
    return key % size;
}

void insert(int key){
    int index = h(key);
    if(arr[index] == -1){
        arr[index] = key;
    }
    else{
        int i=1;
        while(i<size){
            int newindex = (index+i*i)%size;
            if(arr[newindex] == -1){
                arr[newindex] = key;
                return;
            }
            i++;
        }
        cout<<"Table is full"<<endl;
    }
}

void display(){
    for(int i=0;i<size;i++){

        cout<<i<<" : "<<arr[i]<<endl;
    }
}
};
int main(){
hashtable h(10);
h.initialize();
h.insert(66);
h.insert(80);
h.insert(41);
h.insert(44);
h.insert(82);
h.insert(89);
h.insert(45);
h.display();
return 0;
}