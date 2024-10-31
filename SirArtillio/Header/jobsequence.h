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
    void jobSequencing(vector<Job> &jobs, int n) {
        sort(jobs.begin(), jobs.end(), compareJobs);
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (jobs[i].deadline > maxDeadline)
                maxDeadline = jobs[i].deadline;
        }

        vector<int> slots(maxDeadline + 1, -1);
        int totalProfit = 0;

        cout << "\nSelected Jobs:\n";
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline; j > 0; j--) {
                if (slots[j] == -1) { 
                    slots[j] = jobs[i].id; 
                    totalProfit += jobs[i].profit; 
                    cout << "Job[" << jobs[i].id << "] with profit " << jobs[i].profit << " scheduled at time slot " << j << endl;
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
        jobSequencing(jobs, n);
        cout << "\n\n| ===== JOB SEQUENCE ===== |\n\n";
        return again();
    }
    
};