#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int a, b, count, mid;
	char str[100];
	scanf("%d %d %d", &a, &b, &count);
	getchar();
	scanf("%s", str);

	for (int i = 0; i < count; i++) {
		mid = (a + b) / 2;
		if (str[i] == 'N') {
			b = mid;
		}
		else if (str[i] == 'Y') {
			a = mid + 1;
		}
		if (a == b) {
			printf("%d", a);
			return 0;
		}
	}	
}
