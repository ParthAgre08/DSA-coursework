// Implement C++ program for storing and accessing patient record which will include
// patient id, patient name using linear probing with chaining without replacement with the
// help of hash table data structure.
#include<iostream>
using namespace std;
class patient{
public:
int id;
string name;
int chain;

patient(){
    id = -1;
    name = " ";
    chain = -1;
}

};

class hashtable{
    public:
    int size;
    patient *arr;

    hashtable(int s){
        size = s;
        arr = new patient[size];
    }

    int h(int key){
        return key%size;
    }

    void insert(int id,string name){
        int index = h(id);
        if(arr[index].id == -1){
            arr[index].id = id;
            arr[index].name = name;
        }
        else{
            int i=index;

            while(arr[i].id != -1){
                    i = (i+1)%size;
            }
            arr[i].id = id;
            arr[i].name = name;

            while(arr[index].chain != -1){
                index = arr[index].chain;
            }
            arr[index].chain = i;
        }
    }

    void display(){
        cout<<"Name\tID\tchain"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i].name<<"\t"<<arr[i].id<<"\t"<<arr[i].chain<<endl;
        }
    }
};
int main(){
hashtable h(10);
h.insert(35,"Ramesh");
h.insert(68,"Suresh");
h.insert(55,"vinit");
h.insert(98,"dilip");
h.insert(34,"dipak");
h.display();
return 0;
}