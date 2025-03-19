#include <iostream>

template <typename T>
class BSTSet 
{
private:
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        T& value;
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