# CPP Modules

C++ exercises from the 42 curriculum, focused on object-oriented programming, memory management, inheritance, polymorphism, templates, STL containers and algorithms.

## About

This repository contains my solutions to the 42 C++ modules.

The goal of these projects is not to build one large application, but to progressively learn the main features of C++ through small and focused exercises. Each module introduces a new set of concepts, starting from basic syntax and classes, and gradually moving toward more advanced topics such as canonical classes, polymorphism, exceptions, templates and the STL.

Most exercises are written under the constraints of the 42 curriculum, mainly using C++98 and Makefiles.

## Repository Structure

```txt
.
├── module_00
├── module_01
├── module_02
├── module_03
├── module_04
├── module_05
├── module_06
├── module_07
├── module_08
└── module_09

Each module contains several exercises, usually organized as ex00, ex01, ex02, etc.

Modules Overview
Module	Main Topics
module_00	C++ basics, namespaces, classes, member functions, stdio streams
module_01	Memory allocation, pointers, references, file streams
module_02	Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form
module_03	Inheritance
module_04	Subtype polymorphism, abstract classes, interfaces
module_05	Exceptions and error handling
module_06	C++ casts and type conversion
module_07	Function templates and class templates
module_08	Templated containers, iterators and algorithms
module_09	STL containers and more advanced data handling
What I Learned

Through these modules I practiced:

Writing clean and modular C++ code
Understanding object-oriented programming in C++
Managing memory manually and avoiding leaks
Using constructors, destructors and copy assignment operators correctly
Applying inheritance and polymorphism
Handling errors with exceptions
Using templates to write generic code
Working with STL containers and algorithms
Creating and using Makefiles for compilation
Compilation

Each exercise usually has its own Makefile.

To compile one exercise:

cd module_XX/exYY
make

To clean generated files:

make clean

To remove all generated files, including the executable:

make fclean

To rebuild:

make re
Example Usage
cd module_04/ex00
make
./program_name

The executable name depends on each exercise.

Technologies
C++
Makefile
Unix/Linux environment
Git
Notes

This repository is part of my learning process at 42.
The code is intended for educational purposes and reflects my progression while learning C++ and object-oriented programming.

If you are also a 42 student, use this repository only as a reference. The best way to learn these modules is to understand and implement the exercises by yourself.

Author

Luis Ángel Álvarez Gil
Computer Engineering student
42 Málaga
