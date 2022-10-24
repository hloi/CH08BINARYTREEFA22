//
// Created by hloi on 10/21/2022.
//

#ifndef CH08BINARYTREEFA22_BINARY_TREE_H
#define CH08BINARYTREEFA22_BINARY_TREE_H
#include "BTNode.h"
#include <stddef.h>
#include <stdexcept>

template<typename Item_Type>
class Binary_Tree {
public:
    Binary_Tree() : root(nullptr) {}
    Binary_Tree(const Item_Type& the_data,
                const Binary_Tree<Item_Type>& left_child= Binary_Tree<Item_Type>(),
                const Binary_Tree<Item_Type>& right_child= Binary_Tree<Item_Type>()) :
                root(new BTNode<Item_Type>(the_data, left_child.root, right_child.root)) {}

    virtual ~Binary_Tree() {}

    Binary_Tree<Item_Type> get_right_subtree() const;

    Binary_Tree<Item_Type> get_left_subtree() const;

    const Item_Type& get_data() const;

    bool is_null() const;

    bool is_left() const;

    virtual std::string to_string() const;

    static Binary_Tree<Item_Type> read_binary_tree(std::istream& in);

    std::string root_to_string() const {
        return root->to_string();
    }
protected:
    Binary_Tree(BTNode<Item_Type>* new_root) : root(new_root) {}
    BTNode<Item_Type>* root;

};

template<typename Item_Type>
Binary_Tree<Item_Type> Binary_Tree<Item_Type>::get_left_subtree() const {
    if (root == NULL) {
        throw std::invalid_argument("get_left_subtree on empty tree");
    }
    return Binary_Tree<Item_Type>(root->left);
}

template<typename Item_Type>
Binary_Tree<Item_Type> Binary_Tree<Item_Type>::get_right_subtree() const {
    if (root == NULL) {
        throw std::invalid_argument("get_right_subtree on empty tree");
    }
    return Binary_Tree<Item_Type>(root->right);
}

template<typename Item_Type>
const Item_Type &Binary_Tree<Item_Type>::get_data() const {
    if (root == NULL) {
        throw std::invalid_argument("get data on empty tree");
    }
    return root->data;
}

template<typename Item_Type>
bool Binary_Tree<Item_Type>::is_null() const {
    return root == NULL;
}

template<typename Item_Type>
bool Binary_Tree<Item_Type>::is_left() const {
    return root->left == NULL & root->right == NULL;
}

template<typename Item_Type>
std::string Binary_Tree<Item_Type>::to_string() const {
    std::ostringstream oss;
    if (is_null()) {
        oss << "NULL\n";
    }
    else {
        oss << *root << "\n";
        oss << get_left_subtree().to_string();
        oss << get_right_subtree().to_string();
    }
    return oss.str();
}

template<typename Item_Type>
std::ostream& operator<<(std::ostream& out,
        const Binary_Tree<Item_Type>& tree) {
    return out << tree.to_string();
}

template<typename Item_Type>
std::istream& operator>>(std::istream& in,
        Binary_Tree<Item_Type>& tree) {
    tree = Binary_Tree<Item_Type>::read_binary_tree(in);
    return in;
}



#endif //CH08BINARYTREEFA22_BINARY_TREE_H
