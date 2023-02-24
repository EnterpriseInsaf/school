#ifndef SRC_MASTER_LEVELS_H_
#define SRC_MASTER_LEVELS_H_

#include <stdio.h>


typedef struct master_levels {
    int memory_number;
    int cells_count;
    int protection_flag;
} s_levels;

void select_levels(FILE *pfile, int count);
int insert_level(FILE *pfile, s_levels *s);
void print_levels(s_levels *s);
int scanf_s_levels(s_levels *s);
int update_level(FILE *pfile, int id, s_levels *s);
int delete_level(FILE *pfile, int id);

int set_protected_mode_by_id(FILE *pfile, int id);

#endif  // SRC_MASTER_LEVELS_H_
