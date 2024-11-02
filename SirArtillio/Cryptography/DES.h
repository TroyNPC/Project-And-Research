#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#include <regex>
#include <string>
using namespace std;

class DES {
public:
    vector<int> P10, P8, IP, EP, P4;
    int S0[4][4], S1[4][4];

    bool validateInput(int value, int max) {
        return value >= 0 && value <= max;
    }

    int inputPermutationsAndSBoxes() {
        cout << "\n| ------- DES Configuration ------- |\n\n";

        auto inputVector = [&](vector<int>& vec, int size, int maxVal, const string& name) {
            cout << "\nEnter " << name << " permutation (" << size << " numbers between 1 and " << maxVal << "):\n";
            vec.resize(size);
            for (int i = 0; i < size; i++) {
                while (true) {
                    cout << name << " [" << i + 1 << "] = ";
                    cin >> vec[i];
                    if (validateInput(vec[i], maxVal)) break;
                    cout << "Invalid input! Please enter a number between 1 and " << maxVal << ".\n";
                }
            }
        };

        inputVector(P10, 10, 10, "P10");
        inputVector(P8, 8, 8, "P8");
        inputVector(IP, 8, 8, "IP");
        inputVector(EP, 8, 4, "EP");
        inputVector(P4, 4, 4, "P4");

        auto inputSBox = [&](int box[4][4], const string& name) {
            cout << "\nEnter " << name << " S-box (4x4 matrix with values between 0 and 3):\n";
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    while (true) {
                        cout << name << " [" << i + 1 << "][" << j + 1 << "] = ";
                        cin >> box[i][j];
                        if (validateInput(box[i][j], 33)) break;
                        cout << "Invalid input! Please enter a number between 0 and 3.\n";
                    }
                }
            }
        };

        inputSBox(S0, "S0");
        inputSBox(S1, "S1");

        cout << "\nAll inputs have been recorded successfully!\n";
        return 0;
    }

    void permuteVector(const vector<int>& input, const vector<int>& perm, vector<int>& output) {
        output.resize(perm.size());
        for (size_t i = 0; i < perm.size(); i++) {
            output[i] = input[perm[i] - 1];
        }
    }

    vector<int> shiftLeft(const vector<int>& data, int shifts) {
        vector<int> shifted = data;
        rotate(shifted.begin(), shifted.begin() + shifts, shifted.end());
        return shifted;
    }

    vector<int> combine(const vector<int>& left, const vector<int>& right) {
        vector<int> combined(left);
        combined.insert(combined.end(), right.begin(), right.end());
        return combined;
    }

    int encrypt() {
        inputPermutationsAndSBoxes();

        string K;
        cout << "\nEnter 10-bit key (K): ";
        cin >> K;

        vector<int> keyBits(K.begin(), K.end());
        for (auto& bit : keyBits) bit -= '0';
        vector<int> permutedKey;
        permuteVector(keyBits, P10, permutedKey);

        vector<int> leftHalf(permutedKey.begin(), permutedKey.begin() + 5);
        vector<int> rightHalf(permutedKey.begin() + 5, permutedKey.end());
        leftHalf = shiftLeft(leftHalf, 1);
        rightHalf = shiftLeft(rightHalf, 1);

        vector<int> combined = combine(leftHalf, rightHalf);
        vector<int> key1;
        permuteVector(combined, P8, key1);

        leftHalf = shiftLeft(leftHalf, 2);
        rightHalf = shiftLeft(rightHalf, 2);
        combined = combine(leftHalf, rightHalf);
        vector<int> key2;
        permuteVector(combined, P8, key2);

        cout << "Key 1: ";
        for (int bit : key1) cout << bit;
        cout << "\nKey 2: ";
        for (int bit : key2) cout << bit;
        cout << "\n";

        string inputText;
        cout << "Enter plaintext (hex numbers or letters/words): ";
        cin.ignore();
        getline(cin, inputText);

        bool isHex = regex_match(inputText, regex("^[0-9a-fA-F]+$"));
        stringstream encryptedStream;

        if (isHex) {
            for (size_t i = 0; i < inputText.size(); i += 2) {
                int byte = stoi(inputText.substr(i, 2), nullptr, 16);
                bitset<8> binary(byte);
                vector<int> textBits(8);
                for (int j = 0; j < 8; ++j) {
                    textBits[j] = binary[7 - j];
                }
                processEncryptionRounds(textBits, key1, key2, encryptedStream);
            }
        } else {
            for (char ch : inputText) {
                if (ch == ' ') continue;
                bitset<8> binary(static_cast<int>(ch));
                vector<int> textBits(8);
                for (int i = 0; i < 8; ++i) {
                    textBits[i] = binary[7 - i];
                }
                processEncryptionRounds(textBits, key1, key2, encryptedStream);
            }
        }

        cout << "Ciphertext: " << encryptedStream.str() << endl;
        return 0;
    }

        void processEncryptionRounds(vector<int>& textBits, vector<int>& key1, vector<int>& key2, stringstream& encryptedStream) {
            vector<int> permutedText;
            permuteVector(textBits, IP, permutedText);
            auto textHalves = splitKey(permutedText);

            for (int round = 0; round < 10; round++) {
                vector<int> subkey = (round % 2 == 0) ? key1 : key2;
                cout << "\n---- ROUND " << (round + 1) << " ----\n";
                auto result = desRound(textHalves, subkey);
                textHalves.first = result.first;
                textHalves.second = result.second;
            }

            vector<int> combined = combine(textHalves.second, textHalves.first);
            for (int bit : combined) encryptedStream << bit;
        }

        pair<vector<int>, vector<int>> desRound(pair<vector<int>, vector<int>>& halves, const vector<int>& subkey) {
            cout << "Expanded half: ";
            vector<int> expanded;
            permuteVector(halves.second, EP, expanded);
            for (int bit : expanded) cout << bit;
            cout << endl;

            cout << "XOR with subkey: ";
            for (size_t i = 0; i < expanded.size(); i++) {
                expanded[i] ^= subkey[i];
                cout << expanded[i];
            }
            cout << endl;

            vector<int> left(expanded.begin(), expanded.begin() + 4);
            vector<int> right(expanded.begin() + 4, expanded.end());

            vector<int> sBoxOutput(4);
            sBoxOutput[0] = S0[static_cast<int>(left[0])][static_cast<int>(left[3])];
            sBoxOutput[1] = S1[static_cast<int>(right[0])][static_cast<int>(right[3])];

            vector<int> p4Output;
            permuteVector(sBoxOutput, P4, p4Output);

            for (int i = 0; i < 4; i++) {
                halves.first[i] ^= p4Output[i];
            }
            return { halves.first, halves.second };
        }

        pair<vector<int>, vector<int>> splitKey(const vector<int>& key) {
            return { vector<int>(key.begin(), key.begin() + 4), vector<int>(key.begin() + 4, key.end()) };
        }
    int decrypt() {
        cout << "\n| ------- Decryption ------- |\n";
        inputPermutationsAndSBoxes();

        string K;
        cout << "\nEnter 10-bit key (K): ";
        cin >> K;

        vector<int> keyBits(K.begin(), K.end());
        for (auto& bit : keyBits) bit -= '0';
        vector<int> permutedKey;
        permuteVector(keyBits, P10, permutedKey);

        vector<int> leftHalf(permutedKey.begin(), permutedKey.begin() + 5);
        vector<int> rightHalf(permutedKey.begin() + 5, permutedKey.end());
        leftHalf = shiftLeft(leftHalf, 1);
        rightHalf = shiftLeft(rightHalf, 1);

        vector<int> combined = combine(leftHalf, rightHalf);
        vector<int> key1;
        permuteVector(combined, P8, key1);

        leftHalf = shiftLeft(leftHalf, 2);
        rightHalf = shiftLeft(rightHalf, 2);
        combined = combine(leftHalf, rightHalf);
        vector<int> key2;
        permuteVector(combined, P8, key2);

        string inputText;
        cout << "Enter ciphertext (binary string of 8-bits per block): ";
        cin.ignore();
        getline(cin, inputText);

        stringstream decryptedStream;

        for (size_t i = 0; i < inputText.size(); i += 8) {
            vector<int> textBits(8);
            for (int j = 0; j < 8; ++j) {
                textBits[j] = inputText[i + j] - '0';
            }
            processDecryptionRounds(textBits, key1, key2, decryptedStream);
        }

        cout << "Decrypted plaintext: " << decryptedStream.str() << endl;
        return 0;
    }

    void processDecryptionRounds(vector<int>& textBits, vector<int>& key1, vector<int>& key2, stringstream& decryptedStream) {
        vector<int> permutedText;
        permuteVector(textBits, IP, permutedText);
        auto textHalves = splitKey(permutedText);

        for (int round = 0; round < 10; round++) {
            vector<int> subkey = (round % 2 == 0) ? key2 : key1;
            auto result = desRound(textHalves, subkey);
            textHalves.first = result.first;
            textHalves.second = result.second;
        }

        vector<int> combined = combine(textHalves.second, textHalves.first);
        for (int bit : combined) decryptedStream << bit;
    }


    int menu() {
        while (true) {
            system("cls");
            cout << "\n\n| ------- DES MENU ------- |\n";
            cout << "1. Encrypt\n";
            cout << "2. Decrypt\n";
            cout << "3. Menu\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    encrypt();
                    break;
                case 2:
                    decrypt();
                    break;
                case 3:
                    cout << "Exiting...\n";
                    return go_back();
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        return 0;
    }
};
