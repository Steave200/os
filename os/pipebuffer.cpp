#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int count_ = 0;
int empty_slots = BUFFER_SIZE;
int full = 0;
int mutex_ = 1;
void wait(int &S) {
while (S <= 0);
S--;
}
void signal(int &S) {
S++;
}
void producer() {
wait(empty_slots);
wait(mutex_);
srand(static_cast<unsigned
int>(time(0)));
int item = rand()%100+1;
buffer[count_] = item;
cout << "Produced: " << item <<
endl;
count_++;
signal(mutex_);
signal(full);
}
void consumer() {
wait(full);
wait(mutex_);
int item = buffer[count_ - 1];
cout << "Consumed: " << item <<
endl;
count_--;
signal(mutex_);
signal(empty_slots);
}
int main() {
int j;
for (int i = 0; i < 3; ++i) {
j=fork();
if(j>0){
producer();
sleep(1);
}
else{
consumer();
sleep(1);
}
}
return 0;
} 
