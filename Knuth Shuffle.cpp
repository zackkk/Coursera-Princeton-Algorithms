/*
	Different from the algorithm in <Cracking the Coding Interview>
	for each i,
		sequence from [0, i-1] are shuffled
		generate a random number from [0, i-1]
		swap arr[i] and arr[random]
 */

// shuffle all, can't generate m elements of n

#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class knuthShuffle{
public:
	void shuffle(vector<int> &arr){
		int sz = arr.size();
		for(int i = 1; i < sz; i++){
			srand(time(NULL));
			int r = rand() % i;
			swap(arr, r, i);
		}
		for(int i : arr)
			cout << i << " ";
		cout << endl;
	}

	void swap(vector<int> &arr, int i, int j){
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};

int main(){
	knuthShuffle k;
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> arr (a, a+10);
	k.shuffle(arr);
	return 0;
}