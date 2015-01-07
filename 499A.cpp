//CodeForces 499A http://codeforces.com/problemset/problem/499/A

#include <iostream>
#include <vector>
#include <string>
#include <map>


std::map<std::string, std::string> A;
int N, M;
int X,Y;
int main(){
	// N - num of best moments, M - how many minutes we can skip
	std::cin >> N >> M;
	
	int currMin = 1;
	int currLen = 0;
	while (N--){
		// X - start min, Y - end min
		std::cin >> X >> Y;
		
		while ((currMin+M) <= X){
			currMin += M;
		}
		currLen += ((Y+1)-currMin);
		currMin = Y+1;
	}

	std::cout << currLen;



return 0;
}
