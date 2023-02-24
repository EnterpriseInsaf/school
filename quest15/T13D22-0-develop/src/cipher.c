#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <dirent.h>

#include "logger.h"

void menu();
void name_text(char* name_txt);
void read_text(char* name_txt, int* flag);
void input_text(char* name_txt, int* check);
void path_check(char* name_txt, int *flag);
void shift(int *shiftt);
void finder(char *dir_path, int shift);
void caesar(char *cs_in, char *cs_out, int shift);
void flag_checker(int flag);

int main(){
    menu();

    return 0;
}

void menu(){
    int check = 1, user = 0, flag = 0, shift1;
    user = scanf("%d", &check);
    char name_txt[256];
    while (check != -1)
    {
        if(user == 1 && (check == 1 || check == 2 || check == 3)){
            switch (check)
            {
            case 1: {
                name_text(name_txt);
                path_check(name_txt, &flag);
                read_text(name_txt, &flag);
                flag_checker(flag);
                break;
            }
            case 2: {
                input_text(name_txt, &flag);
                read_text(name_txt, &flag);
                flag_checker(flag);
                break;
            }
            case 3: {
                name_text(name_txt);
                shift(&shift1);
                finder(name_txt, shift1);
                break;
            }
            default: printf("n/a\n"); break;
            }
        }else{
            printf("n/a\n");
            scanf("%*[^\n]");
        }
        user = scanf("%d", &check);
    }
}

void flag_checker(int flag) {
    if (flag == 1)
        printf("n/a\n");
}

void name_text(char* name_txt){
    scanf("%s", name_txt);
}

void shift(int *shiftt) {
    scanf("%d", shiftt);
}

void path_check(char *name_txt, int *flag) {
    int sn = strlen(name_txt);
    if (name_txt[sn - 1] == 't' && name_txt[sn - 2] == 'x' &&
    name_txt[sn - 3] == 't' && name_txt[sn - 4] == '.')
        *flag = 0;
    else
        *flag = 1;
}

void read_text(char* name_txt, int* flag){
    FILE *ptrf = fopen(name_txt, "r");
        char ch;
        if (ptrf != NULL) {
            ch = fgetc(ptrf);
            if (ch != EOF) {
                while (ch != EOF) {
                    putchar(ch);
                    ch = fgetc(ptrf);
                }
                putchar('\n');
            } else {
                *flag = 0;
                printf("n/a\n");
            }
        } else {
            *flag = 1;
        }
        fclose(ptrf);
}

void input_text(char* name_txt, int* flag){
    char ch, ch1;
    if (*flag != 1) {
        FILE *ptrf = fopen(name_txt, "a");
        if (ptrf != NULL) {
            ch1 = getchar();
            while ((ch = getchar()) != '\n') {
                fputc(ch, ptrf);
            }
        } else {
                *flag = 1;
                ch1 = getchar();
                ch1 = ' ';
                while (ch1 != '\n') {
                ch1 = getchar();
                }
        }
        fclose(ptrf);
    } else {
        ch1 = getchar();
        ch1 = ' ';
        while (ch1 != '\n') {
            ch1 = getchar();
        }
    }
}

void finder(char *dir_path, int shift) {
    char *ptr1, *ptr2, *cs_in, *clean_in;
    char dir_path_cp[256], dir_path_cp1[256];
    DIR *dr;
    int rn;
    struct dirent *drr;
    dr = opendir(dir_path);
    if (dr != NULL) {
        while ((drr = readdir(dr)) != NULL) {
            ptr1 = strtok(drr -> d_name, ".");
            ptr2 = strtok(NULL, ".");
            if (ptr2 != NULL) {
                rn = strcmp(ptr2, "c");
                if (rn == 0) {
                    cs_in = strcat(ptr1, ".c");
                    strcpy(dir_path_cp, dir_path);
                    cs_in = strcat(dir_path_cp, cs_in);
                    caesar(cs_in, ptr1, shift);
                    remove(cs_in);
                    rename(ptr1, cs_in);
                }
                rn = strcmp(ptr2, "h");
                if (rn == 0) {
                    clean_in = strcat(ptr1, ".h");
                    strcpy(dir_path_cp1, dir_path);
                    clean_in = strcat(dir_path_cp1, clean_in);
                    FILE *cl_aim = fopen(clean_in, "wb");
                    fclose(cl_aim);
                }
            }
        }
        closedir(dr);
    } else {
        printf("n/a\n");
    }
}

void caesar(char *cs_in, char *cs_out, int shift) {
    FILE *file1, *file2;
    file1 = fopen(cs_in, "r");
    file2 = fopen(cs_out, "w");
    char ch;
    ch = getc(file1);
    while (ch != EOF) {
        ch = ((ch + shift) % 125);
        fputc(ch, file2);
        ch = getc(file1);
    }
    fclose(file1);
    fclose(file2);
}
