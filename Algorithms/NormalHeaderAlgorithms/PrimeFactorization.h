class PrimeFactor {
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

    int input() {
        system("cls");
        cout << "\n\n|| ===== PRIME FACTORIZATION ===== ||\n\n";

        vector<int> numbers;
        int num;
        char choice;

        do {
            cout << "\nEnter a number: ";
            cin >> num;
            numbers.push_back(num);

            cout << "\nDo you wish to input another number? (y/n): ";
            cin >> choice;
            choice = tolower(choice); 
            
        } while (choice == 'y');

        cout << "\n\n|| ===== PRIME FACTORIZATION RESULTS ===== ||\n";
        for (int number : numbers) {
            vector<int> factors = Prime_factorization(number);
            display_factors(factors, number);
        }
        cout << "\n\n|| ===== PRIME FACTORIZATION COMPLETE ===== ||\n\n";
           return again();
    }
};