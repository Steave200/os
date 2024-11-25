#include<iostream>
#include<thread>
using namespace std;
bool chopsticks[5] = { true, true, true, true, true }; // true means available
void philosopher(int id) {
while (true) {
int left = id;
int right = (id + 1) % 5;
// Try to pick up chopsticks
if (chopsticks[left] && chopsticks[right]) {
chopsticks[left] = false; // pick left
chopsticks[right] = false; // pick right
cout << "Philosopher " << id << " is eating." << endl;
this_thread::sleep_for(chrono::seconds(1)); // eating
chopsticks[left] = true; // release left
chopsticks[right] = true; // release right
cout << "Philosopher " << id << " finished eating and starts thinking." << endl;
this_thread::sleep_for(chrono::seconds(1)); // thinking
}
}
}
int main() {
thread philosophers[5];
for (int i = 0; i < 5; ++i) {
philosophers[i] = thread(philosopher, i);
}
for (int i = 0; i < 5; ++i) {
philosophers[i].join();
}
return 0;
}
