#include <stdio.h>

int main(void) {
    int x = 10;
    int y = 5;

    // 대장님이 '이거겠지?' 라고 생각하는 코드 (하지만 실제로는 다르게 해석됩니다)
    if (x > 5)           // 1번 if
        if (y > 10)      // 2번 if
            printf("x는 5보다 크고, y는 10보다 크다.\n");
    else                 // ??? 이 else는 과연 1번 if에 붙을까요, 2번 if에 붙을까요?
        printf("x는 5보다 작거나 같다.\n");

    printf("\n");

    x = 3; // x를 3으로 바꿔서 다시 테스트
    y = 5;

    if (x > 5)           // 1번 if (거짓)
        if (y > 10)      // 2번 if (실행 안됨)
            printf("x는 5보다 크고, y는 10보다 크다.\n");
    else                 // ???
        printf("x는 5보다 작거나 같다.\n");
        
    return 0;
}