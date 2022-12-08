#include "array.h"
#include <iostream>
size_t totalAllocatedMemory = 0;

Array::Array(): size_(0), array_(nullptr){
    //std::cout << "Constructor with no args " << std::endl;
}

Array::Array(int size): size_(size), array_(nullptr){
    //std::cout << "Constructor with size ";
    array_ = new double[size_];
    totalAllocatedMemory += size_ * sizeof(array_);
    //std::cout << array_ << std::endl;
}

Array::Array(std::initializer_list<double> list) {
    //std::cout << "Constructor with list ";
    size_= list.size();
    array_ = new double[size_];
    for(int i=0; i<size_; i++){
        array_[i] = list.begin()[i];
    }
    //std::cout << array_ << std::endl;
    totalAllocatedMemory += size_ * sizeof(array_);
}

Array::Array(const Array& other) {
    //std::cout << "Copy Constructor.";
    size_ = other.size_;
    array_ = new double[size_];
    for(int i=0; i<size_; i++){
        array_[i] = other.array_[i];
    }
    //std::cout << " Source: " << other.array_ << " Destiny: " << array_ << std::endl;
    totalAllocatedMemory += size_ * sizeof(array_);
}

Array::Array(Array&& other) {
    //std::cout << "Move Constructor.";
    size_ = other.size_;
    array_ = other.array_;

    other.size_ = 0;
    other.array_ = nullptr;
    //std::cout << " Source: " << other.array_ << " Destiny: " << array_ << std::endl;
}

Array& Array::operator=(const Array& other) {
    //std::cout << "Assignment operator" << std::endl;
    totalAllocatedMemory += (other.size_ - size_) * sizeof(array_);
    
    if( size_ != other.size_ ){
        delete[] array_;
        size_ = other.size_;
        array_ = new double[size_];
    }

    for(int i=0; i<size_; i++){
        array_[i] = other.array_[i];
    }

    return *this;
}

Array& Array::operator=(Array&& other) {
    //std::cout << "Move assignment" << std::endl;
    totalAllocatedMemory -= size_ * sizeof(array_);
    size_ = other.size_;
    array_ = other.array_;

    other.size_ = 0;
    other.array_ = nullptr;
    return *this;
}

Array::~Array() {
    //std::cout << "DESTRUCTOR: " << array_ << std::endl;
    delete[] array_;
    totalAllocatedMemory -= size_ * sizeof(array_);
    //std::cout << totalAllocatedMemory << std::endl;
}

double& Array::operator[](size_t index) {
    return *(array_ + index);   
}

size_t Array::size() const {
    // std::cout << "Size: " << size_ << " {"; // <----- Debug print
    // if(array_ != nullptr){
    //     for(int i=0; i<size_; i++){
    //         std::cout << ' ' << array_[i] << ' ';
    //     }
    // } 
    // std::cout << '}' << std::endl;          // <----- Debug print
    // std::cout << totalAllocatedMemory << std::endl;
    return size_;
}

size_t& Array::allocated_memory() {
    return(totalAllocatedMemory);
}

