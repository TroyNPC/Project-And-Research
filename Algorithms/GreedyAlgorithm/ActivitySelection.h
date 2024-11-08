struct Activity {
    int start, finish;
};

class ActivitySelection {
public:
    static bool compareActivities(Activity a1, Activity a2) {
        return a1.finish < a2.finish;
    }

    void displayTable(const vector<Activity>& activities, const string& label) {
        cout << "\n| === " << label << " === |\n\n";
        cout << left << setw(10) << "Activity" << setw(10) << "Start" << "Finish\n";
        cout << string(30, '-') << endl;
        for (size_t i = 0; i < activities.size(); i++) {
            cout << "Activity " << i + 1 << setw(6) << " "
                 << setw(10) << activities[i].start
                 << activities[i].finish << endl;
        }
        cout << string(30, '-') << endl;
    }

    void activitySelection(vector<Activity>& activities) {
        displayTable(activities, "Unsorted Activities");
        sort(activities.begin(), activities.end(), compareActivities);

        displayTable(activities, "Sorted Activities (by Finish Time)");

        cout << "\nSelected activities:\n";
        int lastSelectedIndex = 0;
        int totalActivities = 1;
        cout << "Activity( " << activities[lastSelectedIndex].start
             << ", " << activities[lastSelectedIndex].finish << " )\n";

        for (size_t i = 1; i < activities.size(); i++) {
            if (activities[i].start >= activities[lastSelectedIndex].finish) {
                cout << "Activity( " << activities[i].start
                     << ", " << activities[i].finish << " )\n";
                lastSelectedIndex = i;
                totalActivities++;
            }
        }

        cout << "\nThe Total of Selected Activities are: " << totalActivities << "\n";
    }

    int input() {
        system("cls");
        cout << "\n\n| ===== ACTIVITY SELECTION ===== |\n\n";
        int n;

        cout << "Enter the number of activities: ";
        cin >> n;

        if (n <= 0) {
            cout << "Number of activities must be a positive integer.\n";
            return again();
        }

        vector<Activity> activities(n);

        for (int i = 0; i < n; i++) {
            cout << "Enter start and finish time for activity " << i + 1 << ": ";
            cin >> activities[i].start >> activities[i].finish;

            if (activities[i].start < 0 || activities[i].finish < 0 || activities[i].start >= activities[i].finish) {
                cout << "Invalid input! Start time must be less than finish time, and both should be non-negative.\n";
                return again();
            }
        }

        activitySelection(activities);
        cout << "\n\n| ===== ACTIVITY SELECTION ===== |\n\n";
        return again();
    }
};
