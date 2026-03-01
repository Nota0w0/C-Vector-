/*********************************************************************
Test driver program: Vector_test.cpp
FUNCTION: This program tests the functionality of the Vector class.
*********************************************************************/
#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;

int main() {
    cout << "Testing default constructor\n\n";

    Vector v1;
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << (v1.empty() ? "empty\n" : "not empty\n") << endl;

    cout << "Testing push_back()\n\n";
    for (int i = 10; i < 200; i += 10)
        v1.push_back(i);

    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << (v1.empty() ? "empty\n" : "not empty\n") << endl;

    cout << "Testing pop_back()\n\n";
    for (int i = 0; i < 3; ++i)
        v1.pop_back();

    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 is " << (v1.empty() ? "empty\n" : "not empty\n") << endl;

    cout << "Testing copy constructor\n\n";
    Vector v2 = v1;
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;

    cout << "Testing front() and back()\n\n";
    cout << "Front item of v1: " << v1.front() << endl;
    cout << "Rear item of v1: " << v1.back() << endl;
    cout << "Front item of v2: " << v2.front() << endl;
    cout << "Rear item of v2: " << v2.back() << endl << endl;

    cout << "Testing pop() to empty\n\n";
    while (!v1.empty()) {
        cout << v1.back() << ' ';
        v1.pop_back();
    }
    cout << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 is " << (v1.empty() ? "empty\n" : "not empty\n") << endl;

    cout << "Testing assignment operator\n\n";
    Vector v3;
    v3 = v2;

    cout << "v2: " << v2 << endl;
    cout << "v3: " << v3 << endl;

    Vector v4;
    v3 = v4;

    cout << "v3: " << v3 << endl;
    cout << "v4: " << v4 << endl;

    v3 = v2;
    cout << "v3: " << v3 << endl;

    cout << "Testing clear()\n\n";
    v2.clear();
    cout << "v2 (size " << v2.size() << "): " << v2 << endl;
    cout << "v3 (size " << v3.size() << "): " << v3 << endl << endl;

    cout << "Testing assignment to self and swap\n\n";
    v3 = v3;
    v2 = v3;
    v3.clear();
    cout << "v2 (size " << v2.size() << "): " << v2 << endl;
    cout << "v3 (size " << v3.size() << "): " << v3 << endl << endl;

    cout << "Testing chained assignment\n\n";
    Vector v5;
    v5 = v3 = v2;
    cout << "v2 (size " << v2.size() << "): " << v2 << endl;
    cout << "v3 (size " << v3.size() << "): " << v3 << endl;
    cout << "v5 (size " << v5.size() << "): " << v5 << endl << endl;

    cout << "Testing write version of subscript operator\n\n";
    for (int i = 0; i < v5.size(); ++i)
        v5[i] += 5;
    cout << "v5 (size " << v5.size() << "): " << v5 << endl << endl;

    cout << "Testing read version of subscript operator\n\nv5: ";
    for (int i = 0; i < v5.size(); ++i)
        cout << v5[i] << ' ';
    cout << endl << endl;

    cout << "Testing const correctness\n\n";
    const Vector& r5 = v5;
    cout << "v5: " << r5 << endl;
    cout << "v5 size: " << r5.size() << endl;
    cout << "v5 capacity: " << r5.capacity() << endl;
    cout << "v5 is " << (r5.empty() ? "empty\n" : "not empty\n") << endl;
    cout << "Front item of v5: " << r5.front() << endl;
    cout << "Rear item of v5: " << r5.back() << endl;
    cout << "4th item of v5: " << r5[3] << endl << endl;

    v1 = r5;
    cout << "v1: " << v1 << endl;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 is " << (v1.empty() ? "empty\n" : "not empty\n") << endl << endl;

    cout << "Testing equality operator\n\n";
    cout << "v1 and v5 are " << (v1 == r5 ? "equal\n" : "not equal\n");
    cout << "v5 and v3 are " << (r5 == v3 ? "equal\n" : "not equal\n");
    cout << "v1 and v2 are " << (v1 == v2 ? "equal\n" : "not equal\n");

    v5.pop_back();
    cout << "v1 and v5 are now " << (v1 == v5 ? "equal\n" : "not equal\n") << endl;

    Vector v6;
    for (int i = 1; i < 6; i++)
        v6.push_back(i);

    Vector v7;
    for (int i = 6; i < 11; i++)
        v7.push_back(i);

    cout << "Testing inner product of two vectors\n\n";
    cout << "v6 * v7: " << v6 * v7 << endl << endl;

    cout << "Testing vector multiplication with a constant\n\n";
    Vector v8 = v6 * 2;
    cout << "v8 (size " << v8.size() << "): " << v8 << endl << endl;
    cout << "v6 (size " << v6.size() << "): " << v6 << endl << endl;

    cout << "Testing adding of two vectors\n\n";
    Vector v9 = v6 + v7;
    cout << "v9 (size " << v9.size() << "): " << v9 << endl << endl;
    cout << "v6 (size " << v6.size() << "): " << v6 << endl << endl;
    cout << "v7 (size " << v7.size() << "): " << v7 << endl << endl;

    return 0;
}
