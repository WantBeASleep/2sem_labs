# CMakeList.txt: проект CMake для lab3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("lab3")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab3 "lab3.cpp" "BinaryTree.hpp" "Menu.cpp" "Menu.hpp" "BinTree.cpp" "BinTree.hpp" "Set.hpp" "SetTest.cpp" "SetTest.hpp" "BinaryHeap.hpp" "BinHeap.hpp" "BinHeap.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.