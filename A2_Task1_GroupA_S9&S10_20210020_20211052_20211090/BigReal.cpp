#include "BigReal.h"
#include "BigDecimalInt.cpp"


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
        if(num[num.size()-1]=='.'){
            num = num+'0';
        }
        if(num[0]=='.'){
            num = '0'+num;
        }
        if (num[0] == '+' || isdigit(num[0]))
            sign = '+';
        else
            sign = '-';

        

        int pos = num.find('.');
        if(*num.begin()=='-' ){
            num[0]='+';
        }
        


        *decimal = num.substr(0,pos);
        *fraction = num.substr(pos+1);
        if(pos<0){
            string zero="0";
            *decimal=num;
            *fraction =zero ;
        }

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
    *decimal = *other.decimal;
    *fraction = *other.fraction;
    sign = other.sign;
}
//-------------------------------------------------------------------------
// Move constructor
BigReal :: BigReal(BigReal&& other)
{
    decimal = other.decimal;
    fraction = other.fraction;
    sign = other.sign;
    other.decimal = nullptr;
    other.fraction = nullptr;
}
//------------------------------------------------------------------------
// Assignment operator
BigReal &BigReal :: operator = (BigReal &other)
{
    if(this != &other)
    {
        *this->decimal = *other.decimal;
        *this->fraction = *other.fraction;
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
        this->decimal = other.decimal;
        this->fraction = other.fraction;
        this->sign = other.sign;
        other.decimal = nullptr;
        other.fraction = nullptr;
    }
    return *this;
}
//--------------------------------------------------------------------------
// operator + overloading function.
BigReal BigReal :: operator + (const BigReal &other)
{
        BigReal sum;
        if (other.sign == sign) {
            if (fraction->size() > other.fraction->size()) {
                string small = other.fraction->getnum();
                for (int i = 0; i < (fraction->size() - other.fraction->size()); i++) {
                    small += "0";
                }
                string original = other.fraction->getnum();
                *other.fraction = small;
                *sum.fraction = *fraction + *other.fraction;
                if (sum.fraction->size() > fraction->size()) {
                    *sum.decimal = *decimal + *other.decimal + BigDecimalInt("1");
                    string s = sum.fraction->getnum();
                    s.erase(s.begin());
                    *sum.fraction = s;
                } else {
                    *sum.decimal = *decimal + *other.decimal;
                }
                *other.fraction = original;
            } else if (fraction->size() <= other.fraction->size()) {
                string original = fraction->getnum();
                if (fraction->size() < other.fraction->size()) {
                    string small = fraction->getnum();
                    for (int i = 0; i < (other.fraction->size() - fraction->size()); i++) {
                        small += "0";
                    }
                    *fraction = small;
                }
                *sum.fraction = *fraction + *other.fraction;
                if (sum.fraction->size() > other.fraction->size()) {
                    *sum.decimal = *decimal + *other.decimal + BigDecimalInt("1");
                    string s = sum.fraction->getnum();
                    s.erase(s.begin());
                    *sum.fraction = s;
                } else {
                    *sum.decimal = *decimal + *other.decimal;
                }
                *fraction = original;
            }
            sum.sign = sign;
            if ((*decimal == BigDecimalInt("0") && *other.decimal == BigDecimalInt("0")) &&
                ((*fraction == BigDecimalInt("0")) && (*other.fraction == BigDecimalInt("0")))) {
                *sum.fraction = BigDecimalInt("0");
                *sum.decimal = BigDecimalInt("0");
                sum.sign = ' ';
            }
        }
        else {
            if (*other.decimal > *decimal) {
                *sum.decimal = *other.decimal - *decimal;
                string original1 = other.fraction->getnum();
                string original2 = fraction->getnum();
                if (fraction->size() > other.fraction->size()) {
                    string small = other.fraction->getnum();
                    for (int i = 0; i < (fraction->size() - other.fraction->size()); i++) {
                        small += "0";
                    }
                    *other.fraction = small;
                } else if (fraction->size() < other.fraction->size()) {
                    string small = fraction->getnum();
                    for (int i = 0; i < (other.fraction->size() - fraction->size()); i++) {
                        small += "0";
                    }
                    *fraction = small;
                }
                BigDecimalInt s = *other.fraction - *fraction;

                if (s.Sign() == 0) {
                    *sum.decimal = *sum.decimal - BigDecimalInt("1");
                    string ss = other.fraction->getnum();
                    ss = "1" + ss;
                    *other.fraction = ss;
                    cout<<ss;
                    *sum.fraction = *other.fraction - *fraction;
                }
                else {
                    *sum.fraction = *other.fraction - *fraction;
                }

                if(fraction->size()==other.fraction->size()) {
                    if (sum.fraction->size() < fraction->size()){
                        string str="";
                        for(int i=0;i<(fraction->size()-sum.fraction->size());i++){
                            str+="0";
                        }
                        str=str+sum.fraction->getnum();
                        *sum.fraction=str;
                    }
                }

                if (other.sign == '-') {
                    sign = '-';
                    sum.sign = sign;
                } else {
                    sign = '+';
                    sum.sign = sign;
                }
                *other.fraction = original1;
                *fraction = original2;
            }
            else if (*other.decimal <  *decimal) {
                *sum.decimal = *decimal - *other.decimal;

                string original1 = other.fraction->getnum();
                string original2 = fraction->getnum();
                if (fraction->size() > other.fraction->size()) {
                    string small = other.fraction->getnum();

                    for (int i = 0; i < (fraction->size() - other.fraction->size()); i++) {
                        small += "0";
                    }
                    *other.fraction = small;
                }
                else if(fraction->size() < other.fraction->size()) {
                    string small = fraction->getnum();
                    for (int i = 0; i < (other.fraction->size() -fraction->size()); i++) {
                        small += "0";
                    }
                    *fraction = small;
                }
                BigDecimalInt s = *fraction - *other.fraction;
                if (s.Sign() == 0) {
                    *sum.decimal = *sum.decimal - BigDecimalInt("1");
                    string ss = fraction->getnum();
                    ss = "1" + ss;
                    *fraction = ss;
                    *sum.fraction = *fraction - *other.fraction;

                } else {
                    *sum.fraction = s;
                }

                if(fraction->size()==other.fraction->size()) {
                    if (sum.fraction->size() <fraction->size()){
                        string str="";
                        for(int i=0;i<(fraction->size()-sum.fraction->size());i++){
                            str+="0";
                        }
                        str=str+sum.fraction->getnum();
                        *sum.fraction=str;
                    }
                }



                if (sign == '-') {
                    sum.sign = sign;
                } else {
                    sign = '+';
                    sum.sign = sign;
                }
                *other.fraction=original1;
                *fraction=original2;




            }
            else{
                *sum.decimal = *decimal - *other.decimal;
                string original1 = other.fraction->getnum();
                string original2 = fraction->getnum();
                if (fraction->size() > other.fraction->size()) {
                    string small = other.fraction->getnum();

                    for (int i = 0; i < (fraction->size() - other.fraction->size()); i++) {
                        small += "0";
                    }
                    *other.fraction = small;
                }
                else if(fraction->size() < other.fraction->size()) {
                    string small = fraction->getnum();
                    for (int i = 0; i < (other.fraction->size() -fraction->size()); i++) {
                        small += "0";
                    }
                    *fraction = small;
                }

                if (*fraction>*other.fraction) {

                    BigDecimalInt s = *fraction - *other.fraction;
                    *sum.fraction = s;
                    sign=sign;
                    sum.sign = sign;
                }
                else if(*fraction<*other.fraction){
                    BigDecimalInt s = *other.fraction - *fraction;
                    *sum.fraction = s;
                    sign=other.sign;
                    sum.sign = sign;
                }
                else{
                    BigDecimalInt s = *other.fraction - *fraction;
                    *sum.fraction = s;
                    set_sign(' ');
                    sum.sign=sign;
                }
                if(fraction->size()==other.fraction->size()) {
                    if (sum.fraction->size() <fraction->size()){
                        string str="";
                        for(int i=0;i<(fraction->size()-sum.fraction->size());i++){
                            str+="0";
                        }
                        str=str+sum.fraction->getnum();
                        *sum.fraction=str;
                    }
                }
            }
            if ((*decimal == BigDecimalInt("0") && *other.decimal == BigDecimalInt("0")) &&
                ((*fraction == BigDecimalInt("0")) && (*other.fraction == BigDecimalInt("0")))) {
                *sum.fraction = BigDecimalInt("0");
                *sum.decimal = BigDecimalInt("0");
                sum.sign = ' ';
            }
        }
        return sum;
    }
//---------------------------------------------------------------------------
//operator - overloading function.
BigReal BigReal ::operator - (const BigReal &other)
{
    BigReal sum;
    BigReal final;
            *final.decimal=*other.decimal;
            *final.fraction=*other.fraction;

            if(other.sign=='-')
                final.sign='+';

            else
                final.sign='-';

            sum=final+ *this;

    return sum;
}
//-----------------------------------------------------------------------------
// set sign
void BigReal::set_sign(char s) {
    sign=s;
}
//------------------------------------------------------------------------------------
bool BigReal::operator< (BigReal anothorReal){
    if(sign=='-' and anothorReal.sign =='+'){
        return true;
    }
    else if(anothorReal.sign=='-' and sign =='+'){
        return false;
    }
    if(sign=='+' and anothorReal.sign =='+'){
        if(*decimal<*anothorReal.decimal){
            return true;
        }
        else if(*decimal>*anothorReal.decimal){
            return false;
        }
        else if (*decimal==*anothorReal.decimal){
            if(*fraction < *anothorReal.fraction){
                return true;
            }
            else{
                return false;
            }
        }
    }
    if (sign=='-' and anothorReal.sign =='-'){
        if(*decimal<*anothorReal.decimal){
            return false;
        }
        else if(*decimal>*anothorReal.decimal){
            return true;
        }
        else if (*decimal==*anothorReal.decimal){
            if(*fraction > *anothorReal.fraction){
                return true;
            }
            else{
                return false;
            }
        }

    }

    return true;
}
//------------------------------------------------------------------------------------
bool BigReal::operator== (BigReal anothorReal){
    if(sign==anothorReal.sign)
    {if(*decimal == *anothorReal.decimal){
        if(*fraction==*anothorReal.fraction){
            return true;
        }
    }
    }
    return false;
}
//------------------------------------------------------------------------------------
ostream& operator<< (ostream& out , BigReal num){

    if(num.sign=='-')
    out<<num.sign;
    out<<*num.decimal<<'.'<<*num.fraction;
    return out;
}
bool BigReal::operator> (BigReal anothorReal){
   string comp1 = "", comp2 = "" , num1="" , num2="";
    long long len1 = (fraction)->size(), len2 = (anothorReal.fraction)->size();
    while (len1 < len2){
        comp1 += '0';
        len1++;
    }
    while (len2 < len1){
        comp2 += '0';
        len2++;
    }
    num1 = fraction->getnum()+ comp1;
    num2 = anothorReal.fraction->getnum()+ comp2;
    *fraction = num1;
    *anothorReal.fraction = num2;
    if(sign=='-' and anothorReal.sign =='+'){
        return false;
    }
    else if(anothorReal.sign=='-' and sign =='+'){
        return true;
    }
    if(sign=='+' and anothorReal.sign =='+'){
        if(*decimal<*anothorReal.decimal){
            return false;
        }
        else if(*decimal>*anothorReal.decimal){
            return true;
        }
        else if (*decimal==*anothorReal.decimal){
            if(*fraction > *anothorReal.fraction){
                return true;
            }
            else{
                return false;
            }
        }
    }
    if (sign=='-' and anothorReal.sign =='-'){
        if(*decimal<*anothorReal.decimal){
            return true;
        }
        else if(*decimal>*anothorReal.decimal){
            return false;
        }
        else if (*decimal==*anothorReal.decimal){
            if(*fraction < *anothorReal.fraction){
                return true;
            }
            else{
                return false;
            }
        }

    }
    return true;
}
//------------------------------------------------------------------------------------
int BigReal::size(){
    return fraction->size() + decimal->size() ;
}
//------------------------------------------------------------------------------------
istream& operator>> (istream& in , BigReal& num){
    string number;
    in>>number;
    num = BigReal(number);
    
    return in;
}
//------------------------------------------------------------------------------------
