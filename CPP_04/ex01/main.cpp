#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    Animal obj;
    Dog* d1 = new Dog();
    d1->getBrain()->setIdea(0, "Fetch the ball");
    Dog d2 = *d1;
    d2.getBrain()->setIdea(0, "Eat food");

    std::cout << "d1 brain idea[0]: " << d1->getBrain()->getIdea(0) << std::endl;
    std::cout << "d2 brain idea[0]: " << d2.getBrain()->getIdea(0) << std::endl;
    Dog d3;
    d3 = *d1;
    
    delete d1;
    std::cout << "--------------------------------------------------" << std::endl;
    Animal **animal = new Animal*[20];
    for (size_t i = 0; i < 10; i++)
        animal[i] = new Dog();
    for (size_t i = 10; i < 20; i++)
        animal[i] = new Cat();
    for (size_t i = 0; i < 20; i++)
        delete animal[i];
    
    delete[] animal;
    
    return 0;
}
