// 재귀 호출

void fruit(int count){
printf("apple\n");
if(count==3) return;
fruit(count+1);
printf("jam\n");
}

// fruit(1) 호출

// printf("apple\n"); -> "apple" 출력
// count (1)은 3이 아니므로 if문을 건너뛰고 다음 줄로.
// fruit(count+1); -> fruit(2) 호출 (이 시점에서 fruit(1)은 잠시 멈춰서 fruit(2)가 끝나기를 기다립니다.)
// fruit(2) 호출 (1단계에서 호출됨)

// printf("apple\n"); -> "apple" 출력
// count (2)는 3이 아니므로 if문을 건너뛰고 다음 줄로.
// fruit(count+1); -> fruit(3) 호출 (이 시점에서 fruit(2)는 잠시 멈춰서 fruit(3)가 끝나기를 기다립니다.)
// fruit(3) 호출 (2단계에서 호출됨)

// printf("apple\n"); -> "apple" 출력
// count (3)은 3과 같으므로 if(count==3)이 참이 됩니다.
// return; 실행 -> fruit(3) 함수는 즉시 종료됩니다. 이 fruit(3) 함수 내부의 printf("jam\n");은 실행되지 않아요.
// fruit(3)의 실행이 끝나고 호출했던 fruit(2)로 돌아갑니다.
// fruit(2) 재개 (3단계에서 fruit(3)가 끝나서 돌아옴)

// fruit(count+1); (즉, fruit(3)) 호출이 끝났습니다. 다음 줄인 printf("jam\n");을 실행합니다.
// printf("jam\n"); -> "jam" 출력
// fruit(2) 함수의 실행이 끝나고 호출했던 fruit(1)로 돌아갑니다.
// fruit(1) 재개 (4단계에서 fruit(2)가 끝나서 돌아옴)

// fruit(count+1); (즉, fruit(2)) 호출이 끝났습니다. 다음 줄인 printf("jam\n");을 실행합니다.
// printf("jam\n"); -> "jam" 출력
// fruit(1) 함수의 실행이 끝나고 호출했던 main 함수로 돌아갑니다.