// Implement C++ program for storing and accessing Library record which will include
// book id, book name and author name using linear probing with chaining without
// replacement with the help of hash table data structure.
#include <iostream>
using namespace std;

class library
{
public:
    int id;
    string name;
    float price;
    int chain;

    library()
    {
        id = -1;
        name = " ";
        price = 0.0;
        chain = -1;
    }
};

class hashtable
{
public:
    int size;
    library *arr;

    hashtable(int s)
    {
        size = s;
        arr = new library[size];
    }

    int hashfunction(int key){
return key%size;
    }

    void insert(int id,string name , float price){
        int index = hashfunction(id);
        if(arr[index].id ==-1){
            arr[index].id = id;
            arr[index].name = name;
            arr[index].price = price;
        }
        else{
            int i=index;
            //find empty slot 
            while(arr[i].id != -1){
                i = (i+1)%size;
            }
            arr[i].id = id;
            arr[i].name = name;
            arr[i].price = price;

            //create chaining 
            while(arr[index].chain != -1){
                index = arr[index].chain;
            }
            arr[index].chain = i;
        }
    
    }


    void display(){
        cout<<"Name\t\tID\tPrice\tchain"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i].name<<"\t\t"<<arr[i].id<<"\t"<<arr[i].price<<"\t"<<arr[i].chain<<endl;
        }
    }
};
int main()
{
    hashtable h(10);
    h.insert(23,"Hittler",346.24);
    h.insert(142,"Warrior",386.2);
    h.insert(21,"Sanktt",646.13);
    h.insert(79,"dhoni",455.42);
    h.insert(18,"virat",3531.24);
    h.display();
    return 0;
}