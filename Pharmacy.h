#include "functions\functions.h"
#include "medicine\medicine.cpp"
#include "member\member.cpp"
#include "stocks\stocks.cpp"
#include "sales\sales.cpp"

class Pharmacy{
    private:
        int id; static int uid;
        string name,address,owner;

        Medicine med;
        Employee mem;
        Stocks stock;
        Sales sale;
    public:
        Pharmacy(string name = "ABC Medical Pharmacy" , string address = "Lahore" , string owner = "KANWAR ADNAN" ){
            setName(name);
            setAddress(address);
            setOwner(owner);
            uid++;
            id = uid;
        }

        void menu();

        // Getters & Setters
        int getId()         {return id;}
        string getName()    {return name;}
        string getAddress() {return address;}
        string getOwner()   {return owner;}

        void setName(string name)       { this -> name = name;}
        void setAddress(string address) { this -> address = address;}
        void setOwner(string owner)     { this -> owner = owner;} 

};


void Pharmacy::menu(){
    int temp;
    while (true)
    {
        clear();

        cout << "\nMENU\n";
        cout << "\n1) MEDICINES ";
        cout << "\n2) MEMBERS ";
        cout << "\n3) SALES";
        cout << "\n4) STOCKS";
        cout << "\n5) LOGIN";
        cout << "\n6) EXIT";

        cout << "\n\nSELECT AN OPTION : ";
        cin >> temp;

        cin.ignore();
        clear();
        switch (temp)
        {
        case 1:
            med.setCount(0);
            med.setPCount(0);
            med.loadData();
            med.menu();
            med.storeData();
            system("cls");
            break;
        case 2:
            mem.setCount(0);
            mem.loadData();
            mem.menu();
            mem.storeData();
            system("cls");
            break;
        case 3:
            sale.med.setCount(0);
            sale.med.setPCount(0);
            sale.med.loadData();
            sale.menu();
            system("cls");
            break;
        case 4:
            stock.med.setCount(0);
            stock.med.setPCount(0);
            stock.med.loadData();
            stock.menu();
            system("cls");
            break;
        case 5:
            system("cls");
            break;
        case 6:
            system("cls");
            goto End;
        case -1:
            goto End;
        default:
            system("cls");
            cout << "\nExiting Due to bad input! \n\n";
            system("pause");
            exit(0);
        }
    }
End:
    cout << "\n";    
}