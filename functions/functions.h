#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void clear(){
	system("cls");
}

void pause(){
	system("pause");
}

void _upper(string& arr){
    for(int i = 0 ; i < arr.length() ; i++){
        arr[i] = toupper(arr[i]);
    }
}

int elementCount(string& arr,char character,int size){
    int count = 0;
    for(int i = 0 ; i < size ; i++){
        if (arr[i]==character){
            count++;
        }
    }
    return count;
}

string *split(string line, char separator = ',')
{

    // used to find the element count for array

    int frequency = 0, count = 0;

    while (line[count] != '\0')
    {
        if (line[count] == separator)
        {
            frequency++;
        }
        count++;
    }

    string *arr = new string[frequency + 1];
    string temp;

    int index = 0; // index for array

    istringstream iss(line);

    while (iss.good())
    {
        getline(iss, temp, separator); // slicing information :D
        arr[index] = temp;
        index++;
    }

    return arr;
}