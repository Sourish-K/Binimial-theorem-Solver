#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int conversionType;
    cout << "Select conversion:" << '\n';
    cout << "For Vector with no A or B value to Standard, Type 1" << '\n';
    cout << "For Standard to Factorized, Type 2" << '\n';
    cout << "For Binomial Expansion (Case 3), Type 3" << '\n';
    cin >> conversionType;

    switch(conversionType) {
        case 1:
            cout << "Vector to Standard Conversion" << '\n';
            double hValue, vValue;
            cout << "Please enter the h value: ";
            cin >> hValue;
            cout << "Please enter the v value: ";
            cin >> vValue;
            cout << "x^" << vValue << " + " << (2 * hValue) << "x" << " + " << pow(hValue, vValue) << '\n';
            break;

        case 2:
            double aValue;
            cout << "Vector with A and B values to Standard Conversion" << '\n';
            cout << "Please enter the h value: ";
            cin >> hValue;
            cout << "Please enter the v value: ";
            cin >> vValue;
            cout << "Please enter the a value: ";
            cin >> aValue;
            cout << aValue << "x^" << vValue << " + " << aValue * (2 * hValue) << "x" << " + " << aValue * pow(hValue, vValue) << '\n';
            break;

        case 3:
            double kValue, cValue, yValue, bValue, result;
            cout << "Binomial Expansion" << '\n';
            
            cout << "Please enter the y value: ";
            cin >> yValue;
            cout << "Please enter the a value: ";        
            cin >> aValue; 
            cout << "Please enter the v value: ";        
            cin >> vValue; 

            for (kValue = 0; kValue <= vValue; kValue++) {
                bValue = pow(aValue, vValue - kValue);
                cValue = pow(yValue, kValue);
                result = bValue + cValue;
            }

            switch(vValue){
                case 1:
                    cout << aValue << "x^" << vValue << " + " << vValue * yValue * aValue << "x + " << cValue << '\n'; // pow of 2
                    break;
                case 2:
                    cout << aValue << "x^" << vValue << " + " << vValue * yValue * aValue << "x + " << cValue << '\n'; // pow of 3  EDIT
                    break;
                case 3:
                    cout << aValue << "x^" << vValue << " + " << vValue * yValue * aValue << "x + " << cValue << '\n'; // pow of 4 EDIT
                    break;
                default;
                    cout << "Sadly we do not support numbers this large";

            }          

            cout << aValue << "x^" << vValue << " + " << vValue * yValue * aValue << "x + " << cValue << '\n'; // pow of 2

            break;

        default:
            cout << "Please type a valid number" << '\n';
            break;
    }
    
    return 0;
}

/*

    cout << "vector >> Standard" << '\n';
    double x,h, b, a, v, ANSWER;
    //cout << "Please enter x Value";
    //cin >> x;
    cout << "Please enter h Value";
    cin >> h;
    cout << "Please enter b Value";
    //cin >> b;
    cout << "Please enter a Value";        
    //cin >> a; 

    cout << "x^" << v << " + " << (2 * h) << "x" << " + " << pow(h, v);
    */
