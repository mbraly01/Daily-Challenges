#include <iostream>
#include "node.hpp"

Node::Node(int new_num) {
    num = new_num;
}

void Node::AssignNode(Node* new_node) {
    node = new_node;
}

Node* Node::AssignArray(int list[]) {
    if (sizeof(list) == 0) {
        return 0;
    }
    else {

        Node new_node(list[0]);
        int new_list[sizeof(list)-1];
        std::copy(1, std::end(list), std::begin(new_list));
        new_node.AssignNode(new_node.AssignArray(new_list));
        return &new_node;

    }

}