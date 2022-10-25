# ft_containers
This 42 project aims to make us learn and understand how some STL containers work and reverse engineer it to make our own implementation alongside their iterators.
We need to stick to C++ 98 only, even if obsolete. See below the list of containers implemented:

## Functions to reproduce
- ``vector``: sequence containers representing arrays that can change in size
- ``map``: associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order
- ``stack``: a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container

We must to use a self-balancing binary search tree in our ``map`` implementation. Original map container from STL uses a Red-Black Tree as its inner data structure. I decided to use an AVL Tree because it seemed easier to implement at first glance. Using an AVL will reduce speed at both insertion and removal (due to rotations for balancing), but it should find elements quicker.

## 🧭 Usage
Clone this repo and go to container_tests, then choose which test to run using sh. I used the @Mli42 tester which is really good, but I implemented my own test files. 
Feel free to use your own tests
