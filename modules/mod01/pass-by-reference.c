#include <stdio.h>

int
add_one_to_int(int var) {
        return ++var;
}

int
add_one_to_pointer(int *var) {
        return ++(*var);
}

int
main() {
        int foo = 42;
        int result;

        printf("Start value of foo is %d\n", foo);

        result = add_one_to_int(foo);
        printf("Added one to foo and got %d\n", result);
        printf("Foo is now %d\n", foo);

        result = add_one_to_pointer(&foo);
        printf("Added one to &foo and got %d\n", result);
        printf("Foo is now %d\n", foo);
}
