# Template_for_Project_Works

Template for developing and testing C++ programs

* Build system: cmake
* Tests: gtest
* Code style check: cpplint

***
# **Template structure**

This template includes the following folders: cmake (contains the rules and build goals), function_lib (contains the header and the source files), gtest (contains files with auxiliary code necessary for the operation of the test system and the entire program), main (contains the main function that demonstrates the operation of the program), test (contains a set of tests to check the correctness of the program).

***
# **Merging an upstream repository into your fork (master branch)**

`git checkout master`

 `git pull https://github.com/UsovaMA/Development-Template.git master`
 
 ***
# **Updating working branch**

`git checkout <your branch>`

 `git rebase master`

 ***
# **Building project witn cmake**
(In the "Build" folder via Git Bash Here)

`cmake ../`
