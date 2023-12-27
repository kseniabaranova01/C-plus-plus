#include <iostream>
#include <string>
#include <ctime>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <unordered_set>

using namespace std;

const int WIDTH = 6;
const int HEIGHT = 6;

void fillField(int** field) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            field[i][j] = rand() % 2;
        }
    }
}

void printField(int** field) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (field[i][j] == 1) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

void copyField(int* field[], int destination[][HEIGHT])
 {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            destination[i][j] = field[i][j];
        }
    }
}

int getneighborn(int i) {
    return (WIDTH + i) % WIDTH;
}

int getneighborn2(int j) {
    return (HEIGHT + j) % HEIGHT;
}

void rebornField(int* field[]) {
    int died[WIDTH][HEIGHT];
    copyField(field, died);

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int neighbors = 0;
            neighbors += died[getneighborn(i - 1)][getneighborn2(j - 1)];
            neighbors += died[getneighborn(i - 1)][getneighborn2(j)];
            neighbors += died[getneighborn(i - 1)][getneighborn2(j + 1)];
            neighbors += died[getneighborn(i)][getneighborn2(j - 1)];
            neighbors += died[getneighborn(i)][getneighborn2(j + 1)];
            neighbors += died[getneighborn(i + 1)][getneighborn2(j - 1)];
            neighbors += died[getneighborn(i + 1)][getneighborn2(j)];
            neighbors += died[getneighborn(i + 1)][getneighborn2(j + 1)];

            if (died[i][j] == 0 && neighbors == 3) {
                field[i][j] = 1;
            }
            else if (neighbors == 2 || neighbors == 3) {
                field[i][j] = 1;
            }
            else if (neighbors < 2 || neighbors > 3) {
                field[i][j] = 0;
            }
            else {
                field[i][j] = 1;
            }
        }
    }
}

bool checklives(int** field) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (field[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool checkrepeats(int** field, std::unordered_set<std::string>& configurations) {
    std::string configuration;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            configuration += std::to_string(field[i][j]);
        }
    }

    if (configurations.count(configuration) > 0) {
        return true; 
    }

    configurations.insert(configuration);
    return false; 
}

bool checkstablerepeats(int** field, int** previousField) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (field[i][j] != previousField[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int** field = new int* [WIDTH];
    int** died = new int* [WIDTH];
    for (int i = 0; i < WIDTH; i++) {
        field[i] = new int[HEIGHT];
        died[i] = new int[HEIGHT];
    }

    fillField(field);
    std::unordered_set<std::string> configurations;

    do {
        printField(field);
        rebornField(field);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("cls");

    } while (!checklives(field) && !checkrepeats(field, configurations) && !checkstablerepeats(field, died));

    for (int i = 0; i < WIDTH; i++) {
        delete[] field[i];
        delete[] died[i];
    }
    delete[] field;
    delete[] died;

    return 0;
}