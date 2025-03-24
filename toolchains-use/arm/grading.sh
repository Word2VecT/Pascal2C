 #!/bin/bash
export PATH=/root/.opam/system/bin:/usr/local/arm/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin:/usr/lib/jvm/jdk-11/bin:/bin:/usr/bin:/usr/local/sbin:/usr/local/bin:/sbin:/usr/games:/usr/local/games:/snap/bin:/opt/RISCV/riscv/bin:/opt/RISCV/riscv/bin:/opt/RISCV/riscv/bin

cd src
rm step2.arm > /dev/null 2>&1  
arm-linux-gnueabihf-gcc -o step2.arm  bubble.s sort.c  ../lib/sylib.c 
if [ -f "step2.arm" ]; then
   qemu-arm -L /usr/arm-linux-gnueabihf/ ./step2.arm 
fi
#echo $?