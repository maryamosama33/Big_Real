#include"BigReal.cpp"
#include <bits\stdc++.h>

int main()
{
    // constructors
    BigReal r1 (+017.000985);     // 17.000985
    BigReal r2(075.20775);        // 75.20775
    BigReal r3(-035.030125);      // -35.030125
    BigReal r4("+023.000152");    //23.000152
    BigReal r5("+078.000q25"); // Invalid
    BigReal r6 ("-073.00125");     //-73.00125
    BigReal r7 (".256");     //0.256
    BigReal r8 ("253.");     // 253.0
    BigReal r9 ("1.235.25"); // invalid
    BigReal r10 ("256.226");  // 256.226
    BigReal r11 ("-523.253");  // -523.253
    BigReal r13("7000.2526");   // 7000.2526
    BigReal r14("7000.2526");   //7000.2526
    BigReal r15("300.2526");    //300.2526 
    BigReal r16("7000.2522");    //7000.2522 
    
    // get size and sign
    cout<< r10.size()<<endl;     // 6
    cout<< r11.get_sign()<<endl;   // -

    //operator + and -
    cout<< (r1+r2)<<endl;    // 92.208735
    cout<<(r6 + r10)<<endl;  // 183.22475
    cout<<(r11-r4)<<endl;    // -546.253125
    cout<< (r3 - r8)<<endl;     // -288.030125
    BigReal r12 = (r7+r8);
    cout<< r12<<endl;          //253.256



    // operator < and > and ==
    // True
    if(r13==r14)
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    
   //False 
    if(r16>r13)
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;

    //False
    if(r13<r14)
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;



    // operator << and >>


    // Remove the comment to test cin


    /*BigReal number;
    cout<<"Enter the number"<<endl;
    cin>>number;
    cout<<number<<endl;
    */
    


 

    
}