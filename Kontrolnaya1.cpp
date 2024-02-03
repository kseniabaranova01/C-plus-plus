#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int fillArray(int* array, int size) {

    for (int i = 0; i < size; i++) {
        array[i] = 1 + rand() % 50;//значени от 1 до 50
    }
    return *array;
}


int showArray(int* array, int size) {

    for (int i = 0; i < size; i++) {
        std::cout << array[i] << std::endl;
    }
    return *array;
}


void printElements(int* array, int size, int sum) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) //перебираем массив и ищем сумму 
            if (array[i] + array[j] == sum) //сравниваем с нужным значением
            {
                std::cout << "Elements "<< array[i] << array[j];
            }
    }
    std::cout << std::endl;
}

struct Contact {
    std::string name;  // имя контакта
    long long number;  // номер телефона контакта
};

void addNewContact(std::string name, long long number) {
    Contact newContact = { name, number };
    std::cout << "New contact " << name << ", " << number << std::endl;
}



int main() {

    /*Task1 */

    srand(static_cast<unsigned int>(time(0)));//штука каждый раз генерирующая новые числа

    std::cout << "Enter a size";
    int size = 0;
    std::cin >> size;
    int* Array = new int[size];//создаем указатель
    int sum = 0;;
    std::cout << "Enter a sum to find matching elements: ";
    std::cin >> sum;

    fillArray(Array, size);
    showArray(Array, size);
    printElements(Array, size, sum);
   

    delete[] Array;


    /*Task 2*/
   

    Contact user1 = { "Alina", 1234567890 };
    Contact user2 = { "Semen", 9876543210 };
    Contact user3 = { "Evachka", 1112233444 };


    addNewContact("Charlie", 555112233);
    std::cout << "All contacts in the phone book: " << std::endl;
   
    return 0;
}

