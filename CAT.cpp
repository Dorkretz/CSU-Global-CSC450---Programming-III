#include <iostream>  
#include <string> 
#include <cstdlib> 

int main() {
    std::string s1, s2;

    for (int i = 1; i <= 3; i++) {
        std::cout << "Round " << i << ":" << std::endl;
        std::cout << "First string: ";
        std::getline(std::cin, s1);
        std::cout << "Second string: ";
        std::getline(std::cin, s2);
        std::cout << "Result: " << s1 + s2 << std::endl << std::endl;
    }

    system("pause");
    return 0;
}