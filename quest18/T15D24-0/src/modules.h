#ifndef SRC_MODULES_H_
#define SRC_MODULES_H_

#include "libs.h"
#include <stdio.h>

typedef struct master_modules {
    int id;
    char name[30];
    int level;
    int cell;
    int delete_flag;
} s_modules;

void select_modules(FILE *pfile, int count);
int insert_module(FILE *pfile, s_modules *s);
void print_modules(s_modules *s);
int scanf_s_moudules(s_modules *s);
int update_module(FILE *pfile, int id, s_modules *s);
int delete_module(FILE *pfile, int id);

int set_deleted_mode_by_id(FILE *pfile, int id);
int set_level_and_cell(FILE *pfile, int id, int level, int cell);

void delete_modules_flag(FILE *pfile);

#endif
