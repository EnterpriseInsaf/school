#include "modules.h"

void select_modules(FILE *pfile, int count) {
    int records_count = get_records_count_in_file(pfile, s_modules);
    if (count > records_count) {
        printf("n/a");
    } else {
        printf("ID\tNAME\t\t\t\tLEVEL\tCELL\tDELETE_FLAG\n");
        for (int i = 0; i < count; i++) {
            s_modules data = read_record_from_file(pfile, i, s_modules);
            print_modules(&data);
        }
    }
}

void print_modules(s_modules *s) {
    printf("%d\t%-30s  %d\t%d\t%d\n", s->id, s->name, s->level, s->cell, s->delete_flag);
}

int insert_module(FILE *pfile, s_modules *s) {
    int records_count = get_records_count_in_file(pfile, s_modules);
    int id_s = s->id;
    int index = find_record(pfile, id_s, s_modules, id);
    if (index == -1)
        write_record_in_file(pfile, s, records_count, s_modules);

    return index == -1 ? 0 : 1;
}

int update_module(FILE *pfile, int id_s, s_modules *s) {
    int error = 0;
    int index = find_record(pfile, id_s, s_modules, id);
    if (index == -1)
        error = 1;

    if (!error) {
        write_record_in_file(pfile, s, index, s_modules);
    }

    return error;
}

int delete_module(FILE *pfile, int id_s) {
    int error = 0;
    int index = find_record(pfile, id_s, s_modules, id);
    if (index == -1) {
        error = 1;
    } else {
        s_modules s = read_record_from_file(pfile, index, s_modules);
        if (s.delete_flag == 1) {
            remove_record(pfile, index, s_modules);
        } else {
            error = 1;
        }
    }
    return error;
}

int scanf_s_moudules(s_modules *s) {
    printf("Insert the struct separated by comma:\n");
    char name[30] = "";
    int error = 0;
    if (scanf("%d,", &(s->id)) != 1)
        error = 1;
    if (!error) {
        for (int i = 0, c = getchar(); c != ',' && c !='\n'; name[i++] = c, c = getchar()) { }
    }

    if (scanf("%d,%d,%d", &(s->level), &(s->cell), &(s->delete_flag)) != 3) {
        error = 1;
    }

    strcpy(s->name, name);
    return error;
}

int set_deleted_mode_by_id(FILE *pfile, int id_s) {
    int index = find_record(pfile, id_s, s_modules, id);
    int error = 0;
    if (index == -1) {
        error = 1;
    } else {
        s_modules s = read_record_from_file(pfile, index, s_modules);
        s.delete_flag = 0;
        write_record_in_file(pfile, &s, index, s_modules);
    }

    return error;
}

int set_level_and_cell(FILE *pfile, int id_s, int level, int cell) {
    int index = find_record(pfile, id_s, s_modules, id);
    int error = 0;
    if (index == -1) {
        error = 1;
    } else {
        s_modules s = read_record_from_file(pfile, index, s_modules);
        s.cell = cell;
        s.level = level;
        write_record_in_file(pfile, &s, index, s_modules);
    }

    return error;
}

void delete_modules_flag(FILE *pfile) {
    int records_count = get_records_count_in_file(pfile, s_modules);
    for (int i = 0; i < records_count; i++) {
        s_modules s = read_record_from_file(pfile, i, s_modules);
        s.delete_flag = 1;
        write_record_in_file(pfile, &s, i, s_modules);
    }
}
