#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int A[100] = { 0 };
int B[100] = { 0 }; //A: 수를 저장할 배열 B: Merge에 필요한 배열

void Merge(int low, int mid, int high) {
	int i;
	int left = low; //왼쪽리스트 인덱스를 low로 초기화
	int right = mid + 1; // 오른쪽 리스트 인덱스를 mid+1로 초기화
	for (i = low; i <= high; i++) {
		if (left > mid) { //왼쪽lsit가 모두 배열B로 이동했을 때
			while (right <= high) {
				B[i] = A[right];
				i++; right++;
			}
			break;
		}
		if (right > high) { //오른쪽list가 모두 배열 B로 이동했을때
			while (left <= mid) {
				B[i] = A[left];
				i++; left++;
			}
		}
		if (A[left] > A[right]) {
			B[i] = A[right];
			right++;
		}
		else {
			B[i] = A[left];
			left++;
		}
	}
	for (i = 0; i <= high; i++) {
		A[i] = B[i];
	}
}
int main() {
	int n;
	int i;
	int l=1; // 길이가 l인 이웃한 리스트들을 2개씩 병합시키기
	int high; // 정렬을 요청할 때 가장 마지막 index
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	while (1) {
		for (int idx = 0; idx < n; idx = idx + l * 2) {
			high = idx + l * 2 - 1;
			if (high >= n) {
				high = n - 1;
			}
			Merge(idx, idx + l - 1, high);
		}
		l = l * 2;
		if (l >= n) break;
	}//정렬 과정

	for (i = 0; i <= high; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");

	return 0;
}
