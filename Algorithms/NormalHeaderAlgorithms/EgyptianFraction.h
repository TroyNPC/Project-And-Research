#include <iostream>
#include <vector>
using namespace std;

class EgyptianFraction {
public:
    void egyptianFraction(int num, int den) {
        vector<int> denominators;

        cout << "Egyptian Fraction Representation of " << num << "/" << den << " is: \n\n";
        cout << "Answer: " << num << "/" << den << " = ";

        cout << "\nSolution Steps:\n";

        while (num != 0) {
            int unitDen = (den + num - 1) / num;  
            denominators.push_back(unitDen);

            
            cout << "1/" << unitDen << " is added, remaining fraction is: ";
            cout << "(" << num << " * " << unitDen << " - " << den << ") / (" << den << " * " << unitDen << ")\n";

            
            num = num * unitDen - den;
            den = den * unitDen;
        }

        cout << "\nResult: ";
        for (size_t i = 0; i < denominators.size(); i++) {
            cout << "1/" << denominators[i];
            if (i != denominators.size() - 1) {
                cout << " + ";
            }
        }
        cout << endl;

        cout << "| ===== EGYPTIAN FRACTION ==== |\n\n";
    }

    int egyptian_input() {
        system("cls");
        cout << "| ===== EGYPTIAN FRACTION ==== |\n\n";
        int num, den;
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;

        if (num > den) {
            cout << "\n\n|| === NUMERATOR SHOULD BE LOWER THAN THE DENOMINATOR - INVALID === ||\n\n";
        } else {
            egyptianFraction(num, den);
        }
        return again();
    }
};

