/*
	Implement class Quick Find
	bool connected(int p, int q);
	void union(int p, int q);

	union(4, 3)
	union(3, 8)
	union(6, 5)
	union(9, 4)
	union(2, 1)
	connected(0, 7) false
	connected(8, 9) true
	union(5, 0)
	union(7, 2)
	union(6, 1)
	union(1, 0)
	connected(0, 7) true
 */

// Union: O(n)
// Find: O(1)

// p and q are connected if they have the same id
// union(p, q) -> if arr[i] = p  =>  arr[i] = q;

#include<iostream>
#include<vector>
using namespace std;

class quickFind{
private:
	vector<int> v;
public:
	quickFind(int size){
		for(int i = 0; i < size; i++) v.push_back(i);
	}

	void myunion(int p, int q){
		int pid = v[p]; // where bug happened
		for(int i = 0; i < v.size(); i++){
			if(v[i] == pid)
				v[i] = v[q];
		}
	}

	// p and q are connected if they have the same id
	bool connected(int p, int q){
		return v[p] == v[q];
	}

	void printV(){
		for(int i : v)
			cout << i << " "; cout << endl;
	}
};

/*
int main(){
	quickFind q (10); 
	q.myunion(4, 3); q.printV();
	q.myunion(3, 8); q.printV();
	q.myunion(6, 5); q.printV();
	q.myunion(9, 4); q.printV();
	q.myunion(2, 1); q.printV();
	cout << q.connected(0, 7) << endl;
	cout << q.connected(8, 9) << endl;
	q.myunion(5, 0);
	q.myunion(7, 2);
	q.myunion(6, 1);
	q.myunion(1, 1);
	cout << q.connected(0, 7) << endl;
	return 0;
}
*/