// binary_search_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    
};


Node* create_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        root = create_node(val);
        return root;
    }

    else if(val <= root->data){
        root->left = insert(root->left, val);
    }

    else if (val > root->data) {
        root->right = insert(root->right,val);
    }
    return root;
}

bool search(Node* node, int data) {
    if (node == nullptr) return false;
    if (data == node->data) return true;
    else if (data <= node->data)return search(node->left, data);
    else  return search(node->right, data);
    
}

void inorder(Node* root) {
    auto temp = root;

    if (temp == nullptr)  return;  
    if(temp->left != nullptr)inorder(temp->left);
    std::cout << temp->data << " ";
    if (temp->right != nullptr) inorder(temp->right);
}

void preorder(Node* root) {
    auto temp = root;

    if (temp == nullptr)  return;
    std::cout << temp->data << " ";
    if (temp->left != nullptr)preorder(temp->left);
    if (temp->right != nullptr) preorder(temp->right);
}

void postorder(Node* root) {
    auto temp = root;

    if (temp == nullptr)  return;
    if (temp->left != nullptr)preorder(temp->left);
    if (temp->right != nullptr) preorder(temp->right);
    std::cout << temp->data << " ";
}
//Node* head = new Node();
void breadth_first(Node* root){
    if (root == nullptr) return;
    std::queue<Node*>bfs;
    bfs.push(root);
    while (!bfs.empty()) {

        Node* current = bfs.front();
        std::cout << current->data << " ";
       if (current->left != nullptr)bfs.push(current->left);
        if (current->right != nullptr)bfs.push(current->right);
        bfs.pop();
    }

}

Node* find_min(Node* node) {

    if (node == nullptr) {
        std::cout << "Empty tree: no min found" << std::endl;
        return NULL;
    }

    while (node->left != nullptr) {
        node = node->left;
    }
    std::cout << "Min val is : " << node->data << " ";
    return node;
}

void find_max(Node* node) {

    if (node == nullptr) {
        std::cout << "Empty tree: no min found" << std::endl;
        return;
    }

    else if (node->right == nullptr) {
        std::cout << "Min val is : " << node->data << " ";
    }
    else {
        find_max(node->right);
    }

    //return node->data;
}

int height(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return std::max(height(node->left),height(node->right)) + 1;
 }

bool is_in_range(Node* node, int min, int max) {

    if (node == nullptr) return true;

    if (node->data > min && node->data < max && is_in_range(node->left, min, node->data)
        && is_in_range(node->right, node->data, max)) return true;

    else return false;
}

bool is_binary_search_tree(Node* node){
   
    int min = -1;// find_min(node);
    int max = 16; // find_max(node);

    return is_in_range(node, min, max);
}

Node* delete_node(Node* node, int val) {
    if (node == nullptr) return node;
    if (node->data > val)return delete_node(node->left, val);
    else if (node->data < val) return delete_node(node->right, val);
    else {
        //case: no child node
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return node = nullptr;
        }
        //case: only 1 child
        else if (node->left == nullptr) {
            auto temp = node;
            node = temp->right;
            delete temp;
        }

        else if (node->right == nullptr) {
            auto temp = node;
            node = temp->left;
            delete temp;
        }
        //case: two child nodes
        else {
            auto temp = find_min(node->right);
            node->data = temp->data;
            node->right = delete_node(node->right, temp->data);
        }
    }
    
    return node;
}


int main()
{
    Node* root = nullptr;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 9);
    root = insert(root, 1); 
    root = insert(root, 0);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 4);
    postorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    breadth_first(root);
    find_min(root);
    std::cout << "Max height is "<< height(root)<<std::endl;
    std::cout << "Is a binary search tree? " << std::boolalpha << is_binary_search_tree(root);
    inorder(root);
    delete_node(root, 9);
    inorder(root);
    //std::cout<<std::boolalpha<<search(root, 1);
    //delete root;
}
