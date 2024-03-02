#include <iostream>
#include <vector>
#include <cstdlib> // Äëÿ èñïîëüçîâàíèÿ ôóíêöèè rand()
#include <ctime>   // Äëÿ èíèöèàëèçàöèè ãåíåðàòîðà ñëó÷àéíûõ ÷èñåë

using namespace std;

// Ôóíêöèÿ äëÿ îáìåíà ýëåìåíòîâ ìàññèâà
template <typename kitty>
void swap(kitty& a, kitty& b) {
    kitty temp = a;
    a = b;
    b = temp;
}

// Quick Sort ñ ðàíäîìèçèðîâàííûì âûáîðîì pivot ýëåìåíòà
template <typename kitty>
int partition(vector<kitty>& arr, int low, int high) {
    // Âûáèðàåì ñëó÷àéíûé pivot ýëåìåíò
    int pivotIndex = low + rand() % (high - low + 1); // Ãåíåðèðóåì ñëó÷àéíûé èíäåêñ â äèàïàçîíå îò low äî high
    kitty pivotValue = arr[pivotIndex]; // Ïîëó÷àåì çíà÷åíèå ýëåìåíòà ïî ñëó÷àéíîìó èíäåêñó
    // Ïåðåìåùàåì pivot â êîíåö
    ::swap(arr[pivotIndex], arr[high]); // Îáìåíèâàåì ìåñòàìè ýëåìåíòû ìàññèâà

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivotValue) {
            i++;
            ::swap(arr[i], arr[j]); // Îáìåíèâàåì ìåñòàìè ýëåìåíòû ìàññèâà
        }
    }
    ::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename kitty>
void quickSort(vector<kitty>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);  // Ðåêóðñèâíî âûçûâàåì quickSort äëÿ ëåâîé ÷àñòè ìàññèâà
        quickSort(arr, pivot + 1, high);  // Ðåêóðñèâíî âûçûâàåì quickSort äëÿ ïðàâîé ÷àñòè ìàññèâà
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

    kitty maxVal = arr[0]; // Èíèöèàëèçèðóåì ìàêñèìàëüíîå çíà÷åíèå êàê ïåðâûé ýëåìåíò ìàññèâà
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];// Îáíîâëÿåì ìàêñèìàëüíîå çíà÷åíèå, åñëè òåêóùèé ýëåìåíò áîëüøå
        }
    }

    vector<int> count(maxVal + 1, 0); // ñîçäàåì âåêòîð count ðàçìåðîì (maxVal + 1), çàïîëíåííûé íóëÿìb
    vector<kitty> output(n); // Ñîçäàåì âåêòîð äëÿ õðàíåíèÿ îòñîðòèðîâàííûõ ýëåìåíòîâ

    // Ñ÷èòàåì êîëè÷åñòâî ýëåìåíòîâ
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Âû÷èñëÿåì ñóììó âñåõ ÷èñåë â ñïèñêå, êîòîðûå ìåíüøå íàøåãî ÷èñëà
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Ðàññòàâëÿåì ýëåìåíòû â ïðàâèëüíîì ïîðÿäêå
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Êîïèðóåì îòñîðòèðîâàííûé ìàññèâ îáðàòíî â arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    // Èíèöèàëèçàöèÿ ãåíåðàòîðà ñëó÷àéíûõ ÷èñåë
    srand(time(nullptr));

    int n;
    cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ â ìàññèâå: ";
    cin >> n;

    // Ñîçäàíèå è çàïîëíåíèå ìàññèâîâ ñëó÷àéíûìè ÷èñëàìè
    vector<int> arr1(n);
    arr1.reserve(100);
    vector<double> arr2(n);
    arr2.reserve(100);
    vector<char> arr3(n);
    arr3.reserve(100);

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100; // ñëó÷àéíîå ÷èñëî îò 0 äî 99
        arr2[i] = rand() % 100 + 0.5; // ñëó÷àéíîå ÷èñëî îò 0.5 äî 99.5
        arr3[i] = 'a' + rand() % 26; // ñëó÷àéíàÿ ìàëåíüêàÿ áóêâà îò a äî z
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
