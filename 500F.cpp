// Codeforces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <limits>
#include <math.h>
// http://codeforces.com/problemset/problem/500/F
// still fails at Time 7 with more efficient search
int N, P, Q;
int A, B, C, D;
struct item{
	int cost;
	int happy;
	int time;
};
using namespace std;
item p[4010];

bool sortOrder(item i1, item i2){ return i1.time < i2.time; }

int returnMaxCombo(int startIdx, int endIdx, int budget){

	if (budget == 0) return 0;
	if (startIdx > endIdx){
		return 0;
	}
	int a = 0;
	int b = budget;
	if (p[startIdx].cost <= budget){
		a = p[startIdx].happy;
		b = budget - p[startIdx].cost;

	}
	if (b == budget){
		return returnMaxCombo((startIdx + 1), endIdx, budget);
	}

	return max(returnMaxCombo((startIdx + 1), endIdx, budget), (returnMaxCombo((startIdx + 1), endIdx, b) + a));
}

// We Want to find the maximum index i such that P[i] <= A and P[i+1] > A

int findMaxIndexHelper(int A, int maxIdx, int minCap, int pivot){
	if (maxIdx < minCap) return -1;
	if (p[pivot].time <= A && p[pivot + 1].time > A) return pivot;
	if (p[pivot].time > A) return findMaxIndexHelper(A, (pivot - 1), minCap, ((pivot - 1 + minCap) / 2));
	// if (p[pivot].time < A) 
	return findMaxIndexHelper(A, maxIdx, (pivot + 1), ((maxIdx + pivot + 1) / 2));

}

int findMaxIndex(int A, int maxIdx, int minCap){
	// cout << "A is: " << A << ", pmaxIdx.time " << p[maxIdx].time << " P is:" << P << endl;
	if (p[maxIdx].time < A && ((p[maxIdx].time + P-1) < A)) return -1;
	if (p[maxIdx].time <= A) return maxIdx;
	if (maxIdx == minCap) return -1;
	int pivot = (maxIdx - 1 + minCap) / 2;
	return findMaxIndexHelper(A, maxIdx-1, minCap, pivot);
}


int findMinIndexHelper(int A, int maxIdx, int minCap, int pivot){
	if (maxIdx < minCap) return N;
	if (p[pivot].time > A) return findMinIndexHelper(A, (pivot - 1), minCap, (pivot + minCap) / 2);
	if (p[pivot].time <= A && p[pivot].time + P-1 >= A && p[pivot - 1].time + P-1 < A) return pivot;
	if (p[pivot].time < A  && p[pivot].time + P - 1 < A) return findMinIndexHelper(A, maxIdx, pivot+1, 1+(maxIdx + pivot) / 2);
	return findMinIndexHelper(A, pivot, minCap, ((pivot + minCap) / 2));
}

int findMinIndex(int A, int maxIdx, int minCap){
	if (p[minCap].time > A || p[maxIdx].time+P-1 < A) return N;
	if (p[minCap].time <= A && p[minCap].time + P-1 >= A) return minCap;
	int pivot = (maxIdx + minCap + 1) / 2;
	return findMinIndexHelper(A, maxIdx, minCap, pivot);
}




int main(){

	cin >> N >> P;
	int idx = 0;
	int L = N;
	while (L--){
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

	sort(p, p + N, sortOrder);
	/*
	for(int i =0 ; i<N; i++){
	cout << p[i].cost << " " << p[i].happy << " " << p[i].time << endl;
	}
	*/
	cin >> Q;
	while (Q--){
		cin >> A >> B;
		// A is visittime, B is budget
		
		int minIndex = findMinIndex(A, (N - 1), 0);
		// adjust maxIndex
		int maxIndex = findMaxIndex(A,(N-1), 0);
		/*
		int desm1 = N - 1;
		while (p[desm1].time > A){
			desm1--;
		}
		
		int desm2 = 0;
		while ((p[desm2].time + P - 1) < A){
			desm2++;
		}
		
		cout << maxIndex << " " << minIndex << " desired: " << desm1 << " " << desm2 <<endl;
		*/
		int util = 0;
		util += returnMaxCombo(minIndex, maxIndex, B);
		cout << util << endl;
	}

	return 0;
}

