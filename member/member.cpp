#include "member.h"
#include <cstring>
#include <iomanip>
#include <fstream>

void Employee::add(){

    /* Temporary Variables for both strings and ints
     * We used getline function for taking strings as input 
     * and used cin for taking intgers.
     * Only first 32 characters for strings will be counted
    */

    string tempString;
    int tempInt;

    cout << "\nAdd Employee\n\n"; // Function Name Message

    cout << "\nEmployee Name : ";
    getline(cin,tempString);

    // Adding Value to Name
    data[count].name = tempString.substr(0,32); // Only first 32 characters

    cout << "\nPassword : ";
    getline(cin,tempString);

    // Adding Value to password
    data[count].password = tempString;

    cout << "\nSalary : ";
    cin >> tempInt;
    cin.ignore(); // Using because we don't want errors

    // Adding Value to Salary
    data[count].salary = tempInt;

    // Assigning Unique Id to Employee

    if (count == 0){
        data[0].id = 1;
    } else{
        // ID OF THE LAST (Employee + 1) because last will be largest id, as it's sorted
        data[count].id = (data[count - 1].id) + 1;
    }

    // Incrementing the count
    count++;

    clear();

    cout << "\nAdded !!!";
    pause();

    // Calling the storeData Function
    storeData();

    clear();
}

void Employee::search(){
    int id; // Local Temporary Variable
    int searchId;

    cout << "\nSearch Employee\n\n";

    // Asking Id
    cout << "\nEnter Id : ";
    cin >> id;
    cin.ignore();

    // Here we called the isId function to search the entered id and performed our task!
    if (isId(id,&searchId)){
        clear();
        cout << "\nSearch Result\n\n";
        showId(searchId);
        pause();
    }
    else {
        clear();
        cout << "\nId not found try again !";
        pause();
        search(); // Calling the search function again
    }

}

void Employee::show(){
    // Displaying all the stored data in Decent way
    clear();
    cout << setw(8) << left << "SR.#" << setw(8) << left << "ID" << setw(40) << left << "EMPLOYEE NAME" << setw(40) << left << "SALARY" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < count; i++){
        cout << setw(8) << left << (i+1) << setw(8) << left << data[i].id << setw(40) << left << data[i].name << setw(40) << left << data[i].salary << endl;
    }
    pause();
}

void Employee::showId(int i){
    // Displaying the data of specific id
    cout << setw(8) << left << "ID" << setw(40) << left << "EMPLOYEE NAME" << setw(40) << left << "SALARY" << setw(40) << left << "PASSWORD" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(8) << left << data[i].id << setw(40) << left << data[i].name << setw(40) << left << data[i].salary << setw(40) << left << data[i].password << endl;
}

// Storing Data
void Employee::storeData()
{
    ofstream file;
    system("MD data"); // Making data folder if not exists

    file.open("data\\Employees.csv");
    if (file.is_open()){
        for (int i = 0; i < count; i++){
            file << data[i].id << ",";
            file << data[i].name << ",";
            file << data[i].password << ",";
            file << data[i].salary << "\n";
        }
        file.close();
    }
}

// Loading Data
void Employee::loadData()
{
    ifstream file;
    string temp;

    file.open("data\\Employees.csv");

    if (file.is_open()){
        while (getline(file, temp)){
            string *ptr = split(temp);
            data[count].id = stoi(ptr[0]);
            data[count].name = ptr[1];
            data[count].password = ptr[2];
            data[count].salary = stoi(ptr[3]);
            count++;
        }
        file.close();
    }
}


void Employee::update(){
    int id; // Local Temporary Variable
    int searchId;
    int tempInt;
    string tempString;

    cout << "\nUpdate Employee\n\n";

    // Asking Id
    cout << "\nEnter Id : ";
    cin >> id;
    cin.ignore();

    // Here we called the isId function to search the entered id and performed our task!
    if (isId(id,&searchId)){
        clear();
        cout << "\nSearch Result\n\n";
        showId(searchId);
        pause();

        cout << "\nNew Information\n\n";

        // Add Function

        cout << "\nEmployee Name : ";
        getline(cin,tempString);

        // Adding Value to Name
        data[searchId].name = tempString.substr(0,32); // Only first 32 characters

        cout << "\nPassword : ";
        getline(cin,tempString);

        // Adding Value to password
        data[searchId].password = tempString;

        cout << "\nSalary : ";
        cin >> tempInt;
        cin.ignore(); // Using because we don't want errors

        // Adding Value to Salary
        data[searchId].salary = tempInt;

        // Calling the store data
        storeData();

        clear();
        cout << "\nUpdated !!!";
        pause();
    }
    else {
        clear();
        cout << "\nId not found try again !";
        pause();
        update(); // Calling the function again
    }

}

void Employee::delete_(){
    int id; // Local Temporary Variable
    int searchId;
    char choice;

    cout << "\nDelete Employee\n\n";

    // Asking Id
    cout << "\nEnter Id : ";
    cin >> id;
    cin.ignore();

    // Here we called the isId function to search the entered id and performed our task!
    if (isId(id,&searchId)){
        showId(searchId);
        cout << "\n\nAre you sure you want to delete ? Press y to delete : ";
        cin >> choice;
        if ( (choice == 'y') || (choice != 'Y') ){
            for(int i = searchId ; i < count ; i++){
                data[i].id = data[i+1].id;
                data[i].name = data[i+1].name;
                data[i].password = data[i+1].password;
                data[i].salary = data[i+1].salary;
            }
        }

        // Decrementing the count, because we deleted
        count--;
        clear();
        cout << "\nDeleted !!!\n\n";
        pause();
    }
   
}

void Employee::menu(){
    int temp;
    while (true)
    {
        clear();

        cout << "\nEMPLOYEES TAB\n";
        cout << "\n1) ADD ";
        cout << "\n2) UPDATE ";
        cout << "\n3) DELETE";
        cout << "\n4) SEARCH";
        cout << "\n5) DISPLAY";
        cout << "\n6) EXIT";

        cout << "\n\nSELECT AN OPTION : ";
        cin >> temp;

        cin.ignore();
        clear();
        switch (temp)
        {
        case 1:
            add();
            storeData();
            system("cls");
            break;
        case 2:
            update();
            storeData();
            system("cls");
            break;
        case 3:
            delete_();
            storeData();
            system("cls");
            break;
        case 4:
            search();
            system("cls");
            break;
        case 5:
            show();
            system("cls");
            break;
        case 6:
            system("cls");
            storeData();
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