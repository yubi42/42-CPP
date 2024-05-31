#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    std::srand(std::time(NULL));

    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            std::cout << "Creating type A." << std::endl;
            return (new A());
        case 1:
            std::cout << "Creating type B." << std::endl;
            return (new B());
        case 2:
            std::cout << "Creating type C." << std::endl;
            return (new C());
        default:
            std::cerr << "Failed to create Base." << std::endl;
            return (NULL);
    }
}

//when using a pointer it returns a nullptr when it fails, so if else works.

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type is A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type is B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type is C." << std::endl;
	else
		std::cout << "Type is unknown." << std::endl;
}

//when using references an exception is thrown instead of nullptr (because there is no ptr, so they have to work with exceptions)

void identify(Base &p)
{
    try 
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "Type is A." << std::endl;
        return ;
    }
    catch (const std::exception&) {}
    try 
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "Type is B." << std::endl;
        return ;
    }
    catch (const std::exception&) {}
    try 
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "Type is C." << std::endl;
        return ;
    }
    catch (const std::exception&) {}

    std::cout << "Type is unknown." << std::endl;
}

int main()
{
    Base *random = generate();

    identify(random);
	identify(*random);
	delete random;
	return 0;
}