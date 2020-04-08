import core.stdc.stdio;

void f() {
    string s = "a";
    final switch (s) {
        case "b" : printf("It's b\n"); break;
        case "a" : printf("It's a\n"); break;
    }
}

extern (C) void main() {
    f();
}
