/*
 * On one hand, u have the 'function' type
 * which u would use to refer global functions
 */

void myGlobalF(int x) {
  import core.stdc.stdio;
  printf("I'm a global function printing the number u gave me: %d\n", x);
}

void aFunction(void delegate(void function(int)) f) {
  import core.stdc.stdio;
  printf("I'm a global function and i'm just here to call the function u gave me:\n");
  f(&myGlobalF);
}

struct ARandomClass {
  int attr;

  this(int attr) {
    this.attr = attr;
  }

  /*
   * As u can see, this method uses the attr attribute, so in order to actually work,
   * its context must also be known; this is not the case for 'function' types, but it
   * is the case for 'delegate' type
   */
  void aRandomFunction(void function(int) f) {
    f(attr);
  }
}

extern (C) void main() {
  ARandomClass a = ARandomClass(234);
  a.aRandomFunction(&myGlobalF);
  aFunction(&a.aRandomFunction);
}
