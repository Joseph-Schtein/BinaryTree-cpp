#pragma once
#include <iostream>

namespace ariel{
    
    template <typename T>
    class BinaryTree{

        
        struct Node{
            T value;
            Node* left;
            Node* right;
        };

        Node* root;

        

        BinaryTree& add_leftPrivate(Node* tmp , const T& insertFrom, T input){
            if(tmp->left->value == insertFrom){
                if(tmp->left->left == NULL){
                    tmp->left->left = new Node(input);
                }

                else{
                    tmp->left->left->value = input;
                }
            }

            else if(tmp->right->value == insertFrom){
                if(tmp->right->left == nullptr){
                    tmp->right->left = new Node(input);
                }

                else{
                    tmp->right->left->value = input;
                }
            }

            else{
                add_leftPrivate(tmp->left ,insertFrom, input);
                add_leftPrivate(tmp->right, insertFrom, input);
            }    
            
            return *this;
        }


        BinaryTree& add_rightPrivate(Node* tmp , const T& insertFrom, T input){
            if(tmp->left->value == insertFrom){
                if(tmp->left->right == nullptr){
                    tmp->left->right = new Node(input);
                }

                else{
                    tmp->left->right->value = input;
                }
            }

            else if(tmp->right->value == insertFrom){
                if(tmp->right->right == nullptr){
                    tmp->right->right = new Node(input);
                }

                else{
                    tmp->right->right->value = input;
                }
            }

            else{
                add_rightPrivate(tmp->left ,insertFrom, input);
                add_rightPrivate(tmp->right, insertFrom, input);
            }    
            
            return *this;
        }

        


    
    public:

        BinaryTree(): root(NULL){}
            

        ~BinaryTree();

        void delete_Tree();

        void deleteTree(Node* tmp);

        Node* createNode(T v){
            Node *output = new Node;
            output->value = v; 
            output->left = NULL;
            output->right = NULL;
            return output;
        }


        BinaryTree<T>& add_root(T v){
            
            /*if(this->root == NULL){
                root = createNode(v);
                std::cout << "create node" << std::endl;
            }

            else{
                this->root->value = v;
            }*/

            return *this;
        }

        Node* get_root(){
            return root;
        }


        BinaryTree<T>& add_left(T insertFrom, T input){
            //add_leftPrivate(root, insertFrom, input);
            return *this;
        }

        BinaryTree<T>& add_right(T insertFrom, T input){

            //add_rightPrivate(root, insertFrom, input);
            return *this;

        }
        
        friend std::ostream& operator<< (std::ostream& os, BinaryTree<T> tree){
            return os << " hello there " << std::endl;
        }


        
        class preorderIterator{

            Node* pointerToNode;

            public:

            preorderIterator(Node* ptr = nullptr): pointerToNode(ptr) {}

            T& operator*() const {
			    return pointerToNode->value;
		    }

            T* operator->() const {
			    return &(pointerToNode->value);
		    }

            preorderIterator& operator++() {
			    /*if(pointerToNode->left){
                    pointerToNode = pointerToNode->left;
                }

                if(pointerToNode->right){
                    pointerToNode = pointerToNode->right;
                }*/
                
                
                return *this;
		    }

		    const preorderIterator operator++(int) {
			    preorderIterator tmp = *this;
                
                /*if(pointerToNode->left){
                    pointerToNode = pointerToNode->left;
                }

                if(pointerToNode->right){
                    pointerToNode = pointerToNode->right;
                }*/
                
                
                return tmp;
		
            }

            bool operator==(const preorderIterator& rhs) const {
                return pointerToNode == rhs.pointerToNode;
            }

            bool operator!=(const preorderIterator& rhs) const {
			    return pointerToNode != rhs.pointerToNode;
		    }

        };


        class inorderIterator{

            Node* pointerToNode;

            public:

            inorderIterator(Node* ptr = nullptr): pointerToNode(ptr) {}

            T& operator*() const {
			    return pointerToNode->value;
		    }

            T* operator->() const {
			    return &(pointerToNode->value);
		    }

            inorderIterator& operator++() {
			    /*if(pointerToNode->left){
                    pointerToNode = pointerToNode->left;
                }

                if(pointerToNode->right){
                    pointerToNode = pointerToNode->right;
                }*/
                
                
                return *this;
		    }

		    const inorderIterator operator++(int) {
			    inorderIterator tmp = *this;
                
                /*if(pointerToNode->left){
                    pointerToNode = pointerToNode->left;
                }

                if(pointerToNode->right){
                    pointerToNode = pointerToNode->right;
                }*/
                
                
                return tmp;
		
            }

            bool operator==(const inorderIterator& rhs) const {
                return pointerToNode == rhs.pointerToNode;
            }

            bool operator!=(const inorderIterator& rhs) const {
			    return pointerToNode != rhs.pointerToNode;
		    }

        };


        class postorderIterator{

            Node* pointerToNode;

            public:

            postorderIterator(Node* ptr = nullptr): pointerToNode(ptr) {}

            T& operator*() const {
			    return pointerToNode->value;
		    }

            T* operator->() const {
			    return &(pointerToNode->value);
		    }

            postorderIterator& operator++() {
			    /*if(pointerToNode->left){
                    pointerToNode = pointerToNode->left;
                }

                if(pointerToNode->right){
                    pointerToNode = pointerToNode->right;
                }*/
                
                
                return *this;
		    }

		    const postorderIterator operator++(int) {
			    postorderIterator tmp = *this;
                
                /*if(pointerToNode->left){
                    pointerToNode = pointerToNode->left;
                }

                if(pointerToNode->right){
                    pointerToNode = pointerToNode->right;
                }*/
                
                
                return tmp;
		
            }

            bool operator==(const postorderIterator& rhs) const {
                return pointerToNode == rhs.pointerToNode;
            }

            bool operator!=(const postorderIterator& rhs) const {
			    return pointerToNode != rhs.pointerToNode;
		    }

        };




        preorderIterator begin_preorder() {
		    return preorderIterator{root};
	    }
	
	    preorderIterator end_preorder() {
		    return preorderIterator{root};
	    }


        inorderIterator begin_inorder() {
		    return inorderIterator{root};
	    }
	
	    inorderIterator end_inorder() {
		    return inorderIterator{root};
	    }


        inorderIterator begin() {
		    return inorderIterator{root};
	    }
	
	    inorderIterator end() {
		    return inorderIterator{root};
	    }


        postorderIterator begin_postorder() {
		    return postorderIterator{root};
	    }
	
	    postorderIterator end_postorder() {
		    return postorderIterator{root};
	    }
    };

    template <typename T>
    BinaryTree<T>::~BinaryTree() {
        delete_Tree();
    };

    template <typename T>
    void BinaryTree<T>::delete_Tree(){
        deleteTree(root);
    };

    template <typename T>
    void BinaryTree<T>::deleteTree(Node* tmp){
        if(tmp != NULL){
            std::cout << tmp << std::endl;
            deleteTree(tmp->left);
            deleteTree(tmp->right);
            delete tmp;              
        }       
    };
} 