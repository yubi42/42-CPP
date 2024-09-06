#pragma once

#include <iostream>
#include <stack>
#include <iterator>

//stack is by default last in, first out. this is why a stack does not need to get iteratet over usually
//stack is an adaption of deque, so the underlying container type is by default deque

template<typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack(void) : std::stack<T>::stack(){}
	MutantStack(MutantStack const &src) : std::stack<T>::stack(src){}
	MutantStack &operator=(MutantStack const &src)
	{
        if (this != &src) std::stack<T>::operator=(src);
        return (*this);
	}
	virtual ~MutantStack(void){}

//container_type references to the underlying container type, in this case: std::deque<T> and since deque has an iterator we can use it.
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

// by default c is the underlying container _Sequence. so we basically say begin() --> return std::deque<T>.begin()
// typedef allows us to create alias's. so now i can use "iterator" instead of always writing: "typename std::stack<T>::container_type::iterator"
    iterator begin() {return this->c.begin();}
    iterator end() {return this->c.end();}
    const_iterator begin() const {return this->c.begin();}
    const_iterator end() const {return this->c.end();}
    reverse_iterator rbegin() {return this->c.rbegin();}
    reverse_iterator rend() {return this->c.rend();}
    const_reverse_iterator rbegin() const {return this->c.rbegin();}
    const_reverse_iterator rend() const {return this->c.rend();}
};