//This is the source code for the rop challenge
//This challenge is a simple ROP challenge
//The goal is to call the function win()

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
int win()
{
     //check if rax is 3 and rbx is 2 in assembly
    __asm__("cmp $3, %rax");
    __asm__("jne fail");
    __asm__("cmp $2, %rbx");
    __asm__("jne fail");
    //Save the value of rax in a variable
    unsigned long long rax;
    __asm__("mov %%rax, %0" : "=r"(rax));
    //Save the value of rbx in a variable
    unsigned long long rbx;
    __asm__("mov %%rbx, %0" : "=r"(rbx));

   
    printf("You win!\n");

    //Print the flag in a very roundabout way, so that the user can't just look at the assembly to find it
    // flag = CTF_SDaT{AW3s0m3_J0b_0n_th3_Ch4113ng3}
    char flag[38];
    //Insert the first part of the flag
    flag[0] = 'C';
    flag[1] = 'T';
    flag[2] = 'F';
    flag[3] = '_';
    flag[4] = 'S';
    flag[5] = 'D';
    flag[6] = 'a';
    flag[7] = 'T';
    flag[8] = '{';

    if (flag[0] == 'C'){
        flag[9] = 'A';
    }
    else{
        flag[9] = 'a';
    }

    if (flag[1] == "T"){
        flag[10] = 'w';
    }
    else{
        flag[10] = 'W';
    }
    flag[11] = '3';
    flag[12] = 's';
    flag[13] = '0';
    flag[14] = 'm';
    if (3>2){
        flag[15] = '3';
    }
    else{
        flag[15] = 'e';
    }
    if (2<3){
        flag[16] = '_';
    }
    else{
        flag[16] = '!';
    }
    flag[17] = 'J';
    flag[18] = '0';
    flag[19] = 'b';
    if (3>1){
        flag[20] = '_';
    }
    else{
        flag[20] = '!';
    }
    flag[21] = '0';
    flag[22] = 'n';
    flag[23] = '_';
    if (34>32){
        flag[24] = 't';
    }
    else{
        flag[24] = 'T';
    }
    //Assert the variable rax is 3
    if (rax == 3){
        flag[25] = 'h';
    }
    else{
        flag[25] = 'H';
    }
    flag[26] = '3';
    flag[27] = '_';
    flag[28] = 'C';
    flag[29] = 'h';
    flag[30] = '4';
    flag[31] = '1';
    flag[32] = '1';
    //Assert the variable rbx is 2
    if (rbx == 2){
        flag[33] = '3';
    }
    else{
        flag[33] = '!';
    }
    flag[34] = 'n';
    flag[35] = 'g';
    flag[36] = '3';
    if (flag[5] == "D"){
        flag[37] = '!';
    }
    else{
        flag[37] = '}';
    }
    flag[38] = '\0';

    printf("%s\n", flag);
}

int fail()
{
    printf("You failed!\n");
    return 0;
}

int main(int argc, char *argv[])
{

    char str[517];

    printf("Welcome to the ROP challenge!\n");
    printf("You are currently in the main function of an executable.\n");
    printf("The goal is to call the function win(), while having a value of 3 in rax, and 2 in rbx.\n");
    printf("You should pass this executable a text file containing your attack string.\n");

    //check if the user passed a file
    if (argc < 2)
    {
        printf("Please pass a file as an argument. Exitting now\n");
        return 0;
    }

    //open the file
    FILE *fp;
    fp = fopen(argv[1], "r");
    fread(str, sizeof(char), 517, fp);
    if (fp == NULL)
    {
        printf("Error opening file. Exitting now\n");
        return 0;
    }


    bof(str);

    printf("You have returned to the main function. Did you win?\n");
    
    return 1;
    
}

int bof(char *str)
{
    char buffer[24];
    memcpy(buffer, str, 100);
    return 1;
}

/* This function marks the start of the farm */
int start_farm()
{
    return 1;
}

unsigned addval_447(unsigned x)
{
   __asm__("pop %rax");
   __asm__("ret");
}

unsigned addval_320(unsigned x)
{
    return x + 2428995912U;
}

unsigned addval_194(unsigned x)
{
    return x + 3347662874U;
}

unsigned addval_106(unsigned x)
{
    return x + 3267856712U;
}

unsigned getval_427()
{
    return 3281012980U;
}

void setval_211(unsigned *p)
{
    *p = 2496104776U;
}

unsigned getval_151()
{
    return 2425393496U;
}

void setval_181(unsigned *p)
{
    *p = 2425393240U;
}

/* This function marks the middle of the farm */
int mid_farm()
{
    return 1;
}

/* Add two arguments */
long add_xy(long x, long y)
{
    return x+y;
}

unsigned getval_249()
{
    __asm__("pop %rbx");
    __asm__("ret");
}

void setval_385(unsigned *p)
{
    *p = 2425411273U;
}

void setval_474(unsigned *p)
{
    *p = 2430650696U;
}

unsigned getval_408()
{
    return 3286272264U;
}

unsigned addval_245(unsigned x)
{
    return x + 3374372521U;
}

void setval_379(unsigned *p)
{
    *p = 3682912937U;
}

unsigned addval_406(unsigned x)
{
    return x + 3281174921U;
}

unsigned addval_298(unsigned x)
{
    return x + 3380134281U;
}

unsigned getval_312()
{
    return 3286272328U;
}

unsigned addval_139(unsigned x)
{
    return x + 3682126473U;
}

unsigned addval_420(unsigned x)
{
    return x + 3767101693U;
}

unsigned getval_145()
{
    return 3398021000U;
}

unsigned getval_376()
{
    return 3599603943U;
}

void setval_433(unsigned *p)
{
    *p = 3348158089U;
}

void setval_390(unsigned *p)
{
    *p = 3767093733U;
}

unsigned addval_103(unsigned x)
{
    return x + 3527983497U;
}

unsigned addval_303(unsigned x)
{
    return x + 348373385U;
}

unsigned getval_277()
{
    return 3281049241U;
}

unsigned addval_153(unsigned x)
{
    return x + 3221804681U;
}

void setval_231(unsigned *p)
{
    *p = 2462746980U;
}

unsigned addval_287(unsigned x)
{
    return x + 2497743176U;
}

unsigned addval_209(unsigned x)
{
    return x + 2425539209U;
}

unsigned getval_365()
{
    return 3247489417U;
}

void setval_480(unsigned *p)
{
    *p = 3252717896U;
}

void setval_461(unsigned *p)
{
    *p = 3682912969U;
}

void setval_363(unsigned *p)
{
    *p = 3767093365U;
}

unsigned getval_187()
{
    return 3374369417U;
}

unsigned addval_285(unsigned x)
{
    return x + 3397928363U;
}

void setval_250(unsigned *p)
{
    *p = 3352725979U;
}

unsigned getval_117()
{
    return 3281043848U;
}

unsigned getval_487()
{
    return 3525362057U;
}

unsigned addval_435(unsigned x)
{
    return x + 3281043848U;
}

/* This function marks the end of the farm */
int end_farm()
{
    return 1;
}




