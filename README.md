# Roman number convertor 

This program allows you to convert Roman numbers to Arabic.

* Build system: cmake
* Tests: gtest
* Code style check: cpplint

***
# **Roman number convertor structure**

This program includes the following folders: cmake (contains the rules and build goals), function_lib (contains the header and the source file), gtest (contains files with auxiliary code necessary for the operation of the test system and the entire program), main (contains the main function that demonstrates the operation of the program), test (contains a set of tests to check the correctness of the program).

***
# **Data structures**

The main data structure in this program is `class Convertor`. It contains method `int (Roman_to_Arabic(string value))` that convert Roman numbers to Arabic.

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
