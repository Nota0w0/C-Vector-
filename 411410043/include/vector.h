#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

#include <iostream>

class Vector 
{
private:
    int* array;           // Dynamic array 
    int capacity_;        // Maximum capacity of the array, capacity , name is same as capacity() so i canged it into capacity_
    int currentSize_;     // Current size (number of elements), size ,name is same as size so i canged it into currentSize_

public:
    // Constructors and destructor
    Vector();                                // Default constructor
    Vector(const Vector& vectorToCopy);      // Copy constructor
    ~Vector();                               // Destructor

    // Operator overloads
    Vector& operator=(const Vector& other);  // Assignment operator
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector); // Output stream operator
    int& operator[](int index);              // Subscript operator (non-const)
    const int& operator[](int index) const;  // Subscript operator (const)
    bool operator==(const Vector& other) const; // Equality operator
    Vector operator*(int scalar) const;      // Scalar multiplication (vector * scalar)
    friend Vector operator*(int scalar, const Vector& vector); // Scalar multiplication (scalar * vector)
    Vector operator*(const Vector& other) const;  // Element-wise multiplication (vector * vector)
    Vector operator+(const Vector& other) const; // Vector addition

    // Member functions
    void clear();                            // Clear the vector
    int size() const;                        // Get number of elements
    int capacity() const;                    // Get current capacity
    bool empty() const;                      // Check if vector is empty
    int& front();                            // Access the first element
    const int& front() const;                // Access the first element (const)
    int& back();                             // Access the last element
    const int& back() const;                 // Access the last element (const)
    void push_back(int item);                // Add element at the end
    void pop_back();                         // Remove the last element
    void reserve(int newCapacity);           // Reserve memory
};

#endif // INCLUDE_VECTOR_H
