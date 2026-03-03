        #include <iostream>
        using namespace std;

        // const int size = 10;
        // int arr[10];

        class hashtable
        {
        public:
            int size;

            int *arr;

            hashtable(int s)
            {
                size = s;
                arr = new int[size];
            }

            void initialize()
            {
                for (int i = 0; i < size; i++)
                {
                    arr[i] = -1;
                }
            }
            int hashfunction(int key)
            {
                return key % size;
            }
            void insert(int key)
            {
                int index = hashfunction(key);
                for (int i = 0; i < size; i++)
                {
                    if (arr[index] == -1)
                    {
                        arr[index] = key;
                        break;
                    }
                    index = (index + 1) % size;
                }
            }

            void display()
            {
                for (int i = 0; i < size; i++)
                {
                    cout << i << " : " << arr[i] << endl;
                }
            }
        };

        int main()
        {
            hashtable h(10);
            h.initialize();
            h.insert(13);
            h.insert(64);
            h.insert(31);
            h.insert(14);
            h.insert(33);
            h.insert(64);
            h.display();
            return 0;
        }