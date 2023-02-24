#ifndef SRC_MASTER_STATUS_EVENTS_H_
#define SRC_MASTER_STATUS_EVENTS_H_

#include <stdio.h>


typedef struct master_status_events {
    int event_id;
    int module_id;
    int new_module_status;
    char change_date[11];
    char change_time[9];
} s_status_events;

void select_status_events(FILE *pfile, int count);
int insert_status_events(FILE *pfile, s_status_events *s);
void print_status_events(s_status_events *s);
int scanf_s_status_events(s_status_events *s);
int update_status_events(FILE *pfile, int id, s_status_events *s);
int delete_status_events(FILE *pfile, int id);

void select_status_events_equal_1(FILE *pfile);

void off_modules(FILE *pfile);
void change_status_main(FILE *pfile, int status);

#endif  // SRC_MASTER_STATUS_EVENTS_H_
