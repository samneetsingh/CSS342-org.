//
// Created by Sam Singh on 5/7/22.
//

#ifndef X_ARRAY_H
#define X_ARRAY_H


class X_Array {
public:

    template<class T>
    X_Array();

    template<class T>
    X_Array(const X_Array &);

    ~X_Array();


    X_Array & operator = (const X_Array &);

    bool operator == (const X_Array &) const;

    bool operator != (const X_Array &) const;

    template<class T>
    T add(T);

    template<class T>
    void removeLast();

    template<class T>
    int getSize() const { return currLength; }

    template<class T>
    T getAt(T index) const;

    template<class T>
    void setAt(T index, T value);

    template<class T>
    void sort();

    template<class T>
    int find(const T &) const;

private:

    int ** dataArray;

    int currMax;
    int currLength;

    template<class T>
    void setUpData(const X_Array & rhs);
};

#include "X_Array.ipp"
#endif //X_ARRAY_H
