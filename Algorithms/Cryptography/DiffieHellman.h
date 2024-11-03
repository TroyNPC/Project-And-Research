class DiffieHellman {
private:
    long long int p;
    long long int g;
    long long int privateKeyA;
    long long int privateKeyB;
    long long int publicKeyA;
    long long int publicKeyB;
    long long int sharedSecretA;
    long long int sharedSecretB;

public:

    long long int modExp(long long int base, long long int exp, long long int mod) {
        long long int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp / 2;
        }
        return result;
    }

    void setInput(long long int prime, long long int root, long long int privKeyA, long long int privKeyB) {
        p = prime;
        g = root;
        privateKeyA = privKeyA;
        privateKeyB = privKeyB;
    }

    void generatePublicKeys() {

    	cout << "\n\n| ====== SOLUTIONS ====== |\n\n";
        publicKeyA = modExp(g, privateKeyA, p);
        publicKeyB = modExp(g, privateKeyB, p);

        cout << "\nAlice's public key solution:\n";
        cout << "g^a mod p = " << g << "^" << privateKeyA << " mod " << p << " = " << publicKeyA << "\n";
        
        cout << "\nBob's public key solution:\n";
        cout << "g^b mod p = " << g << "^" << privateKeyB << " mod " << p << " = " << publicKeyB << "\n";
    }

    void computeSharedSecrets() {
        sharedSecretA = modExp(publicKeyB, privateKeyA, p);
        sharedSecretB = modExp(publicKeyA, privateKeyB, p);

        cout << "\nAlice's shared secret solution:\n";
        cout << "PublicKeyB^a mod p = " << publicKeyB << "^" << privateKeyA << " mod " << p << " = " << sharedSecretA << "\n";
        
        cout << "\nBob's shared secret solution:\n";
        cout << "PublicKeyA^b mod p = " << publicKeyA << "^" << privateKeyB << " mod " << p << " = " << sharedSecretB << "\n";
    	cout << "\n\n| ====== SOLUTIONS ====== |\n\n";
    }

    bool validateSharedSecrets() {
        return sharedSecretA == sharedSecretB;
    }

    void input() {
    	system("cls");
    	cout << "\n|| ===== DiffieHellman ===== ||\n\n";
        long long int q, g, privKeyA, privKeyB;

        cout << "Enter a large prime number (q): ";
        cin >> q;

        cout << "Enter a primitive root modulo q (g): ";
        cin >> g;

        cout << "Enter Alice's secret key: ";
        cin >> privKeyA;

        cout << "Enter Bob's secret key: ";
        cin >> privKeyB;

        setInput(q, g, privKeyA, privKeyB);

        generatePublicKeys();
        computeSharedSecrets();

        if (validateSharedSecrets()) {
            cout << "\nShared secrets match! Key exchange is successful.\n";
            again();
        } else {
            cout << "\nShared secrets do not match! Something went wrong.\n";
            again();
        }
    }
};
