#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    int n;

    std::cout << "Digite o número de elementos que deseja ordenar: ";
    std::cin >> n;

    std::vector<int> data(n);
    std::cout << "Insira os elementos do vetor:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Elemento " << (i + 1) << ": ";
        std::cin >> data[i];
    }

    std::cout << "Array original: ";
    printArray(data);

    // Escolha o algoritmo
    int choice;
    std::cout << "Escolha o algoritmo de ordenação:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(data);
            std::cout << "Array ordenado (Bubble Sort): ";
            break;
        case 2:
            insertionSort(data);
            std::cout << "Array ordenado (Insertion Sort): ";
            break;
        case 3:
            selectionSort(data);
            std::cout << "Array ordenado (Selection Sort): ";
            break;
        default:
            std::cout << "Escolha inválida!" << std::endl;
            return 1;
    }

    printArray(data);

    return 0;
}
