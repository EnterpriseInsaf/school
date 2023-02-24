#include <stdio.h>

int main() {
	int name;
	printf("Напишите имя: ");
	scanf("%d", &name);
	printf("Hello, %i", &name);

	return 0;
}
