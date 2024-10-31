class Bitwise {
public:
    void equalize_length_with_decimal(string &num1, string &num2) {
        size_t dot1 = num1.find('.');
        size_t dot2 = num2.find('.');

        
        if (dot1 == string::npos) dot1 = num1.length();
        if (dot2 == string::npos) dot2 = num2.length();

        
        int int_part_diff = (dot1 > dot2) ? dot1 - dot2 : dot2 - dot1;
        if (dot1 > dot2) {
            num2.insert(0, int_part_diff, '0');
        } else if (dot2 > dot1) {
            num1.insert(0, int_part_diff, '0');
        }

        
        int frac_part_diff = (num1.length() - dot1) - (num2.length() - dot2);
        if (frac_part_diff > 0) {
            num2.append(frac_part_diff, '0');
        } else if (frac_part_diff < 0) {
            num1.append(-frac_part_diff, '0');
        }
    }

    string thisand(const char *numbers, const char *numberstwo, int lengthone, int lengthtwo) {
        cout << "\n\n| === AND === |\n";
        cout << "\n1: "; 
        string str;
        cin.ignore();
        numbers = numbers_convertion(numbers);
        cout << " - Decimal value of num1: -> ";
        double numone = choose_bintodec(numbers);
        cout << "\n\n2: "; 
        numberstwo = second_numbers_convertion(numberstwo);
        cout << " - Decimal value of num2: -> ";
        double numtwo = choose_bintodec(numberstwo);

        string num1 = string(numbers);
        string num2 = string(numberstwo);

        equalize_length_with_decimal(num1, num2); 

        bool has_dot = (num1.find('.') != string::npos || num2.find('.') != string::npos);
        
        for (size_t i = 0; i < num1.length(); i++) {
            if (num1[i] == '.' || num2[i] == '.') {
                str += ".";  
            } else if (num1[i] == '1' && num2[i] == '1') {
                str += "1";
            } else {
                str += "0";
            }
        }

        cout << "\nResult: " << str;
        cout << " - Decimal value of Resulting Answer: -> ";
        const char* turnresult = str.c_str();
        double numresult = choose_bintodec(turnresult);
        return str;
    }

    string thisor(const char *numbers, const char *numberstwo, int lengthone, int lengthtwo) {
        cout << "\n\n| === OR === |\n";
        cout << "\n1: "; 
        string str;
        cin.ignore();
        numbers = numbers_convertion(numbers);
        cout << " - Decimal value of num1: -> ";
        double numone = choose_bintodec(numbers);
        cout << "\n\n2: ";
        numberstwo = second_numbers_convertion(numberstwo);
        cout << " - Decimal value of num2: -> ";
        double numtwo = choose_bintodec(numberstwo);
        string num1 = string(numbers);
        string num2 = string(numberstwo);

        equalize_length_with_decimal(num1, num2); 

        for (size_t i = 0; i < num1.length(); i++) {
            if (num1[i] == '.' || num2[i] == '.') {
                str += "."; 
            } else if (num1[i] == '1' || num2[i] == '1') {
                str += "1";
            } else {
                str += "0";
            }
        }

        cout << "\nResult: " << str;
        cout << " - Decimal value of Resulting Answer: -> ";
        const char* turnresult = str.c_str();
        double numresult = choose_bintodec(turnresult);
        return str;
    }

    string thisxor(const char *numbers, const char *numberstwo, int lengthone, int lengthtwo) {
        cout << "\n\n| === XOR === |\n";
        cout << "\n1: "; 
        string str;
        cin.ignore();
        numbers = numbers_convertion(numbers);
        cout << " - Decimal value of num1: -> ";
        double numone = choose_bintodec(numbers);
        cout << "\n\n2: ";
        numberstwo = second_numbers_convertion(numberstwo);
        cout << " - Decimal value of num2: -> ";
        double numtwo = choose_bintodec(numberstwo);
        string num1 = string(numbers);
        string num2 = string(numberstwo);

        equalize_length_with_decimal(num1, num2); 

        for (size_t i = 0; i < num1.length(); i++) {
            if (num1[i] == '.' || num2[i] == '.') {
                str += "."; 
            } else if (num1[i] != num2[i]) {
                str += "1";
            } else {
                str += "0";
            }
        }

        cout << "\nResult: " << str;
        cout << " - Decimal value of Resulting Answer: -> ";
        const char* turnresult = str.c_str();
        double numresult = choose_bintodec(turnresult);
        return str;
    }

    string thisnot(const char *numbers, int lengthone) {
        cout << "\n\n| === NOT === |\n";
        cout << "\n1: "; 
        cin.ignore();
        numbers = numbers_convertion(numbers);
        cout << " - Decimal value of num1: -> ";
        double numone = choose_bintodec(numbers);        
        string str;

        for (int i = 0; i < strlen(numbers); i++) {
            if (numbers[i] == '1') {
                str += "0";
            } else if (numbers[i] == '0') {
                str += "1";
            } else if (numbers[i] == '.') {
                str += ".";  
            }
        }
        cout << "\nResult: " << str;
        cout << " - Decimal value of Resulting Answer: -> ";
        const char* turnresult = str.c_str();
        double numresult = choose_bintodec(turnresult);
        return str;
    }
};


class Bitwiseinput : Bitwise {
public:    
    stop_errors stop;
    string input() {
        system("cls");
        cout << "\n\n| ===== BITWISE OPERATOR ===== |\n\n";
        cout << "\nA.) AND \n\n";
        cout << "\nB.) OR \n\n";
        cout << "\nC.) XOR \n\n";
        cout << "\nD.) NOT \n\n";
        cout << "\nE.) Go back to menu \n\n";
        bool run = true;  
        while(run){
            const char* numbers;
            const char* numberstwo;
            int lengthone;
            int lengthtwo; 
            char decision;
            cout << "\nChoose - ";
            cin >> decision;
            switch(toupper(decision)){       
            case 'A':
                thisand(numbers, numberstwo,  lengthone,  lengthtwo);
                again();
                run = false;
            break;            
            case 'B':
                thisor(numbers, numberstwo,  lengthone,  lengthtwo);
                again();
                cout << "\n"; 
                run = false;
            break;
            case 'C':
                thisxor(numbers, numberstwo,  lengthone,  lengthtwo);
                again();
                cout << "\n"; 
                run = false;
            break;
            case 'D':
                thisnot(numbers, lengthone);
                again();
                run = false;
                break;
            case 'E':
                go_back();
                run = false;
                break;
            default:
                stop.error();
                run = false;
                break;
            }
        }
        return "0";
    }
};
