#ifndef TREE_H
#define TREE_H

// Same idea with Node, though Node is only every instanciated in class Tree, whatever datatype class Tree has so will Node
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
#endif