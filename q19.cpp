#include <iostream>
#include <stdexcept>

class Vector {
private:
    int* data;       // Pointer to store array elements
    size_t size;     // Size of the vector

public:
    // Default constructor
    Vector(size_t size) : size(size) {
        data = new int[size]();
    }

    // Parameterized constructor
    Vector(size_t size, int initialValue) : size(size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = initialValue;
        }
    }

    // Copy constructor
    Vector(const Vector& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    // Addition operator
    Vector operator+(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of the same size for addition.");
        }
        Vector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Subtraction operator
    Vector operator-(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of the same size for subtraction.");
        }
        Vector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Equality operator
    bool operator==(const Vector& other) const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Less than operator
    bool operator<(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of the same size for comparison.");
        }
        for (size_t i = 0; i < size; ++i) {
            if (data[i] >= other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Greater than operator
    bool operator>(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of the same size for comparison.");
        }
        for (size_t i = 0; i < size; ++i) {
            if (data[i] <= other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Function to display the vector
    void display() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create vectors
    Vector v1(5, 2);    // Vector of size 5 with all elements initialized to 2
    Vector v2(5, 3);    // Vector of size 5 with all elements initialized to 3

    // Display vectors
    std::cout << "Vector v1: ";
    v1.display();
    std::cout << "Vector v2: ";
    v2.display();

    // Addition
    Vector v3 = v1 + v2;
    std::cout << "v1 + v2: ";
    v3.display();

    // Subtraction
    Vector v4 = v2 - v1;
    std::cout << "v2 - v1: ";
    v4.display();

    // Equality
    bool isEqual = (v1 == v2);
    std::cout << "v1 == v2: " << (isEqual ? "True" : "False") << std::endl;

    // Less than
    bool isLess = (v1 < v2);
    std::cout << "v1 < v2: " << (isLess ? "True" : "False") << std::endl;

    // Greater than
    bool isGreater = (v1 > v2);
    std::cout << "v1 > v2: " << (isGreater ? "True" : "False") << std::endl;

    return 0;
}
