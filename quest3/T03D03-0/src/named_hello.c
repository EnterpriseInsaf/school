#include <stdio.h>

/*int input();
int uotput(int* input);*/

int main() {
	/*int name;
	printf("Напишите имя: ");
	scanf("%d", &name);
	printf("Hello, ", name);*/
    int t;
	t = input();
	output(t);

	return 0;
}

int input(){
    int n;
    printf("Input you name: ");
    scanf("%d", &n);

    return n;
}

int output(int* input){
    printf("You name %d", input);
}
