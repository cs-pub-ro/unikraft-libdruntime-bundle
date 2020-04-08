extern (C) {
  void f(int[10] a) {
    import core.stdc.stdio;

    int[5] a2 = a[5..10];

    foreach (e; a2) {
      printf("%d ", e);
    }
  }

  void main() {
    int[10] ra;
    ra[] = 4;
    ra[] += 12;

    int[6] rb = ra[3..9];
    //rb = ra[3..8];    -> error

    f(ra);
  }
}
