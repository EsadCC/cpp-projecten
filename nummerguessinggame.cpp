#include <iostream>
#include <ctime>

int main()
{
    int num;
    int guess;
    int tries = 0;

    srand(time(NULL));
    num = (rand() % 100) + 1;

    std::cout << "***** NUMBER GUESSING GAME *****\n";

    do{
        std::cout << "Enter a guess between (1-100): ";
        std::cin >> guess;
        tries++;

        if(guess > num)
        {
            std::cout << "Too high!\n";
        }
        else if(guess < num)
        {
            std::cout << "Too low!\n";
        }
        else
        {
            std::cout << "CORRECT!\n";
            std::cout << "It took you: " << tries << " tries to guess the number!\n";
        }
    }while(guess != num);

    return 0;
}
