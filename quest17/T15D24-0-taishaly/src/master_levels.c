#include "master_levels.h"
#include "binary_work.h"


void select_levels(FILE *pfile, int count) {
    int records_count = get_records_count_in_file(pfile, s_levels);
    if (count > records_count) {
        printf("n/a");
    } else {
        // printf("%zu\n", get_records_count_in_file(pfile, s_levels));
        printf("MEMORY_NUMBER\tCELLS_COUNT\tPROTECTION_FLAG\n");
        for (int i = 0; i < count; i++) {
            s_levels data = read_record_from_file(pfile, i, s_levels);
            print_levels(&data);
        }
    }
}

void print_levels(s_levels *s) {
    printf("%d\t\t%d\t\t%d\n", s->memory_number, s->cells_count, s->protection_flag);
}

int insert_level(FILE *pfile, s_levels *s) {
    int records_count = get_records_count_in_file(pfile, s_levels);
    int id = s->memory_number;
    int index = find_record(pfile, id, s_levels, memory_number);
    if (index == -1)
        write_record_in_file(pfile, s, records_count, s_levels);

    return index == -1 ? 0 : 1;
}

int update_level(FILE *pfile, int id, s_levels *s) {
    int error = 0;
    int index = find_record(pfile, id, s_levels, memory_number);
    if (index == -1)
        error = 1;

    if (!error) {
        write_record_in_file(pfile, s, index, s_levels);
    }

    return error;
}

int delete_level(FILE *pfile, int id) {
    int error = 0;
    int index = find_record(pfile, id, s_levels, memory_number);
    if (index == -1)
        error = 1;
    else
        remove_record(pfile, index, s_levels);

    return error;
}

int scanf_s_levels(s_levels *s) {
    printf("Insert the struct separated by comma:\n");
    int error = 0;

    if (scanf("%d,%d,%d", &(s->memory_number), &(s->cells_count), &(s->protection_flag)) != 3)
        error = 1;

    return error;
}

int set_protected_mode_by_id(FILE *pfile, int id) {
    int index = find_record(pfile, id, s_levels, memory_number);
    int error = 0;
    if (index == -1) {
        error = 1;
    } else {
        s_levels s = read_record_from_file(pfile, index, s_levels);
        s.protection_flag = 1;
        write_record_in_file(pfile, &s, index, s_levels);
    }

    return error;
}
