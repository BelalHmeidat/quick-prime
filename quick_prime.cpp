#include <iostream>
#include <iostream>
#include <iomanip> 
#include <utility> // for std::pair
#include <cmath>

using namespace std;

bool estimatePrimeEnh2(int arr[], int N, int num){
	if (num == 1){
		return false;
	}
	for (int i = 0; i < N; i++){
		// cout << arr[i] << endl;
		if (num == arr[i]){
			return true;
		}
		if(num % arr[i] == 0){
			return false;
		}
	}
	return true;
}
bool isPrimeLoopEnh(int num){
	if (num < 2){
		return false;
	}
	if (num == 2)
		return true;
	if (num % 2 == 0){
		return false;
	}
	for (int i = 3; i < num; i+=2){
		if (num % i == 0) return false;
	}
	return true;
}

pair<int*, int> getAllPrimesLoopEnh(int N){
	int* primes = new int[N/4];
	int index = 0;
	for (int i = 0; i < N; i++){
		if (isPrimeLoopEnh(i)){
			primes[index++] = i;
		}
	}
	return make_pair(primes, index);
}


void findAllprimesEstEnh2(int N){
	clock_t start, end;
	start = clock();
	int primes = 0;
	pair<int*, int> arrayInfo = getAllPrimesLoopEnh(sqrt(N));
	int* arr = arrayInfo.first;
	int arrSize = arrayInfo.second;
	for (int i = 0; i < N; i++){
		if(estimatePrimeEnh2(arr, arrSize, i)){
			cout << i << ", ";
			primes++;
		}
	}
	cout << endl;
	cout << "Found "<< primes << " primes between 0 and " << N << " in ";
	end = clock();
	double time = double(end - start) / CLOCKS_PER_SEC;
	cout << time << " seconds." << endl;
}

int testRunEstEnh2(int N){
	//please comment out all cout prints in findAllprimesEstEnh2() before running this.
	double longrun = 0;
	for (int i = 0; i < N; i++){
		clock_t start, end;
		start = clock();
		findAllprimesEstEnh2(1000);
		end = clock();
		double time = double(end - start) / CLOCKS_PER_SEC;
		longrun+=time;
	}
	double avg = longrun/N;
	cout << "AVG Time: " << avg << " sec for " << N << " runs" << endl;
	return avg;
}

void findPrimes(int N){
	findAllprimesEstEnh2(N);
}


int main () {
	findPrimes(1000000);
	return 0;
}