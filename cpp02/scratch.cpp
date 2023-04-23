#include <iostream>

int main(void)
{
    int a = 10;
    int b = 2;

    std::cout << "before " << a << std::endl;
    a = a << 1;
    std::cout << "after " << a << std::endl;
}