#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <limits>
#include <math.h>
// http://codeforces.com/problemset/problem/500/F
// Fails on Test 7, believe sorting the array takes too long as no output was generated as seen here:
// http://codeforces.com/contest/500/submission/9362706
// Could implement pseudo-binary search first to see if run time improves
int N,P, Q;
int A,B,C,D;
struct item{
	int cost;
	int happy;
	int time;
};
using namespace std;
item p[4010];

bool sortOrder(item i1, item i2){ return i1.time < i2.time;}

int returnMaxCombo(int startIdx, int endIdx, int budget){
	
	if(budget == 0) return 0;
	if(startIdx > endIdx){
		return 0;
	}
	int a = 0;
	int b = budget;
	if(p[startIdx].cost <= budget){
		a = p[startIdx].happy;
		b = budget-p[startIdx].cost;
	
	}
	if(b == budget){
		return returnMaxCombo((startIdx+1), endIdx, budget);
	}
	
	return max(returnMaxCombo((startIdx+1), endIdx, budget), (returnMaxCombo((startIdx+1), endIdx, b)+a));
}


int main(){

 cin >> N >> P;
 int idx =0;
 int L=N;
 while(L--){
	item temp;
	cin >> A;
	cin >> B;
	cin >> D;
	temp.cost = A;
	temp.happy = B;
	temp.time = D;

	p[idx] = temp;
	 idx++;
 }

 sort(p, p+N, sortOrder);
cin >> Q;

 while(Q--){
cin >> A >> B;
// A is visittime, B is budget
int maxIndex = N-1;
int minIndex = 0;
int tMax = N-1;
int tMin = 0;
// Lazy implementation, of finding proper max/min indexes
// Adds some bottleneck
// TODO: reimplement proper pseudo-binary to improve find time

while(p[maxIndex].time > A && maxIndex > 0){
	maxIndex = maxIndex/2 - 1;
}
while(maxIndex != N-1 && p[maxIndex+1].time <= A){
	maxIndex++;
}
if(p[maxIndex].time > A){
	maxIndex = -1;
}

while(((p[minIndex].time + P-1) < A && minIndex <(N-1))){
	minIndex = ((N-1)+minIndex)/2 +1;
}
while(minIndex > 0 && (p[minIndex-1].time + P-1) >= A){
	minIndex--;
}
int util = 0;
util += returnMaxCombo(minIndex,maxIndex, B);
cout << util << endl;
}
return 0;
}
