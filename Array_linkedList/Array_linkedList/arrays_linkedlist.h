#pragma once
#include<array>
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

class linked_list {


};