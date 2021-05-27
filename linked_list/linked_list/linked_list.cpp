// linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct Node {
	int data;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node(int x) {
		data = x;
	}
	//Node(){}
};


Node* head = new Node(0);

void insert_at_head(Node* node) {
	node->next = head->next;
	//node->prev = head;
	head->next = node;
}

void insert_node(Node* node) {

	auto temp = head;
	if (head->next == nullptr) {
		insert_at_head(node);
		return;
	}
	
	while (temp->next != nullptr) {
		
		node->next = temp->next;
		node->prev = temp;
		temp->next = node;
		temp = temp->next;
	}
	

}



void insert(Node* node, int pos) {
	auto temp = head;
	if (head->next == nullptr) {
		head->next = node;
		return;
	}
	for (int i{ 1 }; i < pos; i++) {
		if (temp->next == nullptr) break;
		temp = temp->next;
		
	}
	node->prev = temp->prev;
	temp->prev = node;
	node->next = temp;
	temp->next = temp->next;
}
void display() {

	auto temp = head;
	while (temp->next != nullptr) {
		std::cout << temp->next->data << " ";
		temp = temp->next;
	}
}
/*
void reverse_display() {
	auto temp = head;
	if (temp->next == nullptr) return;
	while(temp->next != nullptr){
		temp = temp->next;
	}
	
	while (temp->prev == nullptr) {
		std::cout << temp->data << " ";
		temp = temp->prev;

	}
}

void reverse_links() {
	auto temp = head;

	while (temp->next != nullptr) {
		temp = temp->next;
		if (temp->prev == nullptr) {
			auto temp2 = temp->next;
			temp->next = nullptr;
			temp->prev = temp2;
		}
	    
		auto temp3 = temp->prev;
		temp->prev = temp->next;
		temp->next = temp3;

	}

		//auto temp3 = temp->next;
		//temp->next = temp->prev;
		//head->next = temp;
		//temp->prev = nullptr;
}
*/
//TODO delete a node

void delete_node(Node* node) {

	auto temp = node->next;
	auto temp2 = node->prev;
	temp2->next = temp;
	temp->next = node->next->next;
	delete node;
}


int main()
{
	
	Node n1(0);
	insert_at_head(&n1);
	Node n2(25);
	insert_node(&n2);
	Node n3(50);
	insert_node(&n3);
	display();
}

