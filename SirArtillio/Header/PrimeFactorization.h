//| =========== PRIME FACTORIZATION =========== |
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


    void input() {
        system("cls");
        cout << "\n\n|| ===== PRIME FACTORIZATION ===== ||\n\n";

        int num1, num2;
        cout << "\nEnter first number: ";
        cin >> num1;
        cout << "\nEnter second number: ";
        cin >> num2;

        vector<int> factors1 = Prime_factorization(num1);
        vector<int> factors2 = Prime_factorization(num2);

        display_factors(factors1, num1);
        display_factors(factors2, num2);

        cout << "\n\n|| ===== PRIME FACTORIZATION COMPLETE ===== ||\n\n";
        again();
    }
};
//| =========== PRIME FACTORIZATION =========== |
