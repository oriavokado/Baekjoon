#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct resistance { //저항에 대한 구조체 선언
	char colorname[50]; //색상
	int value; //값
	int mul; //곱
};

int main(void) {

	char color[3][50]; //입력으로 받을 색상에 대한 배열 선언
	int i, value1=-1, value2=-1; //각각의 값을 담을 변수 선언
	long long multiplier=-1, sum = 0; //곱을 담을 변수 및 저항값을 담을 변수 선언
	struct resistance RESIS[10] = { {"black", 0, 1}, {"brown", 1,10}, {"red", 2, 100},
		{"orange",3,1000}, {"yellow",4,10000}, {"green", 5, 100000}, {"blue", 6, 1000000},
		{"violet", 7, 10000000}, {"grey", 8, 100000000}, {"white", 9, 1000000000} }; //색상별로 관련 값을 가지는 구조체 배열 생성 + 값 초기화
	
	for (i = 0; i < 3; i++) { //이용자로부터 색상을 3번 입력받아 color 배열에 하나씩 저장
		scanf("%s", color[i]);
	}

	for (i = 0; i < 10; i++) { //구조체 배열을 돌면서
		if (!strcmp(RESIS[i].colorname, color[0])) { //colo[0]r와 colorname이 같을 때 그 colorname에 대한 value를 받아둠(x10)
			value1= RESIS[i].value * 10;
		}
		if (!strcmp(RESIS[i].colorname, color[1])) { //colo[1]r와 colorname이 같을 때 그 colorname에 대한 value를 받아둠
			value2= RESIS[i].value;
		}
		if (!strcmp(RESIS[i].colorname, color[2])) { //color[2]와 colorname이 같을 때 그 colorname의 mul를 받아둠
			multiplier = RESIS[i].mul;
		}
	}

	if (value1 == -1 || value2 == -1 || multiplier == -1) { //value와 multiplier 중 초기값에서 변하지 않은 것이 있다면 오류 문구 출력
		fprintf(stderr, "존재하지 않는 저항의 색입니다.");
		exit(1);
	}
	
	sum = (value1 + value2) * multiplier; //최종 저항값 구하기 (value1은 미리 10을 곱해두었으니 여기서는 x)

	printf("%lld", sum); //최종 저항값 출력

	return 0;
}
