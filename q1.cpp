    // Implement C++ program for storing and accessing students record which will include student roll number, name and marks using linear probing with chaining without replacement with the help of hash table data structure.

    #include <iostream>
    using namespace std;

    class Student
    {

    public:
        int roll;
        string name;
        int marks;
        int chain;

        Student()
        {
            roll = -1;
            name = " ";
            marks = 0;
            chain = -1;
        }
    };

    class hashtable
    {
        int size;
        Student * arr;

        public:
            hashtable(int s){
            size = s;
            arr = new Student[size];
            }


            int hashfunction(int key){
                return key%size;
            }
        void insert(int roll, string name, int marks)
    {
        int start = hashfunction(roll);   // original hash index
        int index = start;

        // Case 1: Empty slot at hash index
        if(arr[index].roll == -1)
        {
            arr[index].roll = roll;
            arr[index].name = name;
            arr[index].marks = marks;
            return;
        }

        // Case 2: Collision

        int i = index;

        // Find empty slot using linear probing
        while(arr[i].roll != -1)
            i = (i + 1) % size;

        // Store record at empty location
        arr[i].roll = roll;
        arr[i].name = name;
        arr[i].marks = marks;

        // Now attach to correct chain
        int temp = start;

        // Move to last element of SAME hash group
        while(arr[temp].chain != -1)
            temp = arr[temp].chain;

        arr[temp].chain = i;
    }

            void display(){
                cout<<"Name\tRoll\tMarks\tChain"<<endl;
                for(int i=0;i<size;i++){
                cout<<arr[i].name<<"\t"<<arr[i].roll<<"\t"<<arr[i].marks<<"\t"<<arr[i].chain<<endl;

                }
            }



    };
    int main()
    {
    hashtable h(10);
    h.insert(3,"Parth",96);
    h.insert(4,"Pranali",90);
    h.insert(32,"Sarvesh",75);
    h.insert(13,"Sarthak",85);
    h.insert(65,"Harsh",68);
    h.insert(23,"sahil",58);
    h.display();
        return 0;
    }