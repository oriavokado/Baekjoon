#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXNUM 1000
int is_prime(int k); //함수 미리 선언

int main(void) {

	int n, i, m=0;
	char num_str[MAXNUM];
	int num_list[MAXNUM];
	int count = 0;
	
	scanf("%d", &n); //숫자 1개(=입력할 숫자 개수)를 입력받아 n에 저장
	getchar(); //개행문자 처리

	if (n > MAXNUM) //예외 처리
		fprintf(stderr, "100 이하의 수 입력\n");

	fgets(num_str, MAXNUM, stdin); //숫자들을 입력받아 num_str에 저장

	char* token = strtok(num_str, " \t\n"); //개행문자 단위로 토큰화
	while (token != NULL) {
		num_list[m++] = atoi(token); //토큰을 정수로 변환하여 num_list에 저장
		token = strtok(NULL, " \t\n");
	}

	if (n != m) //앞서 입력한 숫자의 개수와 실제 개수가 맞는지 확인
		fprintf(stderr, "지정 개수에 맞게 숫자를 입력하시오\n");

	for (i = 0; i<m; i++) { //각 숫자를 num_list에서 하나씩 가져와서
		if (is_prime(num_list[i])) //소수인지 판별 -> 소수이면
			count++; //count를 +1
	}

	printf("%d", count); //for문을 모두 돌고 최종 count를 출력

	return 0;
}
int is_prime(int k) { //소수를 판별하는 함수

	if (k == 1) //0은 소수가 아니기 때문에 0 반환
		return 0;

	for (int i = 2; i < k; i++) { //k가 2~k-1로 나누어 떨어지는지 확인
		if (k % i == 0) //나누어 떨어지면 0 반환
			return 0;
	}
	return 1; //나눠지는 숫자가 없으면 1 반환
}
