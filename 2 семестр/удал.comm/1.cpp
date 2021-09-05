#include "my_lab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void deleteComments(FILE* fr, FILE* fw) {

    bool StringComment = false;
    bool inComment = false;

    char* buff = (char*)malloc(100 * sizeof(char));
    if (!buff)
        return;
    /*dnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkbdnkb*/
    int i = 0;
    while (true) {
        //djdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacndjdsjacn
        //gfdk
        /*///*/int k;
        if (!fgets(buff,/*sjdk*/ 100, fr)) //fdsk.m//fdskl           

            break;
        i = 0;
        while (buff[i] != '\0')
        {
            if (((((buff[i] == '/' && buff[i + 1] == '/') || StringComment) && !inComment))) {

                if (!StringComment)
                    fputc('\n', fw);
                StringComment = true;
                break;
            }


            /*if (buff[i] == '/' && buff[i + 1] == '*')

                inComment2 = true;*/
            if (buff[i] == '*' && buff[i + 1] == '/' && inComment) {
                i += 2;
                inComment = false;
                continue;

            }

            if (buff[i] == '/' && buff[i + 1] == '*' && !inComment)
            {
                inComment = true;
                i++;
            }

            if (!inComment)
                fputc(buff[i], fw);

            i++;
        }
        if (buff[strlen(buff) - 1] == '\n') {//dsajkds,a/*
            /**/    StringComment = false;
        }

    }//gfd/*/
    /*/*/free(buff);
}