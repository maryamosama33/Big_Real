#include"BigReal.h"
#include <bits\stdc++.h>

int main()
{

    BigReal x("0.0"),y("-0.0");
    BigReal sum;
    sum=x-BigReal("0.9");
    cout<<sum.getnum()<<endl;

}