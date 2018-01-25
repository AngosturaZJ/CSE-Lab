#include <iostream>
#include <cstdlib>
using namespace std;

void insertionSort(int* array, int size) {

  int i, j, key;
  for (i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j+1] = array[j];
      j--;
    }

    array[j+1] = key;

    for (int k = 0; k < i+1; k++) {
      cout << array[k] << ";";
    }
    cout << "\n";
  }

}

int main() {

  int size;
  cin >> size;

  int* array = (int*) malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    cin >> array[i];
  }

  insertionSort(array, size);

  return 0;
}
