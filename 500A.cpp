#include <string>
#include <map>
#include <iostream>
// 500A - http://codeforces.com/problemset/problem/500/A
using namespace std;
int N, idx, A;


// next1 stores the next index and next2 stores how much time it takes to get from next1[i]->next1[j]




int main(){
	
	std::cin >> N;
	cin >> idx;
	int currIdx =1;
	int b = 1;

	while(N--){
		cin >> A;
		currIdx += A;
		b++;
		if(currIdx > b){
			while(currIdx > b){
				cin >> A;
				b++;
			}
		}	
		if(currIdx >= idx) break;
	}
	if(currIdx == idx){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

return 0;
}
