import core.stdc.stdio;

void outterF() {
    void innerF() {
        struct Outter {
            this(int i) {
                this.i = i;
                printf("Constructing Outter object with %d\n", i);
            }

            struct Inner {
                string data;
                int idx = 5;
            };
            int i;
            Inner instance;
        }
        Outter var = Outter(2);
        printf("%d\n", var.instance.idx);
    }
    innerF();
}


extern (C) void main() {
    outterF();
}
