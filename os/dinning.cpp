#include <bits/stdc++.h>
using namespace std
class DiningPhilosophers{
private:
int numPhilosophers;
vector<bool> forks;
vector<bool> philosophersEating; // Track if philosophers are eating
public:
DiningPhilosophers(int num) : numPhilosophers(num), forks(num, true), philosophersEating(num, false) {}
void pickUpForks(int philosopher) {
int leftfork = (philosopher - 1);
int rightfork = philosopher % numPhilosophers
if (forks[leftfork] && forks[rightfork]) {
forks[leftfork] = forks[rightfork] = false;
philosophersEating[philosopher - 1] = true; // Philosopher is eating
cout << "Philosopher " << philosopher << " has picked up forks "
<< leftfork + 1 << " and " << rightfork + 1 << " and is now eating.\n";
}
else
{
cout << "Philosopher " << philosopher << " is waiting as forks are not available.\n";
}
checkDeadlock();
}
void putDownForks(int philosopher)
{
int leftfork = (philosopher - 1);
int rightfork = philosopher % numPhilosophers;
forks[leftfork] = forks[rightfork] = true;
philosophersEating[philosopher - 1] = false; // Philosopher is no longer eating
cout << "Philosopher " << philosopher << " has put down forks "
<< leftfork + 1 << " and " << rightfork + 1 << " and is now thinking.\n";
}
void displayForksStatus()
{
cout << "Fork status: ";
for (int i = 0; i < numPhilosophers; ++i)
{
cout << "Fork " << i + 1 << (forks[i] ? " is available. " : " is being used. ");
}
cout << "\n";
}
void checkDeadlock()
{
// Check for deadlock condition
bool allWaiting = true;
for (int i = 0; i < numPhilosophers; ++i)
{
if (philosophersEating[i])
{
allWaiting = false; // At least one philosopher is eating
break;
}
}
if (allWaiting)
{
cout << "Deadlock detected! All philosophers are waiting.\n";
printDeadlockStatus();
// No more eating can occur after deadlock
for (int i = 0; i < numPhilosophers; ++i)
{
philosophersEating[i] = false; // Mark all as not eating
}
}
}
void printDeadlockStatus()
{
cout << "Current status: All philosophers are waiting for forks.\n";
for (int i = 0; i < numPhilosophers; ++i)
{
if (philosophersEating[i])
{
cout << "Philosopher " << (i + 1) << " is eating.\n";
}
else
{
cout << "Philosopher " << (i + 1) << " is waiting.\n";
}
}
}
void simulateDeadlock(){
cout << "\nSimulating deadlock...\n";
for (int i = 0; i < numPhilosophers; ++i)
{
int leftfork = (i);
int rightfork = (i + 1) % numPhilosophers;
// Pick up left fork
forks[leftfork] = false;
philosophersEating[i] = true; // Philosopher is eating
cout << "Philosopher " << (i + 1) << " has picked up fork " << (leftfork + 1) << " and is waiting for fork " << (rightfork + 1) << ".\n";
}
// This will cause a deadlock since each philosopher has one fork and waits for another
checkDeadlock();
}
};
int main()
{
int n, ch, philosopher;
cout << "Enter the number of philosophers: ";
cin >> n;
int f;
cout << "Enter the number of Forks:";
cin >> f;
while (f != n)
{
cout << "Enter the number of Forks:";
cin >> f;
}
DiningPhilosophers dp(n);
while (true)
{
cout << "\n1. Philosopher tries to eat" << endl;
cout << "2. Philosopher puts down forks (starts thinking)" << endl;
cout << "3. Display forks status" << endl;
cout << "4. Simulate deadlock" << endl;
cout << "5. Exit" << endl;
cout << "Enter your choice: ";
cin >> ch;
switch (ch)
{
case 1:
cout << "Enter philosopher number (1 to " << n << "): ";
cin >> philosopher;
if (philosopher > 0 && philosopher <= n)
{
dp.pickUpForks(philosopher);
}
else
{
cout << "Invalid philosopher number!" << endl;
}
break;
case 2:
cout << "Enter philosopher number (1 to " << n << "): ";
cin >> philosopher;
if (philosopher > 0 && philosopher <= n)
{
dp.putDownForks(philosopher);
}
else
{
cout << "Invalid philosopher number!" << endl;
}
break;
case 3:
dp.displayForksStatus();
break;
case 4:
dp.simulateDeadlock();
break;
case 5:
cout << "Exiting..." << endl;
return 0;
default:
cout << "Invalid choice! Please try again." << endl;
}
}
return 0;
}

