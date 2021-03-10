# Cyclic list

This program allows you to create a cyclic list and check it for a cycle in two ways: 1. the method of "fast and slow pointers" (in other words, "turtle and hare"); 2. the method of reversing the list.

* Build system: cmake
* Tests: gtest
* Code style check: cpplint

***
# **Cyclic list repository's structure**

This repository includes the following folders: cmake (contains the rules and build goals), function_lib (contains the header and the source files), gtest (contains files with auxiliary code necessary for the operation of the test system and the entire program), main (contains the main function that demonstrates the operation of the program), test (contains a set of tests to check the correctness of the program).

***
# **Data structures**

The main data structures in this program are `struct Node` and `struct Cyclic_List`. `struct Node`contains variables required to work with list elements. `struct Cyclic_List` contains variables required to work with a list, list initialization function and list printing function. In addition, the functions for checking the list for a cycle are separately provided: `bool HasCycle_by_Slow_and_Fast_Pointers(Cyclic_List _list)` and `bool HasCycle_by_Slow_and_Fast_Pointers(Cyclic_List _list)`.

***
# **Merging an upstream repository into your fork (master branch)**

`git checkout master`

 `git pull https://github.com/enjulia17/Template_for_Project_Works.git master`
 
 ***
# **Updating working branch**

`git checkout <your branch>`

 `git rebase master`

 ***
# **Building project witn cmake**
(In the "Build" folder via Git Bash Here)

`cmake ../`
