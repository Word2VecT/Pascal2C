gcc -o def-test def-test.c alibaba.c -DBILIBILI

clang -O2 -target armv7-linux-gnueabihf -S bar.c -o bar.clang.arm.s

arm-linux-gnueabihf-gcc -S iplusf.c -o iplusf.arm
arm-linux-gnueabihf-gcc iplusf.arm.s sylib.a -o iplusf.arm
qemu-arm ./iplusf.arm