#include <iostream>
#include <vector>
#include <cstdlib> // ��� ������������� ������� rand()
#include <ctime>   // ��� ������������� ���������� ��������� �����

using namespace std;

// ������� ��� ������ ��������� �������
template <typename kitty>
void swap(kitty& a, kitty& b) {
    kitty temp = a;
    a = b;
    b = temp;
}

// Quick Sort � ����������������� ������� pivot ��������
template <typename kitty>
int partition(vector<kitty>& arr, int low, int high) {
    // �������� ��������� pivot �������
    int pivotIndex = low + rand() % (high - low + 1); // ���������� ��������� ������ � ��������� �� low �� high
    kitty pivotValue = arr[pivotIndex]; // �������� �������� �������� �� ���������� �������
    // ���������� pivot � �����
    ::swap(arr[pivotIndex], arr[high]); // ���������� ������� �������� �������

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivotValue) {
            i++;
            ::swap(arr[i], arr[j]); // ���������� ������� �������� �������
        }
    }
    ::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename kitty>
void quickSort(vector<kitty>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);  // ���������� �������� quickSort ��� ����� ����� �������
        quickSort(arr, pivot + 1, high);  // ���������� �������� quickSort ��� ������ ����� �������
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

    kitty maxVal = arr[0]; // �������������� ������������ �������� ��� ������ ������� �������
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];// ��������� ������������ ��������, ���� ������� ������� ������
        }
    }

    vector<int> count(maxVal + 1, 0); // ������� ������ count �������� (maxVal + 1), ����������� �����b
    vector<kitty> output(n); // ������� ������ ��� �������� ��������������� ���������

    // ������� ���������� ���������
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // ��������� ����� ���� ����� � ������, ������� ������ ������ �����
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // ����������� �������� � ���������� �������
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // �������� ��������������� ������ ������� � arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    // ������������� ���������� ��������� �����
    srand(time(nullptr));

    int n;
    cout << "������� ���������� ��������� � �������: ";
    cin >> n;

    // �������� � ���������� �������� ���������� �������
    vector<int> arr1(n);
    vector<double> arr2(n);
    vector<char> arr3(n);

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100; // ��������� ����� �� 0 �� 99
        arr2[i] = rand() % 100 + 0.5; // ��������� ����� �� 0.5 �� 99.5
        arr3[i] = 'a' + rand() % 26; // ��������� ��������� ����� �� a �� z
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
