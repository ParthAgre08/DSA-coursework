// Implement C++ program for storing and accessing students record which will include
// student roll number, name and marks using linear probing with chaining without
// replacement with the help of hash table data structure.

#include <iostream>
using namespace std;
class student
{
public:
    int roll;
    string name;
    int marks;
    int chain;

    student()
    {
        roll = -1;
        name = " ";
        marks = 0;
        chain = -1;
    }
};

class hashtable
{
public:
    int size;
    student *arr;

    hashtable(int s)
    {
        size = s;
        arr = new student[size];
    }

    int h(int key){
        return key%size;
    }

    void insert(int roll , string name , int marks){
        int index = h(roll);
        if(arr[index].roll == -1){
            arr[index].roll = roll;
            arr[index].name  = name ;
            arr[index].marks = marks;
        }
        else{
            int i=index;

            //finding empty slot
            while(arr[i].roll != -1){
                i = (i+1)%size;
                
            }
            arr[i].roll = roll;
            arr[i].name  = name ;
            arr[i].marks = marks;

            //creating chian 
            while(arr[index].chain != -1){
                index = arr[index].chain;
            }
            arr[index].chain = i;
        }
    }

    void display(){
        cout<<"Name\tRoll\tMakrs\tchain"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i].name<<"\t"<<arr[i].roll<<"\t"<<arr[i].marks<<"\t"<<arr[i].chain<<endl;
        }
    }
};
int main()
{
hashtable h(10);
h.insert(3,"Parth",97);
h.insert(4,"Pranali",87);
h.insert(35,"Harshit",35);
h.insert(18,"Virat",75);
h.insert(45,"Rohit",67);

h.display();
    return 0;
}