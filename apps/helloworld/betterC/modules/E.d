module E;

import A;
import B;
import C;

alias foo = B.foo;
void test()
{
    foo();   // call B.foo()
    A.foo(); // call A.foo()
    B.foo(); // call B.foo()
    C.test();
}

extern (C) void main() {
    test();
}
