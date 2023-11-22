// Fig. 20.5: fig20_05.cpp
// Sorting an array into ascending order with selection sort
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

// sort and array into ascending order
template <typename T, size_t size>
void selectionSort(array <T, size>& items) {
    // loop over size - 1 elements
    for (size_t i{0}; i < items.size() - 1; ++i) {
        size_t indexOfSmallest{i}; // will hold index of smallest element
        // loop to find index of smallest element
        for (size_t index{i + 1}; index < items.size(); ++index) {
            if (items[index] < items[indexOfSmallest]) {
                indexOfSmallest = index;
            }
        }

        // swap the elements at positions i and indexOfSmallest
        T hold{items[i]};
        items[i] = items[indexOfSmallest];
        items[indexOfSmallest] = hold;
    }
}

int main() {
    const size_t arraySize{10};
    array<int, arraySize> data {34, 56, 4, 10, 77, 51, 93, 30, 5, 32};
    cout << "Unsorted array:\n";

    // output original array
    for (size_t i{0}; i < arraySize; ++i) {
        cout << setw(4) << data[i];
    }
    selectionSort(data);
    cout << "\nSorted array:\n";
    for (size_t i{0}; i < arraySize; ++i) {
        cout << setw(4) << data[i];
    }
    cout << endl;
}