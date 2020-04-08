module D;

import A;
import B;

void test()
{
    //foo();   // error, A.foo() or B.foo() ?
    A.foo(); // ok, call A.foo()
    B.foo(); // ok, call B.foo()
}
