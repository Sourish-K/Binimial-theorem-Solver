#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int conversionType;
    char goBack;
    cout << "Select conversion type:" << '\n'; 
    cout << "1. Convert vertex form with no A or K value to Standard form" << '\n'; // works
    cout << "2. Convert Standard form to Factorized form" << '\n'; // works
    cout << "3. Perform Polynomial Expansion" << '\n';
    cout << "4. Convert Standard form to Vertex form" << '\n';  // works
    cout << "5. Solve the Quadratic Formula" << '\n';
    cin >> conversionType;

    switch(conversionType) {
        case 1: //Convert vertex form with no A or B value to Standard form    // works
            cout << "Convert vertex form with no A or B value to Standard form" << '\n';
            double hValue, vValue;
            cout << "Please enter the h value: ";
            cin >> hValue;
            cout << "Standard form: x^2 + " << (2 * hValue) << "x + " << pow(hValue, 2) << '\n';
            
            break;
            
        case 2: // works
            double aValue, kValue;
            cout << "vertex  with A and K values to Standard Conversion" << '\n';
            cout << "Please enter the h value: ";
            cin >> hValue;
            cout << "Please enter the k value: ";
            cin >> kValue;
            cout << "Please enter the a value: ";
            cin >> aValue;

            cout << "Standard form: " << aValue << "x^2" << " + " << (aValue * (2 * hValue)) << "x + " << (aValue * (kValue + pow(hValue, 2))) << '\n';
            break;

        case 3:
            double cValue, yValue, result;

            cout << "Polynomial Expansion" << '\n';

            cout << "Please enter the y value: ";
            cin >> yValue;
            cout << "Please enter the a value: ";
            cin >> aValue;
            cout << "Please enter the v value: ";
            cin >> vValue;

            for (int kValue = 0; kValue <= vValue; kValue++) {
                double nValue = pow(aValue, vValue - kValue);  // n value is x^(v-k)
                double mValue = pow(yValue, kValue);           // m value is y^k
                result = nValue * mValue;                      // product of terms
                cout << "nValue: " << nValue << '\n';
                cout << "mValue: " << mValue << '\n';
                cout << "Result: " << result << '\n';
            }
            cout << '\n';

            if (yValue < 0) {  // Expanding (x - y)
                if (vValue == 2) {
                    cout << "Expanding (x - y)^2: " << '\n';
                    cout << "Result: " << aValue << "x^2 - " << (2 * aValue * yValue) << "x + " << (pow(yValue, 2)) << '\n';
                }
                else if (vValue == 3) {
                    cout << "Expanding (x - y)^3: " << '\n';
                    cout << "Result: " << aValue << "x^3 - " << (3 * aValue * yValue) << "x^2 + " << (3 * aValue * pow(yValue, 2)) << "x - " << pow(yValue, 3) << '\n';
                }
                else if (vValue == 4) {
                    cout << "Expanding (x - y)^4: " << '\n';
                    cout << "vValue = 4 expansion not implemented yet" << '\n'; // placeholder
                }
            }

            if (yValue >= 0) {  // Expanding (x + y)
                if (vValue == 2) {
                    cout << "Expanding (x + y)^2: " << '\n';
                    cout << "Result: " << aValue << "x^2 + " << (2 * aValue * yValue) << "x + " << (pow(yValue, 2)) << '\n';
                }
                else if (vValue == 3) {
                    cout << "Expanding (x + y)^3: " << '\n';
                    cout << "Result: " << aValue << "x^3 + " << (3 * aValue * yValue) << "x^2 + " << (3 * aValue * pow(yValue, 2)) << "x + " << pow(yValue, 3) << '\n';
                }
                else if (vValue == 4) {
                    cout << "Expanding (x + y)^4: " << '\n';
                    cout << "vValue = 4 expansion not implemented yet" << '\n'; // placeholder
                }
            }

            break;

        case 4: // works
            
            cout << "Standard form to Vertex form Conversion" << '\n';

            cout << "Please enter the a value: ";
            cin >> aValue;
            cout << "Please enter the b value: ";
            cin >> bValue;
            cout << "Please enter the c value: ";
            cin >> cValue;

            // Calculate h and k
            hValue = -bValue / (2 * aValue);
            kValue = cValue - (bValue * bValue) / (4 * aValue);
            //kValue = cValue - ((pow(bValue, 2) /2));

            cout << "Vertex form: " << aValue << "(x - " << hValue << ")^2 + " << kValue << '\n'; 

            break;
        case 5:
            double x1Value, x2Value, discriminant, term1, term2;

            cout << "Solve the Quadratic Formula" << '\n';

            cout << "Please enter the a value: ";
            cin >> aValue;
            cout << "Please enter the b value: ";
            cin >> bValue;
            cout << "Please enter the c value: ";
            cin >> cValue;

            discriminant = pow(bValue, 2) - (4 * aValue * cValue);  // Calculate the discriminant

            if (discriminant > 0) {
                // Two real and distinct roots
                term1 = -bValue / (2 * aValue);
                term2 = sqrt(discriminant) / (2 * aValue);

                x1Value = term1 + term2;
                x2Value = term1 - term2;

                cout << "This quadratic equation has 2 x intercepts:" << '\n';
                cout << "x1 = " << x1Value << '\n';
                cout << "x2 = " << x2Value << '\n';
            }
            else if (discriminant == 0) {
                // One real root (repeated)
                x1Value = x2Value = -bValue / (2 * aValue);

                cout << "This quadratic equation has 1 x intercept (repeated root):" << '\n';
                cout << "x = " << x1Value << '\n';
            }
            else {
                // No real roots
                cout << "There are no real solutions." << '\n';
                cout << "The parabola has no x intercepts." << '\n';
            }

            break;
        default;
            cout << "Please reenter your number";
    } 
    
    return 0;
}
