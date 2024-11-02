//| =========== EUCLIDEAN =========== |
class euclidean{
private:
    int temp;
    int quotient;
    int a, b;
public:
    int solve_euclidean(int a, int b){
        cout << "\n\n| ====== Euclidean ====== |\n\n";
        int repetition = 1;
        while(b != 0){
            cout << "(" << repetition << " Loop)";
            cout << " -> " << a << " = " << b << "(" << a/b << ")";  
            temp = a%b;
            cout << " + " << temp << endl;
            a = b;
            b = temp;
            repetition++;
        }
        cout << "\n\nGCD = " << a << endl; 
        "\n\n| ====== Euclidean ====== |\n\n";
        again();
        return 0;
    };

};

class input : euclidean{
public:
    int value_check(int a1,int b1){
        if(a1 < b1){
            int temp = a1;
            a1 = b1;
            b1 = temp;
            solve_euclidean(a1,b1);
        }
        else{
            solve_euclidean(a1,b1);
        }
        return 0;
    }

    int encode(){
        system("cls");
        int a1, b1;
        cout << "|| ===== EUCLIDEAN ===== ||\n\n";
        cout << "\nNumber 1: ";
        cin >> a1;
        cout << "\nNumber 2: ";
        cin >> b1;
        value_check(a1, b1);
        return 0;
    }
};

//| =========== EUCLIDEAN =========== |