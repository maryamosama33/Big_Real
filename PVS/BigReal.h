
#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H

#include<bits/stdc++.h>
#include <utility>
#include"BigDecimalInt.h"
using namespace std;
class BigReal
{
private:
    BigDecimalInt *decimal = new BigDecimalInt("0");
    BigDecimalInt *fraction = new BigDecimalInt("0");
    char sign;
public:
    static bool is_valid( const string &realNumber);
    void check_divide(string num);
    BigReal (double realNumber = 0.0);
    BigReal (string realNumber);
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other);
    BigReal (BigReal&& other);
    BigReal& operator= (BigReal& other);
    BigReal& operator= (BigReal&& other);
    void set_sign(char s);
    char get_sign(){
        return sign;
    }
    BigReal operator+ (const BigReal& other);
    BigReal operator- (const BigReal& other);
    bool operator< (BigReal anothorReal);
    bool operator> (BigReal anothorReal);
    bool operator== (BigReal anothorReal);
    int size();
    friend ostream& operator<< (ostream& out ,const BigReal num);
    friend istream& operator>> (istream& in , BigReal& num);

};

#endif
