#include <iostream>
using namespace std;


class Medicine{
    public:

        struct Data{
            int id,price,quantity;
            string name,company;
        };

        Data data[100];
        int count;

        struct PurchaseData{
            int id,medId;
            int day,month,year,quantity,price;
            string name;
        };

        PurchaseData pData[100];
        int pCount;


	// Methods

        Medicine(){
            count = 0;
            pCount = 0;
            loadData();
        }

        void menu();
        void add();
        void update();
        void delete_();
        void search();  
        void show();    // It will display all the data
        void showId(int id); //It will display information using id
        void purchase();
        void showPurchases();
        void showPurchaseId(int id);
        void printPurchaseHeader();
        void showPurchaseIdWD(int id,int sr);
        void printPurchaseHeaderWD();

        void storeData(); // It will store data as csv
        void loadData(); // It will load csv into program

        /*  This function will search through all the data structure
            to find the required id if not found it will return false
            and there will be no id in pointer

            how to use:
                if isId(id,&Var){
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

        // It's used to search id in Purchase Structure

        bool isIdP(int id, int *ID){
            for (int i = 0; i < count; i++){
                if (id == pData[i].id){
                    *ID = i;
                    return true;
                }
            }
            return false;
        }
    int getCount() { return this->count; }
    void setCount(int count) { this->count = count; }
    int getPCount() { return this->pCount; }
    void setPCount(int pCount) { this->pCount = pCount; }};