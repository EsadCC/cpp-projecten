#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    std::string name;
    std::string age;

    std::cout << "What's your full name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "What's your age: ";
    std::cin >> age;

    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << '\n';

    return 0;
}