unittest
{
   assert(0);
}
/*
 * Running: dmd -betterC -unittest _7unittests.d
 */
extern(C) void main()
{
    static foreach(u; __traits(getUnitTests, __traits(parent, main)))
        u();
}
