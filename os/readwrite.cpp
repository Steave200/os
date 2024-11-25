#include<iostream>
#include<thread>
using namespace std;
int read_count = 0;
bool writing = false;
void reader(int id) {
while (true) {
if (!writing) {
read_count++;
cout << "Reader " << id << " is reading. Total readers: " << read_count << endl;
this_thread::sleep_for(chrono::seconds(1)); // Simulate reading time
read_count--;
cout << "Reader " << id << " finished reading." << endl;
}
this_thread::sleep_for(chrono::seconds(1)); // Simulate thinking time
}
}
void writer(int id) {
while (true) {
if (read_count == 0 && !writing) {
writing = true;
cout << "Writer " << id << " is writing." << endl;
this_thread::sleep_for(chrono::seconds(1)); // Simulate writing time
writing = false;
cout << "Writer " << id << " finished writing." << endl;
}
this_thread::sleep_for(chrono::seconds(1)); // Simulate thinking time
}
}
int main() {
thread readers[3], writers[2];
for (int i = 0; i < 3; ++i) {
readers[i] = thread(reader, i);
}
for (int i = 0; i < 2; ++i) {
writers[i] = thread(writer, i);
}
for (int i = 0; i < 3; ++i) {
readers[i].join();
}
for (int i = 0; i < 2; ++i) {
writers[i].join();
}
return 0;
}
