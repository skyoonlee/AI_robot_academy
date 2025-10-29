#include <stdio.h>
#include <string.h>

typedef struct student{

    int num;
    char name[20];
    int score[3];
    double total;
    char grade;

}stdt;

void print_data(stdt *ps);
double sum_score(stdt *ps);
double avg_score(stdt *ps);
char grade_res(stdt *ps);

int main(void){

    stdt s[5];
    stdt temp;

        for(int i=0; i<5; i++){
        
            printf("학번 : ");
            scanf("%d", &s[i].num);

            printf("이름 : ");
            scanf("%s", s[i].name);

            printf("국어, 영어, 수학 점수 : ");
            scanf("%d %d %d", &s[i].score[0], &s[i].score[1], &s[i].score[2]);
        
        }
        
        printf("# 정렬 전 데이터... \n")
        for (int j=0;j<5;j++){
            print_data(&s[j]);
        }
        printf("# 정렬 후 데이터... \n")
        


    return 0;
}

void print_data(stdt *ps){

    printf("학번 : %d ", ps -> num);
    printf("이름 : %s ", ps -> name);
    printf("국어, 영어, 수학 점수 : %5d %5d %5d", ps -> score[0], ps -> score[1], ps -> score[2]);
    
    grade_res(ps);
}

double sum_score(stdt *ps){
    
    double total;
    total = (double)ps->score[0] + ps->score[1] + ps->score[2];
    printf("\t%5.1lf", total);

    return total;

}

double avg_score(stdt *ps){

    double total = sum_score(ps);
    double avg;

    avg = total / 3;

    printf("%5.lf", avg);

    return avg;

}

char grade_res(stdt *ps){

    char grade;
    double avg = avg_score(ps);

    if (avg >= 90){
        grade = 'A';
    }
    else if (avg >= 80){
        grade = 'B';
    }
    else if (avg >= 70){
        grade = 'C';
    }
    else {
        grade = 'F';
    }
    printf("%5c",grade);

    return grade;

}



