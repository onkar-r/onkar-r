
// BINARY TREE AND
// BINARY SEARCH TREE
template <typename T>
struct BTNode {
    T          val;
    BTNode<T>* left;   // TODO: use shared_ptr
    BTNode<T>* right;
};


// LINKED LIST
template <typename T>
ListNode {
    T           val;
    ListNode<T> next;  // TODO: use shared_ptr
};






/* 
 * S A M P L E 
 *  C O D E
*/

// ITERATE OVER A 2D VECTOR
void iter2DVec() {
    vector<vector<int>> v = {{1, 2}, {3, 4}};
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
    }
}

// REVERSE A LINKED LIST USING STACK
void reverseLinkedList(ListNode<int> *head) {
    stack<int> rev;
    ListNode<int> *ptr = head;
    while (ptr != nullptr) {
        rev.push(ptr);
        ptr = ptr->next;
    }

    while(!rev.empty()) {
        cout << rev.top() << endl;
        rev.pop();
    }
}


// SEARCH A VALUE IN A BINARY SEARCH TREE
BSTNode<int>* searchBST(BSTNode<int>* root, const int& key) {
    auto node = root;
    if (node == nullptr) {
        return nullptr;
    }
    if (node->val == key) {
        return node;
    }
    if (node->val < key) {
        return searchBST(node->left);
    } else {
        return searchBST(node->right);
    }
}


