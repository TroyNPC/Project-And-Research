//| =========== CHOICES =========== |
string choose_conversion();
string choose_calculator();
int again();
int go_back();
const char* numbers_convertion(const char* numbers);
const char* second_numbers_convertion(const char* numbers);
//| =========== CHOICES =========== |


// -------------------> THIS IS MY REUSABLE ERROR CHECK CODES <-------------------
//| =========== ERROR CHECKS =========== |
int again(){
    cout << "\n";
    system("Pause");
    cout << "\n\nDo you wish to try again? (Y/N) - ";
    char decision;
    cin >> decision;

    if(decision == 'y' || decision == 'Y'){
        system("cls");
        cout << "\n\n| ===== GOING BACK TO MENU ===== |\n\n";
        system("Pause");
        return main();
        return true;
    }
    else if(decision == 'n' || decision == 'N'){
        cout << "\n\n| ===== ENDING PROGRAM =====|\n\n";
        return false;
    }
    return false;
}

int again_conversion(){
    system("Pause");
    cout << "\n\nDo you wish to try again? (Conversion) (Y/N) - ";
    char decision;
    cin >> decision;

    if(decision == 'y' || decision == 'Y'){
        system("cls");
        cout << "\n\n| ===== GOING BACK TO MENU ===== |\n\n";
        system("Pause");
        choose_decisions('a');
        choose_conversion();
        return true;
    }
    else if(decision == 'n' || decision == 'N'){
        cout << "\n\n| ===== ENDING PROGRAM =====|\n\n";
        return false;
    }
    return false;
}

int again_operator(){
    system("Pause");
    cout << "\n\nDo you wish to try again? (Operation) (Y/N) - ";
    char decision;
    cin >> decision;

    if(decision == 'y' || decision == 'Y'){
        system("cls");
        cout << "\n\n| ===== GOING BACK TO MENU ===== |\n\n";
        system("Pause");
        choose_decisions('b');
        choose_calculator();    
        return true;
    }
    else if(decision == 'n' || decision == 'N'){
        cout << "\n\n| ===== ENDING PROGRAM =====|\n\n";
        return false;
    }
    return false;    
}

int size(const char *numbers){
    int length = strlen(numbers);
    return length;
}
int go_back(){
    cout << "\n";
    Sleep(1000);
    cout << ".";
    Sleep(1000);
    cout << " .";
    Sleep(1000);
    cout << " .";
    Sleep(1000);
    cout << "\n";
    system("Pause");
    return main();
}

int binary_check(const char* numbers, int length) {
    int dot = -1;
    string decimal;
    string fraction;
    for (int i = 0; i < length; i++) {
        if (numbers[i] == '.') {
            dot = i;
            break;
        } else {
            decimal += numbers[i];
        }
    }
    if (dot == -1) {
        dot = length;
    } else {
        for (int i = dot + 1; i < length; i++) {
            fraction += numbers[i];
        }
    }

    for (int i = dot-1; i >= 0; i--) {
        if (numbers[i] != '0' && numbers[i] != '1') {
            cout << "\n\n| === INVALID VALUES DETECTED === |\n";
            return 1;  
        }
    }
    if (!fraction.empty()) {
        for (int i = dot+1; i < length; i++) {
            if (numbers[i] != '0' && numbers[i] != '1') {
                cout << "\n\n| === INVALID VALUES DETECTED === |\n";
                return 1;  
            }
        }
    }

    return 0; 
}

int octal_check(const char*numbers, int length){
    int dot = -1;
    string decimal;
    string fraction;
    for (int i = 0; i < length; i++) {
        if (numbers[i] == '.') {
            dot = i;
            break;
        } else {
            decimal += numbers[i];
        }
    }
    if (dot == -1) {
        dot = length;
    } else {
        for (int i = dot + 1; i < length; i++) {
            fraction += numbers[i];
        }
    }
    for (int i = dot-1; i >= 0; i--) {
        if (!(numbers[i] >= '0' && numbers[i] <= '7')){
            cout << "\n\n| === INVALID VALUES DETECTED === |\n";
            return 1;  
        }
    }
    if (!fraction.empty()) {
        for (int i = dot+1; i < length; i++) {
            if (!(numbers[i] >= '0' && numbers[i] <= '7')) {
                cout << "\n\n| === INVALID VALUES DETECTED  === |\n";
                return 1;  
            }
        }
    }

    return 0; 
}

int decimal_check(const char*numbers, int length){
    int dot = -1;
    string decimal;
    string fraction;
    for (int i = 0; i < length; i++) {
        if (numbers[i] == '.') {
            dot = i;
            break;
        } else {
            decimal += numbers[i];
        }
    }
    if (dot == -1) {
        dot = length;
    } else {
        for (int i = dot + 1; i < length; i++) {
            fraction += numbers[i];
        }
    }
    for (int i = dot-1; i >= 0; i--) {
        if (!(numbers[i] >= '0' && numbers[i] <= '9')) {
            cout << "\n\n| === INVALID VALUES DETECTED === |\n";
            return 1;  
        }
    }
    if (!fraction.empty()) {
        for (int i = dot+1; i < length; i++) {
            if (!(numbers[i] >= '0' && numbers[i] <= '9')) {
                cout << "\n\n| === INVALID VALUES DETECTED IN THE FRACTIONAL PART z=== |\n";
                return 1;  
            }
        }
    }

    return 0; 
}
int hexadecimal_check(const char*numbers, int length){
    int dot = -1;
    string decimal;
    string fraction;
    for (int i = 0; i < length; i++) {
        if (numbers[i] == '.') {
            dot = i;
            break;
        } else {
            decimal += numbers[i];
        }
    }
    if (dot == -1) {
        dot = length;
    } else {
        for (int i = dot + 1; i < length; i++) {
            fraction += numbers[i];
        }
    }
    for (int i = dot-1; i >= 0; i--) {
        if((numbers[i] <= '0' && numbers[i] >= '9') || (numbers[i] <= 'A' && numbers[i] >= 'F') || (numbers[i] <= 'a' && numbers[i] >= 'f')) {
            cout << "\n\n| === INVALID VALUES DETECTED === |\n";
            return 1;  
        }
    }
    if (!fraction.empty()) {
        for (int i = dot+1; i < length; i++) {
            if((numbers[i] <= '0' && numbers[i] >= '9') || (numbers[i] <= 'A' && numbers[i] >= 'F') || (numbers[i] <= 'a' && numbers[i] >= 'f')) {
                cout << "\n\n| === INVALID VALUES DETECTED IN THE FRACTIONAL PART z=== |\n";
                return 1;  
            }
        }
    }

    return 0;
}

const char* numbers_convertion(const char* numbers){
    static string input_num;
    cout << "Input your number - ";
    getline(cin, input_num);
    numbers = input_num.c_str();
    int length = strlen(numbers);
    for(int i = 0;i<length; i++){
        if(numbers[i] >= 71 && numbers[i] <= 90 || numbers[i] >= 103 && numbers[i] <= 122){
            cout << "\n\n| === INVALID === |\n\n";
            again();
            return nullptr;
        }
    }
    return numbers;
}
const char* second_numbers_convertion(const char* numbers){
    static string input_num;
    cout << "Input your number - ";
    getline(cin, input_num);
    numbers = input_num.c_str();
    int length = strlen(numbers);
    for(int i = 0;i<length; i++){
        if(numbers[i] >= 71 && numbers[i] <= 90 || numbers[i] >= 103 && numbers[i] <= 122){
            cout << "\n\n| === INVALID === |\n\n";
            again();
            return nullptr;
        }
    }
    return numbers;
}
//| =========== ERROR CHECKS =========== |
// -------------------> THIS IS MY REUSABLE ERROR CHECK CODES <-------------------