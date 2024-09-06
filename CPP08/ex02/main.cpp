#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << "cur size: " << mstack.size() << std::endl;
std::cout << "top is:" << mstack.top() << std::endl;
mstack.pop();
std::cout << "cur size: " << mstack.size() << std::endl;
std::cout << "top is:" << mstack.top() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it; 
std::cout << "iterationg through a stack x):" << std::endl;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
return 0;
}