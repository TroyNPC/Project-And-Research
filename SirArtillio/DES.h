#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

class DES {
public:
    vector<int> valid_input(string str, int size) {
        vector<int> num(size);
        int index = 0;
        cout << "\nEnter your " << str << " Values\n";
        while (index < size) {
            cout << "\n" << str << "[" << index + 1 << "] = ";
            cin >> num[index];
            if (cin.fail() || num[index] < 1 || num[index] > size) { 
                cin.clear();  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                cout << "\n\nInvalid input. Please enter a valid number between 1 and " << size << ".\n" << endl;
                continue;  
            }
            ++index;
        }
        return num;
    }

    void display_box(const string &label, const vector<int> &values, int inputSize, int outputSize) {
        cout << "\n" << label << endl;
        cout << setw(8) << "Input";
        for (int i = 1; i <= inputSize; i++) {
            cout << setw(4) << i;
        }
        cout << "\n" << setw(8) << "Output";
        for (int i = 0; i < outputSize; i++) {
            cout << setw(4) << values[i];
        }
        cout << "\n";
    }

    int input() {
        system("CLS");
        cout << "\n\n| ----- DES ----- |\n\n";
        
        vector<int> p10 = valid_input("P10", 10);
        vector<int> p8 = valid_input("P8", 8);
        vector<int> p4 = valid_input("P4", 4);
        vector<int> EP = valid_input("EP", 8);
        vector<int> IP = valid_input("IP", 8);

        display_box("P10", p10, 10, 10);
        display_box("P8", p8, 8, 8);
        display_box("P4", p4, 4, 4);
        display_box("EP", EP, 4, 8);
        display_box("IP", IP, 8, 8);

        return 0;
    }
};

int main() {
    DES des;
    des.input();
    return 0;
}
