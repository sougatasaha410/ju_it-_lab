#include <iostream>
#include <algorithm> // For std::reverse and std::sort

class IntArray {
private:
    int* data; // Pointer to dynamically allocated array
    int size;  // Size of the array

public:
    // Constructor
    IntArray(int s) : size(s), data(new int[s]) {}

    // Constructor with initializer list
    IntArray(int s, const int arr[]) : size(s), data(new int[s]) {
        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    // Copy constructor
    IntArray(const IntArray& other) : size(other.size), data(new int[other.size]) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~IntArray() {
        delete[] data;
    }

    // Get the size of the array
    int getSize() const {
        return size;
    }

    // Overload the [] operator for element access (non-const version)
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Overload the [] operator for element access (const version)
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Overload the assignment operator
    IntArray& operator=(const IntArray& other) {
        if (this == &other) return *this; // Self-assignment check

        delete[] data;  // Clean up existing data
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Overload the + operator for adding two IntArrays
    IntArray operator+(const IntArray& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Arrays must be of the same size for addition");
        }
        IntArray result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Reverse the array
    void reverse() {
        std::reverse(data, data + size);
    }

    // Sort the array
    void sort() {
        std::sort(data, data + size);
    }

    // Print the array elements
    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    // Create an IntArray object with elements 1, 2, and 3
    int arr[] = {1, 2, 3};
    IntArray array1(3, arr);

    // Print elements of array1
    std::cout << "Array1 elements: ";
    array1.print();

    // Create another IntArray object which is an exact copy of array1
    IntArray array2 = array1;

    // Print elements of array2
    std::cout << "Array2 elements (copy of Array1): ";
    array2.print();

    // Reverse the elements of array2
    array2.reverse();

    // Print elements of both arrays
    std::cout << "Array1 elements after reversing Array2: ";
    array1.print();
    
    std::cout << "Array2 elements after reversing: ";
    array2.print();

    return 0;
}
