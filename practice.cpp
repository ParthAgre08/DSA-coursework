#include<iostream>
using namespace std;
class student{
    public:
    int roll;
    string name;
    int marks;
    int chain;

    student(){
        name = " ";
        roll=-1;
        marks = 0;
        chain = -1;
    }

};

class hashtable{
    public:
    int size;
    student *arr;

    hashtable(int s){
        size = s;
        arr = new student[size];
    }

    int hashfunction(int key){
        return key%size;
    }
    void insert(int roll,string name , int marks ){
        int index = hashfunction(roll);
        if(arr[index].roll == -1){
            arr[index].roll = roll;
            arr[index].name = name;
            arr[index].marks = marks;
        }
        else{
            int i = index;

            while(arr[i].roll != -1){
               i  = (i+1) % size;
            }
            arr[i].roll = roll;
            arr[i].name = name;
            arr[i].marks = marks;

            
            while(arr[index].chain != -1){
                index = arr[index].chain;
            }
            arr[index].chain = i;
        }
    }

    void display(){
        cout<<"Name\tRoll\tMarks\tChain"<<endl;
        for(int i =0;i<size;i++){
            cout<<arr[i].name<<"\t"<<arr[i].roll<<"\t"<<arr[i].marks<<"\t"<<arr[i].chain<<endl;
        }
    }

};
int main(){
hashtable h(10);
h.insert(3,"Parth",89);
h.insert(23,"sahil",55);
h.insert(57,"hitewsh",24);
h.insert(24,"mahendra",12);
h.insert(11,"sumit",31);
h.insert(90,"rakesh",32);
h.display();

return 0;
}