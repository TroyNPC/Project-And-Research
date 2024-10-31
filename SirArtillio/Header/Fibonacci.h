//| =========== FIBONACCI =========== |
class Fibonacci {
private:
    int temp;
public:
    int run(int n, int lim) {
        cout << "\n\n| ====== FIBONACCI ====== |\n\n";
        vector<int> array(lim);
        array[0] = 0;
        if (lim > 1) {
            array[1] = 1;
        }

        if (lim <= 0) {
            cout << "Fib(0) = 0\n";
            return 0;
        }
        if (lim == 1) {
            cout << "Fib(0) = 0\n";
            cout << "Fib(1) = 1\n";
            again();
            return 0;
        }

        cout << "Fib(0) = 0\n";
        if (lim > 1) {
            cout << "Fib(1) = 1\n";
        }

        for (int i = 2; i <= lim; i++) {
            array[i] = array[i - 1] + array[i - 2];
        }

        for (int i = n; i <= lim; i++) {
            if (i == 0 || i == 1) {
                continue;  
            }
            cout << "\nFib(" << i << ") = Fib(" << i - 1 << ") + Fib(" << i - 2 << ")\n";
            cout << array[i - 1] << " + " << array[i - 2] << "\n";
            cout << " = " << array[i] << endl;
        }

        cout << "\n\n\nFibonacci Sequence [";
        for (int i = 0; i <= lim; i++) {
            cout << array[i];
            if (i <= lim - 1) cout << ",";
        }
        cout << "]";
        cout << "\n\n| ====== FIBONACCI ====== |\n\n";
        again();
        return 0;
    };

    string fibonacci_input() {
        system("cls");
        cout << "| ===== FIBONACCI ==== |\n\n";
        cout << "\nEnter where to start [First index]: ";
        int a; cin >> a;
        cout << "\nEnter where to end [Last Index]: ";
        int b; cin >> b;
        if(b > a){
            cout << "\n\n| ==== THIS IS INVALID ==== |\n\n";
            again();
        }
        else{
        run(a, b);
        }
        return "0";
    }
};
//| =========== FIBONACCI =========== |
