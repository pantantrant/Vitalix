tar -xf ../src/Java_6_Interpreter_in_C.tar.xz
cd Java_6_Interpreter_in_C
mkdir build
cd build
cmake ..
make CC=clang CFLAGS="-Oz"
cd ../..
tar -xf ../src/uefi-musl-master.tar.xz
clang -std=c89 -Iuefi-musl-master/include -IJava_6_Interpreter_in_C/jvm/include -IJava_6_Interpreter_in_C/jvm/interpreter -IJava_6_Interpreter_in_C/jvm/include/interpreter -target x86_64-unknown-windows -m32 -ffreestanding -fshort-wchar -fuse-ld=ld.bfd -c ../src/Vitalix.c Java_6_Interpreter_in_C/build/libLIB_JVM.a -static -Oz -Wno-error -o BOOTX64.EFI -Wl,-entry:UefiMain
dd if=/dev/zero of=Vitalix.img bs=48M count=1 && printf "g\nn\n\n\n\nt\n1\nx\nn\nVitalix\nr\nw\n" | fdisk Vitalix.img && mkfs.fat -F 32 Vitalix.img && mmd -i Vitalix.img ::/EFI && mmd -i Vitalix.img ::/EFI/BOOT && mcopy -i Vitalix.img BOOTX64.EFI ::/EFI/BOOT
