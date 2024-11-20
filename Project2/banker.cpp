#include <iostream>
#include <vector>
using namespace std;

const int P = 5; // Number of processes
const int R = 3; // Number of resource types

bool isSafeState(vector<vector<int>> &allocation, vector<vector<int>> &max, vector<int> &available) {
    vector<vector<int>> need(P, vector<int>(R));
    vector<bool> finish(P, false);
    vector<int> safeSequence;

    // Calculate the Need matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Check for safe state
    vector<int> work = available; // Copy of available resources
    int count = 0;

    while (count < P) {
        bool found = false;

        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool canAllocate = true;

                for (int j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    // Allocate resources to process Pi
                    for (int j = 0; j < R; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            cout << "The system is not in a safe state.\n";
            return false;
        }
    }

    // Safe state found
    cout << "The system is in a safe state.\nSafe Sequence: ";
    for (int i = 0; i < safeSequence.size(); i++) {
        cout << "P" << safeSequence[i];
        if (i != safeSequence.size() - 1) cout << " -> ";
    }
    cout << endl;

    return true;
}

int main() {
    // Resource allocation for each process from given table
    vector<vector<int>> allocation = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    // Maximum resource need for each process from given table
    vector<vector<int>> max = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Available resources from given table
    vector<int> available = {3, 3, 2};

    isSafeState(allocation, max, available);

    return 0;
}
