// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iostream>
#include<vector>
#include <stack>
/* Dynamic array implementation of stack
* Push and pop is constant time in average case but O(n) in worse in case of arraysize extension;
*/

std::vector<int> stack;

void push(int x) {
    
    stack.push_back(0);
}

int top() {
    return stack.at(stack.size()-1);
}

void pop() {
    stack.pop_back();
}

/* Linked list inplementation*/

struct Node {
    int data;
    Node* next = NULL;
};

Node* head = new Node;
void s_push(Node* node) {
    if (head->next == NULL) {
        head->next = node;
        return;
    }
    else {
        node->next = head->next;
        head->next = node; 
    }
}

void s_pop() {
    auto temp = head;
    temp = temp->next;
    head->next = temp->next;
    delete temp;
}

void s_top() {

    std::cout << head->next->data << " ";
}

bool is_balance_patenthesis(std::string s) {

    std::stack<char>stack_;
    for (int i{ 0 }; i < s.size(); i++) {

        if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[') stack_.push(s.at(i));
        else if ((s.at(i) == ')' || s.at(i) == '}' || s.at(i) == ']') ) {
            if (stack_.empty() || s.at(i) != stack_.top()) return false;
            else {
                stack_.pop();
            }
            
        }
    }
    return stack_.empty() ? true : false;
}


bool isOperator(char s) {
    if (s == '+' || s== '*' || s== '-' || s== '/') return true;

    return false;
}

bool has_higher_precedence(char c1, char c2){

    char ops[] = { c1, c2 };
    std::vector<int> val;

    for (char c : ops) {
        switch (c)
        {
        case '*':
            val.push_back(3);
            break;
        case '/':
            val.push_back(2);
            break;

        case '+':
            val.push_back(1);
            break;
        case '-':
            val.push_back(2);
            break;
        default:
            break;
        }
    }

    return val.at(0) < val.at(1) ? true : false;
};

//prefix:operator-operand-operand
bool is_prefix(std::string expr) { return true; }

std::string to_prefix(const std::string& infix){
    return " ";
}

int evalaute_prefix(std::string expr) { return 1; }

//postfix
bool is_post_fix(std::string expr) { return true; }

int evaluate_postfix(std::string expr) { return 1; }

std::string to_postfix(std::string infix) {
    
    std::stack<char> optr_stack;
    std::string result_string{};
    
    for (auto& s : infix) {
        if (s == '(') {
            optr_stack.push(s);
        }
        else if (s == ')') {

            while (!optr_stack.empty() && !optr_stack.top() == '(') {
                result_string += optr_stack.top();
                optr_stack.pop();
            }

            optr_stack.pop();
        }

        else if (s == isOperator(s)) {
            if(optr_stack.empty() || !isOperator(optr_stack.top())) optr_stack.push(s);

            else{
                while (!optr_stack.empty() && !has_higher_precedence(s, optr_stack.top()))
                {
                    result_string += optr_stack.top();
                    optr_stack.pop();
                }
                optr_stack.push(s);
            
            }
            
        }
    
        else if (s != ' ') {
            result_string += s;
        }
    }
    while (!optr_stack.empty()) {
        result_string += optr_stack.top();
        optr_stack.pop();
    }
    return result_string;
}

int main()
{
   
    std::cout << " 2*3  becomes " << to_postfix("2*3");


    /*  Node* n1 = new Node;
    n1->data = 3;
    s_push(n1);
    Node* n2 = new Node;
    n2->data = 6;
    s_push(n2);
    Node* n3 = new Node;
    n3->data = 9;
    s_push(n3);
    Node* n4 = new Node;
    n4->data = 12;
    s_push(n4);

   // s_pop();
    s_pop();
    Node* n5 = new Node;
    n5->data = 1000;
    s_push(n5);
    s_top();
    //std::cout << ;


    std::stack<char>container;
        std::string newstring{ "LEADER" };
        for (auto& s : newstring) {
            container.push(s);
        }
        while (!container.empty()) {
            std::cout << container.top() << " ";
            container.pop();
        }

   std::string exp{ "(3*(2^2) +2[(3+5)])" };
        std::cout << "The expression (3*(2^2) +2[(3+5)]) is :" << std::boolalpha 
                  << is_balance_patenthesis(exp);

       //int i = ( 3 * (2 ^ 2) + 2[(3 + 5)])
*/
        
}
