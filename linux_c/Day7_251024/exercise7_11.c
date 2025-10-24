// 매개 변수가 없는 함수

#include<stdio.h>

int get_num(void);

int main (void){

int result;

result = get_num();
printf("반환값 : %d\n", result);
return 0;

}

int get_num(void){

    int num;

    printf("양수 입력 : ");
    scanf("%d", &num);

    return num;

}

// 반환형에 void를 적는다.
// return문이 없으며 함수의 실행을 끝내면 자동으로 반환한다.
// 함수의 중간에서 반환할 때는 값 없이 return문만 사용한다.
// 호출문을 수식과 함께 사용할 수 없다.