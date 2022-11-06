//Samneet Singh
#include "X_Array.h"

template<class T>
void X_Array::setUpData(const X_Array & rhs) {

    currMax = rhs.currMax;
    currLength = rhs.currLength;
    dataArray = new T * [currLength/10];
    for(int i = 0; i < currLength/10; i++) {

        dataArray[i] = new T[10];

        for(int j = 0; j < 10; j++) {
            dataArray[i][j] = rhs.dataArray[i][j];
        }
    }
}
template<class T>
X_Array::X_Array()
{
    dataArray = new T *[1];
    dataArray[0] = new T[10];
    currMax = 10;
    currLength = 0;
}

template<class T>
X_Array::X_Array(const X_Array & rhs) {
    setUpData(rhs);
}

X_Array::~X_Array() {
    for(int i = 0; i< currLength/10; i++) {
        delete [] dataArray[i];
    }
    delete [] dataArray;
}

X_Array & X_Array::operator =(const X_Array & rhs) {
    if(*this == rhs) {
        return *this;
    }
    for(int i = 0; i < currLength/10; i++) {
        delete [] dataArray[i];
    }
    delete []dataArray;
    setUpData(rhs);
    return *this;
}

bool X_Array::operator==(const X_Array &) const {
    if(*this == rhs) {
        return true;
    } else {
        return false;
    }
}

bool X_Array::operator!=(const X_Array &) const {
    if(*this != rhs) {
        return true;
    } else {
        return false;
    }
}

template<class T>
T X_Array::add(T value) {
    if(currLength < currMax) {
        T newLoc = currLength;
        T masterIndex = newLoc/10;
        T locIndex = newLoc%10;
        dataArray[masterIndex][locIndex] = value;
        currLength ++;
    }
    else {
        T numMasterElements = currLength/10;
        T ** temp = new T * [numMasterElements +1];
        for(int i = 0; i < numMasterElements; i++) {
            temp[i] = dataArray[i];
        }
        temp[numMasterElements] = new T[10];
        delete dataArray;
        dataArray = temp;
        currMax = currMax + 10;
        add(value);
    }
    return currLength -1;
}

template<class T>
void X_Array::removeLast() {
    
}

template<class T>
T X_Array::getAt(T index) const {
    return 0;
}

template<class T>
void X_Array::setAt(T index, T value) {

}

template<class T>
void X_Array::sort() {

}

template<class T>
int X_Array::find(const T &) const {
    return 0;
}







