// xxxThe keys 12, 18, 13, 2, 3, 23, 5 and 15 are inserted into an initially empty hash table of
// length 10 using open addressing with hash function h(k) = k mod 10 and linear probing.
// What is the resultant hash table? Implement in c++.

#include<iostream>
using namespace std;
class hashtable{
    public:
    int size;
    int * arr;

    hashtable(){
        size = 10;
        arr = new int[size];
    }

    void initialize(){
        for(int i =0;i<size;i++){
            arr[i] = -1;
        }
    }

    int hashfunction(int key){
        return key%10;
    }

    void insert(int key){
        int index = hashfunction(key);
        if(arr[index] == -1){
            arr[index] = key;
        }
        else{
            while(arr[index] != -1){
                index = (index+1)%10;
            }
            arr[index] = key;
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
h.insert(12);
h.insert(18);
h.insert(13);
h.insert(2);
h.insert(3);
h.insert(23);
h.insert(5);
h.insert(15);
h.display();
return 0;
}