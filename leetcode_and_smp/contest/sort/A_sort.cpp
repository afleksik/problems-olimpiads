#include <iostream>
#include <vector>

using namespace std;


vector<int> sort(vector<int> arr, int size) {
	for (int i = size - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
		  if (arr[j + 1] < arr[j]) {
		    std::swap(arr[j+1], arr[j]);
      }
    }	    
	}
	return arr;
}


int main(){
    int n, x;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> x;
        arr.push_back(x);
    }
    arr = sort(arr, arr.size());
    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}