struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareJobs(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

class JobSequencing {
public:
    void displayTable(const vector<Job>& jobs, const string& label) {
        cout << "\n| === " << label << " === |\n\n";
        cout << "Job ID  | Deadline | Profit\n";
        cout << "---------------------------\n";
        for (const auto& job : jobs) {
            cout << "Job[" << job.id << "]   |   " << setw(6) << job.deadline << "   |   " << setw(5) << job.profit << "\n";
        }
        cout << "---------------------------\n";
    }

    void jobSequencing(vector<Job>& jobs) {
        int n = jobs.size();

        displayTable(jobs, "Unsorted Jobs");
        sort(jobs.begin(), jobs.end(), compareJobs);
        displayTable(jobs, "Sorted Jobs by Profit");

        int maxDeadline = 0;
        for (const auto& job : jobs) {
            if (job.deadline > maxDeadline)
                maxDeadline = job.deadline;
        }

        vector<int> slots(maxDeadline + 1, -1);
        int totalProfit = 0;

        cout << "\nSelected Jobs:\n";
        for (const auto& job : jobs) {
            for (int j = job.deadline; j > 0; j--) {
                if (slots[j] == -1) { 
                    slots[j] = job.id; 
                    totalProfit += job.profit;
                    cout << "Job[" << job.id << "] with profit " << job.profit << " scheduled at time slot " << j << endl;
                    break;
                }
            }
        }

        cout << "\nTotal Profit: " << totalProfit << endl;
    }

    int input() {
        system("cls");
        cout << "\n\n| ===== JOB SEQUENCE ===== |\n\n";
        int n;

        cout << "Enter the number of jobs: ";
        while (!(cin >> n) || n <= 0) {
            cout << "Invalid input! Please enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<Job> jobs(n);

        for (int i = 0; i < n; i++) {
            cout << "Enter deadline and profit for job " << i + 1 << ": ";
            while (!(cin >> jobs[i].deadline >> jobs[i].profit) || jobs[i].deadline <= 0 || jobs[i].profit <= 0) {
                cout << "Invalid input! Deadline and profit should be positive integers. Re-enter: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            jobs[i].id = i + 1;
        }

        jobSequencing(jobs);

        cout << "\n\n| ===== JOB SEQUENCE ===== |\n\n";
        return again();
    }
};
