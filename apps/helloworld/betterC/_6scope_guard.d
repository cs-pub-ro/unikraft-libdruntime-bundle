import core.stdc.stdio;

void f() {
    struct Foo
    {
        this(string s) { printf("0"); }
        ~this() { printf("1"); }
    }
    {
        scope(exit) printf("2");
        Foo f = Foo("0");
        /*
         * executes when the scope exits due to exception unwinding
         * Since we don't have exceptions in betterC, we'll observe
         * that these are never executed
         *
         * scope(success) also doesn't work
         */
        //scope(failure) printf("4");
        scope(exit) printf("5");
    }
    printf("\n");
}

extern (C) void main() {
    f();
}
