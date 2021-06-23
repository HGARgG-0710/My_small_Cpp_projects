#include <iostream>
#include <vector>

const int input();

int main()
{
    const int sequenceLength = input(), nonRepeat = input();
    std::vector<std::vector<int>> countArray = {{}, {1, nonRepeat - 1}};

    for (int i = 2; i < sequenceLength; i++)
    {
        countArray.resize(i + 1);
        countArray[i].resize(2);
        countArray[i][0] = countArray[i - 1][1];
        countArray[i][1] = countArray[1][1] * (countArray[i - 1][0] + countArray[i - 1][1]);
    }

    int count = 0;

    for (int j = 1; j < countArray.size(); j++)
        count += countArray[j][0] + countArray[j][1];

    std::cout << count;
}

const int input()
{
    int target;
    std::cin >> target;
    return target;
}