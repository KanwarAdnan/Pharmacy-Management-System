#include "sales.h"

void Sales::display(){
    med.showPurchases();
}

void Sales::seeToday(){
	int temp;

	int year,month,day,count=0,totalSales=0;
	    int indexs[100];
    	int index = 0;
	string year_;
	string date;

	time_t now= time(0);
	tm *today = localtime(&now);

	year = today -> tm_year;

	// Removing 1 from the year

	year_ = to_string(year);
	year_ = year_.substr(1); // 1th index to end

	year = stoi(year_);

	month = today -> tm_mon;
    month +=1 ;
	day = today -> tm_mday;

	for(int i = 0 ; i < med.pCount ; i++){
		if ((med.pData[i].month == month ) && (med.pData[i].year == year ) && (med.pData[i].day == day )){
            indexs[index] = i;
            index++;
			count++;
			totalSales = totalSales + med.pData[i].price*med.pData[i].quantity;
		}
	}
    if (totalSales > 0){
        cout << "\nDisplaying Purchase History of Date : " << (to_string(day) + "/" + to_string(month) + "/" + to_string(year)) + "\n\n";
        med.printPurchaseHeaderWD();
        for(int i = 0 ; i < index ; i++){
            med.showPurchaseIdWD(med.pData[indexs[i]].id,(i+1));
        }
    	cout << "\nSelling Amount : Rs. " << totalSales << endl;
    }
    else {
        cout << "\nNo Records Found !!!\n\n";
        pause();
    }

}

void Sales::seeDate(){
	int temp;
    int indexs[100];
    int index = 0;

	cout << "\nSee Date\n\n";

	int year,month,day,totalSales=0;

	cout << "\nEnter Day : ";
	cin >> day;
	cout << "\nEnter Month : ";
	cin >> month;
	cout << "\nEnter Year : ";
	cin >> year;
    clear();

    cout << "\nDisplaying Purchase History of Date : " << (to_string(day) + "/" + to_string(month) + "/" + to_string(year)) + "\n\n";
    med.printPurchaseHeaderWD();
	for(int i = 0 ; i < med.pCount ; i++){
		if ((med.pData[i].day == day ) && (med.pData[i].month == month ) && (med.pData[i].year == year )){
            indexs[index] = i;
            index++;
            med.showPurchaseIdWD(med.pData[indexs[i]].id,(i+1));
			totalSales = totalSales + med.pData[i].price*med.pData[i].quantity;
            //cout << i << " : " << med.pData[i].price << " : " << med.pData[i].quantity << endl;
		}
	}
    cout << "\nSelling Amount : Rs. " << totalSales << endl;
    /*
    pause();
    if (totalSales > 0){
        cout << "\nDisplaying Purchase History of Date : " << (to_string(day) + "/" + to_string(month) + "/" + to_string(year)) + "\n\n";
        med.printPurchaseHeaderWD();
        for(int i = 0 ; i < index ; i++){
            med.showPurchaseIdWD(med.pData[indexs[i]].id,(i+1));
        }
        cout << "\nSelling Amount : Rs. " << totalSales << endl;
    }
    else {
        cout << "\nNo Records Found !!!\n\n";
        pause();
    }
    */
}

void Sales::menu(){
    int temp;
    while (true)
    {
        clear();

        cout << "\nSALES TAB\n";
        cout << "\n1) DISPLAY ALL ";
        cout << "\n2) SEE TODAY ";
        cout << "\n3) SEE DATE";
        cout << "\n4) EXIT";

        cout << "\n\nSELECT AN OPTION : ";
        cin >> temp;

        cin.ignore();
        clear();
        switch (temp)
        {
        case 1:
            display();
            clear();
            break;
        case 2:
            clear();
            seeToday();
            pause();
            clear();
            break;
        case 3:
            clear();
            seeDate();
            pause();
            clear();
            break;
        case 4:
            clear();
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