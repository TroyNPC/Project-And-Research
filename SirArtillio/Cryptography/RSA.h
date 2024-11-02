class RSA {
public:

    bool is_prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long mod_exp(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }

    long long mod_inverse(long long e, long long phi) {
        long long t = 0, newt = 1;
        long long r = phi, newr = e;

        while (newr != 0) {
            long long quotient = r / newr;
            t = t - quotient * newt;
            swap(t, newt);
            r = r - quotient * newr;
            swap(r, newr);
        }

        if (r > 1) return -1; // No modular inverse exists
        if (t < 0) t += phi;
        return t;
    }

    // Generate random prime number between 2 and 100
    int generate_random_prime() {
        int prime;
        do {
            prime = rand() % 100 + 2;  
        } while (!is_prime(prime));
        return prime;
    }

    // Main RSA calculation
    void calculate_RSA(long long p, long long q, long long ptext) {
        cout << "1.) Two Prime Numbers: " << "P = " << p << ", Q = " << q;
        long long n = p * q;
        cout << "\n2.) n = p*q -> n = " << p << " * " << q << " = " << n;

        long long phi = (p - 1) * (q - 1);
        cout << "\n3.) (n) = (p-1) * (q-1) -> (n) = (" << p << "-1) * (" << q << "-1) = " << phi;
        vector<long long> possible_e;
        for (long long e = 3; e < phi; e++) {
            if (gcd(e, phi) == 1) {
                possible_e.push_back(e); 
            }
        }

        cout << "\n\nPossible values for e (gcd((n), e) = 1 and 1 < e < (n)):\n [";
        for (size_t i = 0; i < possible_e.size(); ++i) {
            cout << possible_e[i] << ",";
                    }
             cout << "]\n";

        long long choice_index;
        cout << "\nSelect e (1-" << possible_e.size() << "): ";
        cin >> choice_index;

        if (choice_index < 1 || choice_index > possible_e.size()) {
            cout << "Error: Invalid choice for e. Exiting...\n";
            again();
        }
        else{
        int remind = 0;
        for(int i =0; i<possible_e.size(); ++i){
            if(possible_e[i] == choice_index){
                remind = i;
            }
        }
        long double chosen_e = possible_e[remind]; 
        cout << "\n4.) Public Key (e) chosen: e = " << chosen_e;

        long long d = mod_inverse(chosen_e, phi);
        if (d == -1) {
            cout << "\nError: Could not find modular inverse for e. Exiting...\n";
            again();
        }
        else{
        cout << "\n5.) Private Key (d) calculated as the modular inverse of e mod (n) -> d = " << d;
        cout << "\n\nPublic key (e, n) => (" << chosen_e << ", " << n << ")\n";
        cout << "\nPrivate key (d, n) => (" << d << ", " << n << ")\n";

        cout << "\n\n6.) Now, encrypt using public key: ciphertext = (plaintext^e) % n\n";
        long long ciphertext = mod_exp(ptext, chosen_e, n);
        cout << "Ciphertext: " << ciphertext;

        cout << "\n7.) Decrypt using private key: plaintext = (ciphertext^d) % n\n";
        long long decrypted_plaintext = mod_exp(ciphertext, d, n);
        cout << "Decrypted Plaintext: " << decrypted_plaintext << endl;
    }
  }
 }

    void input() {
        system("cls");
        cout << "\n\n| ===== RSA ALGORITHM ===== |\n\n";
        long long p, q, plain_text;
        char choice;

        cout << "\nDo you want to input prime numbers? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "\nEnter your first prime number: ";
            cin >> p;
            if (!is_prime(p)) {
                cout << "Error: " << p << " is not a prime number. Exiting...\n";
                again();
            }

            cout << "\nEnter your second prime number: ";
            cin >> q;
            if (!is_prime(q)) {
                cout << "Error: " << q << " is not a prime number. Exiting...\n";
                again();
            }
        } else {
            srand(time(0)); 
            p = generate_random_prime();
            q = generate_random_prime();
            cout << "Random Prime Numbers Generated: P = " << p << ", Q = " << q << endl;
        }

        cout << "\nEnter your plain text number (Numbers Only): ";
        cin >> plain_text;

        cout << "\n\n| ==== RSA SOLUTION ==== |\n\n";
        calculate_RSA(p, q, plain_text);
        cout << "\n\n| ==== RSA SOLUTION ==== |\n\n";

        cout << "\n\n| ===== RSA ALGORITHM ===== |\n";
        again();
    }
};
