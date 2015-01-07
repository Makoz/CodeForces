#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <limits>
// 500C - http://codeforces.com/problemset/problem/500/C
using namespace std;
int N, D, W[510],K,A[1010];
// next1 stores the next index and next2 stores how much time it takes to get from next1[i]->next1[j]
int minWeight = numeric_limits<int>::max();

int main(){

	cin >> N >> D;
	int idx=1;
	int sum=0;
	while(N--){
		cin >> W[idx];
		idx++;
	}
	int C = D;
	cin >> K;
	A[D] = K;
	C--;
	int j = 1;
	while(C--){
		j++;
		cin >> K;
		int i = D;
		int k2 = K;
		while(A[i] != K){
			sum += W[A[i]];
			int m = A[i];
			A[i] = k2;
			i--;
			k2=m;
			if(A[i] == 0){
				A[i] = m;
				break;
			}
			
		}
		A[i] = k2;
	}
	cout << sum;
	
return 0;
}
