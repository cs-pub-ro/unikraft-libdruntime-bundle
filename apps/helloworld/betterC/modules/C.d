module C;

import A;

import core.stdc.stdio;
void foo()
{
    printf("C.foo\n");
}

void test()
{
    foo(); // C.foo() is called, it is found before imports are searched
    bar(); // A.bar() is called, since imports are searched
}
