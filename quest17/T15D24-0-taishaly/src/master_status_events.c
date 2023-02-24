#include "master_status_events.h"
#include "binary_work.h"
#include <string.h>


void select_status_events(FILE *pfile, int count) {
    int records_count = get_records_count_in_file(pfile, s_status_events);
    if (count > records_count) {
        printf("n/a");
    } else {
        // printf("%zu\n", get_records_count_in_file(pfile, s_status_events));
        printf("EVENT_ID\tMODULE_ID\tNEW_MODULE_STATUS\tCHANGE_DATE\tCHANGE_TIME\n");
        for (int i = 0; i < count; i++) {
            s_status_events data = read_record_from_file(pfile, i, s_status_events);
            print_status_events(&data);
        }
    }
}

void print_status_events(s_status_events *s) {
    printf("%d\t\t%d\t\t%d\t\t\t%-10s\t%-8s\n", s->event_id, s->module_id,
            s->new_module_status, s->change_date, s->change_time);
}

int insert_status_events(FILE *pfile, s_status_events *s) {
    int records_count = get_records_count_in_file(pfile, s_status_events);
    int id = s->event_id;
    int index = find_record(pfile, id, s_status_events, event_id);
    if (index == -1)
        write_record_in_file(pfile, s, records_count, s_status_events);

    return index == -1 ? 0 : 1;
}

int update_status_events(FILE *pfile, int id, s_status_events *s) {
    int error = 0;
    int index = find_record(pfile, id, s_status_events, event_id);
    if (index == -1)
        error = 1;

    if (!error) {
        write_record_in_file(pfile, s, index, s_status_events);
    }

    return error;
}

int delete_status_events(FILE *pfile, int id) {
    int error = 0;
    int index = find_record(pfile, id, s_status_events, event_id);
    if (index == -1)
        error = 1;
    else
        remove_record(pfile, index, s_status_events);

    return error;
}

int scanf_s_status_events(s_status_events *s) {
    printf("Insert the struct separated by comma:\n");
    int error = 0;
    char time[9] = "";
    char date[11] = "";

    if (scanf("%d,%d,%d,", &(s->event_id), &(s->module_id), &(s->new_module_status)) != 3)
        error = 1;
    int hh, mm, ss, d, m, y;
    if (scanf("%d.%d.%d,%d:%d:%d", &d, &m, &y, &hh, &mm, &ss) != 6 ||
        !(0 <= d && d <= 31) || !(0<= m && m <= 12) || y < 0 ||
        !(0 <= hh && hh <= 23) || !(0 <= mm && mm <= 59) || !(0 <= ss && ss <= 59))
        error = 1;
    if (!error) {
        sprintf(date, "%02d.%02d.%04d", d, m, y);
        sprintf(time, "%02d:%02d:%02d", hh, mm, ss);
    }

    strcpy(s->change_date, date);
    strcpy(s->change_time, time);

    return error;
}

void select_status_events_equal_1(FILE *pfile) {
    int records_count = get_records_count_in_file(pfile, s_status_events);
    printf("EVENT_ID\tMODULE_ID\tNEW_MODULE_STATUS\tCHANGE_DATE\tCHANGE_TIME\n");
    for (int i = 0; i < records_count; i++) {
        s_status_events data = read_record_from_file(pfile, i, s_status_events);
        if (data.new_module_status == 1) {
            print_status_events(&data);
        }
    }
}

void off_modules(FILE *pfile) {
    int records_count = get_records_count_in_file(pfile, s_status_events);
    for (int i = 0; i < records_count; i++) {
        s_status_events s = read_record_from_file(pfile, i, s_status_events);
        s.new_module_status = 0;
        write_record_in_file(pfile, &s, i, s_status_events);
    }
}

void change_status_main(FILE *pfile, int status) {
    int index = find_record(pfile, 0, s_status_events, module_id);

    s_status_events s = read_record_from_file(pfile, index, s_status_events);
    s.new_module_status = status;
    write_record_in_file(pfile, &s, index, s_status_events);
}
