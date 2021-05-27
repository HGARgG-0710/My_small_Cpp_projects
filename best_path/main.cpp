#include <iostream>
#include <algorithm>
#include <string.h>

int bestPath(const int *, const int);

int main()
{
    int steps;
    std::cout << "Please, input the number of ladder steps: ";
    std::cin >> steps;
    steps++;

    int stepValues[steps] = {0};
    std::string inputStr;
    std::string *currNum = new std::string();

    std::cin.ignore(20, '\n');
    std::cout << "Please, input the values written on those steps (format: '1 2 3 4'): ";
    std::getline(std::cin, inputStr);

    std::cout << "\nThank you! The biggest possible sum of the step values: ";

    (*currNum).resize(steps);

    for (int i = 1, j = 0, k = 0; i < steps + 1; i++, j++, k = 0)
    {
        while (j < inputStr.length() && inputStr.at(j) != ' ')
        {
            (*currNum).at(k) = inputStr.at(j);
            j++;
            k++;
        }

        stepValues[i] = std::atoi((*currNum).c_str());

        std::fill(currNum->begin(), currNum->end(), ' ');
    }

    std::cout << bestPath(stepValues, steps);
}

int bestPath(const int *stepsValues, const int stepsCount)
{
    int finalValues[stepsCount] = {0, stepsValues[1]};

    for (int i = 2; i < stepsCount; i++)
        finalValues[i] = std::max(finalValues[i - 1], finalValues[i - 2]) + stepsValues[i];

    return finalValues[stepsCount - 1];
}