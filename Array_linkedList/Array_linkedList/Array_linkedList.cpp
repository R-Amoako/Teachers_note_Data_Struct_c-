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

int main()
{
    arrays my_array;
    std::array<int,10> arr{ 0, 1,2,3,4,5,6,7,8,9 };
    my_array.insert_array(arr);

    my_array.find_element(5);
    my_array.print();
    
}

