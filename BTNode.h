//
// Created by hloi on 10/21/2022.
//

#ifndef CH08BINARYTREEFA22_BTNODE_H
#define CH08BINARYTREEFA22_BTNODE_H
#include <sstream>

template<typename Item_Type>
struct BTNode  {
    Item_Type data;
    BTNode<Item_Type>* left;
    BTNode<Item_Type>* right;

    BTNode(const Item_Type& the_data,
           BTNode<Item_Type>* left_val = NULL,
           BTNode<Item_Type>* right_val = NULL) :
           data(the_data), left(left_val), right(right_val) {}

   virtual ~BTNode() {}

   virtual std::string to_string() const {
        std::ostringstream oss;
        oss << data;
        return oss.str();
    }

};

template<typename Item_Type>
std::ostream& operator<<(std::ostream& out, const BTNode<Item_Type>& node) {
    return out << node.to_string();
}
#endif //CH08BINARYTREEFA22_BTNODE_H
