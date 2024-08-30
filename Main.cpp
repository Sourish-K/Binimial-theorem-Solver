#include <iostream>  // Include the input/output stream library
#include <cmath>     // Include the math library for mathematical operations like pow and sqrt
using namespace std; // Use the standard namespace to avoid prefixing std:: to standard functions

int main() {
    int conversionType;   // Variable to store user's selection for the type of conversion
    char goBack;          // Variable to store user's input if they want to go back (not currently used)
    
    // Display menu options to the user
    cout << "Select conversion type:" << '\n'; 
    cout << "1. Convert vertex form with no A or K value to Standard form" << '\n'; // Menu option 1
    cout << "2. Convert Standard form to Factorized form" << '\n'; // Menu option 2
    cout << "3. Perform Polynomial Expansion" << '\n'; // Menu option 3
    cout << "4. Convert Standard form to Vertex form" << '\n';  // Menu option 4
    cout << "5. Solve the Quadratic Formula" << '\n'; // Menu option 5
    
    // Get user input for conversion type
    cin >> conversionType;

    // Switch statement to handle each conversion type based on user's input
    switch(conversionType) {
        case 1: // Convert vertex form with no A or B value to Standard form
            cout << "Convert vertex form with no A or B value to Standard form" << '\n';
            
            double hValue, vValue;  // Variables to store h and v values from vertex form
            
            // Prompt the user for the h value
            cout << "Please enter the h value: ";
            cin >> hValue;
            
            // Calculate and display the equivalent standard form equation
            cout << "Standard form: x^2 + " << (2 * hValue) << "x + " << pow(hValue, 2) << '\n';
            
            break;
            
        case 2: // Convert vertex form with A and K values to Standard form
            double aValue, kValue; // Variables to store a and k values from vertex form
            
            cout << "Vertex with A and K values to Standard Conversion" << '\n';
            
            // Prompt the user for the h, k, and a values
            cout << "Please enter the h value: ";
            cin >> hValue;
            cout << "Please enter the k value: ";
            cin >> kValue;
            cout << "Please enter the a value: ";
            cin >> aValue;

            // Calculate and display the equivalent standard form equation
            cout << "Standard form: " << aValue << "x^2" << " + " << (aValue * (2 * hValue)) << "x + " << (aValue * (kValue + pow(hValue, 2))) << '\n';
            break;

        case 3: // Perform Polynomial Expansion
            double cValue, yValue, result; // Variables for polynomial expansion

            cout << "Polynomial Expansion" << '\n';

            // Prompt the user for the y, a, and v values
            cout << "Please enter the y value: ";
            cin >> yValue;
            cout << "Please enter the a value: ";
            cin >> aValue;
            cout << "Please enter the v value: ";
            cin >> vValue;

            // Loop through each term in the expansion and calculate the result
            for (int kValue = 0; kValue <= vValue; kValue++) {
                double nValue = pow(aValue, vValue - kValue);  // Calculate n value as x^(v-k)
                double mValue = pow(yValue, kValue);           // Calculate m value as y^k
                result = nValue * mValue;                      // Calculate product of terms
                cout << "nValue: " << nValue << '\n';
                cout << "mValue: " << mValue << '\n';
                cout << "Result: " << result << '\n';
            }
            cout << '\n';

            // Determine whether to expand (x - y) or (x + y) based on the sign of yValue
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
                    cout << "vValue = 4 expansion not implemented yet" << '\n'; // Placeholder for future implementation
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
                    cout << "vValue = 4 expansion not implemented yet" << '\n'; // Placeholder for future implementation
                }
            }

            break;

        case 4: // Convert Standard form to Vertex form
            cout << "Standard form to Vertex form Conversion" << '\n';

            // Prompt the user for the a, b, and c values from standard form
            cout << "Please enter the a value: ";
            cin >> aValue;
            cout << "Please enter the b value: ";
            cin >> bValue;
            cout << "Please enter the c value: ";
            cin >> cValue;

            // Calculate h and k values to convert to vertex form
            hValue = -bValue / (2 * aValue);
            kValue = cValue - (bValue * bValue) / (4 * aValue);

            // Display the equivalent vertex form equation
            cout << "Vertex form: " << aValue << "(x - " << hValue << ")^2 + " << kValue << '\n'; 

            break;

        case 5: // Solve the Quadratic Formula
            double x1Value, x2Value, discriminant, term1, term2; // Variables for solving the quadratic equation

            cout << "Solve the Quadratic Formula" << '\n';

            // Prompt the user for the a, b, and c values from the quadratic equation
            cout << "Please enter the a value: ";
            cin >> aValue;
            cout << "Please enter the b value: ";
            cin >> bValue;
            cout << "Please enter the c value: ";
            cin >> cValue;

            // Calculate the discriminant to determine the nature of the roots
            discriminant = pow(bValue, 2) - (4 * aValue * cValue);

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

        default: // Handle invalid input
            cout << "Please reenter your number"; // Prompt user to reenter a valid option
    } 
    
    return 0; // Exit the program
}
