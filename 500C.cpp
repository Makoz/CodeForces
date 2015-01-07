#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <limits>
// 500C - http://codeforces.com/problemset/problem/500/C
using namespace std;
int N, D,X;
map<int, int> W; // stores the respective weight of the ith book
vector<int> myVect;

int minWeight = numeric_limits<int>::max();





int main(){


	cin >> N >> D;
	int idx=1;
	int B;
	int Q=N;
	while(Q--){
		cin >> B;
		W[idx] = B;
		idx++;
	}

int count = 1;

	while(N >= count){
		myVect.push_back(count);
		count++;
	}
vector<int> orderOfRead;
int K=D;
while(K--){
		cin >> X;
		orderOfRead.push_back(X);
}

do{
	vector<int> temp = myVect;
	int tempWeight = 0;
	for(int i=0; i<orderOfRead.size(); i++){
		int Z = orderOfRead[i];
	
		int vectIdx = N-1;
		while(temp[vectIdx] != Z){
	
			tempWeight += W[(temp[vectIdx])];
			vectIdx--;
		}
		
		
		for(int j=vectIdx; j<(N-1); j++){
			temp[j] = temp[j+1];
		}
		temp[N-1] = Z;
	}
	
	if(tempWeight < minWeight){
		minWeight = tempWeight;
	}
} while(next_permutation(myVect.begin(), myVect.end()));

cout << minWeight << endl;
return 0;
}
