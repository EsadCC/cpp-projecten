#include <iostream>

int main()
{
    int ageMonths;
    int years;
    int monthsLeft;

    std::cout << "Voer je leeftijd in maanden in: ";
    std::cin >> ageMonths;
    
    years = ageMonths / 12;
    monthsLeft = ageMonths % 12;

    std::cout << "Je bent " << years << " Jaar en " << monthsLeft << " maanden oud\n";

    return 0;
}
