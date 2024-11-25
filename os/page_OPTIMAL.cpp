//Optimal
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find(const vector<int>& qs, const vector<int>& pages, int index) {
int furthestIndex = -1;
int replace = -1;
for (int i = 0; i < qs.size(); i++) {
int j;
for (j = index; j < pages.size(); j++) {
if (qs[i] == pages[j]) {
break;
}
}
if (j == pages.size()) {
return i; }
if (j > furthestIndex) {
furthestIndex = j;
replace = i;
}
}
return replace;
}
void printt(const vector<int>& q) {
for (int i = 0; i < q.size(); i++) {
cout << q[i] << " ";
}
cout << endl;
}
int main() {
vector<int> qs;
cout << "Enter number of processes (pages) and number of frames" << endl;
int n, siz, fault = 0;
cin >> n >> siz;
vector<int> pages(n);
for (int i = 0; i < n; i++) {
cout << "Enter element (page): ";
cin >> pages[i];
}
for (int i = 0; i < n; i++) {
int x = pages[i];
if (find(qs.begin(), qs.end(), x) == qs.end()) {
fault++;
if (qs.size() == siz) {
int Ind = find(qs, pages, i + 1);
qs[Ind] = x;
} else {
qs.push_back(x);
}
}
printt(qs);
}
cout << "The number of faults is: " << fault << endl;
cout << "The number of hits is: " << n - fault << endl;
return 0;
}
