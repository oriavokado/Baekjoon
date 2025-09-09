#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 1000001 //최대 문자열 길이 지정(\n 포함)

int main(void) {

	char str[MAXLINE]; //입력 받을 문자열 정의
	int count = 0; //단어의 개수를 셀 변수 선언
	int now_word = 0; //플래그용 변수 선언 (단어 속에 있는지 아닌지)

	fgets(str, MAXLINE, stdin); //str에 입력받기
	str[strcspn(str, "\n")] = '\0'; //개행문자를 제거

	for (int i = 0; str[i] != '\0'; i++) { //문자열 전체를 돌며 i번째에 대해
		if (isspace(str[i]) == 0 && now_word == 0) { //공백이고 + 단어속이 아니면
			count++; //count를 +1
			now_word = 1; //단어 속으로 들어가니까 플래그를 1로 변경
		}
		else if (isspace(str[i])) //공백으로 빠져나왔을때
			now_word = 0; //단어 속에서 탈출했으니 플래그를 0으로 변경
	}

	printf("%d\n", count); //count 수를 출력
	return 0;
}
