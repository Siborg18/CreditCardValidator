cmake_minimum_required(VERSION 3.10)

project(CreditCardValidator)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Add the include directory to the include path
include_directories(CreditCardValidator)

# Create an executable target for our program
add_executable(main CreditCardValidator.cpp)

