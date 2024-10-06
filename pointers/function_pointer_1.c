#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*func_ptr)(int, int); // Declare a function pointer
    func_ptr = add;       // Assign the address of 'add' function to the pointer

    // Now you can call the function using the pointer
    int result = func_ptr(5, 3);
    printf("Result: %d\n", result); // Output will be 8

    return 0;
}