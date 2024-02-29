#include <iostream>
#include <vector>
#include <cstdlib> // Для использования функции rand()
#include <ctime>   // Для инициализации генератора случайных чисел

using namespace std;

// Функция для обмена элементов массива
template <typename kitty>
void swap(kitty& a, kitty& b) {
    kitty temp = a;
    a = b;
    b = temp;
}

// Quick Sort с рандомизированным выбором pivot элемента
template <typename kitty>
int partition(vector<kitty>& arr, int low, int high) {
    // Выбираем случайный pivot элемент
    int pivotIndex = low + rand() % (high - low + 1); // Генерируем случайный индекс в диапазоне от low до high
    kitty pivotValue = arr[pivotIndex]; // Получаем значение элемента по случайному индексу
    // Перемещаем pivot в конец
    ::swap(arr[pivotIndex], arr[high]); // Обмениваем местами элементы массива

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivotValue) {
            i++;
            ::swap(arr[i], arr[j]); // Обмениваем местами элементы массива
        }
    }
    ::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename kitty>
void quickSort(vector<kitty>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);  // Рекурсивно вызываем quickSort для левой части массива
        quickSort(arr, pivot + 1, high);  // Рекурсивно вызываем quickSort для правой части массива
    }
}

// Bubble Sort
template <typename kitty>
void bubbleSort(vector<kitty>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                ::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Counting Sort
template <typename kitty>
void countingSort(vector<kitty>& arr) {
    int n = arr.size();
    if (n == 0) return;

    kitty maxVal = arr[0]; // Инициализируем максимальное значение как первый элемент массива
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];// Обновляем максимальное значение, если текущий элемент больше
        }
    }

    vector<int> count(maxVal + 1, 0); // создаем вектор count размером (maxVal + 1), заполненный нулямb
    vector<kitty> output(n); // Создаем вектор для хранения отсортированных элементов

    // Считаем количество элементов
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Вычисляем сумму всех чисел в списке, которые меньше нашего числа
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Расставляем элементы в правильном порядке
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Копируем отсортированный массив обратно в arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    int n;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    // Создание и заполнение массивов случайными числами
    vector<int> arr1(n);
    vector<double> arr2(n);
    vector<char> arr3(n);

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100; // случайное число от 0 до 99
        arr2[i] = rand() % 100 + 0.5; // случайное число от 0.5 до 99.5
        arr3[i] = 'a' + rand() % 26; // случайная маленькая буква от a до z
    }

    // Quick Sort
    quickSort(arr1, 0, arr1.size() - 1);
    cout << "Quick Sort: ";
    for (auto elem : arr1) {
        cout << elem << " ";
    }
    cout << endl;

    // Bubble Sort
    bubbleSort(arr2);
    cout << "Bubble Sort: ";
    for (auto elem : arr2) {
        cout << elem << " ";
    }
    cout << endl;

    // Counting Sort
    countingSort(arr3);
    cout << "Counting Sort: ";
    for (auto elem : arr3) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
