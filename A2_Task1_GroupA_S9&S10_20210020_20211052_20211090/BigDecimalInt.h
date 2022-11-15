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
