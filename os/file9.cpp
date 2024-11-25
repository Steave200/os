#include <iostream>
#include <vector>
using namespace std;

#define MAX_BLOCKS 50

void continuousAllocation(vector<int>& fileSizes, int totalBlocks);
void linkedAllocation(vector<int>& fileSizes, int totalBlocks);
void indexedAllocation(vector<int>& fileSizes, int totalBlocks);

int main() {
    int n, totalBlocks;
    vector<int> fileSizes;

    cout << "Enter the number of files: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int size;
        cout << "Enter size of file " << i + 1 << " (in blocks): ";
        cin >> size;
        fileSizes.push_back(size);
    }

    cout << "Enter the total number of available blocks: ";
    cin >> totalBlocks;

    int choice;
    do {
        cout << "\nChoose a File Allocation Method:\n";
        cout << "1. Continuous Allocation\n";
        cout << "2. Linked Allocation\n";
        cout << "3. Indexed Allocation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                continuousAllocation(fileSizes, totalBlocks);
                break;
            case 2:
                linkedAllocation(fileSizes, totalBlocks);
                break;
            case 3:
                indexedAllocation(fileSizes, totalBlocks);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void continuousAllocation(vector<int>& fileSizes, int totalBlocks) {
    vector<bool> memory(totalBlocks, false);
    int startBlock = 0;

    cout << "\nContinuous Allocation:\n";
    for (int i = 0; i < fileSizes.size(); i++) {
        int size = fileSizes[i];
        int freeBlocks = 0, j;

        for (j = startBlock; j < totalBlocks; j++) {
            if (!memory[j]) {
                freeBlocks++;
                if (freeBlocks == size) break;
            } else {
                freeBlocks = 0;
                startBlock = j + 1;
            }
        }

        if (freeBlocks == size) {
            for (int k = startBlock; k <= j; k++) {
                memory[k] = true;
            }
            cout << "File " << i + 1 << " allocated from block " << startBlock << " to " << j << "\n";
            startBlock = j + 1;
        } else {
            cout << "File " << i + 1 << " cannot be allocated due to insufficient contiguous blocks.\n";
        }
    }
}

void linkedAllocation(vector<int>& fileSizes, int totalBlocks) {
    vector<int> memory(totalBlocks, -1);

    cout << "\nLinked Allocation:\n";
    for (int i = 0; i < fileSizes.size(); i++) {
        int size = fileSizes[i];
        vector<int> fileBlocks;
        int allocated = 0;

        for (int j = 0; j < totalBlocks && allocated < size; j++) {
            if (memory[j] == -1) {
                fileBlocks.push_back(j);
                allocated++;
            }
        }

        if (allocated == size) {
            for (int j = 0; j < fileBlocks.size() - 1; j++) {
                memory[fileBlocks[j]] = fileBlocks[j + 1];
            }
            memory[fileBlocks.back()] = -2;

            cout << "File " << i + 1 << " allocated at blocks: ";
            for (int block : fileBlocks) {
                cout << block << " ";
            }
            cout << "\n";
        } else {
            cout << "File " << i + 1 << " cannot be allocated due to insufficient blocks.\n";
        }
    }
}

void indexedAllocation(vector<int>& fileSizes, int totalBlocks) {
    vector<bool> memory(totalBlocks, false);

    cout << "\nIndexed Allocation:\n";
    for (int i = 0; i < fileSizes.size(); i++) {
        int size = fileSizes[i];
        vector<int> fileBlocks;
        int indexBlock = -1;

        for (int j = 0; j < totalBlocks; j++) {
            if (!memory[j]) {
                indexBlock = j;
                memory[j] = true;
                break;
            }
        }

        if (indexBlock != -1) {
            int allocated = 0;

            for (int j = 0; j < totalBlocks && allocated < size; j++) {
                if (!memory[j]) {
                    fileBlocks.push_back(j);
                    memory[j] = true;
                    allocated++;
                }
            }

            if (allocated == size) {
                cout << "File " << i + 1 << " index block: " << indexBlock << " -> blocks: ";
                for (int block : fileBlocks) {
                    cout << block << " ";
                }
                cout << "\n";
            } else {
                cout << "File " << i + 1 << " cannot be allocated due to insufficient blocks.\n";
                memory[indexBlock] = false;
            }
        } else {
            cout << "File " << i + 1 << " cannot be allocated due to no free index block.\n";
        }
    }
}

