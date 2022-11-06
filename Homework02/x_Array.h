// Samneet Singh, HW02 header file
// header file for class X_Array

#ifndef x_Array.h
#define x_Array.h

class X_Array {
    public :
        X_Array();
        bool operator == (const X_Array &) const {
            
        }
        bool operator !=(const X_Array &) const {

        }
        int add(int x) {
        
        }
        void removeLast();
        int getSize() const {
            return maxLength;
        }
        int getAt(int index) const {

        }
        void setAt(int index, int value) {

        }
    private :
        int currLength;
        int maxLength;

        int ** dataArray;

} 
#endif