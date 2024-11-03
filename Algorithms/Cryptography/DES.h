class DES {
public:
    vector<vector<int>> S0_table = {
        {1, 0, 3, 2}, // row 0
        {3, 2, 0, 1}, // row 1
        {0, 2, 1, 3}, // row 2
        {2, 1, 0, 3}  // row 3
    };

    vector<vector<int>> S1_table = {
        {0, 1, 2, 3}, // row 0
        {2, 0, 1, 3}, // row 1
        {3, 0, 1, 2}, // row 2
        {2, 1, 0, 3}  // row 3
    };

    int hexToInt_single(const string& hex) {
    return stoul(hex, nullptr, 16);
    }
    string intToBinaryString_single(int num, int bits = 2) {
        string binaryStr = bitset<2>(num).to_string();
        return binaryStr.substr(binaryStr.size() - bits); // Ensures the result is only `bits`-length
    }
    string binaryToHex_single(const string& binary) {
        unsigned long decimalValue = std::stoul(binary, nullptr, 2);
        std::stringstream hexStream;
        hexStream << std::hex << decimalValue; 
        return hexStream.str(); 
    }

    vector<int> hexToInt(vector<string> str) {
        vector<int> holder;
        holder.resize(str.size()-1);
        for(int i = 0; i < str.size(); i ++){
                holder[i] = stoul(str[i], nullptr, 16);
        }
        return holder;
    }

    vector<string> hexToBinaryString(const vector<string>& hex_values, int bits = 8) {
        vector<string> binary_strings;

        for (const auto& hex_val : hex_values) {
            int num;
            stringstream ss;
            ss << hex << hex_val;
            ss >> num;

            string binaryStr = bitset<8>(num).to_string();
            binary_strings.push_back(binaryStr.substr(binaryStr.size() - bits)); 
        }

        return binary_strings;
    }
    string binaryToHex(const string& binary) {
        unsigned long decimalValue = std::stoul(binary, nullptr, 2);
        std::stringstream hexStream;
        hexStream << std::hex << decimalValue; 
        return hexStream.str(); 
        }

    vector<int> valid_input(string str, int size, int limit) {
        vector<int> num(size);
        int index = 0;
        cout << "\nEnter your " << str << " Values\n";
        while (index < size) {
            cout << "\n" << str << "[" << index + 1 << "] = ";
            cin >> num[index];
            if(str == "P8"){
                if (cin.fail() || num[index] < limit || num[index] > 10) { 
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                cout << "\n\nInvalid input. Please enter a valid number between 1 and " << size << ".\n" << endl;
                continue;  
                }
                ++index;
            }
            else{
            if (cin.fail() || num[index] < limit || num[index] > size) { 
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                cout << "\n\nInvalid input. Please enter a valid number between 1 and " << size << ".\n" << endl;
                continue;  
            }
            ++index;
        }
    }
        return num;
    }

    vector<int> valid_key_input(string str, int size, int limit){
        vector<int> num(size);
        int index = 0;
        cout << "\nEnter your " << str << " Values\n";
        while (index < size) {
            cout << "\n" << str << "[" << index << "] = ";
            cin >> num[index];
            if (num[index] != 0 && num[index] != 1) { 
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                cout << "\n\nInvalid input. Please enter a valid number between 1 and " << '0' << ".\n" << endl;
                continue;  
            }
            ++index;
        }
        return num;     
    }

    void display_box(const string &label, const vector<int> &values, int inputSize, int outputSize) {

        int boxWidth = 10 + inputSize * 4; 

        if(label == "KEY"){
            cout << "\nKEY: ";
            for(int i = 0; i<inputSize; i++){
               cout << values[i];
            }
        }
        else{
            cout << string(boxWidth, '_') << endl;
        cout << "|" << setw(boxWidth - 1) << left << label << "|" << endl;
        cout << "|" << setw(8) << "Input" << "|";
        for (int i = 1; i <= inputSize; i++) {
            if(label == "EP" && i > 4){
                cout << setw(4);
            }
            else{
                cout << setw(4) << i; 
            }
        }
        cout << "|" << endl;

        cout << string(boxWidth, '-') << endl;


        cout << "|" << setw(8) << "Output" << "|";
        for (int i = 0; i < outputSize; i++) {
            cout << setw(4) << values[i];
        }
        cout << "|" << endl;

        cout << string(boxWidth, '-') << endl;
    }
}
vector<int> permutate(const vector<int>& permPattern, const vector<int>& bits, int size, string message) {
    vector<int> storage(size);
    cout << "permutate " << message << ": " ;
    for (int i = 0; i < size; i++) {
        storage[i] = bits[permPattern[i] - 1];
        cout << storage[i]; 
    }
    cout << endl;
    return storage;
}

vector<int> left_shift(const vector<int>& bits, int shifts) {
    vector<int> shifted = bits;
    rotate(shifted.begin(), shifted.begin() + shifts, shifted.end());
    return shifted;
}
vector<int> binaryStringToVector(const string& binaryString) {
    vector<int> binaryVector;
    for (char bit : binaryString) { 
        binaryVector.push_back(bit - '0'); 
    }
    return binaryVector;
}
vector<int>IP_EP_STEP(vector<int> PT, vector<int> IP, vector<int> EP, vector<int> P4,vector<int> K1){

vector<int>Initial(8);

    cout << "\nCurrent Plaintext: ";
    for(auto bits : PT){
        cout << bits;
    }
 for (int i = 0; i < 8; ++i) {
        Initial[i] = PT[IP[i] - 1];  
    }

 vector<int> left_half(Initial.begin(), Initial.begin() + 4);
 vector<int> right_half(Initial.begin() + 4, Initial.end());

cout << "\n\nIP: ";
    for (auto bit : Initial) cout << bit << "";
    cout << endl;

cout << "left_half: ";
for (auto bit : left_half) cout << bit << "";
 cout << "\n";



    cout << "right half: ";
    for (auto bit : right_half) cout << bit << "";
    cout << endl;

 
 vector<int> EP_bit(8);
 for (int i = 0; i < 8; ++i) {
        EP_bit[i] = right_half[EP[i] - 1];  
    }

   
cout << "EP: ";
for (auto bit : EP_bit) cout << bit << "";


vector<int> XOR_result(8); 
    for (int i = 0; i < 8; ++i) {
        XOR_result[i] = EP_bit[i] ^ K1[i]; 
    }

cout << "XOR of EP and K1: ";
for (auto bit : XOR_result) cout << bit << "";



cout <<endl;
vector<int> S0(XOR_result.begin(), XOR_result.begin() + 4); // S0 should be 4 bits
vector<int> S1(XOR_result.begin() + 4, XOR_result.end());   // S1 should be 4 bits


cout << "S0: ";
for (auto bit : S0) cout << bit << "";

cout << "s1: ";
for (auto bit : S1) cout << bit << "";




    // S0 row and col
    vector<int> S0row;
    if (!S0.empty()) {
        S0row.push_back(S0.front()); 
        S0row.push_back(S0.back());  
    }

    vector<int> S0col;
    if (S0.size() == 4) {
        S0col.push_back(S0[1]); 
        S0col.push_back(S0[2]); 
    }

    // S1 row and col
    vector<int> S1row;
    if (!S1.empty()) {
        S1row.push_back(S1.front()); 
        S1row.push_back(S1.back()); 
    }

    vector<int> S1col;
    if (S1.size() == 4) {
        S1col.push_back(S1[1]); 
        S1col.push_back(S1[2]); 
    }

    string s0joinedrow;
    string s0joinedcol;

    for (int bit : S0row) {
        s0joinedrow += to_string(bit);
    }
     for (int bit : S0col) {
        s0joinedcol += to_string(bit);
    }
    cout<<"row :" << s0joinedrow << ", col :"<< s0joinedcol<<endl;;



    string hexofS0row = binaryToHex(s0joinedrow);
    int s0rowint = hexToInt_single(hexofS0row);
   

    string hexofS0col = binaryToHex(s0joinedcol);
    int s0colint = hexToInt_single(hexofS0col);
   







    string s1joinedrow;
    string s1joinedcol;

    for (int bit : S1row) {
        s1joinedrow += to_string(bit);
    }
     for (int bit : S1col) {
        s1joinedcol += to_string(bit);
    }
    cout<<"row :" << s1joinedrow << ", col :"<< s1joinedcol<<endl;;



    string hexofS1row = binaryToHex(s1joinedrow);
    int s1rowint = hexToInt_single(hexofS1row);
  

    string hexofS1col = binaryToHex(s1joinedcol);
    int s1colint = hexToInt_single(hexofS1col);
   

    int s0_answer = S0_table[s0rowint][s0colint];
    int s1_answer = S1_table[s1rowint][s1colint];


    string s0_binary = intToBinaryString_single(s0_answer);
    string s1_binary = intToBinaryString_single(s1_answer);

    cout << "S0 Output (binary): " << s0_binary << endl;
    cout << "S1 Output (binary): " << s1_binary << endl;

    string combined_binary = s0_binary + s1_binary;

    vector<int> combined_vector;

for (char bit : combined_binary) {
    combined_vector.push_back(bit - '0');  // Convert char to int and add to vector
}
vector<int> P4_bit(4);
for (int i = 0; i < 4; ++i) {
        P4_bit[i] = combined_vector[P4[i] - 1];  
    }

 cout << "p4_bit: ";
 for (auto bit : P4_bit) cout << bit << "";
    cout<<endl;


vector<int> XOR_result2(4); 
for (int i = 0; i < 4; ++i) {
    XOR_result2[i] = P4_bit[i] ^ combined_vector[i] ^ left_half[i];  // XOR corresponding bits
}






vector<int> final_answer;

final_answer.insert(final_answer.end(), XOR_result2.begin(), XOR_result2.end());
final_answer.insert(final_answer.end(), right_half.begin(), right_half.end());

cout << "XOR of IP,SOS1 and P4: ";
 for (auto bit : final_answer) cout << bit << "";

    cout<<endl<<endl;


vector<int> shifted_answer;
shifted_answer.insert(shifted_answer.end(), right_half.begin(), right_half.end());
shifted_answer.insert(shifted_answer.end(), XOR_result2.begin(), XOR_result2.end());


cout << "final_answer: ";
 for (auto bit : shifted_answer) cout << bit << "";

    cout<<endl;




return shifted_answer;
}

        int menu() {
        system("CLS");
        cout << "\n\n| ----- DES ----- |\n\n";
        
        cout << "| ---- USER INPUT FOR KEYS ---- |\n\n";
        vector<int> p10 = valid_input("P10", 10, 1);
        vector<int> p8 = valid_input("P8", 8, 1);
        vector<int> p4 = valid_input("P4", 4, 1);
        vector<int> EP = valid_input("EP", 8, 1);
        vector<int> IP = valid_input("IP", 8, 1);
        vector<int> KEY_INPUT = valid_key_input("KEY", 10, 0);

        display_box("P10", p10, 10, 10);
        display_box("P8", p8, 8, 8);
        display_box("P4", p4, 4, 4);
        display_box("EP", EP, 8, 8);
        display_box("IP", IP, 8, 8);
        display_box("KEY", KEY_INPUT, 10, 10);

        cout << "\n\n| ----- SOLVING FOR KEY ----- |\n";

        cout << "\n| ----- Getting Permutation and Key ----- |\n";

        display_box("KEY", KEY_INPUT, 10, 10);
        cout << endl;

        //LEFT SHIFT 1
        vector<int> permuted_key(10);
        vector<int> K1, K2;
         for (int i = 0; i < 10; ++i) {
                permuted_key[i] = KEY_INPUT[p10[i] - 1];  // P10 is 1-indexed
            }

        cout << "\nP10 (PERMUTATION) : ";
         for (auto bit : permuted_key) cout << bit << "";
            cout<<endl;

         vector<int> left_half(permuted_key.begin(), permuted_key.begin() + 5);
         vector<int> right_half(permuted_key.begin() + 5, permuted_key.end());

        left_half = left_shift(left_half, 1);
        right_half = left_shift(right_half, 1);



        vector<int> combined_key_for_K1;
        combined_key_for_K1.insert(combined_key_for_K1.end(), left_half.begin(), left_half.end());
        combined_key_for_K1.insert(combined_key_for_K1.end(), right_half.begin(), right_half.end());

        cout << "\nLEFT SHIFT 1: ";
         for (auto bit : combined_key_for_K1) cout << bit << "";
            cout<<endl;

        K1.resize(8); K2.resize(8);

        for (int i = 0; i < 8; ++i) {
            K1[i] = combined_key_for_K1[p8[i] - 1];  
        }

        cout << "\nKey 1: ";
         for (auto bit : K1) cout << bit << "";
            cout<<endl;


        left_half = left_shift(left_half, 2); 
        right_half = left_shift(right_half, 2); 


        //LEFT SHIFT 2
        vector<int> combined_key_for_K2;
        combined_key_for_K2.insert(combined_key_for_K2.end(), left_half.begin(), left_half.end());
        combined_key_for_K2.insert(combined_key_for_K2.end(), right_half.begin(), right_half.end());

        cout << "\nLeftShift 2: ";
         for (auto bit : combined_key_for_K2) cout << bit << "";
            cout<<endl;

        for (int i = 0; i < 8; ++i) {
            K2[i] = combined_key_for_K2[p8[i] - 1];  

        }

        cout << "\nKey 2: ";
         for (auto bit : K2) cout << bit << "";
            cout<<endl;        
        cout << "\n| ----- Getting Permutation and Key ----- |\n";

        cout << "\n\nSingle Hexa Combination or Plaintext? (H/P) \n\n";
        char decision; 
        cin >> decision;
        cin.ignore();

            if (decision == 'H' || decision == 'h') {
                cout << "\nEnter your PlainText: ";
                string PT;
                getline(cin, PT);

                vector<string> hex_values;

                cout << "\n-> Turn Each Letter/Symbols into Ascii <-\n";
                for (char ch : PT) {

                    stringstream hex_stream;
                    hex_stream << hex << setw(2) << setfill('0') << uppercase << int(static_cast<unsigned char>(ch));
                    string hex_value = hex_stream.str();

                    hex_values.push_back(hex_value);
                    cout << "'" << ch << "' -> 0x" << hex_value << endl;
                }

                cout << "\nHex values stored for plaintext:\n";
                for (const auto& hex_val : hex_values) {
                    cout << hex_val << "";
                }
                vector<int> Integer_hex = hexToInt(hex_values);
                cout << endl;

                cout << "\n\n| ---- Complete Hex to Binary Values From Letters ---- | \n\n";
                cout << "Hex to Integers: \n";
                for(int i = 0; i<hex_values.size(); i++){
                    cout << hex_values[i] << " = " << Integer_hex[i] << endl;
                }
                cout << "\nHex to Binaries: \n";
                 vector<string> hex_to_binaries = hexToBinaryString(hex_values, 8);

                    for (int i = 0; i < hex_to_binaries.size(); i++) {
                        cout << hex_values[i] << " = " << hex_to_binaries[i] << endl;
                    }
                 cout << "\n\n| ---- Complete Hex to Binary Values From Letters ---- | \n\n";
                
                 cout << "\n\n| ----- Round 1 ----- |\n\n";
                 
            vector<vector<int>> XorFirstRound(hex_to_binaries.size());

            for (int i = 0; i < hex_to_binaries.size(); i++) {
                cout << "------> Letter being Solved " << PT[i] << " <------\n";
                vector<int> hex_holder = binaryStringToVector(hex_to_binaries[i]);
                vector<int> IP_Permutate = IP_EP_STEP(hex_holder, IP, EP, p4, K1);
                XorFirstRound[i] = IP_Permutate;
                cout << "\n------> Letter being Solved " << PT[i] << " <------\n";
            }

                cout << "\n\n| ----- Round 1 ----- |";

                cout << "\n\n| ----- Round 2 ----- |\n\n";

                for (int i = 0; i < hex_to_binaries.size(); i++) {
                    cout << "------> Letter being Solved " << PT[i] << " <------\n";
                    vector<int> hex_holder = binaryStringToVector(hex_to_binaries[i]);
                    vector<int> IP_Permutate = IP_EP_STEP(XorFirstRound[i], IP, EP, p4, K2);
                    cout << "\n------> Letter being Solved " << PT[i] << " <------\n";
                }
                cout << "\n\n| ----- Round 2 ----- |\n\n";

        }
         else {
            cout << "\nEnter your Hexa: ";
            string PT;
            getline(cin, PT); 
            cin.ignore();  

            vector<int>binary_holder = binaryStringToVector(PT);
            vector<int>XorFirstRound;
            cout << "\n\n| ----- Round 1 ----- |\n\n";
            vector<int> IP_Permutate = IP_EP_STEP(binary_holder, IP, EP, p4, K2);
            XorFirstRound = IP_Permutate;
            cout << "\n\n| ----- Round 1 ----- |\n\n";
            cout << "\n\n| ----- Round 2 ----- |\n\n";
            vector<int> IP_Permutate_second = IP_EP_STEP(XorFirstRound, IP, EP, p4, K2);
            cout << "\n\n| ----- Round 2 ----- |\n\n";
        }
        cout << "\n\n| ----- DES ----- |\n\n";

        return again();
}


};

