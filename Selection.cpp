/*
	Quick Sort Idea to Find the Kth Largest
	Sort: O(nlogn) 
	Improve: O(n)
 */

#include<iostream>
#include<vector>
using namespace std;

class Selection{
public:
	int selection(vector<int> &arr, int k){
		int lo = 0, hi = arr.size()-1;
		while(lo < hi){
			int j = partition(arr, lo, hi);
			if(j == k)
				return arr[j];
			else if(j < k)
				lo = j+1;
			else
				hi = j-1;
		}
		return arr[k];
	}

	int partition(vector<int> &arr, int lo, int hi){
		int i = lo, j = hi+1;
		while(true){
			while(arr[++i] < arr[lo])
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
	Selection s;
	int a[] = {5,1,4,9,10,8,2,3,7,6};
	vector<int> arr (a, a+10);
	cout << s.selection(arr, 9) << endl;
	cout << s.selection(arr, 8) << endl;
	cout << s.selection(arr, 7) << endl;
	return 0;
}