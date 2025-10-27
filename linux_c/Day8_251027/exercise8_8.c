#include<stdio.h>

int main(void){

    int sum, sum2;
  
    int arr[5][6] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};

    for (int i=0; i<5; i++){
        sum = 0;

        for (int j=0; j<6; j++){

            sum += arr[i][j];
            
            if (j == 5){
                arr[i][j] = sum;

            }
            
            arr[4][j] += arr[i][j];

        if (i == 4){
           arr[i][j]= sum2;
        }

        printf("%d ", arr[i][j]);
        }
        printf("\n");

       
    }


return 0;
}

