#include<iostream>
#include<queue>
using namespace std;
bool find(std::queue<int> q, int value) {
while (!q.empty()) {
if (q.front() == value) {
return true;
}
q.pop();
}
return false;
}
void printt(queue<int>q){
while (!q.empty()) {
cout << q.front() << " ";
q.pop();
}
cout << endl;
}
int main(){
queue<int>qs;
cout<<"Enter number of processes and no of frames"<<endl;
int n;
int siz,fault=0;
cin>>n>>siz;
for(int i=0;i<n;i++) {
cout<<"Enter element : ";
int x;
cin>>x;
if(i<3){
qs.push(x);
}
else if(find(qs,x)){
fault++;
}
else{
qs.push(x);
qs.pop();
}
printt(qs);
}
cout<<"The no of fault is "<<fault<<endl;
cout<<"THe number of hit is "<<n-fault<<endl;
return 0;
}
