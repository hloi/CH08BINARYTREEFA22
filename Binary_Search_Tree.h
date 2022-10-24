//
// Created by hloi on 10/24/2022.
//

#ifndef CH08BINARYTREEFA22_BINARY_SEARCH_TREE_H
#define CH08BINARYTREEFA22_BINARY_SEARCH_TREE_H

#include "Binary_Tree.h"
template <typename Item_Type>
class Binary_Search_Tree : public Binary_Tree<Item_Type> {
public:
    Binary_Search_Tree() : Binary_Tree<Item_Type>() {}

    virtual bool insert(const Item_Type& item);

    virtual bool erase(const Item_Type& item);

    const Item_Type* find(const Item_Type& target) const;

private:
    virtual bool insert(BTNode<Item_Type>*& local_root,
                        const Item_Type& item);

    virtual bool erase(BTNode<Item_Type>*& local_root,
                       const Item_Type& item);

    const Item_Type* find(BTNode<Item_Type>* local_root,
                          const Item_Type& target) const;
};
#endif //CH08BINARYTREEFA22_BINARY_SEARCH_TREE_H
