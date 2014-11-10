/*
	Quick Sort
	Version of inventor: Sir Charles Antony Richard Hoare
 */

#include<iostream>
#include<vector>
using namespace std;

class quickSort{
public:
	void quicksort(vector<int> &arr, int lo, int hi){
		if(lo < hi){
			int j = partition(arr, lo, hi);
			quicksort(arr, lo, j-1);
			quicksort(arr, j+1, hi);
		}
	}

	int partition(vector<int> &arr, int lo, int hi){
		int i = lo, j = hi+1;
		while(true){
			while(arr[++i] < arr[lo])  // move first and then check
				if(i == hi) break;
			while(arr[--j] > arr[lo]) 
				if(j == lo) break;
			
			if(j <= i) break;
			swap(arr, i, j);
		}
		swap(arr, lo, j);
		return j;
	}

	void swap(vector<int> &arr, int i, int j){
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
};

int main(){
	quickSort q;
	int a[] = {5,1,9,9,10,4,9,3,7,6};
	vector<int> arr(a, a+10);
	q.quicksort(arr, 0, arr.size()-1);
	for(int i : arr)
		cout << i << " ";
	cout << endl;
	return 0;
}