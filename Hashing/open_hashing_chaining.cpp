#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int d){
        data = d;
        next = NULL;
    }

};

class hashtable{
    int size;
    Node ** table;
    public:
    hashtable(int s){
        size = s;
        table = new Node*[size];

         // initialize all buckets as empty
        for (int i =0;i<size;i++){
            table[i] = NULL;
        }
    }

    int  hashfunction(int key){
        return key%size;
    }

    void insert(int key){
        int index = hashfunction(key);
        Node * newNode  = new Node(key);
        if(table[index] == NULL){
            table[index] = newNode;  
        }
        else{
                // insert at beginning
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    void display(){

        cout<<"Index : Data"<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<" : ";
            Node * temp = table[i];
            while(temp != NULL){
                    cout<<temp->data<<" -> ";
                    temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }

};
int main(){
hashtable h(10);
h.insert(22);
h.insert(52);
h.insert(45);
h.insert(97);
h.insert(27);
h.insert(36);
h.insert(75);
h.display();
return 0;
}