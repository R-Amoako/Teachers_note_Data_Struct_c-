#pragma once
struct Node {
	int data;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node(int x) {
		data = x;
	}
	Node(){}
};


class linked_list {


private:
	Node* head; 

public:
	linked_list() { head = new Node(); }

	~linked_list() = default;
};