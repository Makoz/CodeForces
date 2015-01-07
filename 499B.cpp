// http://codeforces.com/problemset/problem/499/B

#include <iostream>
#include <vector>
#include <string>
#include <map>


std::map<std::string, std::string> A;
int N, M;
std::string X,Y;
std::string in;
int main(){
	std::cin >> N >> M;
	while (M--){
		std::cin >> X >> Y;
		if(X.size()> Y.size()){
			A[X] = Y;
		}
		else{
			A[X] = X;
		}
	}

	while(N--){
	std::cin >> in;
	std::cout << A[in] << " ";
	}



return 0;
