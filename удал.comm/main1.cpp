#define _CRT_SECURE_NO_WARNINGS
#include "my_lab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        printf("Filename is not set,\nCorrect input for example: Project10.exe ../Project10/my_lab.cpp ../Project10/Qw.txt ");
        exit(1);
    }
    
    FILE* fr = fopen(argv[1], "r");
    if (!fr) {
        puts("The file was not detected");
        exit(1);
    }
        FILE* fw = fopen(argv[2], "w");
        if (!fw) {
            puts("The file was not created");
            exit(1);
        }
           deleteComments(fr,fw);
    fclose(fr);
    fclose(fw);
    printf("Okey ");
    return 0;
} 
    //C:\Users\Honor>cd /d D:\Лабы инфа\Project10\Debug
//D:\Лабы инфа\Project10\Debug > Project10.exe
//Filename is not set
//D : \Лабы инфа\Project10\Debug > Project10.exe ../Project10/my_lab.cpp ../Project10/Qw.txt
//Okey