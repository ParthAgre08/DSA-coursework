// Insert 1, 21, 75, 33, 41 and 45 in the given hash table using quadratic probing with table
// size 10. Implement in c++.
#include<iostream>
using namespace std;

class hashtable{
    public:
    int size=10;
    int * arr = new int[size];

    void initialize(){
        for(int i=0;i<size;i++){
            arr[i] = -1;
        }
    }

    int h(int key){
        return key%size;
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
hashtable h;
h.initialize();
h.insert(1);
h.insert(21);
h.insert(75);
h.insert(33);
h.insert(41);
h.insert(45);
h.display();
return 0;
}