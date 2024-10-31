class DES {
public:
    vector<int> P10, P8, IP, EP, P4;  
    vector<vector<int>> S0, S1;      

    DES() {
        P10.resize(10);
        P8.resize(8);
        IP.resize(8);
        EP.resize(8);
        P4.resize(4);
        S0.resize(4, vector<int>(4));
        S1.resize(4, vector<int>(4));
    }
        void inputPermutationsAndSBoxes() {
        cout << "\n\n| ------- DES ------- |\n\n";
        
        auto validateInput = [](int value, int max) {
            return value >= 1 && value <= max; 
        };

        cout << "\n[Step 1/7] Enter P10 permutation (10 numbers between 1 and 10):\n";
        for (int i = 0; i < P10.size(); i++) {
            while (true) {
                cout << "P10 [" << i + 1 << "] = ";
                cin >> P10[i];
                if (validateInput(P10[i], 10)) break;  
                cout << "Invalid input! Please enter a number between 1 and 10.\n";
            }
        }

        cout << "\n[Step 2/7] Enter P8 permutation (8 numbers between 1 and 8):\n";
        for (int i = 0; i < P8.size(); i++) {
            while (true) {
                cout << "P8 [" << i + 1 << "] = ";
                cin >> P8[i];
                if (validateInput(P8[i], 8)) break;
                cout << "Invalid input! Please enter a number between 1 and 8.\n";
            }
        }

        cout << "\n[Step 3/7] Enter IP permutation (8 numbers between 1 and 8):\n";
        for (int i = 0; i < IP.size(); i++) {
            while (true) {
                cout << "IP [" << i + 1 << "] = ";
                cin >> IP[i];
                if (validateInput(IP[i], 8)) break;
                cout << "Invalid input! Please enter a number between 1 and 8.\n";
            }
        }

        cout << "\n[Step 4/7] Enter EP permutation (8 numbers between 1 and 4):\n";
        for (int i = 0; i < EP.size(); i++) {
            while (true) {
                cout << "EP [" << i + 1 << "] = ";
                cin >> EP[i];
                if (validateInput(EP[i], 4)) break;
                cout << "Invalid input! Please enter a number between 1 and 4.\n";
            }
        }

        cout << "\n[Step 5/7] Enter P4 permutation (4 numbers between 1 and 4):\n";
        for (int i = 0; i < P4.size(); i++) {
            while (true) {
                cout << "P4 [" << i + 1 << "] = ";
                cin >> P4[i];
                if (validateInput(P4[i], 4)) break;
                cout << "Invalid input! Please enter a number between 1 and 4.\n";
            }
        }

        cout << "\n[Step 6/7] Enter S0 S-box (4x4 matrix with values between 0 and 3):\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                while (true) {
                    cout << "S0 [" << i << "][" << j + 1 << "] = ";
                    cin >> S0[i][j];
                    if (validateInput(S0[i][j], 44)) break; 
                    cout << "Invalid input! Please enter a number between 0 and 3.\n";
                }
            }
        }

        cout << "\n[Step 7/7] Enter S1 S-box (4x4 matrix with values between 0 and 3):\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                while (true) {
                    cout << "S1 [" << i << "][" << j  << "] = ";
                    cin >> S1[i][j];
                    if (validateInput(S1[i][j], 44)) break; 
                    cout << "Invalid input! Please enter a number between 0 and 3.\n";
                }
            }
        }

        cout << "\nAll inputs have been recorded successfully!\n";
    }

    int input() {
        system("cls");
        cout << "| ----- DES ----- |\n\n";
        int choice;
        cout << "Choose an option:\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            inputPermutationsAndSBoxes();
            encrypt();
            return go_back();
        } else if (choice == 2) {
            inputPermutationsAndSBoxes();
            decrypt();
            return go_back();
        } else if (choice == 3) {
            return go_back(); 
        } else {
            cout << "Invalid choice! Please try again.\n";
            input(); 
        }
        return 0;
    }

    int encrypt() {
        string K;
        cout << "Enter 10-bit key (K): ";
        cin >> K;

        vector<int> permutedKey = permute(K, P10);
        auto halves = splitKey(permutedKey);

        vector<vector<int>> subkeys;
        for (int i = 0; i < 10; i++) {
            halves.first = shiftLeft(halves.first, 1);
            halves.second = shiftLeft(halves.second, 1);
            vector<int> combinedShift = combine(halves.first, halves.second);
            subkeys.push_back(permute(combinedShift, P8));
        }

        string inputText;
        cout << "Enter plaintext (letters/words with spaces): ";
        cin.ignore();
        getline(cin, inputText);

        stringstream encryptedStream;

        for (char ch : inputText) {
            if (ch == ' ') continue; 

            int asciiValue = static_cast<int>(ch);
            bitset<8> binaryValue(asciiValue); 

            vector<int> textBits(8);
            for (int i = 0; i < 8; ++i) {
                textBits[i] = binaryValue[7 - i]; 
            }

            vector<int> permutedText = permute(textBits, IP);
            auto textHalves = splitKey(permutedText);

            cout << "Initial permutation (IP): ";
            display(permutedText);

            for (int round = 0; round < 10; round++) {
                cout << "\n---- ROUND " << (round + 1) << " ----\n";
                auto result = desRound(textHalves, subkeys[round]);
                textHalves.first = result.first;
                textHalves.second = result.second;
            }

            vector<int> combined = combine(textHalves.second, textHalves.first);
            cout << "Final combined (before last permutation): ";
            display(combined);

            for (int bit : combined) encryptedStream << bit;
        }

        cout << "Ciphertext: " << encryptedStream.str() << endl;
        return go_back();
    }

    int decrypt() {
        string K;
        cout << "Enter 10-bit key (K): ";
        cin >> K;

        vector<int> permutedKey = permute(K, P10);
        auto halves = splitKey(permutedKey);

        vector<vector<int>> subkeys;
        for (int i = 0; i < 10; i++) {
            halves.first = shiftLeft(halves.first, 1);
            halves.second = shiftLeft(halves.second, 1);
            vector<int> combinedShift = combine(halves.first, halves.second);
            subkeys.push_back(permute(combinedShift, P8));
        }

        string inputText;
        cout << "Enter ciphertext (letters/words with spaces): ";
        cin.ignore();
        getline(cin, inputText);

        stringstream decryptedStream;

        for (char ch : inputText) {
            if (ch == ' ') continue;

            vector<int> textBits;
            for (char c : inputText) {
                int bit = (c == '1') ? 1 : 0;
                textBits.push_back(bit);
            }

            vector<int> permutedText = permute(textBits, IP);
            auto textHalves = splitKey(permutedText);

            cout << "Initial permutation (IP): ";
            display(permutedText);

            for (int round = 9; round >= 0; round--) {
                cout << "\n---- ROUND " << (10 - round) << " ----\n"; 
                auto result = desRound(textHalves, subkeys[round]);
                textHalves.first = result.first;
                textHalves.second = result.second;
            }

            vector<int> combined = combine(textHalves.second, textHalves.first);
            cout << "Final combined (before last permutation): ";
            display(combined);

            char decryptedChar = static_cast<char>(toDecimal(combined));
            decryptedStream << decryptedChar; 
        }

        cout << "Decrypted Text: " << decryptedStream.str() << endl;
        return go_back();
    }

    pair<vector<int>, vector<int>> desRound(pair<vector<int>, vector<int>> halves, const vector<int>& subkey) {
        vector<int> expanded = permute(combine(halves.second, halves.second), EP);
        cout << "Expanded half: ";
        display(expanded);

        vector<int> xorResult = xorOperation(expanded, subkey);
        cout << "XOR with subkey: ";
        display(xorResult);

        auto sboxOutput = sBoxSubstitution(xorResult);
        cout << "S-box output: ";
        display(sboxOutput);

        vector<int> p4Output = permute(sboxOutput, P4);
        cout << "P4 output: ";
        display(p4Output);

        halves.first = xorOperation(halves.first, p4Output);
        cout << "Left half after XOR with P4: ";
        display(halves.first);

        swap(halves.first, halves.second);
        return halves;
    }

    vector<int> permute(const string& input, const vector<int>& permutation) {
        vector<int> permuted(permutation.size());
        for (size_t i = 0; i < permutation.size(); ++i) {
            permuted[i] = input[permutation[i] - 1]; 
        }
        return permuted;
    }

    vector<int> permute(const vector<int>& input, const vector<int>& permutation) {
        vector<int> permuted(permutation.size());
        for (size_t i = 0; i < permutation.size(); ++i) {
            permuted[i] = input[permutation[i] - 1]; 
        }
        return permuted;
    }

    pair<vector<int>, vector<int>> splitKey(const vector<int>& key) {
        vector<int> left(key.begin(), key.begin() + 5);
        vector<int> right(key.begin() + 5, key.end());
        return { left, right };
    }

    vector<int> combine(const vector<int>& left, const vector<int>& right) {
        vector<int> combined(left);
        combined.insert(combined.end(), right.begin(), right.end());
        return combined;
    }

    vector<int> shiftLeft(const vector<int>& input, int shifts) {
        vector<int> shifted(input.size());
        for (size_t i = 0; i < input.size(); ++i) {
            shifted[i] = input[(i + shifts) % input.size()];
        }
        return shifted;
    }

    vector<int> xorOperation(const vector<int>& a, const vector<int>& b) {
        vector<int> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] ^ b[i];
        }
        return result;
    }

    vector<int> sBoxSubstitution(const vector<int>& input) {
        int row = (input[0] << 1) | input[3]; 
        int col = (input[1] << 1) | input[2]; 
        int value1 = S0[row][col]; 
        row = (input[4] << 1) | input[7]; 
        col = (input[5] << 1) | input[6];
        int value2 = S1[row][col]; 

        vector<int> output;
        output.push_back((value1 >> 1) & 1);
        output.push_back(value1 & 1);
        output.push_back((value2 >> 1) & 1);
        output.push_back(value2 & 1);
        return output;
    }

    int toDecimal(const vector<int>& bits) {
        int decimalValue = 0;
        for (int i = 0; i < bits.size(); i++) {
            decimalValue += bits[i] * (1 << (bits.size() - 1 - i));
        }
        return decimalValue;
    }

    void display(const vector<int>& vec) {
        for (int bit : vec) cout << bit;
        cout << endl;
    }
};
