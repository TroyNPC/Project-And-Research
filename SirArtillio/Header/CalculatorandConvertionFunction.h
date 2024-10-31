//| =========== Calculation or Convertion =========== |
string choose_conversion(){
    const char* numbers;
    int length;
    char select_convertion;
    cout << "\n\n CHOOSE - ";
    cin >> select_convertion;
    cin.ignore();
    bool run = true;
    while(run){
       switch(toupper(select_convertion)){
        case 'A': 
        cout << "\n\nYou have chosen Binary to Decimal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if (binary_check(numbers, length) == 0) {  
                cout << "\nBinary to Decimal: ";
                choose_bintodec(numbers);
                again_conversion(); 
        } 
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'B':
        cout << "\n\nYou have chosen Decimal to Binary\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if(decimal_check(numbers, length)== 0){
        cout << "\nDecimal to Binary: ";
        choose_dectobin(numbers);
        again_conversion();
        }
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'C':
        
        cout << "\n\nYou have chosen Binary to Octal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
            if (binary_check(numbers, length) == 0) {  
                choose_bintoocta(numbers);
                again_conversion(); 
            }
            else{
            again_conversion();
        } 
        run = false;
        break;
        case 'D':
        
        cout << "\n\nYou have chosen Octal to Binary\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if(octal_check(numbers,length) == 0){
            choose_octatobin(numbers);
            again_conversion();
        }
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'E':
        
        cout << "\n\nYou have chosen Binary to Hexadecimal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if (binary_check(numbers, length) == 0){
            choose_bintohexa(numbers);  
            again_conversion(); 
        } 
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'F':
        
        cout << "\n\nYou have chosen Hexadecimal to Binary\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if (hexadecimal_check(numbers, length) == 0) {  
                choose_hexatobin(numbers);
                again_conversion(); 
        } 
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'G':
        
        cout << "\n\nYou have chosen Octal to Decimal \n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if(octal_check(numbers,length) == 0){
            cout << "\nOctal to Decimal: ";
            choose_octaltodec(numbers);
            again_conversion();
        }
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'H':
        
        cout << "\n\nYou have chosen Decimal to Octal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if(decimal_check(numbers, length)== 0){
            cout << "\nDecimal to Octal: ";
            choose_dectooctal(numbers);
            again_conversion();
        }
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'I':
        
        cout << "\n\nYou have chosen Octal to Hexadecimal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        choose_octaltohexa(numbers);
        if(octal_check(numbers,length) == 0){
            again_conversion();
        }
        run = false;
        break;
        case 'J':
        
        cout << "\n\nYou have chosen Hexadecimal to Octal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if (hexadecimal_check(numbers, length) == 0) { 
                choose_hexatooctal(numbers); 
                again_conversion(); 
        } 
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'K':
        
        cout << "\n\nYou have chosen Hexadecimal to Decimal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if (hexadecimal_check(numbers, length) == 0) {
            cout << "\nHexadecimal to Decimal: ";
            choose_hexatodec(numbers);  
            again_conversion(); 
        }
        else{
            again_conversion();
        }
        run = false;
        break;
        case 'L':
        
        cout << "\n\nYou have chosen Decimal to Hexadecimal\n\n";
        numbers = numbers_convertion(numbers);
        length = size(numbers);
        if(decimal_check(numbers, length)== 0){
            cout << "\nDecimal to Hexadecimal: ";
            choose_dectohexa(numbers);
            again_conversion();
        }
        else{
            choose_dectohexa(numbers);
        }
        run = false; 
        break;
        case 'M':

        cout << "\n| === You have chosen to Go back To Menu === |\n\n"; 
        go_back();
        run = false; 
        break; 
        default:
            stop_errors();
            again();
            run = false;
        break;
       } 
    }

    return "";
}

string choose_calculator() {
    bool run = true;
    cout << "\nChoose - ";
    while (run) {
        char decision;
        cin >> decision;
        const char* numbers;
        const char* numberstwo;
        int lengthone;
        int lengthtwo;
        string operators;
        switch (toupper(decision)) {
            case 'A':
                cout << "\n\n| === Binary === |\n";
                cout << "\n1: "; 
                cin.ignore();
                numbers = numbers_convertion(numbers);
                lengthone = binary_check(numbers, strlen(numbers));
                if (lengthone == 0) {  
                    cout << "\nEnter Operator: ";
                    getline(cin, operators);
                    if(operators != "+" && operators != "-" && operators != "*" && operators != "/"){
                        again_operator();
                        run = false;
                        break;
                    }
                    
                    cout << "\n2: ";
                    numberstwo = second_numbers_convertion(numberstwo);
                    lengthtwo = binary_check(numberstwo, strlen(numberstwo));
                    if(lengthtwo == 0){    
                        long double num1 = binary_convert(numbers);
                        long double num2 = binary_convert(numberstwo);
                        string answer = calc(num1,num2,operators);
                        const char* nums = answer.c_str();
                        cout << "\n\nResult: ";
                        choose_dectobin(nums);
                        cout << endl << endl;
                        again_operator();
                        run = false;
                        break;
                    } 
                    else{
                        again_operator();
                        run = false;
                        break;
                    }
                } 
                else{
                    again_operator();
                    run = false;
                    break;
                }
                break;
           case 'B':
                cout << "\n\n| === Octal === |\n";
                cout << "\n1: "; 
                cin.ignore();
                numbers = numbers_convertion(numbers);
                lengthone = octal_check(numbers, strlen(numbers));
                if (lengthone == 0) {  
                    cout << "\nEnter Operator: ";
                    getline(cin, operators);
                    if(operators != "+" && operators != "-" && operators != "*" && operators != "/"){
                        again_operator();
                        run = false;
                        break;
                    }
                    
                    cout << "\n2: ";
                    numberstwo = second_numbers_convertion(numberstwo);
                    lengthtwo = octal_check(numberstwo, strlen(numberstwo));
                    if(lengthtwo == 0){    
                        string numone = octal_convert(numbers);
                        long double num1 = stod(numone);
                        string numtwo = octal_convert(numberstwo);
                        long double num2 = stod(numtwo);
                        string answer = calc(num1,num2,operators);
                        const char* nums = answer.c_str();
                        cout << "\n\nResult: ";
                        choose_dectooctal(nums);
                        cout << endl << endl;
                        again_operator();
                        run = false;
                        break;
                    } 
                    else{
                        again_operator();
                        run = false;
                        break;
                    }
                } 
                else{
                    again_operator();
                    run = false;
                    break;
                }
                break;
            case 'C':
                cout << "\n\n| === Hexadecimal === |\n";
                cout << "\n1: "; 
                cin.ignore();
                numbers = numbers_convertion(numbers);
                lengthone = hexadecimal_check(numbers, strlen(numbers));
                if (lengthone == 0) {  
                    cout << "\nEnter Operator: ";
                    getline(cin, operators);
                    if(operators != "+" && operators != "-" && operators != "*" && operators != "/"){
                        again_operator();
                        run = false;
                        break;
                    }
                    
                    cout << "\n2: ";
                    numberstwo = second_numbers_convertion(numberstwo);
                    lengthtwo = hexadecimal_check(numberstwo, strlen(numberstwo));
                    if(lengthtwo == 0){    
                        string numone = hexadecimal_convert(numbers);
                        long double num1 = stod(numone);

                        string numtwo = hexadecimal_convert(numberstwo);
                        long double num2 = stod(numtwo);

                        string answer = calc(num1,num2,operators) ;
                        const char* nums = answer.c_str();
                        cout << "\nResult: ";
                        choose_dectohexa(nums);
                        cout << endl << endl;
                        again_operator();
                        run = false;
                        break;
                    } 
                    else{
                        again_operator();
                        run = false;
                        break;
                    }
                } 
                else{
                    again_operator();
                    run = false;
                    break;
                }
                break;
                case 'D':
                    cout << "\n| === You have chosen to Go back To Menu === |\n\n"; 
                    go_back();
                    run = false;
                    break;
            default:
                stop_errors();
                again();
                run = false;
                break;
        }   
    }
    return 0;
}
//| =========== Calculation or Convertion =========== |





//| ========== CODES FOR EACH CONVERTIONS AND OPERATORS ========== |

//| ==== Binary to Decimal/Decimal to Binary ==== |
double choose_bintodec(const char *num){
    long double decimalpart = 0.0;
    long double fraction = 0.0;
    int exponent = 0;
    int length = strlen(num);
    int dot = -1;

    for (int i = 0; i < length; i++) {
        if (num[i] == '.') {
            dot = i;
            break;
        }
    }
    if (dot == -1) {
        dot = length;
    }

    for (int i = dot - 1; i >= 0; i--) {
        if (num[i] == '1') {
            decimalpart += (long double)pow(2, exponent);
        }
        exponent++;
    }

    long double fractionstart = 0.5;
    for (int i = dot + 1; i < length; i++) {
        if (num[i] == '1') {
            fraction += fractionstart;
        }
        fractionstart /= 2;
    }

    long double value = decimalpart+fraction;
    if(dot != length){
        length-=dot;
        cout << fixed << setprecision(length-1) << value << endl;
        }
    else{
        cout << fixed << setprecision(0) << value << endl;
        }
 
    return 0;
}

double choose_dectobin(const char *num){
    int decimalpart = 0;
    int exponent = 0;
    int length = strlen(num);
    int dot = -1;   

    string holdernumbers = "";
    string holderfraction = "";

     int number = 0;
    double fraction = 0; 
    for(int i = 0; i<length; i++){
        if(num[i] == '.'){
            dot = i;
            break;
        }
        else{
            holdernumbers+=num[i];
        }
    }

    if(dot == -1){
        dot = length;
    }
    else{
        for(int i = dot+1; i<length; i++){
            holderfraction+=num[i];
        }

        fraction = stod("0." + holderfraction);
    }
        number = stoi(holdernumbers);

        int remainder = 1;
        int divisor = 0;

        string nonfractionbinary = "";
            
        while(number != 0){
            remainder = number % 2;
            number = number/2;
            string str = to_string(remainder);
            nonfractionbinary = str+nonfractionbinary;
        }
        cout << nonfractionbinary;
        string fractionbinary = "";
        if(fraction > 0.0){ 
            cout << "."; 
            while(fraction > 0.0 && fractionbinary.size() < 20){
                fraction *= 2;
                int bit = static_cast<int>(fraction);
                if(bit == 1){
                    fractionbinary += '1';
                    fraction -= 1;
                }
                else{
                    fractionbinary += '0';
                }
            }
            cout << fractionbinary << endl << endl;
        }

        return 0;
}
//| ==== Binary to Decimal/Decimal to Binary ==== |


//| ==== Binary to Octal/Octal to Binary ==== |
double choose_bintoocta(const char *num) {  
    int decimalpart = 0;
    long double fraction = 0.0;
    int exponent = 0;
    int length = strlen(num);
    int dot = -1;

    for (int i = 0; i < length; i++) {
        if (num[i] == '.') {
            dot = i;
            break;
        }
    }
    if (dot == -1) {
        dot = length;
    }
    
const char *number  = num;
    
    for (int i = dot - 1; i >= 0; i--) {
        if (num[i] == '1') {
            decimalpart += (long double)pow(2, exponent);
        }
        exponent++;
        number++;
    }

    int octal = 0;
    exponent = 1;

    while(decimalpart != 0){    
        octal+=(decimalpart%8) * exponent;
        decimalpart/=8;
        exponent*=10;
    }

    if(*number == '.'){
        ++number;
        double power = 0.5;
        while(*number!='\0'){
            if(*number == '1'){
                fraction+=power;
            }
            power/=2;
            number++;
        }
    }

     string octalFractional = "";
    while (fraction > 0.0 && octalFractional.size() < 10) { 
        fraction *= 8;
        int digit = static_cast<int>(fraction);
        octalFractional += to_string(digit);
        fraction -= digit;
    }
    if (!octalFractional.empty()) {
        cout << "\nBinary to Octal: " << octal << "." << octalFractional << endl;
    } else {
        cout << "\nBinary to Octal: "  << octal << endl;
    }

    return 0;
}
double choose_octatobin(const char *num){
    int decimalpart = 0;
    long double fraction = 0.0;
    int exponent = 0;
    int length = strlen(num);
    int dot = -1;   

    for(int i = 0; i<length; i++){
        if(num[i] == '.'){
            dot = i;
            break;
        }
    }

    if(dot == -1){
        dot = length;
    }
    const char *number = num;
    for(int i = 0;i<dot;i++){
            decimalpart = decimalpart * 8 + (num[i] - '0');
        }

        string nonfractionbinary = "";
        while(decimalpart > 0){
            int remainder = decimalpart%2;
            nonfractionbinary = to_string(remainder) + nonfractionbinary;
            decimalpart/=2;
        }

        if(dot < length - 1){
            ++number;
            double power = 0.125;
            for(int i = dot+1; i<length; i++){
                fraction+=(num[i]-'0')*power;
                power/=8;
            }
        }

        string fractionbinary = "";
        while(fraction > 0.0 && fractionbinary.size() < 30){
            fraction*=2;
            int digit = static_cast<int>(fraction);
            fractionbinary += to_string(digit);
            fraction-=digit;
        }

        cout << "\nOctal to Binary: " << nonfractionbinary;
        if(!fractionbinary.empty()){
            cout << "." << fractionbinary << "\n";
        }
           else{
            cout << endl;
        }
        return 0;
}
//| ==== Binary to Octal/Octal to Binary ==== |

//| ==== Binary to Hexa/Hexa to Binary ==== |
double choose_bintohexa(const char* num){
 int hex[1000];
 string holdernumbers = "";
 string holderfraction = "";

 int length = strlen(num);
 int dot = 0;

  for(int i = 0; i < length; i++){
    if(num[i] == '.'){
        dot = i;
        break;
    }
    else{
        holdernumbers+=num[i];
    }
  }

  if(dot == 0){
    dot = length;
  }

  else{
    for(int i = dot + 1; i<length; i++){
        holderfraction+=num[i];
    }
  }

  int decimal = 0;
  int exponent = 0;
  for(int i = holdernumbers.length()-1; i>=0; i--){
    if(holdernumbers[i] == '1'){
        decimal += pow(2,exponent);
    }
    exponent++;
  }

  int hexindex = 0;
  while(decimal > 0){
    hex[hexindex] = decimal % 16;
    decimal = decimal/16;
    hexindex++;
  }

  cout << "\nBinary to Hexadecimal: ";
  for(int i = hexindex-1; i>=0; i--){
    if(hex[i] > 9){
        cout << (char)(hex[i]+55);
    }
    else{
        cout << hex[i];
    }
  }

  if(!holderfraction.empty()){
    long double fraction = 0.0;
    long double power = 0.5;
    const char* bits;
    for(char bits : holderfraction){
       if(bits == '1'){
        fraction+=power;
       }
       power/=2;
    }

    string hexfract = "";
    int max = 10;
    while(fraction > 0.0 && hexfract.length() < max){
        fraction*=16;
        int digits= static_cast<int>(fraction);
        if(digits>9){
            hexfract += (char)(digits+55);
        }
        else{
            hexfract +=to_string(digits);
        }
        fraction-=digits;
    }
    cout<< "." << hexfract;
  }
  cout << endl;
  return 0;
}

double choose_hexatobin(const char* num) {
    int length = strlen(num);
    int dot = -1;
    for (int i = 0; i < length; i++) {
        if (num[i] == '.') {
            dot = i;
            break;
        }
    }

    if (dot == -1) {
        dot = length; 
    }

    string holdbinaries[length];
    for (int i = 0; i < dot; i++) {
        switch (toupper(num[i])) {
            case '0': 
                holdbinaries[i] = "0000"; 
            break;
            case '1': 
                holdbinaries[i] = "0001";
             break;
            case '2': 
                holdbinaries[i] = "0010";
             break;
            case '3': 
                holdbinaries[i] = "0011";
             break;
            case '4': 
                holdbinaries[i] = "0100"; 
            break;
            case '5': 
                holdbinaries[i] = "0101"; 
            break;
            case '6': 
                holdbinaries[i] = "0110"; 
            break;
            case '7': 
                holdbinaries[i] = "0111"; 
            break;
            case '8': 
                holdbinaries[i] = "1000"; 
            break;
            case '9': 
                holdbinaries[i] = "1001"; 
            break;
            case 'A':
            case 'a': 
                holdbinaries[i] = "1010"; 
            break;
            case 'B': 
            case 'b':
                holdbinaries[i] = "1011"; 
            break;
            case 'C':
            case 'c': 
                holdbinaries[i] = "1100"; 
            break;
            case 'D':
            case 'd':
             holdbinaries[i] = "1101"; 
             break;
            case 'E':
            case 'e':
                holdbinaries[i] = "1110";
             break;
            case 'F':
            case 'f': 
                holdbinaries[i] = "1111"; 
            break;
            default: cout << "Invalid Hex Character!\n"; return -1;
        }
    }

    if (dot < length - 1) {
        holdbinaries[dot] = ".";
        for (int i = dot + 1; i < length; i++) {
            switch (toupper(num[i])) {
                case '0': 
                    holdbinaries[i] = "0000"; 
                    break;
                case '1': 
                    holdbinaries[i] = "0001"; 
                break;
                case '2':
                 holdbinaries[i] = "0010"; 
                 break;
                case '3': 
                    holdbinaries[i] = "0011"; 
                break;
                case '4': 
                    holdbinaries[i] = "0100"; 
                break;
                case '5': 
                    holdbinaries[i] = "0101"; 
                break;
                case '6': 
                    holdbinaries[i] = "0110";
                 break;
                case '7': 
                    holdbinaries[i] = "0111"; 
                break;
                case '8': 
                    holdbinaries[i] = "1000"; 
                break;
                case '9': 
                    holdbinaries[i] = "1001"; 
                break;
                case 'A': 
                case 'a':
                    holdbinaries[i] = "1010"; 
                break;
                case 'B':
                case 'b': 
                    holdbinaries[i] = "1011"; 
                break;
                case 'C':
                case 'c': 
                    holdbinaries[i] = "1100"; 
                break;
                case 'D':
                case 'd': 
                    holdbinaries[i] = "1101"; 
                break;
                case 'E':
                case 'e':
                    holdbinaries[i] = "1110"; 
                break;
                case 'F':
                case 'f': 
                    holdbinaries[i] = "1111"; 
                break;
                default: cout << "Invalid Hex Character!\n"; return -1;
            }
        }
    }

    cout << "\nHexadecimal to Binary: ";
    for (int i = 0; i < length; i++) {
        cout << holdbinaries[i];
    }
    cout << endl;

    return 0;
}
//| ==== Binary to Hexa/Hexa to Binary ==== |

//| ==== Octal to Decimal/Decimal to Octal ==== |
double choose_octaltodec(const char* num) {
    int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(num);

    for (int i = 0; i < length; i++) {
        if (num[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += num[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += num[i];
        }
    }

    int octalInteger = stoi(holdernumbers);
    int decimalInteger = 0, exponent = 0, rem = 0;
    while (octalInteger != 0) {
        rem = octalInteger % 10;
        decimalInteger += rem * pow(8, exponent);
        octalInteger /= 10;
        exponent++;
    }

    double decimalFraction = 0.0;
    if (!holderfraction.empty()) {
        for (int i = 0; i < holderfraction.size(); i++) {
            int digit = holderfraction[i] - '0'; 
            decimalFraction += digit * pow(8, -(i + 1));
        }
    }

    double result = decimalInteger + decimalFraction;
    stringstream ss;
    ss.precision(19);
    ss << fixed << result;

    string resultStr = ss.str();
    resultStr.erase(resultStr.find_last_not_of('0') + 1); 
    if (resultStr.back() == '.') {
        resultStr.pop_back();  
    }

    // Output the final result
    cout << resultStr << endl;

    return result;
}
double choose_dectooctal(const char* num) {
    int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(num);

    for (int i = 0; i < length; i++) {
        if (num[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += num[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += num[i];
        }
    }

    long long decimalInteger = stoll(holdernumbers);
    long long octalInteger = 0, i = 1, rem = 0;
    while (decimalInteger != 0) {
        rem = decimalInteger % 8;
        octalInteger += rem * i;
        decimalInteger /= 8;
        i *= 10;
    }

    long double decimalFraction = holderfraction.empty() ? 0.0 : stod("0." + holderfraction);
    string octalFraction = "";
    int precision = 25; 
    while (decimalFraction > 0 && precision-- > 0) {
        decimalFraction *= 8;
        int digit = static_cast<int>(decimalFraction);
        octalFraction += to_string(digit);
        decimalFraction -= digit;
    }

    cout << octalInteger;
    if (!octalFraction.empty()) {
        cout << "." << octalFraction;
    }
    cout << endl;

    return static_cast<double>(octalInteger) + (octalFraction.empty() ? 0 : stod("0." + octalFraction));
}

//| ==== Octal to Decimal/Decimal to Octal ==== |


//| ==== Octal to Hexa / Hexa to Octal ==== |
double choose_octaltohexa(const char* number) {
    int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += number[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += number[i];      
        }
    }

    int octalInt = stoi(holdernumbers);
    int decimalInt = 0;
    int exponent = 0;
    int rem = 0;
    while (octalInt != 0) {
        rem = octalInt % 10;
        octalInt /= 10;
        decimalInt += rem * pow(8, exponent);
        exponent++;
    }


    double fraction = 0.0;
    if (!holderfraction.empty()) {
        for (int i = 0; i < holderfraction.size(); i++) {
            int digit = holderfraction[i] - '0'; 
            fraction += digit * pow(8, -(i + 1));
        }
    }


    int integerPart = decimalInt;
    string hexResult = "";
    while (integerPart != 0) {
        rem = integerPart % 16;
        if (rem < 10)
            hexResult = to_string(rem) + hexResult;
        else
            hexResult = char(rem - 10 + 'A') + hexResult;
        integerPart /= 16;
    }

    string hexFraction = "";
    int precision = 25;
    while (fraction > 0 && precision-- > 0) {
        fraction *= 16;
        int fractionDigit = static_cast<int>(fraction);
        if (fractionDigit < 10)
            hexFraction += to_string(fractionDigit);
        else
            hexFraction += char(fractionDigit - 10 + 'A');
        fraction -= fractionDigit;
    }
    cout << "\nOctal to Hexadecimal: " << hexResult;
    if (!hexFraction.empty()) {
        cout << "." << hexFraction;
    }
    cout << endl;

    return 0;
}
double choose_hexatooctal(const char* number) {
    int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += number[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += number[i];      
        }
    }

    int decimalInt = 0;
    int base = 1; 
    for (int i = holdernumbers.size() - 1; i >= 0; i--) {
        if (holdernumbers[i] >= '0' && holdernumbers[i] <= '9') {
            decimalInt += (holdernumbers[i] - '0') * base;
        } else if (holdernumbers[i] >= 'A' && holdernumbers[i] <= 'F' || holdernumbers[i] >= 'a' && holdernumbers[i] <= 'f') {
            decimalInt += (toupper(holdernumbers[i]) - 'A' + 10) * base;
        }
        base *= 16;
    }

    double fraction = 0.0;
    if (!holderfraction.empty()) {
        for (int i = 0; i < holderfraction.size(); i++) {
            int digit;
            if (holderfraction[i] >= '0' && holderfraction[i] <= '9') {
                digit = holderfraction[i] - '0';
            } else {
                digit = toupper(holderfraction[i]) - 'A' + 10;
            }
            fraction += digit * pow(16, -(i + 1));
        }
    }

    int octalholder = 0;
    int i = 1;
    int rem;
    while (decimalInt != 0) {
        rem = decimalInt % 8;
        decimalInt /= 8;
        octalholder += rem * i;
        i *= 10;
    }

    string octalFraction = "";
    int precision = 25; 
    while (fraction > 0 && precision-- > 0) {
        fraction *= 8;
        int fractionDigit = static_cast<int>(fraction);
        octalFraction += to_string(fractionDigit);
        fraction -= fractionDigit;
    }

    cout << "\nHexadecimal to Octal: " << octalholder;
    if (!octalFraction.empty()) {
        cout << "." << octalFraction;
    }
    cout << endl;

    return 0;
}
//| ==== Octal to Hexa / Hexa to Octal ==== |


//| ==== Hexa to Dec/Dec to Hex ==== |
double choose_hexatodec(const char* number) {
    int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += number[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += number[i];      
        }
    }
    int decimalInt = 0;
    int base = 1;
    for (int i = holdernumbers.size() - 1; i >= 0; i--) {
        if (holdernumbers[i] >= '0' && holdernumbers[i] <= '9') {
            decimalInt += (holdernumbers[i] - '0') * base;
        } else if (holdernumbers[i] >= 'A' && holdernumbers[i] <= 'F' || holdernumbers[i] >= 'a' && holdernumbers[i] <= 'f') {
            decimalInt += (toupper(holdernumbers[i]) - 'A' + 10) * base;
        }
        base *= 16;
    }

    double fraction = 0.0;
    if (!holderfraction.empty()) {
        for (int i = 0; i < holderfraction.size(); i++) {
            int digit;
            if (holderfraction[i] >= '0' && holderfraction[i] <= '9') {
                digit = holderfraction[i] - '0';
            } else {
                digit = holderfraction[i] - 'A' + 10;
            }
            fraction += digit * pow(16, -(i + 1));
        }
    }


    double result = decimalInt + fraction;

    stringstream ss;
    ss.precision(19);
    ss << fixed << result;

    string resultStr = ss.str();
    resultStr.erase(resultStr.find_last_not_of('0') + 1);
    if (resultStr.back() == '.') {
        resultStr.pop_back(); 
    }

    cout << resultStr << endl;

    return result;
}

double choose_dectohexa(const char* number) {
    int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += number[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += number[i];      
        }
    }

    long long decimalInt = stoll(holdernumbers);
    string hexResult = "";
    int rem;
    while (decimalInt != 0) {
        rem = decimalInt % 16;
        if (rem < 10)
            hexResult = to_string(rem) + hexResult;
        else
            hexResult = char(rem - 10 + 'A') + hexResult;
        decimalInt /= 16;
    }

    
    long double fraction = holderfraction.empty() ? 0.0 : stod("0." + holderfraction);
    string hexFraction = "";
    int precision = 25; 
    while (fraction > 0 && precision-- > 0) {
        fraction *= 16;
        int fractionDigit = static_cast<int>(fraction);
        if (fractionDigit < 10)
            hexFraction += to_string(fractionDigit);
        else
            hexFraction += char(fractionDigit - 10 + 'A');
        fraction -= fractionDigit;
    }

    
    cout << hexResult;
    if (!hexFraction.empty()) {
        cout << "." << hexFraction;
    }
    cout << endl;

    return 0;
}
//| ==== Hexa to Dec/Dec to Hex ==== |


//| ==== Binary Operators ==== |
string calc(double num1, double num2, string op){
    double result;
    const char* num;
    if(op == "+"){
        result = num1 + num2;
        stringstream ss;
        ss.precision(19);
        ss << fixed << result;

        string resultStr = ss.str();
        resultStr.erase(resultStr.find_last_not_of('0') + 1); 
        if (resultStr.back() == '.') {
            resultStr.pop_back();  
        }

        return resultStr;
    }
    else if(op == "-"){
         result = num1-num2;
        stringstream ss;
        ss.precision(19);
        ss << fixed << result;

        string resultStr = ss.str();
        resultStr.erase(resultStr.find_last_not_of('0') + 1); 
        if (resultStr.back() == '.') {
            resultStr.pop_back();  
        }

        return resultStr;
    }     
    else if(op == "*"){
        result = num1*num2; 
        stringstream ss;
        ss.precision(19);
        ss << fixed << result;

        string resultStr = ss.str();
        resultStr.erase(resultStr.find_last_not_of('0') + 1); 
        if (resultStr.back() == '.') {
            resultStr.pop_back();  
        }

        return resultStr;
    }      
        else if(op == "/"){
        result = num1/num2;
        stringstream ss;
        ss.precision(19);
        ss << fixed << result;

        string resultStr = ss.str();
        resultStr.erase(resultStr.find_last_not_of('0') + 1); 
        if (resultStr.back() == '.') {
            resultStr.pop_back();  
        }

        return resultStr;     
    }
    return "0";
} 

double binary_convert(const char *num){
    long double decimalpart = 0.0;
    long double fraction = 0.0;
    int exponent = 0;
    int length = strlen(num);
    int dot = -1;

    for (int i = 0; i < length; i++) {
        if (num[i] == '.') {
            dot = i;
            break;
        }
    }
    if (dot == -1) {
        dot = length;
    }

    for (int i = dot - 1; i >= 0; i--) {
        if (num[i] == '1') {
            decimalpart += (long double)pow(2, exponent);
        }
        exponent++;
    }

    long double fractionstart = 0.5;
    for (int i = dot + 1; i < length; i++) {
        if (num[i] == '1') {
            fraction += fractionstart;
        }
        fractionstart /= 2;
    }

    long double value = decimalpart+fraction;
    return value;
}

string octal_convert(const char*num){
     int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(num);

    for (int i = 0; i < length; i++) {
        if (num[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += num[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += num[i];
        }
    }

    int octalInteger = stoi(holdernumbers);
    int decimalInteger = 0, exponent = 0, rem = 0;
    while (octalInteger != 0) {
        rem = octalInteger % 10;
        decimalInteger += rem * pow(8, exponent);
        octalInteger /= 10;
        exponent++;
    }

    double decimalFraction = 0.0;
    if (!holderfraction.empty()) {
        for (int i = 0; i < holderfraction.size(); i++) {
            int digit = holderfraction[i] - '0'; 
            decimalFraction += digit * pow(8, -(i + 1));
        }
    }

    double result = decimalInteger + decimalFraction;
    stringstream ss;
    ss.precision(19);
    ss << fixed << result;

    string resultStr = ss.str();
    resultStr.erase(resultStr.find_last_not_of('0') + 1); 
    if (resultStr.back() == '.') {
        resultStr.pop_back();  
    }

    return resultStr;
}

string hexadecimal_convert(const char* number){
    int dot = -1;
    string holdernumbers = "";
    string holderfraction = "";
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        if (number[i] == '.') {
            dot = i;
            break;
        } else {
            holdernumbers += number[i];
        }
    }

    if (dot != -1) {
        for (int i = dot + 1; i < length; i++) {
            holderfraction += number[i];      
        }
    }
    int decimalInt = 0;
    int base = 1;
    for (int i = holdernumbers.size() - 1; i >= 0; i--) {
        if (holdernumbers[i] >= '0' && holdernumbers[i] <= '9') {
            decimalInt += (holdernumbers[i] - '0') * base;
        } else if (holdernumbers[i] >= 'A' && holdernumbers[i] <= 'F') {
            decimalInt += (holdernumbers[i] - 'A' + 10) * base;
        }
        base *= 16;
    }

    double fraction = 0.0;
    if (!holderfraction.empty()) {
        for (int i = 0; i < holderfraction.size(); i++) {
            int digit;
            if (holderfraction[i] >= '0' && holderfraction[i] <= '9') {
                digit = holderfraction[i] - '0';
            } else {
                digit = holderfraction[i] - 'A' + 10;
            }
            fraction += digit * pow(16, -(i + 1));
        }
    }


    double result = decimalInt + fraction;

    stringstream ss;
    ss.precision(19);
    ss << fixed << result;

    string resultStr = ss.str();
    resultStr.erase(resultStr.find_last_not_of('0') + 1);
    if (resultStr.back() == '.') {
        resultStr.pop_back(); 
    }

    return resultStr;
}
//| ==== Binary Operators ==== |