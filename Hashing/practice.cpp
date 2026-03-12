// Solve the following question and show step by step table.
// Insert the keys 79, 69, 98, 72, 14, 50 into the Hash Table of size 13. Resolve all
// collisions using Double Hashing where first hash-function is ℎ1 h1​(k) = k mod 13 and
// second hash-function is ℎ2 h2​(k) = 1 + (k mod 11) Implement in c++.
#include<iostream>
using namespace std;

class hashtable{
    public:
         int size = 13;
         int * arr = new int[size];

        void initialize(){
            for(int i=0;i<size;i++){
                arr[i] = -1;
            }
        }

        int h1(int key){
            return key%13;
        }

        int h2(int key){
            return (1+key%11);
        }

        void insert(int key){
            int index = h1(key);
            if(arr[index]==-1){
                arr[index] = key;
            }
            else{
                int i=1;
                while(i<size){
                    int newindex = (h1(key) + i* h2(key))%size;
                    if(arr[newindex] ==-1){
                            arr[newindex]=key;
                            return;
                    }
                    i++;
                }
                cout<<"Table is full !!"<<endl; 
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
h.insert(79);
h.insert(69);
h.insert(98);
h.insert(72);
h.insert(14);
h.insert(50);
h.display();
return 0;
}