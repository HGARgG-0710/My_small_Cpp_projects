#include <iostream>

int fibonacci(int);
void inputInt(int *, const char *);

int main()
{
    int num;

    inputInt(&num, "Please, input the index of needed positive fibonacci number: ");

    while (num < 0)
    {
        std::cout << "I said *positive*! ;)" << std::endl;
        inputInt(&num, "Number: ");
        std::cout << "Thank you! :)" << std::endl;
    }

    std::cout << fibonacci(num);
}

int fibonacci(const unsigned int index)
{
    int remembered[index + 1] = {0, 1};

    for (int i = 2; i < index + 1; i++)
        remembered[i] = remembered[i - 1] + remembered[i - 2];

    return remembered[index];
}

void inputInt(int *num, const char *message)
{
    std::cout << message;
    std::cin >> *num;
}