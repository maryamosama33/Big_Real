// FCAI - Obejct-Oriented Programming 1 - 2022 - Assignment 2
// Program Name : Big Real
// Last Modification 11/11/2022
// Author1 and ID and Group: Ahmed Saad Ahmed          ID: 20210020  S9&S10
// Author2 and ID and Group: Maryam Osama Mohamed      ID: 20211090  S9&S10
// Author3 and ID and Group: Shahd Osama  Hamed        ID: 20211052  S9&S10

#ifndef MAIN_CPP_BIGDECIMALINT_H
#define MAIN_CPP_BIGDECIMALINT_H


#ifndef BIGREAL_BIGDECIMALINT_H
#define BIGREAL_BIGDECIMALINT_H

#include <iostream>
#include <deque>
#include <regex>

using namespace std;

class BigDecimalInt{
private:
    string number;
    char sign;
    void setNumber(string num);
    bool checkValidInput(string input);

public:
    bool operator < (const BigDecimalInt& anotherDec);
    bool operator > (const BigDecimalInt& anotherDec);
    bool operator == (const BigDecimalInt anotherDec);
    BigDecimalInt& operator = (BigDecimalInt anotherDec);
    BigDecimalInt operator + (BigDecimalInt number2);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    friend ostream &operator << (ostream &out, BigDecimalInt num);
    int size();
    int Sign();
    void push_back(char ch);
    void push_front(char ch);

    BigDecimalInt(){}
    BigDecimalInt(string num)
    {
        setNumber(num);
    }
    string getnum()
    {
        if(sign=='-')
        {
            string res=number;
            return res;
        }
        else
            return number;
    }
};

#endif


#endif //MAIN_CPP_BIGDECIMALINT_H
