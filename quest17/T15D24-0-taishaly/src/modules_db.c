// tut main i menu
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shared.h"

int main() {
    int error = 0;
    char code_string[11];
    int code = 0;
    while (code != -1) {
        printf("\nPlease choose one operation:\n");
        printf("\t\t1. SELECT\n\t\t2. INSERT\n\t\t3. UPDATE\n");
        printf("\t\t4. DELETE\n\t\t");
        printf("5. Get all active additional modules (last module status is 1)\n");
        printf("\t\t6. Delete modules by ids\n");
        printf("\t\t7. Set protected mode for module by id\n");
        printf("\t\t8. Move module by id to specified memory level and cell\n");
        printf("\t\t9. Set protection flag of the specified memory level\n");
        printf("\t\t999. KILL VERTER\n\nEnter -1 to exit\n");

        scanf("%10s", code_string);
        code = atoi(code_string);

        if (code == 1) {
            error = select();
        } else if (code == 2) {
            error = insert();
        } else if (code == 3) {
            error = update();
        } else if (code == 4) {
            error = delete();
        } else if (code == 5) {
            select_additional_modules();
        } else if (code == 6) {
            error = delete_modules();
        } else if (code == 7) {
            error = set_protected_mode_module();
        } else if (code == 8) {
            error = move_module_to();
        } else if (code == 9) {
            error = set_protected_flag_level();
        } else {
            error = 1;
        }

        if (code != -1 && error)
            printf("n/a\n");
    }

    return 0;
}
