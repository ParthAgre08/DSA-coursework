// Implement C++ program for storing and accessing Employee record which will include
// employee id, name, and salary using linear probing with chaining without replacement
// with the help of hash table data structure.

#include <iostream>
using namespace std;
class Employee
{
public:
    int emp_id;
    string name;
    float salary;
    int chain;

    Employee()
    {
        emp_id = -1;
        name = " ";
        salary = 0.0;
        chain = -1;
    }
};

class hashtable
{
    public:
    int size;
    Employee *arr;

    hashtable(int s)
    {
        size = s;
        arr = new Employee[size];
    }

    int hashfunction(int key)
    {
        return key % size;
    }

    void insert(int emp_id, string name, float salary)
    {
        int index = hashfunction(emp_id);
        if (arr[index].emp_id == -1)
        {
            arr[index].emp_id = emp_id;
            arr[index].name = name;
            arr[index].salary = salary;
        }
        else
        {
            int i = index;

            while (arr[i].emp_id != -1)
            {
                i = (i + 1) % size;
            }
            arr[i].emp_id = emp_id;
            arr[i].name = name;
            arr[i].salary = salary;

            //creating chaning 
            while(arr[index].chain  != -1){
                index = arr[index].chain;
            }
            arr[index].chain = i;
        }
    }

    void display(){
        cout<<"Name\tID\tSalary\tchain"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i].name<<"\t"<<arr[i].emp_id<<"\t"<<arr[i].salary<<"\t"<<arr[i].chain<<endl;
        }
    }
};
int main()
{
hashtable h(10);
h.insert(32,"Parth",75000);
h.insert(33,"Pranali",42003);
h.insert(86,"Sarvesh",13331);
h.insert(18,"Virat",100000);
h.insert(57,"Mahi",12232);
h.insert(75,"Sumit",50000);
h.insert(29,"Soham",23440);
h.insert(22,"Mahesh",70221);
h.insert(87,"Lokesh",68099);
h.insert(67,"pravin",32453);

h.display();
    return 0;
}