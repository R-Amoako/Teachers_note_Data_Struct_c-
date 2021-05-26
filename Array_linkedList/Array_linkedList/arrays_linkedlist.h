#pragma once
#include<array>
#include<vector>
class arrays {

private:
    std::array<int,10> num;


public:
    
    arrays();
    ~arrays() = default;
    void insert_element(int num, int pos);
    void insert_array(const std::array<int, 10> arr);
    void delete_element(int pos);
    void find_element(int val);
    void print();

};

class c_style_array{};

struct Node
{
    int data;
    Node* next{ NULL };
    
    Node(int data) {
        this->data = data;
    }
    Node() {}
}; 

class linked_list {
private: 
    std::vector<int> link_list_data{};
    Node* head;
    std::vector<Node*> node_refs{};

public:
    
    linked_list(const std::vector<int>& list);
    linked_list(const linked_list& L);
    ~linked_list() = default;
    Node* get_head() { return head->next; }
    void create_links(const std::vector<int>& list);
    void display_list();
    void delete_node(Node* node);
    void delete_node(int pos);
    void insert_node(int pos, int val);
    void insert_node(Node* node);
    void reverse(Node* head_node);
    
};