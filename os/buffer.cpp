#include<iostream>
#include<thread>
#include<queue>
using namespace std;
queue<int> buffer;
const int BUFFER_SIZE = 10;
void producer() {
int item = 0;
while (true) {
if (buffer.size() < BUFFER_SIZE) {
buffer.push(item);
cout << "Producer produced item " << item << endl;
item++;
this_thread::sleep_for(chrono::seconds(1)); // Simulate time to produce
}
}
}
void consumer() {
while (true) {
if (!buffer.empty()) {
int item = buffer.front();
buffer.pop();
cout << "Consumer consumed item " << item << endl;
this_thread::sleep_for(chrono::seconds(1)); // Simulate time to consume
}
}
}
int main() {
thread prod(producer);
thread cons(consumer);
prod.join();
cons.join();
return 0;
}
