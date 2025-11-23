### How to Compile and Run using Terminal:

1. ASSEMBLE
* Assemble asm File: ```nasm -f win64 asmfunc.asm -o asmfunc.obj```

2. COMPILE
* DEBUG
    * Compile C File: ```gcc -c main.c -o main.obj -m64 -O0 -g```
    * Link the obj files: ```gcc main.obj asmfunc.obj -o MCO2_Debug.exe -m64```

* RELEASE
    * Compile C File: ```gcc -c main.c -o main.obj -m64 -O3```
    * Link the obj files: ```gcc main.obj asmfunc.obj -o MCO2_Release.exe -m64```
 3. RUN
* Run program: ```MCO2_<Debug/Release>.exe```
