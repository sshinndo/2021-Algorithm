#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int Z; //고정값 Z
int a_cnt = 0;
int z_cnt = 0;
double total = 1.0;
double sum = 0;
char hashcode[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

void find_hash(char elem) {
	for (int i = 0; i < 26; i++) {
		if (elem == hashcode[i]) {
			a_cnt = i;
			break;
		}
	}
	total = pow((double)Z, (double)z_cnt);
	sum += a_cnt*total;
	a_cnt = 0;
}

int main() {
	int N; // N개의 문자열
	int cnt = 0; //
	char str[11];

	scanf("%d %d", &N, &Z);
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (int j = 0; j < strlen(str); j++) {
			find_hash(str[j]);
			z_cnt++;
		}
		printf("%.0f\n", sum);
		sum = 0;
		z_cnt = 0;
	}
}
