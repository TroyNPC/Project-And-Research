//| =========== PRIME NUMBER =========== |
class Prime{
public:
    void sieve_of_eratosthenes(int n){
    vector<bool> prime(n + 1, true);  
    prime[0] = prime[1] = false;    
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    cout << "\nPrime numbers up to " << n << " are: \n\n";
    for (int p = 2; p <= n; p++) {
        if (prime[p]){
            cout << p << "| ";
        }
    }
        cout << endl;
    cout << endl; 
    cout << "\n\n| ====== SIEVE OF ERATOSTHENES ====== |\n\n";
    again();       
    }

    void input(){
        system("cls");
        cout << "\n\n| ====== SIEVE OF ERATOSTHENES ====== |\n\n";
        cout << "\n\nEnter your limit: ";
        string a;
        cin.ignore();
        bool okay = true;
        getline(cin, a);
        for(int i = 0; i<a.size(); i++){
            if(a[i] <= '0' && a[i] >= '9' || a[i] == '.'){
                cout << "\n\n|| ========  INVALID VALUE ======== ||\n\n";
                okay = false;
                again();
                break;
            }
        }
        if(okay == true){
            int n = stoi(a);
            sieve_of_eratosthenes(n);
        }
        else{
            again();
        }
    }
};

//| =========== PRIME NUMBER =========== |