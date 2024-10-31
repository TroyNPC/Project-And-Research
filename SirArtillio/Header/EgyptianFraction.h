//| =========== EGYPTIAN FRACTION =========== |
class EgyptianFraction{
public:
    void egyptianFraction(int num, int den) {
        vector<int> denominators;  

        cout << "Egyptian Fraction Representation of " << num << "/" << den << " is: \n\n";
        cout << "Answer: " << num << "/" << den << " = ";

        while (num != 0) {
            int unitDen = (den + num - 1) / num;
            denominators.push_back(unitDen); 
            num = num * unitDen - den;
            den = den * unitDen;
        }

        for (size_t i = 0; i < denominators.size(); i++) {
            cout << "1/" << denominators[i];
            if (i != denominators.size() - 1) {
                cout << " + "; 
            }
        }
        cout << endl << endl;
        cout << "| ===== EGYPTIAN FRACTION ==== |\n\n";
        again();
    }   

    void egyptian_input(){
        system("cls");
        cout << "| ===== EGYPTIAN FRACTION ==== |\n\n";
        int num, den;
        cout << "Enter numerator: ";
        cin >> num;
        cout << "Enter denominator: ";
        cin >> den;

        if(num > den){
            cout << "\n\n|| === NUMERATOR SHOULD BE LOWER THAN THE NUMERATOR - INVALID === ||\n\n";
            again();
        }
        else{
            egyptianFraction(num, den);
        }
    }
};
//| =========== EGYPTIAN FRACTION =========== |