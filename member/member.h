#include <iostream>
using namespace std;


class Employee{
    private:
        struct Data{
            int id,salary;
            string name,password;
        };

        Data data[100];
        int count;

    public:
        Employee(){
            count = 0;
            loadData();
        }

        void menu();
        void add();
        void update();
        void delete_();
        void search();  
        void show();    // It will display all the data
        void showId(int id); //It will display information using id

        void storeData(); // It will store data as csv
        void loadData(); // It will load csv into program

        /*  This function will search through all the data structure
            to find the required id if not found it will return false
            and there will be no id in pointer

            how to use:
                if (isId(id,&Var)){
                    // Defination
                }
                else {
                    cout << "\nNo Match Found !!";
                }
        */

        bool isId(int id, int *ID){
            for (int i = 0; i < count; i++){
                if (id == data[i].id){
                    *ID = i;
                    return true;
                }
            }
            return false;
        }
    int getCount() { return this->count; }
    void setCount(int count) { this->count = count; }
};