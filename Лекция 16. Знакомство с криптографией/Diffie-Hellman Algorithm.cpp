#include <iostream>
#include <cmath>

class Person
{
private:
    int private_key;

public:
    Person(int private_key)
    {
        this->private_key = private_key;
    }

    int calculate_public_key()
    {
        return (int)pow(3.0, this->private_key) % 17;
    }

    void shared_key(int public_key)
    {
        std::cout << (int)pow(public_key, private_key) % 17 << std::endl;
    }
};

int main()
{
    Person Alice(54);
    Person Bob(24);
    Alice.shared_key(Alice.calculate_public_key());
    Bob.shared_key(Bob.calculate_public_key());
    return 0;
}
