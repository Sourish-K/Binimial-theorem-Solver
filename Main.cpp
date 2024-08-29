#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int conversionType;
    cout << "Select conversion:" << '\n';
    cout << "For Vector equation with no A or B value to Standard, Type 1" << '\n';
    cout << "For Standard to Factorized, Type 2" << '\n';
    cout << "For Polynoimal Expansion, Type 3" << '\n';
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
                cout << "bValue: " << bValue << '\n';
                cout << "cValue: " << cValue << '\n';
                cout << "vValue: " << vValue << '\n';
            }
            cout << '\n';
            
            if(yValue <= 0) {  // this if statment is for all the negative ax+y to the power of 2, 3 and 4. 4 is still in progress.
                if(yValue == 0){
                    cout << "yValue = 0";
                }
                
                else if(vValue == 2) {
                    cout << "vValue = 2" << '\n'; // for testing
                    cout << aValue << "x^" << vValue << " - " << vValue * yValue * aValue << "x + " << cValue << '\n'; // pow of 2 (x-y)
                }
                
                else if(vValue == 3) {
                    cout << "vValue = 3" << '\n'; // for testing
                    cout <<  aValue << "x^" << vValue << " " << vValue * yValue * aValue<< "x^2 + " << (aValue * vValue * pow(yValue, (vValue - 1))) << "x^" << vValue - 1 << " " << pow(yValue, 3) << '\n';
                    cout << "V: " << vValue << '\n';
                    cout << "Y: " << yValue << '\n';
                    cout << "A: " << aValue << '\n';
                    
                }
                else if(vValue == 4){
                    cout << "vValue = 4" <<'\n'; // for testing
                }
            }

            if(yValue >= 0) {  // this if statment is for all the postive ax+y to the power of 2, 3 and 4. 4 is still in progress.
                if(yValue == 0){
                    cout << "yValue = 0";
                }
                
                else if(vValue == 2) {
                    cout << "vValue = 2" << '\n'; // for testing
                    cout << aValue << "x^" << vValue << " + " << vValue * yValue * aValue << "x + " << cValue << '\n'; // pow of 2 (x-y)
                }
                
                else if(vValue == 3) {
                    cout << "vValue = 3" << '\n'; // for testing
                    cout <<  aValue << "x^" << vValue << " +3 " << vValue * yValue * aValue << "x^2 + " << (aValue * vValue * pow(yValue, (vValue - 1))) << "x^" << vValue - 1 << " + " << pow(yValue, 3) << '\n';
                    cout << "V: " << vValue << '\n';
                    cout << "Y: " << yValue << '\n';
                    cout << "A: " << aValue << '\n';
                    
                }
                else if(vValue == 4){
                    cout << "vValue = 4" <<'\n'; // for testing
                }
            }

            //cout << aValue << "x^" << vValue << " + " << vValue * yValue * aValue << "x + " << cValue << '\n'; // pow of 2

            break;

        default:
            cout << "Please type a valid number" << '\n';
            break;
    }
    
    return 0;
}







