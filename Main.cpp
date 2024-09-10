#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> findLargestFactors(double aValue, double bValue, double cValue, double& nValueF, double& mValueF) {
    double ACvalue = aValue * cValue; // AC = a * c
    vector<double> factors;
    
    // Find the factors of AC
    for (double i = 1; i <= abs(ACvalue); ++i) {
        if (fmod(ACvalue, i) == 0) { // If it's a factor
            factors.push_back(i);
            factors.push_back(ACvalue / i);
        }
    }

    // Sort the factors to easily find the correct pair
    sort(factors.begin(), factors.end());

    // Find the pair (n, m) such that n + m = bValue
    for (size_t i = 0; i < factors.size(); ++i) {
        double n = factors[i];
        double m = ACvalue / n;
        if (n + m == bValue) {
            nValueF = n;
            mValueF = m;
            return factors;  // Return the factors for AC
        }
    }

    return factors; // In case no factors found, return the factors list anyway
}

bool checkAnswer(double aValue, double bValue, double cValue, double& nValueF, double& mValueF) {
    vector<double> factors = findLargestFactors(aValue, bValue, cValue, nValueF, mValueF);

    // Check if n * m = a * c and n + m = b
    if (nValueF * mValueF == aValue * cValue && nValueF + mValueF == bValue) {
        return true;
    }
    return false;
}




int main() {
    int conversionType;   // Variable to store user's selection for the type of conversion
    char goBack;          // Variable to store user's input if they want to go back (not currently used)
    
    do{
        // Display menu options to the user
        cout << " *********************************************************************************************** \n";
        cout << "Select conversion type:" << '\n'; 
        cout << " ----------------------------------------------------------------------------------------------- \n";
        cout << "1. Convert vertex form with no A or K value to Standard form" << '\n'; // Menu option 1
            cout << "   1(x + h)^2" << '\n';
            cout << "   ---->" << '\n';
            cout << "   ax^2 + 2abx + b^2" << '\n';
        cout << " ----------------------------------------------------------------------------------------------- \n";
        cout << "2. Convert Vectex form to Standard form with A and K value" << '\n'; // Menu option 2
            cout << "   a(x + h)^2 + k" << '\n';
            cout << "   ---->" << '\n';
            cout << "   ax^2 + 2abx + b^2" << '\n';            
        cout << " ----------------------------------------------------------------------------------------------- \n";
        cout << "3. Polynomial Expansion (Power of 2, 3 and 4)" << '\n'; // Menu option 3
            cout << "   a(x +- h)^2" << '\n';
            cout << "            ^ 2, 3, 4" << '\n';
            cout << "   ---->" << '\n';
            cout << "   ax^2 +- 2abx +- b^2" << '\n';
            cout << "   ax^3 +- 3a^2bx +- 3ab^2x +- b^3" << '\n';
            cout << "   the abvoe can be both posible or negative" << '\n';
        cout << " ----------------------------------------------------------------------------------------------- \n";
        cout << "4. Convert Standard form to Vertex form" << '\n';  // Menu option 4
            cout << "   ax^2 + 2abx + b^2" << '\n';
            cout << "   ---->" << '\n';
            cout << "   a(x + h)^2 + k" << '\n'; 
        cout << " ----------------------------------------------------------------------------------------------- \n";
        cout << "5. Solve the Quadratic Formula" << '\n'; // Menu option 5
            cout << "   ax^2 + 2abx + b^2" << '\n';
            cout << "   ---->" << '\n';
            cout << "   x = __, x = __" << '\n'; 
        cout << " ----------------------------------------------------------------------------------------------- \n";
        cout << "6. Converting standard form to factored. NOTE: Only when the trinomial has a = 1" << '\n'; // Menu option 7
            cout << "   1x^2 + 2abx + b^2" << '\n';
            cout << "   ---->" << '\n';
            cout << "   1(x +- a)(x +- b)" << '\n'; 
            cout << "   This feature is currently under work" << '\n';
        cout << " ----------------------------------------------------------------------------------------------- \n";
        cout << "7. Converting standard form to factored." << '\n'; // Menu option 7
            cout << "   This feature is currently under work" << '\n';
        
        // Get user input for conversion type
        cin >> conversionType;

        // Switch statement to handle each conversion type based on user's input
        switch(conversionType) {
            case 1: // Convert vertex form with no A or K value to Standard form
                cout << "Convert vertex form with no A or K value to Standard form" << '\n';
                cout << "a(x + h)^2 + k" << '\n';
                
                double hValue, vValue;  // Variables to store h and v values from vertex form
                
                // Prompt the user for the h value
                cout << "Please enter the h value: ";
                cin >> hValue;
                
                // Calculate and display the equivalent standard form equation
                cout << "Standard form: x^2 + " << (2 * hValue) << "x + " << pow(hValue, 2) << '\n';
                
                break;
                
            case 2: // Convert vertex form with A and K values to Standard form
                double aValue, kValue; // Variables to store a and k values from vertex form
                
                cout << "Convert Vectex form to Standard form with A and K value" << '\n';
                
                // Prompt the user for the h, k, and a values
                cout << "Please enter the h value: ";
                cin >> hValue;
                cout << "Please enter the k value: ";
                cin >> kValue;
                cout << "Please enter the a value: ";
                cin >> aValue;

                // Calculate and display the equivalent standard form equation
                cout << "Standard form: " << aValue << "x^2" << " + " << (aValue * (2 * hValue)) << "x + " << ((aValue * pow(hValue, 2)) + kValue)  << '\n';
                break;

            case 3: // Perform Polynomial Expansion
                double yValue, result; // Variables for polynomial expansion

                cout << "Polynomial Expansion (Power of 2, 3 and 4)" << '\n';

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
                    cout << "Result: " << result << " " << '\n';
                }
                cout << '\n';

                // Determine whether to expand (x - y) or (x + y) based on the sign of yValue
                if (yValue < 0) {  // Expanding (x - y)
                    if (vValue == 2) {
                        cout << "Expanding (x - y)^2: " << '\n';
                        cout << "Result: " << aValue << "x^2 - " << (2 * aValue * yValue) << "x + " << aValue * (pow(yValue, vValue)) << '\n';
                    }
                    else if (vValue == 3) {
                        cout << "Expanding (x - y)^3: " << '\n';
                        cout << "Result: " << aValue << "x^3 - " << (3 * aValue * yValue) << "x^2 + " << (3 * aValue * pow(yValue, 2)) << "x - " << aValue * (pow(yValue, 3)) << '\n';
                    }
                    else if (vValue == 4) {
                        cout << "Expanding (x - y)^4: " << '\n';
                        cout << "vValue = 4 expansion not implemented yet" << '\n'; // Placeholder for future implementation
                    }
                }

                if (yValue >= 0) {  // Expanding (x + y)
                    if (vValue == 2) {
                        cout << "Expanding (x + y)^2: " << '\n';
                        cout << "Result: " << aValue << "x^2 + " << (2 * aValue * yValue) << "x + " << aValue * (pow(yValue, 2)) << '\n';
                    }
                    else if (vValue == 3) {
                        cout << "Expanding (x + y)^3: " << '\n';
                        cout << "Result: " << aValue << "x^3 + " << (3 * aValue * yValue) << "x^2 + " << (3 * aValue * pow(yValue, 2)) << "x + " << aValue * (pow(yValue, 3)) << '\n';
                    }
                    else if (vValue == 4) {
                        cout << "Expanding (x + y)^4: " << '\n';
                        cout << "vValue = 4 expansion not implemented yet" << '\n'; // Placeholder for future implementation
                    }
                }

                break;

            case 4: // Convert Standard form to Vertex form
                double bValue, cValue;
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

            case 6:
                double nValueF, mValueF;
                cout << "Converting standard form to factored. NOTE: Only when the trinomial" << '\n';
                
                cout << "has a = 1" << '\n';
                cout << "Enter A Value: ";
                cin >> aValue;
                cout << "Enter B Value: ";
                cin >> bValue;
                cout << "Enter C Value: ";
                cin >> cValue;

                // Check if the factors work
                if (checkAnswer(aValue, bValue, cValue, nValueF, mValueF)) {
                    cout << "The factors for AC are: n = " << nValueF << ", m = " << mValueF << '\n';
                    cout << "(x + " << nValueF << ")(x + " << mValueF << ")" << '\n';
                
                } 
                else {
                    cout << "No valid factors found for AC with the given bValue.\n";
                }

                break;
            case 7:

                break;

                

            
        } 


    cout << "Do you want to go back to the menu? (y/n): ";
    cin >> goBack;
    cout << " *********************************************************************************************** \n";
    }while(goBack == 'y' || goBack == 'Y');
    cout << " *********************************************************************************************** \n";
    
    return 0; // Exit the program
}


