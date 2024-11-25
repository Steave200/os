//LRU
#include<iostream>
#include<vector>
using namespace std
bool find(vector<int> &q, int value) {
for (int i = 0; i < q.size(); ++i) {
if (q[i] == value) {
q.erase(q.begin() + i);
q.insert(q.begin(), value);
return true;
}
}
return false;
}
void printt(const vector<int>& q) {
for (int i = 0; i < q.size(); ++i) {
cout << q[i] << " ";
}
cout << endl;
}
int main() {
vector<int> qs;
cout << "Enter number of processes and number of frames" << endl;
int n, siz, fault = 0;
cin >> n >> siz;
for (int i = 0; i < n; i++) {
cout << "Enter element : ";
int x;
cin >> x;
if (!find(qs, x)) {
fault++;
if (qs.size() == siz) {
qs.pop_back();
}
qs.insert(qs.begin(), x);
}
printt(qs);
}
cout << "The number of faults is: " << fault << endl;
cout << "The number of hits is: " << n - fault << endl;
return 0;
}
