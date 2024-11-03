class CaesarCipher {
public:
    void calculate_letter(string str, int shift, bool encrypt, bool use_shift_key) {
        string result = "";
        for (int i = 0; i < str.length(); i++) {
            char letter = str[i];
            if (isalpha(letter)) {
                char base = isupper(letter) ? 'A' : 'a';
                int p = toupper(letter) - 'A';

                if (use_shift_key) {
                    if (encrypt) {
                        int shifted = (p + shift) % 26;
                        letter = shifted + base; // Convert back to letter
                    } else {
                        int shifted = (p - shift + 26) % 26;
                        letter = shifted + base; // Convert back to letter
                    }
                } else {
                    if (encrypt) {
                        int shifted = (p + 10) % 26;
                        cout << letter << " = f(" << p << ") = (" << p << " + 10) mod 26 = " << shifted << "\n";
                        letter = shifted + base; // Convert back to letter
                    } else {
                        int shifted = (p - 10 + 26) % 26;
                        cout << letter << " = f(" << p << ") = (" << p << " - 10) mod 26 = " << shifted << "\n";
                        letter = shifted + base; // Convert back to letter
                    }
                }
            }
            result += letter;
        }
        cout << "\nShifted String: " << result << "\n";
    }

    void input() {
        system("cls");
        cout << "\n\n|| ===== CAESAR CIPHER ===== ||\n\n";

        cout << "Choose an option: \nA.) Encrypt\nB.) Decrypt\nC.) Go back to menu";
        char choice;
        cout << "\n\nChoose - ";
        cin >> choice;
        cout << "\n";
        bool encrypt;
        bool can_access = false;
        if (choice == 'a' || choice == 'A') {
            encrypt = true;
            cout << "\nYou chose: Encrypt";
            can_access = true;
        } else if (choice == 'b' || choice == 'B') {
            encrypt = false;
            cout << "\nYou chose: Decrypt";
            can_access = true;
        } 
        else if(choice == 'c' || choice == 'C'){
        	go_back();
        }
        else {
            cout << "\n\n| ===== INVALID OPTION! ===== |\n\n";
            again();
        }
        if(can_access){
        cout << "\n\nChoose a method: \nA.) Shift Key\nB.) Shift Cipher\nC.) Go back to Menu";
        char method;
        cout << "\n\nChoose - ";
        cin >> method;
        cout << "\n";
        int shift;  
        bool use_shift_key = false;

        if (method == 'a' || method == 'A') {
            cout << "\nShift Key selected\n";
            cout << "\n\nEnter your shift key (0-25): ";
            cin >> shift;
            if (shift < 0 || shift > 25) {
                cout << "\n\n| ===== INVALID SHIFT KEY! ===== |\n\n";
                again();
            }
            use_shift_key = true;
            cout << "\nShift Key selected: " << shift;
        } 
        else if (method == 'b' || method == 'B') {
            cout << "\nShift Cipher selected\n";
            cout << "\n\nEnter your shift key (0-25): ";
            cin >> shift;
            if (shift < 0 || shift > 25) {
                cout << "\n\n| ===== INVALID SHIFT KEY! ===== |\n\n";
                again();
            }
        } 

        else if(method == 'c' || method == 'C'){
        	go_back();
       	}

        else {
            cout << "\n\n| ===== INVALID METHOD! ===== |\n\n";
            again();
        }

        cout << "\n\nEnter the string: ";
        string str;
        cin.ignore(); 
        getline(cin, str);

        cout << "\n\nOriginal string: " << str << endl << endl;
        calculate_letter(str, shift, encrypt, use_shift_key);
        again();
    }
      	else{
  		again();
 
  	}
  }

};
