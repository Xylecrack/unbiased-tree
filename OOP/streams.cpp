#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void readArrayFromFile(const string& filename, vector<T>& arr) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line);
    stringstream ss(line);
    T num;
    while (ss >> num) {
        arr.push_back(num);
    }
}

template <typename T>
void writeArrayToFile(const string& filename, const vector<T>& arr) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (const T& num : arr) {
        file << num << " ";
    }
    file << endl;
}

int main() {
    vector<int> arr;
    readArrayFromFile("array.txt", arr);

    insertionSort(arr);

    writeArrayToFile("sorted_array.txt", arr);

    return 0;
}