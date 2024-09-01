#include <iostream>

class Complex {
private:
    float real;
    float imaginary;

public:
    // Set the real part
    void setReal(float r) {
        real = r;
    }

    // Set the imaginary part
    void setImg(float i) {
        imaginary = i;
    }

    // Get the real part
    float getReal() const {
        return real;
    }

    // Get the imaginary part
    float getImg() const {
        return imaginary;
    }

    // Display the complex number
    void disp() const {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }

    // Sum of two complex numbers, returns a new Complex object
    Complex sum(const Complex& c) const {
        Complex result;
        result.real = this->real + c.real;
        result.imaginary = this->imaginary + c.imaginary;
        return result;
    }
};

int main() {
    // Create three Complex objects
    Complex c1, c2, c3;

    // Set values for c1 and c2
    c1.setReal(3.5);
    c1.setImg(2.7);

    c2.setReal(1.6);
    c2.setImg(4.8);

    // Sum c1 and c2, store the result in c3
    c3 = c1.sum(c2);

    // Display all complex numbers
    std::cout << "Complex Number 1: ";
    c1.disp();

    std::cout << "Complex Number 2: ";
    c2.disp();

    std::cout << "Sum (Complex Number 3): ";
    c3.disp();

    return 0;
}
