#include <iostream>
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int average(int a, int b)
{
    return (a + b)/2;
}




int main()
{
    std::cout << "Enter the first number";
    int a = 0;
    std::cin >> a;
    std::cout << "Enter the second number, wchich is less than the first one";
    int b = 0;
    std::cin >> b; 
    std::cout << "Summa"<< " " << add(a, b) << std::endl;
    std::cout << "Proizvedenie" << " " << multiply(a, b) << std::endl;
    std::cout << "Delenie" << " " << divide(a, b) << std::endl;
    std::cout << "Srednee arifmetichescoe" << " " << average(a, b) << std::endl;
    return 0;

}



