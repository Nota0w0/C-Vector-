#include "../include/vector.h"
#include <iostream>

// Default constructor
Vector::Vector() : array(nullptr), capacity_(0), currentSize_(0) {}

// Copy constructor
Vector::Vector(const Vector& vectorToCopy) : array(nullptr), capacity_(0), currentSize_(0) {
    if (vectorToCopy.capacity_ > 0) {
        // Allocate memory
        array = new int[vectorToCopy.capacity_];
        capacity_ = vectorToCopy.capacity_;
        
        // Copy elements
        currentSize_ = vectorToCopy.currentSize_;
        
        std::copy(vectorToCopy.array, vectorToCopy.array + vectorToCopy.currentSize_, array);
        //use copy easy to look 
    }
}

// Destructor
Vector::~Vector() {
    delete[] array;  // Release the memory
    // can't use clear()
}

Vector& Vector::operator=(const Vector& other) {//https://www.geeksforgeeks.org/copy-swap-idiom-c/ i learn the way here
    if (this == &other) return *this;  // Self-assignment

    // copy-and-swap idiom，temp's destructor auto delete old memory, no delte[] array here.
    Vector temp(other);
    std::swap(array, temp.array);
    std::swap(currentSize_, temp.currentSize_);
    std::swap(capacity_, temp.capacity_);

    return *this;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    os << "[";
    if (vector.currentSize_ > 0) {
        os << vector.array[0];// treat first element special. Rather than detemine if the element is the last one 
        for (int i = 1; i < vector.currentSize_; ++i) {
            os << ", " << vector.array[i];
        }
    }
    os << "]";
    return os;
}

// Subscript operator (for non-const objects)
int& Vector::operator[](int index) {
    if (index < 0 || index >= currentSize_) {
        std::cerr << "Error: Index out of range" << std::endl;
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

// Subscript operator (for const objects)
const int& Vector::operator[](int index) const {
    if (index < 0 || index >= currentSize_) {
        std::cerr << "Error: Index out of range" << std::endl;
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

// Equality operator
bool Vector::operator==(const Vector& other) const {
    if (currentSize_ != other.currentSize_) {
        return false;// for speed, fast return
    }
    
    for (int i = 0; i < currentSize_; i++) {
        if (array[i] != other.array[i]) { // checking
            return false;
        }
    }
    
    return true;
}

// Scalar multiplication (vector * scalar)
Vector Vector::operator*(int scalar) const {
    Vector result(*this);
    for (int i = 0; i < currentSize_; i++) {
        result.array[i] *= scalar;
    }
    return result;
}

// Scalar multiplication (scalar * vector)
Vector operator*(int scalar, const Vector& vector) {
    return vector * scalar;  // Reuse the vector * scalar operator because it should be same
}
// Element-wise multiplication (vector * vector)
Vector Vector::operator*(const Vector& other) const {
    if (currentSize_ != other.currentSize_) {
        std::cerr << "Error: Cannot multiply different sizes vectors" << std::endl;
        throw std::invalid_argument("Cannot multiply different sizes vectors");
    }
    
    Vector result(*this);  // Copy this vector
    for (int i = 0; i < currentSize_; i++) {
        result.array[i] *= other.array[i];  // Element-wise multiplication
    }
    return result;
}

// Addition operator
Vector Vector::operator+(const Vector& other) const {
    if (currentSize_ != other.currentSize_) {
        std::cerr << "Error: Cannot add different sizes vectors" << std::endl;
        throw std::invalid_argument("Cannot add different sizes vectors");
    }
    
    Vector result(*this);
    for (int i = 0; i < currentSize_; i++) {
        result.array[i] += other.array[i];
    }
    return result;
}

// Clear the vector (reset size to 0)
void Vector::clear() {
    currentSize_ = 0;
    // no deallocate memory here
}

// Get the size
int Vector::size() const {
    return currentSize_;
}

// Get the capacity
int Vector::capacity() const {
    return capacity_;
}

// Check if the vector is empty
bool Vector::empty() const {
    return currentSize_ == 0;
}

// Access the first element
int& Vector::front() {
    if (empty()) {
        std::cerr << "Error: Cannot access front element of empty vector" << std::endl;
        throw std::out_of_range("Vector is empty");
    }
    return array[0];
}

// Access the first element (const version)
const int& Vector::front() const {
    if (empty()) {
        std::cerr << "Error: Cannot access front element of empty vector" << std::endl;
        throw std::out_of_range("Vector is empty");
    }
    return array[0];
}

// Access the last element
int& Vector::back() {
    if (empty()) {
        std::cerr << "Error: Cannot access back element of empty vector" << std::endl;
        throw std::out_of_range("Vector is empty");
    }
    return array[currentSize_ - 1];
}

// Access the last element (const version)
const int& Vector::back() const {
    if (empty()) {
        std::cerr << "Error: Cannot access back element of empty vector" << std::endl;
        throw std::out_of_range("Vector is empty");
    }
    return array[currentSize_ - 1];
}

// Add an element to the end
void Vector::push_back(int item) {
    if (currentSize_ >= capacity_) { // if the array is full, double it up and use reserve to give it more space.
        int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2; // if the array is empty, mark it non-empty
        reserve(newCapacity);
    }
    
    // Add the new element
    array[currentSize_++] = item;
}

// Remove the last element
void Vector::pop_back() {
    if (empty()){
        std::cerr << "Error: Cannot pop from empty vector" << std::endl;
        throw std::out_of_range("Vector is empty");
    }
    currentSize_--; // not modifying the array's content, move the bound of the array
}

// Reserve memory
void Vector::reserve(int newCapacity) {
    if (newCapacity < capacity_) {
        std::cerr << "Error: New capacity must be greater than or equal to current capacity" << std::endl;
        throw std::invalid_argument("New capacity must be greater than or equal to current capacity");
    }
    
    if (newCapacity == capacity_) { 
        return;  // No change needed, return ealier
    }
    
    // Allocate new array, greater than remains
    int* newArray = new int[newCapacity];
    
    // Copy existing elements
    for (int i = 0; i < currentSize_; i++) {
        newArray[i] = array[i];
    }
    
    // Delete old array
    delete[] array;
    
    // Update member variables
    array = newArray;
    capacity_ = newCapacity;
}
