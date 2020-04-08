# DRuntime-app-test-and-dev
Requirements:<br />
-qemu-system-x86_64 <br />
-dmd compiler <br />
<br />
Steps for running a D application in Unikraft:<br />
-cp [D source files] apps/helloworld/ <br />
-update apps/helloworld/Makefile.uk with the filenames<br />
-make menuconfig<br />
    Select:<br />
    -> Platform Configuration<br />
        -> Linux User Space<br />
        -> KVM Guest<br />
    -> Library Configuration<br />
        -> uksched<br />
-make<br />
-sudo qemu-system-x86_64 -enable-kvm -nographic -device isa-debug-exit -kernel build/helloworld_kvm-x86_64.dbg<br />
