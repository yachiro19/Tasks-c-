#include <iostream>
#include <string>

std::string generatePassword(int size) {
    const std::string tips = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    std::string password;
    for (int i = 0; i < size; ++i) {
        int index = std::rand() % tips.size();
        password += tips[index];
    }

    return password;
}
int main()
{
    char choice;
    do {
        std::cout << "Put the password length" << std::endl;
        int n;
        std::cin >> n;
        generatePassword(n);
        std::string password = generatePassword(n);
        std::cout << "Password:" << " " << password << std::endl;
        std::cout << "Continue? If yes - press e, if no - any button" << std::endl;
        std::cin >> choice;
    } while (choice == 'e');
    return 0;
}







