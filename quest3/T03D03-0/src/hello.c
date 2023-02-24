#include <stdio.h>

int main() {
	int m[3][3];

	for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            m[i][k] = 5;
            printf("%d\t", m[i][k]);
        }
        printf("\n");
	}

	return 0;
}
