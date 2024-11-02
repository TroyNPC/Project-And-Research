class MiceAndHoles {
public:
    int input() {
        system("cls");
        cout << "\n\n| ----- MICE AND HOLES ----- |\n\n";
        cout << "Enter the size of both mice and holes: ";
        int size;
        cin >> size;

        vector<int> mice(size);
        vector<int> holes(size);

        for (int i = 0; i < size; i++) {
            cout << "\nEnter position of Mice[" << i << "] = ";
            mice[i] = getValidNumber();
        }

        for (int i = 0; i < size; i++) {
            cout << "\nEnter position of Hole[" << i << "] = ";
            holes[i] = getValidNumber();
        }

        int minTime = assignHole(mice, holes, size);
        if (minTime == -1) {
            cout << "\nThe number of mice and holes must be equal.\n";
        } else {
            cout << "\nAfter " << minTime << " minutes all of the mice are in the holes." << endl;
            cout << "Since there is no combination possible where the last mouse's time is less than " << minTime << ", answer = " << minTime << ".\n";
        }
        return again();
    }

private:
    int getValidNumber() {
        string input;
        double number;
        
        while (true) {
            cin >> input;
            bool hasDecimal = false;
            bool valid = true;
            for (char c : input) {
                if (c == '.') {
                    if (hasDecimal) {
                        valid = false;
                        break;
                    }
                    hasDecimal = true;
                } else if (!isdigit(c) && c != '-') {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                number = stod(input);
                return static_cast<int>(number);
            } else {
                cout << "Invalid input. Please enter a valid integer: ";
            }
        }
    }

    int assignHole(vector<int>& mice, vector<int>& holes, int size) {
        if (mice.size() != holes.size()) return -1;
        
        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());

        int maxTime = 0;
        cout << "\nAssignment of mice to holes with time taken:\n";
        for (int i = 0; i < size; ++i) {
            int time = abs(mice[i] - holes[i]);
            cout << "Assign mouse at position x = " << mice[i] << " to hole at position x = " << holes[i];
            cout << " : Time taken is " << time << " minutes\n";
            if (time > maxTime) maxTime = time;
        }
        return maxTime;
    }
};
