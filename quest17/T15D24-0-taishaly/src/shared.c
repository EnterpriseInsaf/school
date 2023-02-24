#include "shared.h"
#include "master_modules.h"
#include "master_levels.h"
#include "master_status_events.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int select() {
    int no_error = 1;
    int database = menu();
    FILE *pfile;

    printf("Insert the number of records or leave empty to output all of them: ");
    int count;
    if (scanf("%d", &count) != 1 || count < 0)
        no_error = 0;
    if (database == 1) {
        pfile = fopen("../materials/master_modules.db", "rb");
        select_modules(pfile, count);
    } else if (database == 2) {
        pfile = fopen("../materials/master_levels.db", "rb");
        select_levels(pfile, count);
    }  else if (database == 3) {
        pfile = fopen("../materials/master_status_events.db", "rb");
        select_status_events(pfile, count);
    } else {
        no_error = 0;
    }

    fclose(pfile);
    return !no_error;
}

int insert() {
    int error = 0;
    int database = menu();
    FILE *pfile;

    if (database == 1) {
        s_modules s;
        error = scanf_s_moudules(&s);
        pfile = fopen("../materials/master_modules.db", "rb+");

        if (!error)
            error = insert_module(pfile, &s);
    } else if (database == 2) {
        s_levels s;
        error = scanf_s_levels(&s);
        pfile = fopen("../materials/master_levels.db", "rb+");

        if (!error)
            error = insert_level(pfile, &s);
    } else if (database == 3) {
        s_status_events s;
        error = scanf_s_status_events(&s);
        pfile = fopen("../materials/master_status_events.db", "rb+");

        if (!error)
            error = insert_status_events(pfile, &s);
    } else {
        error = 1;
    }
    fclose(pfile);

    return error;
}

int update() {
    int error = 0;
    int database = menu();
    FILE *pfile;

    if (database == 1) {
        s_modules s;
        int id;
        printf("Enter the id of updated record: ");
        if (scanf("%d", &id) != 1)
            error = 1;
        error &= scanf_s_moudules(&s);
        pfile = fopen("../materials/master_modules.db", "rb+");

        if (!error)
            error = update_module(pfile, id, &s);
    } else if (database == 2) {
        s_levels s;
        int id;
        printf("Enter the memory number of updated record: ");
        if (scanf("%d", &id) != 1)
            error = 1;
        error &= scanf_s_levels(&s);
        pfile = fopen("../materials/master_levels.db", "rb+");

        if (!error)
            error = update_level(pfile, id, &s);
    } else if (database == 3) {
        s_status_events s;
        int id;
        printf("Enter the event id of updated record: ");
        if (scanf("%d", &id) != 1)
            error = 1;
        error &= scanf_s_status_events(&s);
        pfile = fopen("../materials/master_status_events.db", "rb+");

        if (!error)
            error = update_status_events(pfile, id, &s);
    } else {
        error = 1;
    }
    fclose(pfile);

    return error;
}

int delete() {
    int error = 0;
    int database = menu();
    FILE *pfile;

    if (database == 1) {
        int id;
        printf("Enter the id of deleted record: ");
        if (scanf("%d", &id) != 1)
            error = 1;

        pfile = fopen("../materials/master_modules.db", "rb+");

        if (!error)
            error = delete_module(pfile, id);
    } else if (database == 2) {
        int id;
        printf("Enter the memory number of deleted record: ");
        if (scanf("%d", &id) != 1)
            error = 1;

        pfile = fopen("../materials/master_levels.db", "rb+");

        if (!error)
            error = delete_level(pfile, id);
    } else if (database == 3) {
        int id;
        printf("Enter the event id of deleted record: ");
        if (scanf("%d", &id) != 1)
            error = 1;

        pfile = fopen("../materials/master_status_events.db", "rb+");

        if (!error)
            error = delete_status_events(pfile, id);
    } else {
        error = 1;
    }

    fclose(pfile);
    return error;
}

void select_additional_modules() {
    FILE *pfile = fopen("../materials/master_status_events.db", "rb");
    select_status_events_equal_1(pfile);
    fclose(pfile);
}

int set_protected_flag_level() {
    int error = 0;
    int id;
    printf("Enter the module id to set it protected: ");
    if (scanf("%d", &id) != 1)
        error = 1;

    if (!error) {
        FILE *pfile = fopen("../materials/master_levels.db", "rb+");
        error = set_protected_mode_by_id(pfile, id);
        fclose(pfile);
    }

    return error;
}

int set_protected_mode_module() {
    int error = 0;
    int id;
    printf("Enter the module id to set it protected: ");
    if (scanf("%d", &id) != 1)
        error = 1;

    if (!error) {
        FILE *pfile = fopen("../materials/master_modules.db", "rb+");
        error = set_deleted_mode_by_id(pfile, id);
        fclose(pfile);
    }

    return error;
}

int delete_modules() {
    char ids[101];
    char *token;
    int error = 0;
    printf("Enter the module ids to deleting, separated by comma:\n");
    scanf("%100s", ids);
    printf("%s\n", ids);
    FILE *pfile = fopen("../materials/master_modules.db", "rb+");

    token = strtok(ids, ",");

    while (!error && (token != NULL)) {
        int id = atoi(token);

        if (id == 0 && !(strlen(ids) == 1 && ids[0] == '0')) {
            error = 0;
        } else {
            error = delete_module(pfile, id);
        }
        token = strtok(NULL, ",");
    }

    fclose(pfile);

    return error;
}

int move_module_to() {
    int id;
    int error = 0;
    printf("Enter the module id to set its level and cell: ");
    if (scanf("%d", &id) != 1)
        error = 1;

    int level, cell;
    printf("Enter level and cell: ");
    if (scanf("%d%d", &level, &cell) != 2)
        error = 1;

    FILE *pfile = fopen("../materials/master_modules.db", "rb+");

    if (!error) {
        error = set_level_and_cell(pfile, id, level, cell);
    }

    fclose(pfile);

    return error;
}

int menu() {
    printf("Please choose a table:\n");
    printf("\t\t1. Modules\n\t\t2. Levels\n");
    printf("\t\t3. Status events\n");

    int database;
    if (scanf("%d", &database) != 1)
        database = 0;

    return database;
}
