#ifndef SRC_BINARY_WORK_H_
#define SRC_BINARY_WORK_H_

#include <stdio.h>
#include <unistd.h>

#define get_records_count_in_file(pfile, type) ({                           \
    get_file_size_in_bytes(pfile) / sizeof(type);                           \
})

#define read_record_from_file(pfile, index, type) ({                        \
    int offset = index * sizeof(type);                                      \
    fseek(pfile, offset, SEEK_SET);                                         \
    type record;                                                            \
    fread(&record, sizeof(type), 1, pfile);                                 \
    rewind(pfile);                                                          \
    record;                                                                 \
})

#define find_record(pfile, ident, type, id_name) ({                         \
    int record_count = get_records_count_in_file(pfile, type);              \
    int index = -1;                                                         \
    int is_finded = 0;                                                      \
    for (int i = 0; !is_finded && i < record_count; i++) {                  \
        type record = read_record_from_file(pfile, i, type);                \
        if (record.id_name == ident) {                                      \
            is_finded = 1;                                                  \
            index = i;                                                      \
        }                                                                   \
    }                                                                       \
    index;                                                                  \
})

#define write_record_in_file(pfile, record_to_write_prt, index, type) ({    \
    int offset = (index) * sizeof(type);                                    \
    fseek(pfile, offset, SEEK_SET);                                         \
    fwrite(record_to_write_prt, sizeof(type), 1, pfile);                    \
    fflush(pfile);                                                          \
    rewind(pfile);                                                          \
})

#define remove_record(pfile, index, type) ({                                \
    int record_count = get_records_count_in_file(pfile, type);              \
    for (int j = (index) + 1; j < record_count; j++) {                      \
        type record = read_record_from_file(pfile, j, type);                \
        write_record_in_file(pfile, &record, j - 1, type);                  \
    }                                                                       \
    ftruncate(fileno(pfile), (record_count - 1) * sizeof(type));            \
})

void print_file(FILE *pfile);
void sort_file(FILE *pfile);
int is_empty(FILE *pfile);
// struct data_record read_record_from_file(FILE *pfile, int index);
// void write_record_in_file(FILE *pfile, const struct data_record *record_to_write, int index);
// void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
// int less_record(struct data_record r1, struct data_record r2);
// int equal_record(struct data_record r1, struct data_record r2);
// int equal_date(struct data_record r1, struct data_record r2);
// int less_date(struct data_record r1, struct data_record r2);
// int find_record(FILE *pfile, struct data_record data, int *error);
// void remove_records(FILE *pfile, struct data_record from, struct data_record to);

#endif  // SRC_BINARY_WORK_H_
