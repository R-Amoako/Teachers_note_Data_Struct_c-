// Array_linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>


#include "arrays_linkedlist.h"

/* Array class implementation*/
arrays::arrays() {}

void arrays::insert_element(int val, int pos){
    if(pos < num.size() && pos>=0) num.at(pos) = val;
    else {
        pos = abs(pos) % num.size();
        num.at(pos) = val;
    }
}
void arrays::insert_array(const std::array<int, 10> arr) {
    num = arr;
}
void arrays::delete_element(int pos){
    num.at(pos) = NULL;
}
void arrays::find_element(int val){
    auto found = std::find(num.begin(), num.end(), val);
    if (found != num.end())
        std::cout << "Array counts " << val << " at postion " << *found << std::endl;
}

void arrays::print(){
    for (auto& val : num) { 
        std::cout<< val << " " ; }
}

/*Linked_list class implementation*/
linked_list::linked_list(const std::vector<int>& list) :link_list_data{ list } {
    head = new Node;
    create_links(link_list_data);
}

void linked_list::create_links(const std::vector<int>& list){
    auto temp = head;
    for (auto& val : list) {
        Node* node = new Node;
        node->data = val;
        temp->next = node;
        node_refs.push_back(node);
        temp = node;
        
    }

}

linked_list::linked_list(const linked_list& L) :link_list_data{ L.link_list_data } {
     head = new Node;
    *head = *L.head;
}

void linked_list::display_list(){
    auto temp = head;
    while (temp->next != NULL) {
        std::cout << temp->next->data << " ";
        temp = temp->next;
    }
    printf("\n");
}

void linked_list::delete_node(Node* node){
    //
    //Since there is no check if the node exist in the list, it only works if the address of the Node*
    // is known.
   // node->data = node->next->data;
    
    node = node_refs.at(3);
    /*
    if (node->next == NULL) {
        return;
    }
    auto temp = node->next;
    *node = *(node->next);
    delete temp;
    */
    if (node->next == NULL) {
        node = NULL;
        return;
    }
    node->data = node->next->data;
    delete_node(node->next);  
}
void linked_list::delete_node(int pos){
    auto temp = head;
    for (int i = 1; i <= pos ; i++) {
        temp = temp->next;
    }
    auto temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}
void linked_list::insert_node(int pos, int val){
    auto temp = head;
    for (int i = 0; i <=pos-1; i++) {
        temp = temp->next;
    }

    Node* new_node = new Node;
    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
}
void linked_list::insert_node(Node* node){
    node->data = 1; // for test purpose.
   //insert at head: O(1)
    node->next = head->next;
    head->next = node;

    /*
    insert at tail: O(n)
    
    auto temp = head;
    if(temp->next == NULL) head->next = node;
    
    else{

        while (temp->next != NULL) {
            temp = temp->next;
        }
        node->next = NULL;
        temp->next = node;

   }
*/
}

void linked_list::reverse(Node* start_node) {
    if (start_node->next == NULL) {
        std::cout << start_node->data << " ";
        //head = start_node;
        return;
    }
   
    reverse(start_node->next);
    auto temp2 = start_node->next;
    temp2->next = start_node;
    start_node->next = NULL;
    std::cout << " "<<start_node->data << " ";
}

int main()
{
   /* arrays my_array;
    std::array<int,10> arr{ 0, 1,2,3,4,5,6,7,8,9 };
    my_array.insert_array(arr);

    my_array.find_element(5);
    my_array.print();
    */

    std::vector<int>links{ 5,10,15,25 };

    linked_list nodes(links);
    nodes.display_list();
    //nodes.delete_node(3);
    nodes.display_list();
    nodes.insert_node(2, 20);
    nodes.display_list();

    Node* n = new Node;

    nodes.insert_node(n);
    nodes.display_list();
    auto head = nodes.get_head();
    printf("\n");
    std::cout << nodes.get_head()->data;
    nodes.reverse(head);
    //nodes.display_list();
}

