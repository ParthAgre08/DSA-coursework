#include<iostream>
using namespace std;

const int size = 10;
int table1[size];
int table2[size];

void initialize(){
    for(int i=0;i<size;i++){
        table1[i] = table2[i] = -1;
    }
}

int h1(int key){
return key%size;
}
int h2(int key){
return (key/size)%size;
}

void insert(int key){
int count=0;
while(count<size){
    int pos1 = h1(key);
    if(table1[pos1] == -1){
        table1[pos1] = key;
        return;
    }
    int temp = table1[pos1];
    table1[pos1] = key;
    int pos2 = h2(temp);
    if(table2[pos2] ==-1){
        table2[pos2] = temp;
        return;
    }
    count ++;
    key = temp;
}
}
void display(){
    cout<<"Hash table 1 "<<endl;
    for(int i=0;i<size;i++){
        cout<<table1[i]<<endl;
    }
    cout<<"\n\n";
    cout<<"Hash table 1 "<<endl;
    for(int i=0;i<size;i++){
        cout<<table2[i]<<endl;
    }
}
int main(){
initialize();
int arr[] ={20, 50, 53, 75, 100};
for(int i=0;i<5;i++){
    insert(arr[i]);
}

display();
return 0;
}