#include <iostream>

class base {
public:
    virtual void print() {
        std::cout << "base" << std::endl;
    }
    virtual void derived_print()=0;
    virtual ~base() {}
};

class derived : public base {
public:
    void print() {
        std::cout << "derived" << std::endl;
    }
    void derived_print() {
        std::cout << "derived_print" << std::endl;
    }
    ~derived() {}
};

int main() {
    base* b = new derived();
    b->derived_print();
    b->print();
    delete b;
    return 0;
}