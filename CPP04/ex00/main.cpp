/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:02:02 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/05 20:32:21 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    // const Animal* ani = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;
    std::cout << "Old McJesse has a farm I-AY I-AY OHHHHH" << std::endl;
    std::cout << "And on the farm she has some CatDogs I-AY I-AY OHHHHH" << std::endl;
    std::cout << "And a ";
    cat->makeSound();
    cat->makeSound();  
    std::cout << " here" << std::endl;
    std::cout << "And a ";
    dog->makeSound();
    dog->makeSound();  
    std::cout << " there" << std::endl;
    std::cout << "here ";
    cat->makeSound();  
    std::cout  << std::endl << "there ";
    dog->makeSound();  
    std::cout  << std::endl << "everywhere ";
    cat->makeSound();
    dog->makeSound();  
    std::cout << std::endl << "Old McJesse had a farm I-AY I-AYYYYYYOOOOOO" << std::endl;
    std::cout << std::endl;

    delete dog;
    delete cat;

    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;
    std::cout << "Old McJesse has a farm I-AY I-AY OHHHHH" << std::endl;
    std::cout << "And on the farm she has some CatDogs I-AY I-AY OHHHHH" << std::endl;
    std::cout << "And a ";
    wrongCat->makeSound();
    wrongCat->makeSound();  
    std::cout << " here" << std::endl;
    std::cout << "And a ";
    wrongCat->makeSound();
    wrongCat->makeSound();  
    std::cout << " there" << std::endl;
    std::cout << "here ";
    wrongCat->makeSound();  
    std::cout  << std::endl << "there ";
    wrongCat->makeSound();  
    std::cout  << std::endl << "everywhere ";
    wrongCat->makeSound();
    wrongCat->makeSound();  
    std::cout << std::endl << "Old McJesse had a farm I-AY I-AYYYYYYOOOOOO" << std::endl;
    std::cout << std::endl;

    delete wrongCat;
}