//Samneet Singh Homework00

#include<iostream>
#include<fstream>
using namespace std;

int main() {

    string fileName;
    int index;
    
    cout << "Enter file name to read:";
    cin >> fileName;
    fstream myfile;
    myfile.open (fileName);
   
    int x;
    int count;
    while (myfile >> x) {
        count++;
    }
    int command2Max = count - 1;
    int numbers[count];

    myfile.clear();
    
    int z = 0;
    while(!myfile.eof() && z < count) {
        myfile >> numbers[z];
        z++;
    }
    
    /* for(int z = command2Max; z >= 0; z--) {
        myfile >> numbers[z];
    } */

    /* cout << endl << count << endl; */ //test to make sure count is working properly

   cout << endl << "Enter command:" << endl << "   1-get length , 2-get a value at # , 3-print all , 4-exit :";
    while (index != 4) {
        index = 0;
        cout << endl << "command : ";
        cin >> index;
        
        if(index == 1) {
            cout << endl << count << endl;
        }
        if(index == 2) {
            int command2;
            cin >> command2;
            if(0 <= command2 <= command2Max) {
                cout << numbers[command2];
            } else {
                cout << "invalid index";
            }
        }
        if(index == 3) {
            for(int i=0; i < count ; i++)
            {
                cout << numbers[i] << " ";
            }
        } 
        if(index == 4) {
            break;
        }else if (index != 1 && index != 2 && index != 3 && index !=4) {
            cout << "invalid index";
        }
    }
    return(0);
}

