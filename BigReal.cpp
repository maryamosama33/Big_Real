#include "BigReal.h"

#include <utility>

//function to check if real number is valid.
bool BigReal :: is_valid(string realNumber)
{
    regex valid("[-+]?(([0-9]+.)|(.[0-9]+)|([0-9]+.[0-9]+))");
    return regex_match(realNumber, valid);
}
//----------------------------------------------------------------------
//function to check if real number is valid and divide it to fraction and decimal.
void BigReal :: check_divide(string num)
{
    if (is_valid(num))
    {
        int pos = num.find('.');
        decimal = num.substr(0,pos);
        fraction = num.substr(pos+1);

        if (num[0] == '+' || isdigit(num[0]))
            sign = '+';
        else
            sign = '-';

        Num = num;
    }
    else
    {
        cout<<"Invalid real number!!!"<<endl;
        return;
    }
}
//---------------------------------------------------------------------
// Default constructor
BigReal :: BigReal(double realNumber)
{
    string num= to_string(realNumber);
    check_divide(num);
}
//-----------------------------------------------------------------------

BigReal :: BigReal(string realNumber)
{
    check_divide(move(realNumber));
}

//------------------------------------------------------------------------
BigReal :: BigReal(BigDecimalInt bigInteger)
{
    string num = bigInteger.getnum()+'.';
    check_divide(num);
}
//------------------------------------------------------------------------
// Copy constructor
BigReal :: BigReal(const BigReal& other)
{
   Num = other.Num;
   decimal = other.decimal;
   fraction = other.fraction;
   sign = other.sign;
}
//-------------------------------------------------------------------------
// Move constructor
BigReal :: BigReal(BigReal&& other)
{
  Num = move(other.Num);
  decimal = move(other.decimal);
  fraction = move(other.fraction);
  sign = move(other.sign);
}
//------------------------------------------------------------------------
// Assignment operator
BigReal &BigReal :: operator = (BigReal &other)
{
    if(this != &other)
    {
        this->Num=other.Num;
        this->decimal = other.decimal;
        this->fraction = other.fraction;
        this->sign = other.sign;
    }
    return *this;
}
//-----------------------------------------------------------------------
// Move assignment
BigReal &BigReal :: operator = (BigReal &&other)
{
    if(this != &other)
    {
        this->Num= move(other.Num);
        this->decimal = move(other.decimal);
        this->fraction = move(other.fraction);
        this->sign = move(other.sign);
    }
    return *this;
}
//--------------------------------------------------------------------------
// operator + overloading function.
BigReal BigReal :: operator + (BigReal &other)
{

}

//---------------------------------------------------------------------------
//operator - overloading function.
BigReal BigReal ::operator - (BigReal &other)
{

}
//-----------------------------------------------------------------------------