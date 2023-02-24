#include "binary_work.h"
#include <unistd.h>
/*
// Function of writing a record of the specified type to the file at the specified serial number.

// Function of mutual transfer of two records in the file by their indexes.
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    // Read both records from file to variables
    struct data_record record1 = read_record_from_file(pfile, record_index1);
    struct data_record record2 = read_record_from_file(pfile, record_index2);

    // Rewrite records in file
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}*/

// Function to get file size in bytes.
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(pfile);        // Read the number of bytes from
                                // the beginning of the file to the current position pointer.
    rewind(pfile);              // For safety reasons, move the position pointer
                                // back to the beginning of the file.

    return size;
}

// Function to get count of records in file

/*
void print_file(FILE *pfile) {
    int records_count = get_records_count_in_file(pfile);

    for (int i = 0; i < records_count; i++) {
        struct data_record data = read_record_from_file(pfile, i);
        printf("%d %d %d %d %d %d %d %d", data.year, data.month, data.day,
           data.hour, data.minute, data.second, data.status, data.code);

        if (i != records_count - 1)
            printf("\n");
    }
}

void sort_file(FILE *pfile) {
    int records_count = get_records_count_in_file(pfile);

    for (int i = 0; i < records_count; i++) {
        int min_j = i;
        struct data_record min_record_j = read_record_from_file(pfile, i);
        for (int j = i + 1; j < records_count; j++) {
            struct data_record record_j = read_record_from_file(pfile, j);
            if (less_record(record_j, min_record_j)) {
                min_j = j;
                min_record_j = record_j;
            }
        }
        swap_records_in_file(pfile, i, min_j);
    }
}

int is_empty(FILE *pfile) { return get_records_count_in_file(pfile) == 0; }

int less_record(struct data_record r1, struct data_record r2) {
    return r1.year < r2.year || (r1.year == r2.year && (r1.month < r2.month ||
           (r1.month == r2.month && (r1.day < r2.day || (r1.day == r2.day &&
           (r1.hour < r2.hour || (r1.hour == r2.hour && (r1.minute < r2.minute ||
           (r1.minute == r2.minute && r1.second < r2.second)))))))));
}

int equal_record(struct data_record r1, struct data_record r2) {
    return r1.year == r2.year && r1.month == r2.month && r1.day == r2.day &&
           r1.hour == r2.hour && r1.minute == r2.minute && r1.second == r2.second;
}

int equal_date(struct data_record r1, struct data_record r2) {
    return r1.year == r2.year && r1.month == r2.month && r1.day == r2.day;
}

int find_record(FILE *pfile, struct data_record data, int *error) {
    int record_count = get_records_count_in_file(pfile);

    int code = 0;
    int is_finded = 0;
    for (int i = 0; !is_finded && i < record_count; i++) {
        struct data_record record = read_record_from_file(pfile, i);
        if (equal_date(record, data)) {
            is_finded = 1;
            code = record.code;
        }
    }

    if (!is_finded) {
        *error = 1;
    }

    return code;
}

int less_date(struct data_record r1, struct data_record r2) {
    return r1.year < r2.year || (r1.year == r2.year && (r1.month < r2.month ||
           (r1.month == r2.month && r1.day < r2.day)));
}

void remove_records(FILE *pfile, struct data_record from, struct data_record to) {
    int record_count = get_records_count_in_file(pfile);

    int i = 0, j = 0;
    for (; j < record_count; j++) {
        struct data_record record = read_record_from_file(pfile, j);
        if ((less_date(from, record) || equal_date(from, record)) && (!less_date(to, record))) {
            // just skip
        } else {
            write_record_in_file(pfile, &record, i);
            i++;
        }
    }

    ftruncate(fileno(pfile), (record_count - (j - i)) * sizeof(struct data_record));
}
*/
