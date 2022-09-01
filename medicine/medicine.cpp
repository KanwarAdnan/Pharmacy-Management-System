#include "medicine.h"
#include <cstring>
#include <iomanip>
#include <fstream>

void Medicine::add(){

    /* Temporary Variables for both strings and ints
     * We used getline function for taking strings as input 
     * and used cin for taking intgers.
     * Only first 32 characters for strings will be counted
    */

    string tempString;
    int tempInt;

    cout << "\nAdd Medicine\n\n"; // Function Name Message

    cout << "\nMedicine Name : ";
    getline(cin,tempString);

    // Adding Value to Name
    data[count].name = tempString.substr(0,32); // Only first 32 characters

    cout << "\nCompany Name : ";
    getline(cin,tempString);

    // Adding Value to Company
    data[count].company = tempString.substr(0,32);

    cout << "\nPrice : ";
    cin >> tempInt;
    cin.ignore(); // Using because we don't want errors

    // Adding Value to price
    data[count].price = tempInt;

    cout << "\nQuantity : ";
    cin >> tempInt;
    cin.ignore(); // Using because we don't want errors

    // Adding Value to Quantity
    data[count].quantity = tempInt;

    // Assigning Unique Id to Medicine

    if (count == 0){
        data[0].id = 1;
    } else{
        // ID OF THE LAST (Medicine + 1) because last will be largest id, as it's sorted
        data[count].id = (data[count - 1].id) + 1;
    }

    // Incrementing the count
    count++;

    clear();

    cout << "\nAdded !!!\n\n";
    pause();

    // Calling the storeData Function
    storeData();

    clear();
}

void Medicine::search(){
    int id; // Local Temporary Variable
    int searchId;

    cout << "\nSearch Medicine\n\n";

    // Asking Id
    cout << "\nEnter Id : ";
    cin >> id;
    cin.ignore();

    // Here we called the isId function to search the entered id and performed our task!
    if (isId(id,&searchId)){
        clear();
        cout << "\nSearch Result\n\n";
        showId(searchId);
        cout << "\n\n";
        pause();
    }
    else {
        clear();
        cout << "\nId not found try again !\n\n";
        pause();
        search(); // Calling the search function again
    }

}

void Medicine::show(){
    // Displaying all the stored data in Decent way
    clear();
    cout << setw(8) << left << "SR.#" << setw(8) << left << "ID" << setw(40) << left << "MEDICINE NAME" << setw(40) << left << "COMPANY" << setw(16) << left << "QUANTITY"  << setw(16) << left << "PRICE" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < count; i++){
        cout << setw(8) << left << (i+1) << setw(8) << left << data[i].id << setw(40) << left << data[i].name << setw(40) << left << data[i].company  << setw(16) << left << data[i].quantity << setw(16) << left << data[i].price << endl;
    }
    cout << "\n\n";
    pause();
}

void Medicine::showId(int i){
    // Displaying the data of specific id
    cout << setw(8) << left << "ID" << setw(40) << left << "MEDICINE NAME" << setw(40) << left << "COMPANY" << setw(16) << left << "QUANTITY"  << setw(16) << left << "PRICE" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(8) << left << data[i].id << setw(40) << left << data[i].name << setw(40) << left << data[i].company  << setw(16) << left << data[i].quantity << setw(16) << left << data[i].price << endl;
}

// Storing Data
void Medicine::storeData(){
    ofstream file;
    ofstream file2;
    //system("MD data"); // Making data folder if not exists

    file.open("data\\medicines.csv");
    if (file.is_open()){
        for (int i = 0; i < count; i++){
            file << data[i].id << ",";
            file << data[i].name << ",";
            file << data[i].company << ",";
            file << data[i].price << ",";
            file << data[i].quantity << "\n";
        }
        file.close();
    }

    file2.open("data\\purchases.csv");
    if (file2.is_open()){
        for (int i = 0; i < pCount; i++){
            file2 << pData[i].id << ",";
            file2 << pData[i].medId << ",";
            file2 << pData[i].name << ",";
            file2 << pData[i].price << ",";
            file2 << pData[i].quantity << ",";
            file2 << pData[i].day << ",";
            file2 << pData[i].month << ",";
            file2 << pData[i].year << "\n";
        }
        file2.close();
    }

}


// Loading Data
void Medicine::loadData(){
    ifstream file;
    ifstream file2;
    string temp;

    file.open("data\\medicines.csv");

    if (file.is_open()){
        while (getline(file, temp)){
            string *ptr = split(temp);
            data[count].id = stoi(ptr[0]);
            data[count].name = ptr[1];
            data[count].company = ptr[2];
            data[count].price = stoi(ptr[3]);
            data[count].quantity = stoi(ptr[4]);
            count++;
        }
        file.close();
    }

    file2.open("data\\purchases.csv");

    if (file2.is_open()){
        while (getline(file2, temp)){
            string *ptr = split(temp);
            pData[pCount].id = stoi(ptr[0]);
            pData[pCount].medId = stoi(ptr[1]);
            pData[pCount].name = ptr[2];
            pData[pCount].price = stoi(ptr[3]);
            pData[pCount].quantity = stoi(ptr[4]);
            pData[pCount].day = stoi(ptr[5]);
            pData[pCount].month = stoi(ptr[6]);
            pData[pCount].year = stoi(ptr[7]);
            pCount++;
        }
        file2.close();
    }
}


void Medicine::update(){
    int id; // Local Temporary Variable
    int searchId;
    int tempInt;
    string tempString;

    cout << "\nUpdate Medicine\n\n";

    // Asking Id
    cout << "\nEnter Id : ";
    cin >> id;
    cin.ignore();

    // Here we called the isId function to search the entered id and performed our task!
    if (isId(id,&searchId)){
        clear();
        showId(searchId);
        cout << "\n\n";
        pause();

        cout << "\nNew Information\n\n";

        // Add Function

        cout << "\nMedicine Name : ";
        getline(cin,tempString);

        // Updating Medicine Name
        data[searchId].name = tempString.substr(0,32); // Only first 32 characters

        cout << "\nCompany Name : ";
        getline(cin,tempString);

        // Updating Company Name
        data[searchId].company = tempString.substr(0,32);

        cout << "\nPrice : ";
        cin >> tempInt;
        cin.ignore(); // Using because we don't want errors

        // Updating price
        data[searchId].price = tempInt;

        cout << "\nQuantity : ";
        cin >> tempInt;
        cin.ignore(); // Using because we don't want errors

        // Updating Quantity
        data[searchId].quantity = tempInt;

        // Calling the store data
        storeData();

        clear();
        cout << "\nUpdated !!!\n\n";
        pause();
    }
    else {
        clear();
        cout << "\nId not found try again !\n\n";
        pause();
        update(); // Calling the function again
    }

}

void Medicine::delete_(){
    clear();
    int id; // Local Temporary Variable
    int searchId;
    char choice;

    cout << "\nDelete Medicine\n\n";

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
                data[i].company = data[i+1].company;
                data[i].price = data[i+1].price;
                data[i].quantity = data[i+1].quantity;
            }
        }

        // Decrementing the count, because we deleted
        count--;
        clear();
        cout << "\nDeleted !!!\n\n";
        pause();
    }
    else {
        clear();
        cout << "\nId not found try again !\n\n";
        pause();
        delete_(); // Calling the delete function again
    }
   
}

void Medicine::menu(){
    int temp;
    while (true)
    {
        clear();

        cout << "\nMEDICINES TAB\n";
        cout << "\n1) ADD ";
        cout << "\n2) UPDATE ";
        cout << "\n3) DELETE";
        cout << "\n4) SEARCH";
        cout << "\n5) DISPLAY";
        cout << "\n6) PURCHASE";
        cout << "\n7) EXIT";

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
            purchase();
            system("cls");
            break;
        case 7:
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

void Medicine::purchase(){
    // Variables
    int year,month,day,temp,temp2,price;
    int id,searchId;

    string year_;

    // Getting Current Date
    time_t now=time(0);
    tm *today = localtime(&now);

    // Extracting the day,month,year

    // Slicing Year and converting again to Int
    year = today -> tm_year;
    year_ = to_string(year);
    year_ = year_.substr(1); // 1th index to end
    year = stoi(year_);

    // month
    month = today -> tm_mon;
    month += 1;

    // day
    day = today -> tm_mday;

    cout << "\nEnter Medicine Id : ";
    cin >> id;
    cin.ignore();

    // Here we called the isId function to search the entered id and performed our task!
    if (isId(id,&searchId)){
        clear();
        showId(searchId);

        cout << "\nEnter Quantity : ";
        cin >> temp2;
        price = data[searchId].price;
        if (temp2 <= data[searchId].quantity){
            cout << "\nYou purchased " << temp2 << " For Rs. " << (price*temp2) << " ";

            // Subtracting the quantity from purchase quantity

            data[searchId].quantity = data[searchId].quantity-temp2;

            // Updating the PurchaseData Structure

            pData[pCount].day = day;
            pData[pCount].month = month;
            pData[pCount].year = year;

            // Writing the id Of Medicine using it's data
            pData[pCount].medId = data[searchId].id;
            
            // Saving current price for further use
            pData[pCount].price = price;

            pData[pCount].quantity = temp2;

            pData[pCount].name = data[searchId].name;

            // Assigning Unique Id to Purchase
            if (pCount == 0){
                pData[0].id = 1;
            } else {
                // ID OF THE LAST (Purchase + 1) because last will be largest id, as it's sorted
                pData[pCount].id = (pData[pCount - 1].id) + 1;
            }

            // Bill
            clear();
            cout << "\nDate : ";
            cout << pData[pCount].day << "/";
            cout << pData[pCount].month << "/";
            cout << pData[pCount].year << endl;
            cout << "Med Name : " << pData[pCount].name << endl;
            cout << "Med Price : " << pData[pCount].price << endl;
            cout << "Quantity " << pData[pCount].quantity << endl;

            cout << "Selling Amount : Rs. " << (pData[pCount].quantity * pData[pCount].price) << endl;
            pCount++;
            // saving the changes
            storeData();
            cout << "\n\n";
            pause();
            clear();

        }
    }
}

void Medicine::showPurchases(){
    string date;
    string name;
    int ID;
    clear();
    cout << setw(8) << left << "SR.#" << setw(8) << left << "ID" << setw(40) << left << "MEDICINE NAME" << setw(16) << left << "PRICE" << setw(16) << left << "QUANTITY"  << setw(40) << left << "DATE" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < pCount; i++){
        date = to_string(pData[i].day) + "/" + to_string(pData[i].month) + "/" + to_string(pData[i].year);
        if (isId(pData[i].medId,&ID))
            name = data[ID].name;
        cout << setw(8) << left << (i+1) << setw(8) << left << pData[i].id << setw(40) << left << name << setw(16) << left << pData[i].price  << setw(16) << left << pData[i].quantity << setw(40) << left << date << endl;
    }
    cout << "\n\n";
    pause();
}

void Medicine::printPurchaseHeader(){
    cout << setw(8) << left << "ID" << setw(40) << left << "MEDICINE NAME" << setw(16) << left << "PRICE" << setw(16) << left << "QUANTITY"  << setw(40) << left << "DATE" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;

}

void Medicine::showPurchaseId(int i){
    string date;
    string name;
    int ID;
    int ID2;
    if (isIdP(i,&ID2)){
        date = to_string(pData[ID2].day) + "/" + to_string(pData[ID2].month) + "/" + to_string(pData[ID2].year);
    }
    if (isId(pData[ID2].medId,&ID)){
        name = data[ID].name;
    }

    cout << setw(8) << left << pData[ID2].id << setw(40) << left << name << setw(16) << left << pData[ID2].price  << setw(16) << left << pData[ID2].quantity << setw(40) << left << date << endl;

}

void Medicine::printPurchaseHeaderWD(){
    cout << setw(8) << left << "SR.#" << setw(8) << left << "ID" << setw(40) << left << "MEDICINE NAME" << setw(16) << left << "PRICE" << setw(16) << left << "QUANTITY" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
}
/*
void Medicine::showPurchaseIdWD(int ID2,int sr){
    string date;
    string name;
    int ID;
    date = to_string(pData[ID2].day) + "/" + to_string(pData[ID2].month) + "/" + to_string(pData[ID2].year);
    if (isId(pData[ID2].medId,&ID)){
        name = data[ID].name;
    }

    cout << setw(8) << left << sr << setw(8) << left << pData[ID2].id << setw(40) << left << name << setw(16) << left << pData[ID2].price  << setw(16) << left << pData[ID2].quantity << endl;

}
*/
void Medicine::showPurchaseIdWD(int i,int sr){
    string date;
    string name;
    int ID;
    int ID2;
    
    if (isIdP(i,&ID2)){
    date = to_string(pData[ID2].day) + "/" + to_string(pData[ID2].month) + "/" + to_string(pData[ID2].year);
    }
    /*
    if (isId(pData[ID2].medId,&ID)){
        name = data[ID].name;
    }
    */
    name = pData[ID2].name;
    cout << setw(8) << left << sr << setw(8) << left << pData[ID2].id << setw(40) << left << name << setw(16) << left << pData[ID2].price  << setw(16) << left << pData[ID2].quantity << endl;

}
