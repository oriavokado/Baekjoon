#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
int to_result(int n, int* divisor);
int compare(const void* a, const void* b);

int main(void) {

	int n, j=0, result;
	int* divisor;
	char tmp[1024];

	scanf("%d", &n); //약수의 개수를 입력받음
	if (n > 50) { //50이상일 경우 오류문구 출력 후 종료
		fprintf(stderr, "50 이하의 자연수를 입력하세요");
		exit(1);
	}

	divisor = (int*)malloc(sizeof(int) * n); //약수의 개수에 맞춰 약수를 넣을 포인터 크기를 세팅
	
	getchar(); //개행문자 처리
	fgets(tmp, 1024, stdin); //약수들의 받아서 tmp에 저장

	char* token = strtok(tmp, " \t\n"); //tmp를 토큰 단위로 토큰화하여
	while (token!=NULL) {
		divisor[j++] = atoi(token); //각 토큰을 int로 변환하여 divisor에 저장
		token = strtok(NULL, " \t\n");
	}

	if (n != j) { //처음 입력한 토큰의 개수와 실제 입력 개수가 동일한지 확인
		fprintf(stderr, "첫 줄에 입력한 개수에 맞게 약수들을 입력하세요");
		exit(1);
	}

	for (int i = 0; i<n; i++) { //진약수들의 리스트를 돌며
		if (divisor[i] > MAX) { //최대 가능한 값보다 큰 값이 있다면 오류 문구 출력 후 종료
			fprintf(stderr, "1000000 이하의 약수를 입력하세요");
			exit(1);
		}
	}

	qsort(divisor, n, sizeof(int), compare); //약수들의 배열을 오름차순으로 정렬
	printf("%d", to_result(n, divisor)); //to_result함수의 반환값을 최총 출력

	return 0;
}

int to_result(int n, int* divisor) {
	if (n == 1) //약수의 개수가 1개면
		return divisor[0] * divisor[0]; //그 약수를 제곱해서 반환
	else //그 외의 경우
		return divisor[0] * divisor[n - 1]; //가장 작은 약수와 가장 큰 약수를 곱한 값을 반환
}
int compare(const void *a, const void *b) { //오름차순 정렬 함수
	return *(int*)a - *(int*)b;
}
