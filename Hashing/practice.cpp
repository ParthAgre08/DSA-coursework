#include<iostream>
using namespace std;

class hashtable{
public:
int size=13;
int * arr = new int[size];

void initialize(){
    for(int i=0;i<size ;i++){
        arr[i] =-1;
    }
}

int h1(int key){
    return key%13;
}
int h2(int key){
    return (1+key%11);
}

void insert(int key){
    int idx1 = h1(key);
    if(arr[idx1] == -1){
        arr[idx1] = key;
    }
    else{
        int i=1;
        while(i<size){
            int index = (idx1 + i* h2(key))%size;
            if(arr[index] == -1){
                arr[index] = key;
                return;
            }
            i++;
        }
        cout<<"table is full"<<endl;
    }
}

void display(){
    for(int i=0;i<size;i++){
        cout<<i<<" : "<<arr[i]<<endl;
    }
}
};

int main(){
hashtable h;
h.initialize();
h.insert(46);
h.insert(24);
h.insert(68);
h.insert(22);
h.insert(28);
h.display();
return 0;
}