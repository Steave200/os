#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Function to calculate the total seek time and print the seek sequence
void calculateSeekTime(const string& algoName, vector<int> sequence, int head) {
int seekTime = 0;
int currentPosition = head;
cout << algoName << " Disk Scheduling:\n";
cout << "Seek Sequence: ";
for (int req : sequence) {
cout << req << " ";
seekTime += abs(currentPosition - req);
currentPosition = req;
}
cout << "\nTotal Seek Time: " << seekTime << endl << endl;
}
// FCFS Disk Scheduling
void FCFS(vector<int> requests, int head) {
calculateSeekTime("FCFS", requests, head);
}
// SSTF (Shortest Seek Time First) Disk Scheduling
void SSTF(vector<int> requests, int head) {
vector<int> sequence;
vector<bool> visited(requests.size(), false);
int currentPosition = head;
for (int i = 0; i < requests.size(); i++) {
int closestIndex = -1;
int minDistance = INT_MAX;
// Find the closest unvisited request
for (int j = 0; j < requests.size(); j++) {
if (!visited[j] && abs(currentPosition - requests[j]) < minDistance) {
minDistance = abs(currentPosition - requests[j]);
closestIndex = j;
}
}
if (closestIndex != -1) {
visited[closestIndex] = true;
sequence.push_back(requests[closestIndex]);
currentPosition = requests[closestIndex];
}
}
calculateSeekTime("SSTF", sequence, head);
}
// SCAN Disk Scheduling
void SCAN(vector<int> requests, int head, int diskSize, bool direction) {
vector<int> left, right;
vector<int> sequence;
if (direction) right.push_back(diskSize - 1); // Moving towards the end
else left.push_back(0); // Moving towards the start
for (int req : requests) {
if (req < head) left.push_back(req);
else right.push_back(req);
}
sort(left.begin(), left.end());
sort(right.begin(), right.end());
if (direction) {
sequence.insert(sequence.end(), right.begin(), right.end());
sequence.insert(sequence.end(), left.begin(), left.end());
} else {
sequence.insert(sequence.end(), left.rbegin(), left.rend());
sequence.insert(sequence.end(), right.begin(), right.end());
}
calculateSeekTime("SCAN", sequence, head);
}
// CSCAN Disk Scheduling
void CSCAN(vector<int> requests, int head, int diskSize) {
vector<int> left, right;
vector<int> sequence;
right.push_back(diskSize - 1); // End of the disk
left.push_back(0); // Start of the disk
for (int req : requests) {
if (req < head) left.push_back(req);
else right.push_back(req);
}
sort(left.begin(), left.end());
sort(right.begin(), right.end());
sequence.insert(sequence.end(), right.begin(), right.end());
sequence.insert(sequence.end(), left.begin(), left.end());
calculateSeekTime("CSCAN", sequence, head);
}
// LOOK Disk Scheduling
void LOOK(vector<int> requests, int head, bool direction) {
vector<int> left, right;
vector<int> sequence;
for (int req : requests) {
if (req < head) left.push_back(req);
else right.push_back(req);
}
sort(left.begin(), left.end());
sort(right.begin(), right.end());
if (direction) {
sequence.insert(sequence.end(), right.begin(), right.end());
sequence.insert(sequence.end(), left.begin(), left.rend());
} else {
sequence.insert(sequence.end(), left.rbegin(), left.rend());
sequence.insert(sequence.end(), right.begin(), right.end());
}
calculateSeekTime("LOOK", sequence, head);
}
int main() {
vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
int head = 53;
int diskSize = 200;
FCFS(requests, head);
SSTF(requests, head);
SCAN(requests, head, diskSize, true); // Moving towards the right (end of disk)
CSCAN(requests, head, diskSize);
LOOK(requests, head, true); // Moving towards the right (end of disk)
return 0;
} 
