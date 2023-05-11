
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

bool isNumeric(const std::string& userInput) {
    for (char c : userInput) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

std::vector<int> convertIntToVector(std::string userInput)
{
    std::vector<int> outputVector {};
    for (int i{0}; i < userInput.size(); i++)
    {
        outputVector.push_back(userInput[i]);
    }

    return outputVector;
}

void printVector(std::vector<int> vectorToPrint)
{
    for (int i {vectorToPrint.size() - 1}; i >= 0; i--)
    {
        std::cout << vectorToPrint[i] << " / ";
    }
    std::cout << std::endl;
}

int sumOfVector(std::vector<int> vectorToSum)
{
    int sum {0};
    for (int i {0}; i <= vectorToSum.size() - 1; i++)
    {
        sum += vectorToSum[i];
    }
    return sum;
}

int splitTwoDigitsReturnSum(int inputTwoDigits)
{
    int firstDigit {inputTwoDigits % 10};
    int secondDigit {(inputTwoDigits - firstDigit) / 10};
    std::cout << "First and second digit: " << firstDigit << " || " << secondDigit << std::endl; 

    return firstDigit + secondDigit;
}

std::vector<int> doubleAndSumDigits(std::vector<int> userInputVector)
{
    std::cout << "Running doubleAndSumDigits" << std::endl;
    // std::cout << "Size of inputVector " << userInputVector.size();
    for (int i {userInputVector.size() - 1}; i >= 0; i -= 2)
    {
        if (userInputVector[i] * 2 > 9)
        {
            userInputVector[i] = splitTwoDigitsReturnSum(userInputVector[i]*2);
        }
        else
        {
        userInputVector[i] = userInputVector[i] * 2;
        }
    }
    std::cout << "Double vector elements: ";
    printVector(userInputVector);
    return userInputVector;
}

bool creditCardIsValid(std::vector<int> userInputVector)
{
    if(userInputVector.size() <= 1)
    {
        return false;
    }
    for(int i {}; i < userInputVector.size(); i++)
    {
        userInputVector[i] = userInputVector[i] - 48;
    }
    int checkDigit {};
    checkDigit = userInputVector.back();
    printVector(userInputVector);
    userInputVector.pop_back();
    std::cout << "Check Digit: " << checkDigit << std::endl;
    printVector(userInputVector);
    std::cout << "A vector after init pop: ";
    printVector(userInputVector);
    std::cout << "Sum of vector: " << sumOfVector(userInputVector) << std::endl;
    userInputVector = doubleAndSumDigits(userInputVector);
    bool isTrue{0};
    std::cout << "Sum of vector after doubling everyother number: " << sumOfVector(userInputVector) << std::endl;
    std::cout << "10 - sum of vector % 10: " << 10 - (sumOfVector(userInputVector) % 10) << std::endl; 
    isTrue = 10 - (sumOfVector(userInputVector) % 10) == checkDigit;
    std::cout << std::boolalpha;
    std::cout << "Sum matches check value: " << isTrue << std::endl;
    return true;
}



int main ()
{
    std::string userInput {};
    std::cout << "Please enter the credit card number to validate: ";
    std::cin >> userInput;
    std::cout << "is Numeric? " << isNumeric(userInput) << std::endl;
    if (isNumeric(userInput))
    {
    std::vector<int> userInputVector{};  
    userInputVector = convertIntToVector(userInput);
    creditCardIsValid(userInputVector);
    }
    return 0;
}
