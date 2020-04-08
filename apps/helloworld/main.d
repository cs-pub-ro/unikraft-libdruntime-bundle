extern (C) {
	void f(int[10] a) {
		import core.stdc.stdio;
		int[5] a2 = a[5..10];
		foreach (e; a2) {
			printf("%d ", e);
		}
		printf("\n");
	}

	void main() {
		int[10] ra;
		//ra[] = 12;
		f(ra);
	}
}

