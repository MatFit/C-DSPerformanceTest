#include <functional>
#include <vector>
#include <ostream>
#include <iostream>

namespace DataStructure {

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


    template <typename T>
    struct Node {
        T val;
        Node* left;
        Node* right;

        Node(T val) : val(val), left(nullptr), right(nullptr) {}
    };


    // Class Tree that handles datatype T, depending what data types are instanciated with this class, a copy of it will be made to handle that datatype
    template <typename T>  
    class Tree {    
        public:
            Tree() {
                root = nullptr;
            }
            Tree(T val) {
                root = new Node<T>(val);
            }
            // Deconstruct the tree via post order
            ~Tree() {
                deconstructorHelper(root);
            }
            
            void deconstructorHelper(Node<T> *&curr){ // pass by reference to modify the pointer
                if (curr == nullptr){
                    // std::cout << "Reached nullptr" << std::endl;
                    return;
                }

                deconstructorHelper(curr->right);
                deconstructorHelper(curr->left);

                delete curr;
                curr = nullptr;
            }
            // Insert element val into tree
            void insertElement(T val){
                if (root == nullptr){
                    root = new Node<T>(val);
                    return;
                }

                Node<T>* current = root;
                Node<T>* parent = nullptr; // Parent to then attach the new node to it

                while (current != nullptr){
                    parent = current;
                    if (val < current->val){
                        current = current->left;
                    }
                    else{
                        current = current->right;
                    }
                }


                // If bigger go to right of parent, else go to left
                if (val < parent->val){
                    parent->left = new Node<T>(val);
                }
                else{
                    parent->right = new Node<T>(val);
                }


            }

            void deleteElement(T val){
                if (root == nullptr){
                    return;
                }

                Node<T>* current = root;
                Node<T>* parent = nullptr;

                while (current != nullptr){
                    parent = current;
                    if (val < current->val){
                        current = current->left;
                    }
                    else if (val > current->val){
                        current = current->right;
                    }
                }


                if (current == nullptr){
                    return;
                }
                // No children
                if (current->left == nullptr && current->right == nullptr){
                    delete current;
                    current = nullptr;
                }

                else if (current->left == nullptr && current->right != nullptr){
                    // Replace right subtree root node
                    if (current == root) { root = current->right; } 
                    else if (parent->left == current) { parent->left = current->right; }
                    else { parent->right = current->right; }

                    delete current;                
                }
                else if (current->left != nullptr && current->right == nullptr){
                    // Replace left subtree root node
                    if (current == root) { root = current->left; } 
                    else if (parent->left == current) { parent->left = current->left; }
                    else { parent->right = current->left; }
                    
                    delete current;         
                }
                else {
                    Node<T>* successor = current->right; // Right subtree
                    Node<T>* successorParent = current;
                    
                    // Travel far left of right subtree
                    while (successor->left != nullptr) {
                        successorParent = successor;
                        successor = successor->left;
                    }
                    // Replace value 
                    current->val = successor->val;

                    // Delete node of far left in right subtree
                    if (successorParent == current) {
                        successorParent->right = successor->right;
                    } else {
                        successorParent->left = successor->right;
                    }
                    delete successor; 
                }
            }
            // Search tree at O(log(n)) speed
            bool search(T val){
                if (root == nullptr){
                    return false;
                }

                Node<T>* current = root;
                // Traverse binary tree and return if value is found
                while (current != nullptr){
                    if (val < current->val){
                        current = current->left;
                    }
                    else if (val > current->val){
                        current = current->right;
                    }
                    else{
                        return true;
                    }
                }

                return false;
            }

            // Overload << operator by printing the tree in order 
            friend std::ostream& operator<<(std::ostream& os, const Tree<T> &tree) {
                os << "Tree: {";
                tree.inOrderTraversalHelper(os, tree.root);
                os << "}";
                return os;
            }

            void inOrderTraversalHelper(std::ostream& os, Node<T>* curr) const {
                if (curr == nullptr){ return; }
                inOrderTraversalHelper(os, curr->left);
                os << curr->val << " ";
                inOrderTraversalHelper(os, curr->right);
                return;
            }
            // Getter for testing purposes
            Node<T>* getRoot(){
                return root;
            }

        private:
            Node<T>* root;
    };


}