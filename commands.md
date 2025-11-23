commands:

Assemble asm File
```nasm -f win64 asmfunc.asm -o asmfunc.obj```

DEBUG
- Compile C File
- ```gcc -c main.c -o main.obj -m64 -O0 -g```

- Link the obj files
- ```gcc main.obj asmfunc.obj -o MCO2_Debug.exe -m64```

RELEASE
- Compile C File
- ```gcc -c main.c -o main.obj -m64 -O3```

- Link the obj files
- ```gcc main.obj asmfunc.obj -o MCO2_Release.exe -m64```
