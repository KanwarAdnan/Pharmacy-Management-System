#include "stocks.h"

void Stocks::import(){
	char temp;

	while (true){
        clear();
        med.add();
        cout << "\nDo you want to add more Medicines ? (y for yes) : ";
        cin >> temp;
        cin.ignore();
        if ( (temp == 'y') || (temp == 'Y') )
        {
			continue;
		}
        else {
            break;
        }

	}
    clear();
	cout << "\nDone Importing ... !!!\n\n";
    pause();
}

void Stocks::export_(){
	char temp;

	while (true){
        clear();
        med.purchase();
        cout << "\nDo you want to export more Medicines ? (y for yes) : ";
        cin >> temp;
        cin.ignore();
        if ( (temp == 'y') || (temp == 'Y') )
        {
			continue;
		}
        else {
            break;
        }

	}
    clear();
	cout << "\nDone Exporting ... !!!\n\n";
    pause();

}

/*

void Stocks::export_(){
	int temp = 1,temp2 = 0,count = 0,totalBill = 0,searchId;
	cout << "\nExport Stock\nEnter -1 to Exit\nPress Enter to Continue exporting ... !!! \n\n";
	getchar();

	while (true){
        clear();
		cout << "\nPress -1 to Exit\n\n";
		cout << "\nMedicine Id : ";
		cin >> temp;
		if (temp == -1){
			break;
		}

		if (med.isId(temp,&searchId)){
			med.showId(searchId);

			cout << "\nMedicine Quantity : ";
			cin >> temp2;
			if (temp2 == -1){
				break;
			}

			else if (temp2 <= med.data[searchId].quantity){
				med.data[searchId].quantity = med.data[searchId].quantity-temp2;
                med.storeData();
				count++;
				totalBill += (temp2*med.data[searchId].price);
			}
			else {
				clear();
				cout << "\nCant Purchase This medicine !";
				cout << "\n\n";
				pause();
			}
		}
	}
    clear();
	cout << "\nYou Exported Medicines for Rs. " << totalBill << endl;
    pause();
}

*/
void Stocks::menu(){
    int temp;
    while (true)
    {
        clear();

        cout << "\nSTOCKS TAB\n";
        cout << "\n1) IMPORT ";
        cout << "\n2) EXPORT ";
        cout << "\n3) EXIT";

        cout << "\n\nSELECT AN OPTION : ";
        cin >> temp;

        cin.ignore();
        clear();
        switch (temp)
        {
        case 1:
            import();
            system("cls");
            break;
        case 2:
            export_();
            system("cls");
            break;
        case 3:
            system("cls");
            goto End;
            break;
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