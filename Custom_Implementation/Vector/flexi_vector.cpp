/*
Problem Statement:
Create a vector which can take any number of element and any type of datatype as its elements. 
For instance, 1st elem can be int, 2nd can be float, 3rd can be any class object, 4th can be a string etc.
We need a mechanism to add such elemnts and also display an element at an index.

*/

#include <iostream>
#include <vector>

template<typename T>
class FlexibleVector {
private:
    std::vector<T> elements;
public:
    void addElement(const T& element) {
        elements.push_back(element);
    }

    T getElement(int index) const {
        if (index < 0 || index >= elements.size()) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }
};

int main() {
    FlexibleVector<int> intFloatVector;
    intFloatVector.addElement(10);
    intFloatVector.addElement(3.14f);
    
    std::cout << "Element at index 0: " << intFloatVector.getElement(0) << std::endl;
    std::cout << "Element at index 1: " << intFloatVector.getElement(1) << std::endl;

    FlexibleVector<std::string> stringVector;
    stringVector.addElement("Hello");
    stringVector.addElement("World");

    std::cout << "Element at index 0: " << stringVector.getElement(0) << std::endl;
    std::cout << "Element at index 1: " << stringVector.getElement(1) << std::endl;

    // You can add elements of any type and retrieve them as needed
    return 0;
}
