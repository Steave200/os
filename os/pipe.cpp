#include <iostream>
#include <unistd.h>
#include <cstring>
using namespace std;
int main() {
int pipefd[2];
pid_t pid;
char write_msg[] = "Hello from parent!";
char read_msg[100];
if (pipe(pipefd) == -1) {
cerr << "Pipe creation failed!" << endl;
return 1;
}
pid = fork();
if (pid < 0) {
cerr << "Fork failed!" << endl;
return 1;
}
if (pid > 0) {
close(pipefd[0]);
write(pipefd[1], write_msg, strlen(write_msg) + 1);
close(pipefd[1]);
cout << "Parent sent: " << write_msg << endl;
}
else {
close(pipefd[1]);
read(pipefd[0], read_msg, sizeof(read_msg));
close(pipefd[0]);
cout << "Child received: " << read_msg << endl;
}
return 0;
}
