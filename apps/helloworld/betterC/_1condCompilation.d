/*
 * Conditional Compilation
 * VersionCondition
 * DebugCondition
 * StaticIfCondition
 */
import core.stdc.stdio;

/*
 * Compilation cmd example:
 * dmd _1condCompilation.d -betterC -version=full -debug=0 -debug=DEBUGFLAG
 */

version(full)
{
    int extrafunctionality()
    {
        // DebugCondition
        // If debug level >= 1
        debug(1) { printf("Running full extrafunctionality\n"); }
        return 1;  // extra functionality is supported
    }
}
else // demo
{
    version = feature;
    int extrafunctionality()
    {
        debug(DEBUGFLAG) printf("Running demo extrafunctionality\n");
        return 0;  // extra functionality is not supported
    }
}


extern (C) void main() {
    // Version Condition

    if (extrafunctionality())
        printf("full version\n");
    else
        printf("demo version\n");
    version(feature)
    {
        printf("This feature is supported\n");
    }

    // StaticIfCondition + Templates
    template INT(int i)
    {
        static if (i == 32)
            alias INT = int;
        else static if (i == 16)
            alias INT = short;
        else
            static assert(0); // not supported
    }
    INT!(16) a;  // a is a short
    printf("Size of a: %d\n", a.sizeof);


    static foreach(i, v; ['a', 'b', 'c', 'd'])
    {
        static assert(i + 'a' == v);
    }

}
