// #include <set>
// #include <iostream>

// template <typename ItemType>

// class BSTSet 
// {

    
    
//     private:
//         struct TreeNode {
//             TreeNode* left;
//             TreeNode* right;
//             TreeNode* parent;
//             ItemType& value;
//             TreeNode(ItemType z, TreeNode* leftNode = nullptr, TreeNode* rightNode = nullptr, TreeNode* parentNode = nullptr)
//             : value (z) , left(leftNode), right(rightNode), parent(parentNode)                            
//             {}
//         };
//         TreeNode* root; 
       

//     public:
        
//     /* thoughts for this is to keep a root node and a current value, and what it'll do is return return the value that is greater th*/
//         class SetIterator
//         {
//             private:
//             void deleteNode(TreeNode* root)
//                 {
//                     if(root != nullptr)
//                     {
//                         deleteNode(root->left);
//                         deleteNode(root->right);
//                     }
//                     delete root;
//                 }
//             public:
//                 SetIterator(TreeNode* root = nullptr)
//                 :current(root)
//                 {
//                     while(current && current->left)
//                         current = current->left;
                    
//                 }
//                 ~SetIterator() {
//                     deleteNode(current);
//                 }
//                 const ItemType* get_and_advance() //how do i do this? 
//                 {
//                     if(current == nullptr)
//                     {
//                         return nullptr;
//                     }
//                     TreeNode* returnValue = current;

//                     if(current->right != nullptr) //smallest in the right subtree
//                     {
//                         current= current->right;
//                         while(current->left)
//                             current = current->left;
                         
//                     }
//                     else if(current->right == nullptr){
//                         //current doens't have a right sub tree, then have to find the largest value in thje left subtree
                        
//                         //use parent pointers to move upward until you find a node for which the current node is in the left subtree
//                         //what does that mean
//                         //go up the partent pointers, until
//                         while(current->parent && current == current->parent->right)
//                             current= current->parent;
//                         //after the loop it is the right subtree, one more and hten it's good
//                         current = current->parent; 
//                     }
//                     ItemType* returnvaluePointer = returnValue->value;
//                      return returnvaluePointer;
//                 }
                    
                
//             private:
                
//                 TreeNode* current;

                

//         };
//         void insert(const ItemType& value);
//         SetIterator find(const ItemType& value) const;
//         SetIterator find_first_not_smaller(const ItemType& value) const;

//         private: //helper methods
//             void insertHelper(TreeNode* node, const ItemType& value);
//             SetIterator find_helper(const ItemType& value, TreeNode* node) const;

//     };



// //////////////////////////
// //FUNCTION IMPLEMENTATIONS
// //////////////////////////
// template<typename ItemType>
// void BSTSet<ItemType>::insertHelper(TreeNode* node, const ItemType& value)
// {
//     //what this does is it uses exclusion to exlucde the case when value is already in the tree 
//     //implemented with treeNode
//     if(node == nullptr)
//         node = new TreeNode(value,nullptr,nullptr,nullptr);
//     else if(node->value < value)
//     {
//         if(node->right != nullptr)
//             insertHelper(node->right, value);
//         else
//             node->right = new TreeNode(value,nullptr,nullptr,node);
        
//     }
//     else if(node->value > value)
//     {
//         if(node->left != nullptr)
//              insertHelper(node->left, value);
//         else
//             node->left = new TreeNode(value,nullptr,nullptr,node);
//     }
         
// }
// template<typename ItemType> 
// void BSTSet<ItemType>::insert(const ItemType& value)
// {
//     insertHelper(root,value);
// }

// template<typename ItemType>
// typename BSTSet<ItemType>::SetIterator BSTSet<ItemType>::find(const ItemType& value) const{
    
//     return find_helper(value, root);
// }

// template<typename ItemType>
// typename BSTSet<ItemType>::SetIterator BSTSet<ItemType>::find_helper(const ItemType& value, TreeNode* node) const
// {
//     if(!node)
//         return nullptr;
//     if(node->value > node)
//         return find_helper(node->left);
//     else if(node ->value < node)
//         return find_helper(node->right);
//     else
//         return SetIterator(node);
// }
// template<typename ItemType>
// typename BSTSet<ItemType>::SetIterator BSTSet<ItemType>::find_first_not_smaller(const ItemType& value) const{ 
//     BSTSet<ItemType>::SetIterator itr = find(value);
//     itr->get_and_advance();

// //can use parent nodes
// //find node, where its at, Hint: call find method
// //you know where that node is now, 
// //then just go up to its parent node
// //if node is right sub tree then return parent
// //if node is not right sub tree, then 

// }





//     //maybe instead of implementing it with a thing, lets implemnet it with/
//     //instead of a set use a dynamically allocated array

//     //use a binary search tree to implemnt this 


// // template<typename ItemType>
// // void BSTSet::insert(const ItemType& value){

// // }

#include <iostream>

template <typename T>
class BSTSet 
{
private:
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        T value;
        TreeNode(const T& z, TreeNode* leftNode = nullptr, TreeNode* rightNode = nullptr, TreeNode* parentNode = nullptr)
            : value(z), left(leftNode), right(rightNode), parent(parentNode)                            
        {}
    };
    TreeNode* root; 

public:
    BSTSet() : root(nullptr) {}
    ~BSTSet() { clear(root); }

    void insert(const T& value) {
        if (root == nullptr)
            root = new TreeNode(value);
        else
            insertHelper(root, value);
    }

    class SetIterator
    {
    public:
        SetIterator(TreeNode* node)
            : current(node)
        {
            // while(current && current->left)
            //     current = current->left;
        }
        //okay i might need a way to use the default constrction to be set the the minimum value of the treeValue
        //maybemaybenot

        ~SetIterator() { }

        const T* get_and_advance() 
        {
            if(current == nullptr)
                return nullptr;
            TreeNode* returnValue = current;
            if(current->right != nullptr)
            {
                current = current->right;
                while(current->left)
                    current = current->left;
            }
            else 
            {
                while(current->parent && current == current->parent->right)
                    current = current->parent;
                current = current->parent;
            }
            return &(returnValue->value);
        }

    private:
        TreeNode* current;
        friend class BSTSet<T>;
    };

    SetIterator find(const T& value) const {
        TreeNode* node = find_helper(root, value);
        return SetIterator(node);
    }

    SetIterator find_first_not_smaller(const T& value) const { 
        
        TreeNode* current= root;
        TreeNode* returnElement = nullptr;
        while(current)
        {
            if(current->value == value)
            {
                return SetIterator(current);
            }
            else if( (current->value >= value))  // value is less than or equal
            {
                returnElement = current;
                current = current->left;
            }
            else
            {
                current = current->left;
            }
        }

        return returnElement;
    }

private:
    void insertHelper(TreeNode* node, const T& value) 
    {
        if(node->value < value)
        {
            if(node->right != nullptr)
                insertHelper(node->right, value);
            else
                node->right = new TreeNode(value, nullptr, nullptr, node);
        }
        else if(value < node->value)
        {
            if(node->left != nullptr)
                 insertHelper(node->left, value);
            else
                node->left = new TreeNode(value, nullptr, nullptr, node);
        }
        else 
        {
            node->value = value;
        }
    }

    TreeNode* find_helper(TreeNode* node, const T& value) const
    {
        if(!node)
            return nullptr;
        if(value < node->value)
            return find_helper(node->left, value);
        else if(node->value < value)
            return find_helper(node->right, value);
        else
            return node;
    }

    void clear(TreeNode* node)
    {
        if(node)
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};