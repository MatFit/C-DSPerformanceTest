#ifndef HASHMAP_H
#define HASHMAP_H
#include <functional> // std::hash tools


template <typename T>
class HashMap {
    public:
        // Default Constructor that uses insertElement() method
        HashMap(std::vector<T> vals, int size) : table(size), occupied(size, false), size(size) {
            for (const auto &v : vals){
                insertElement(v);
            }
        }
        // Hash function
        int hashKey(T val){
            std::hash<T> hasher;
            size_t hash_val = hasher(val);
            return hash_val % size; // remains in hash table range
        }
        // Insert element via hash key index
        void insertElement(T val){
            int key = hashKey(val);
            if (!occupied[key]){
                table[key] = val;
                occupied[key] = true;
                return;
            }
            else{
                for (int i = 1; i < size; i++){
                    int new_key = (key + i) % size;
                    if (!occupied[new_key]){
                        table[new_key] = val;
                        occupied[key] = true;
                        return;
                    }
                }
            }

            return;
        }

        // Best case search for O(1) worst case with linear probing search O(n)
        bool search(T val){
            int key = hashKey(val);


            // Linear probing because LL handling doesn't work with just type T
            if (!occupied[key]){
                return false;
            }
            if (table[key] == val){
                return true;
            }  
            else{
                for (int i = 1; i < size; i++){
                    int new_key = (key + i) % size;
                    if (!occupied[new_key]){
                        return false;
                    }
                    if (table[new_key] == val){
                        return true;
                    }
                }
            }

            return false;

        }
        // Use hash key to find and delete, best case O(1) and worst case O(n)
        void deleteElement(T val){
            int key = hashKey(val);
            if (!occupied[key]){
                return;
            }
            if (table[key] == val){
                table[key] = T();
                occupied[key] = false;
                return;
            }

            for (int i = 1; i < size; i++){
                int new_key = (key + i) % size;
                if (!occupied[key]){
                    return;
                }
                if (table[new_key] == val){
                    table[new_key] = T();
                    occupied[new_key] = false;
                    return;
                }
            }

            return;
            
        }
        // Getter for testing purposes
        int getSize(){
            return size;
        }
        // Overloading operator << to print hashmap 
        friend std::ostream& operator<<(std::ostream& os, const HashMap<T> &hashMap){
            for (int i = 0; i < hashMap.size; i++){
                os << "Bucket " << i << ": ";
                if (hashMap.occupied[i]){
                    os << hashMap.table[i];
                }
                else{
                    os << "empty";
                }

                os << std::endl;
            }
            return os;
        }

    private:
        std::vector<T> table;
        std::vector<bool> occupied; // To deal with empty slots, if occuiped will trigger linear probing 
        int size;
};

#endif
