class knapsack {
public:
    struct Item {
        int profit, weight;
        
        Item(int profit, int weight) {
            this->profit = profit;
            this->weight = weight;
        }
    };

    static bool cmp(struct Item a, struct Item b) {
        double r1 = (double)a.profit / (double)a.weight;
        double r2 = (double)b.profit / (double)b.weight;
        return r1 > r2;
    }

    bool isNumber(const string& str) {
        for (char const &c : str) {
            if (isdigit(c) == 0) return false;
        }
        return true;
    }

    int getValidInput(const string& prompt) {
        string input;
        while (true) {
            cout << prompt;
            cin >> input;
            if (isNumber(input)) {
                return stoi(input);
            } else {
                cout << "Invalid input. Please enter a valid number.\n";
            }
        }
    }

double fractionalKnapsack(int W, vector<Item>& items) {

    sort(items.begin(), items.end(), cmp);

    double finalValue = 0.0;
    int remainingWeight = W;
    double totalWeightUsed = 0.0;
    bool decimalpoint = false;
    cout << fixed << setprecision(2);
    cout << "\n\nCalculating total weight (x1w1): ";
    for (size_t i = 0; i < items.size(); i++) {
        double ratio = (double)items[i].profit / items[i].weight;
        cout << "\nX = P/W for item [" << i + 1 << "] = " << ratio;

        if (items[i].weight <= remainingWeight) {
            remainingWeight -= items[i].weight;
            finalValue += items[i].profit;
            totalWeightUsed += items[i].weight;

            cout << "\nAdding full item [" << i + 1 << "]:"; 
            cout << "\n  x1w1 += " << items[i].weight << " (current total: " << totalWeightUsed << ")";
            cout << "\n  x1p1 = " << items[i].profit;
        } else {


            double fraction = (double)remainingWeight / items[i].weight;
            finalValue += items[i].profit * fraction;
            totalWeightUsed += remainingWeight; 
            decimalpoint = true;
            cout << "\nAdding partial item [" << i + 1 << "]:"; 
            cout << "\n  x1w1 += " << remainingWeight << " (fraction " << fraction << ")" << " (current total: " << totalWeightUsed << ")"; 
            cout << "\n  x1p1 = " << items[i].profit * fraction;
            break; 
        }
    }

    cout << "\n\nTotal weight in knapsack (x1w1): ";
    if (decimalpoint) {
        cout << fixed << setprecision(0) << totalWeightUsed;
    } else {
        cout << fixed << setprecision(0) << (int)totalWeightUsed;
    }

    cout << "\nTotal value in knapsack: ";
    if (decimalpoint) {
        cout << fixed << setprecision(2) << finalValue;
    } else {
        cout << (int)finalValue;
    }
    return finalValue;
}


    int inputAndSolve() {
    	system("CLS");
    	cout << "\n\n| ---- KNAPSACK ---- |\n\n";
        int N = getValidInput("Enter the number of items: ");
        int W = getValidInput("Enter the maximum weight capacity of the knapsack: ");

        vector<Item> items;
        for (int i = 0; i < N; i++) {
            int profit = getValidInput("Enter profit for item [" + to_string(i + 1) + "]: ");
            int weight = getValidInput("Enter weight for item [" + to_string(i + 1) + "]: ");
            items.push_back(Item(profit, weight));
        }

        cout << "\n--- Calculating Knapsack Solution ---";
        fractionalKnapsack(W, items);
       	return again();
    }
};
