#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//кол-во уникальных эл-тов в массиве

int unique(vector<int> &arr) {
    int n = arr.size();
    int count = arr.size();
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            --count;
        }
    }
    return count;
}


template <typename A> class my_vector
{
private:
    A *_arr;
    int _size;
public:
    my_vector() {
        this->_size = 0;
        this->_arr = new A[0];
    }

    void my_push_back(A val)
    {
        A *res = new A[++this->_size];
        for(int ind = 0; ind < this->_size; ind++) {
            if(ind != this->_size-1) {
                res[ind] = this->_arr[ind];
            }
            else {
                res[ind] = val;
            }
        }
        delete[] this->_arr;
        this->_arr = res;
    }

    void my_display_vector() {
        for (int i = 0; i < this->_size; ++i) {
            std::cout << this->_arr[i] << std::endl;
        }
    }

    int at(A elem) {
        for (int i = 0; i < this->_size; ++i) {
            if (this->_arr[i] == elem) {
                return i;
            }
        }
        std::cout << "element not found" << std::endl;
    }

    void my_pop_back() {
        this->_size = this->_size - 1;
        this->_arr[this->_size] = NULL;
    }

    int my_size() {
        return this->_size;
    }
};


int main() {
    my_vector<int> vec;

    vec.my_push_back(5);
    vec.my_push_back(10);
    vec.my_push_back(14);
    vec.my_push_back(88);
    vec.my_push_back(99);
    vec.my_push_back(101);
    vec.my_display_vector();
    std::cout << vec.at(5) << std::endl;
    std::cout << "----" << std::endl;
    vec.my_pop_back();
    vec.my_pop_back();
    vec.my_display_vector();
    std::cout << vec.my_size();

    // v[0]

    return 0;
}
