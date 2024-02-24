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


namespace local
{
    class temp
    {
        public:
        
        temp(size_t n)
        {
            arr = new int[n];
        }
        ~temp()
        {
            delete [] arr;
        }

        private:
        int *arr;
    };

    template <class T>
    class vector
    {
    public:
        vector() {
            this->_size = 0;
            this->_arr = new T[0];
        }

        vector(int size) {}
        vector(const vector<T> &v) {}

        void resize(size_t new_size, const T &value) {
        }

        void resize(size_t new_size) {
            T *res = new T[new_size];
            if (this->_size < new_size) {
                for (size_t i = 0; i < new_size; ++i) {
                    res[i] = this->_arr[i];
                }
            }
            else {
                // 
            }
            this->_size = new_size;
            delete [] this->_arr;
            this->_arr = res;
            this->_capacity = new_size; // возможно неправильно
        }

        void reserve(size_t capacity) {
            if (capacity < this->_size) {
                return;
            }
            T *res = new T[capacity];
            for (size_t ind = 0; ind < this->_size - 1; ++ind) {
                res[ind] = this->_arr[ind];
            }
            this->_capacity = capacity;
            this->_arr = res;
            delete [] res;
        }

        void push_back(T val)
        {
            if (this->_size == this->_capacity) {
                reserve(2 * this->_capacity);
            }
            this->_arr[this->_size] = val;
            ++this->_size; 
        }// 10/20 -> 11/20 ->

        void display_vector() {
            for (size_t i = 0; i < this->_size; ++i) {
                std::cout << this->_arr[i] << std::endl;
            }
        }

        int at(T elem) {
            for (size_t i = 0; i < this->_size; ++i) {
                if (this->_arr[i] == elem) {
                    return i;
                }
            }
            std::cout << "element not found" << std::endl;
            return 0;
        }

        void pop_back() {
            this->_size = this->_size - 1;
            this->_arr[this->_size] = NULL;
        }

        size_t size() {
            return this->_size;
        }

        ~vector() { 
            delete [] this->_arr;
        }
    
    private:
        T *_arr;
        size_t _size;
        size_t _capacity;
    };
}


int main() {
    local::vector<int> vec;

    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(14);
    vec.push_back(88);
    vec.push_back(99);
    vec.push_back(101);
    vec.display_vector();
    std::cout << vec.at(5) << std::endl;
    std::cout << "----" << std::endl;
    vec.pop_back();
    vec.pop_back();
    vec.resize(10); 
    vec.display_vector();
    std::cout << vec.size();

    // v[0]

    return 0;
}
