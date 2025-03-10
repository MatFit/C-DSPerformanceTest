#ifndef LINEAR_H
#define LINEAR_H
#include <vector>
#include <ostream>

template <typename T>
class Linear {
    public:
        Linear() : data() {} // Default

        Linear(std::vector<T> data) : data(data) {} // Easier for testing
        // Vector method, just push it back
        void insertElement(T element) {
            data.push_back(element);
        }   
        // Vector method allows for erasure of all elements 'element'
        void deleteElement(T element) {
            data.erase(std::remove(data.begin(), data.end(), element), data.end());
        }
        // Getters
        T getElementAtIndex(int index) {
            return data[index];
        }
        
        int getSize() {
            return data.size();
        }
        // Search at O(n) speed
        bool search(T val){
            for (const auto &d : data){
                if (d == val){
                    return true;
                }
            }

            return false;
        }
        // Override operator << to print vector
        friend std::ostream& operator<<(std::ostream& os, const Linear<T> &linear){
            for (const auto &d : linear.data){
                os << d << " ";
            }
            return os;
        }
        
    private:
        std::vector<T> data;
};


#endif