import core.stdc.stdio;

extern (C) void main()
{
    int i = 3;
    auto twice  = function (int x) => x * 2;
    auto square = delegate (int x) => x * x;

    printf("%d\n", twice(i));   // prints 6
    printf("%d\n", square(i));  // prints 9
}
