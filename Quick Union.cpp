/*
	Implement class Quick Union
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

// Union: O(1)
//		union(p, q) => arr[q] = p; 
//		p is the parent of q in the relationship tree
// Find: O(k)
//		go up to the tree until a[p] = p, which is the ancestor
//		check two if they share the ancestor

#include<iostream>
#include<vector>
using namespace std;

class quickUnion{
private:
	vector<int> v;
public:
	quickUnion(int size){
		for(int i = 0; i < size; i++) v.push_back(i);
	}

	// improve: append smaller size tree to the bigger size tree
	void myunion(int p, int q){
		v[q] = p;
	}

	// point
	int root(int i){
		while(v[i] != i) { i = v[i]; }
		return i;
	}

	int connected(int p, int q){
		return root(p) == root(q);
	}
};

int main(){
	quickUnion q (10); 
	q.myunion(4, 3); 
	q.myunion(3, 8); 
	q.myunion(6, 5); 
	q.myunion(9, 4); 
	q.myunion(2, 1); 
	cout << q.connected(0, 7) << endl;
	cout << q.connected(8, 9) << endl;
	q.myunion(5, 0);
	q.myunion(7, 2);
	q.myunion(6, 1);
	q.myunion(1, 1);
	cout << q.connected(0, 7) << endl;
	return 0;
}