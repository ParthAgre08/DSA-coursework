// Let M = 10 , H(X)= X MOD M, KEYS={0,1,4,71,64,89,11,22} insert into hash table
// using linear probing. What is the resultant hash table? Implement same in c++.
#include<iostream>
using namespace std;

class hashtable{
    public:
        int size;
        int * arr ;

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
            return key%size;
        }

        void insert(int key){
            int index = h(key);
            if(arr[index] == -1){
                    arr[index] = key;
            }
            else{
                while(arr[index] != -1){
                    index = (index+1)%size;
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
hashtable h(10);
h.initialize();
h.insert(0);
h.insert(1);
h.insert(4);
h.insert(71);
h.insert(64);
h.insert(89);
h.insert(11);
h.insert(22);
h.display();
return 0;
}