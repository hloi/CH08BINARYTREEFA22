//
// Created by hloi on 10/24/2022.
//

#ifndef CH08BINARYTREEFA22_PRE_ORDER_TRAVERSAL_H
#define CH08BINARYTREEFA22_PRE_ORDER_TRAVERSAL_H
#include "Binary_Tree.h"
#include <ostream>
#include <iostream>

template <typename Item_Type>
void pre_order_traversal(const Binary_Tree<Item_Type>& the_tree,
                         std::ostream& out, int level) {
    if (the_tree.is_null()) {
        for (int i=0; i<level; i++) {
           out << " ";
        }
        out << "null\n";
    }
    else {
        for (int i=0; i<level; i++) {
            out << " ";
        }
        out << the_tree.get_data() << std::endl;
        pre_order_traversal(the_tree.get_left_subtree(), out, level+1);
        pre_order_traversal(the_tree.get_right_subtree(), out, level+1);
    }
}
#endif //CH08BINARYTREEFA22_PRE_ORDER_TRAVERSAL_H
