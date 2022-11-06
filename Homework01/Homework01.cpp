// Samneet Singh Homework01

#include<iostream>
#include<fstream>
using namespace std;

// Read the data from file to the array, 
// return the num of items read
int readData( int * myArray, const char * pfilename) {
    
    fstream myfile;
    myfile.open(pfilename);

    int arr[100];
    int i = 0;
    int x;

    // loop to size the array
    while (myfile >> x) {
        i++;
    }
    
    int arrSize = i;

    myfile.close();
    
    return arrSize;
}

// Sort the array by either bubble or Selection sort
void sortArray( int * pdata, int count) {

    int i;
    for (i = 0; i < count - 1; i++)
 
        // Last i elements are already in place
        for (int z = 0; z < count - i - 1; z++)
            if (pdata[z] > pdata[z + 1])
                swap(pdata[z], pdata[z + 1]);
    return;
}

// Find the index of the provided target in the array. 
// return the index or -1 if not found
int  findData( const int * myArray, int length, int target) {
    
    for(int i = 0; i < length; i++) {
        if(myArray[i] == target) {
            return i;
            break;
        }
    }
    return -1;
}
// method that returns a printed array (makes debugging and command 4 simpler)
void printArray(int arr[], int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
}
int main() {

    char filename[10];
    int fileSize;
    
    cout << "Enter file name to read:";
    cin >> filename;
    
    fstream myfile;
    myfile.open(filename);
    
    int arr[100];
    int i = 0;
    int x;
    while (myfile >> x) {
        
        arr[i] = x;
        i++;
    }
    
    // create and load data array
    int data[i];

    for(int z = 0; z < i; z++) {
        data[z] = arr[z];
    }
    
    //make sure of array size and sort the array to prepare for commands
    int arrSize = sizeof(data)/sizeof(data[0]);
    sortArray(data, arrSize);
    
    // run command prompt and create cases to prepare for possible responses
    int command;
    cout << endl << "Enter command:" << endl << "   1-get Length, 2-get a value at #, 3-get index for value#, 4- print array, 5 - exit :";
    while (command != 5) {
        command = 0;
        cout << endl << "Command: ";
        cin >> command;
        
        // respond to input 1 with array size
        if(command == 1) {
            cout << readData(data, filename);
        }

        // respond to input 2 with the value at index entered (if invalid index, output 'Invalid Index')
        if(command == 2) {
            int command2Index;
            cin >> command2Index;
            if(command2Index < arrSize && command2Index > -1) {
                cout << data[command2Index];
            } else {
                cout << "Invalid Index";
            }
        }

        // respond to input 3 with the index of the entered value (if entered value does not exist in the data set, output '-1')
        if(command == 3) {
            int command3Value;
            cin >> command3Value;

            int valueIndex = -1;
            bool valueExists = false;

            for (int i = 0; i < arrSize; i++) {
                 if (data[i] == command3Value) {
                    valueIndex = i;
                    valueExists = true;
                    break;
                 }
            }
            cout << valueIndex;
        }

        // respond to input 4 by using printArray method created before
        if(command == 4) {
            printArray(data, arrSize);
        }

        // break command prompt loop if input is 5
        if(command == 5) {
            break;
        } else if (command != 1 && command != 2 && command != 3 && command !=4 && command != 5) { // respond to unintended inputs
            cout << "Invalid Input";
        }
    }
}
