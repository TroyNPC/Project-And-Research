class LCDandGCD {
public:
    vector<int> Prime_factorization(int num) {
        vector<int> factors;
        for (int i = 2; i <= num; i++) {
            while (num % i == 0) {
                factors.push_back(i);
                num /= i;
            }
        }
        return factors;
    }

    void display_factors(const vector<int>& factors, int num) {
        cout << "\nPrime factors of " << num << ": ";
        for (int i = 0; i < factors.size(); i++) {
            cout << factors[i];
            if (i < factors.size() - 1) {
                cout << " * ";
            }
        }
        cout << "\n";
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcm(int a, int b, int gcd_value) {
        return (a * b) / gcd_value;
    }

    void input() {
        system("cls");
        cout << "\n\n|| ===== LCD AND GCD ===== ||\n\n";

        vector<int> numbers;
        int num;
        char choice;

        
        do {
            cout << "\nEnter a number: ";
            cin >> num;

            
            if(cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid input. Exiting input loop." << endl;
                break;
            }

            numbers.push_back(num);

            cout << "\nDo you want to enter another number? (y/n): ";
            cin >> choice;

        } while(choice == 'y' || choice == 'Y');


        if (numbers.size() < 2) {
            cout << "At least two numbers are required for GCD and LCM calculations." << endl;
            return;
        }

        vector<vector<int>> all_factors;
        for (int i = 0; i < numbers.size(); i++) {
            vector<int> factors = Prime_factorization(numbers[i]);
            display_factors(factors, numbers[i]);
            all_factors.push_back(factors);
        }

        int gcd_value = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            gcd_value = gcd(gcd_value, numbers[i]);
        }

        int lcm_value = numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            lcm_value = lcm(lcm_value, numbers[i], gcd(lcm_value, numbers[i]));
        }

        cout << "\nGCD of entered numbers = " << gcd_value << endl;
        cout << "\nLCM of entered numbers = " << lcm_value << endl;

        cout << "\n\n|| ===== LCD AND GCD COMPLETE ===== ||\n\n";
        again();
    }
};
