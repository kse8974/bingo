#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5            // 빙고 크기 N은 기호상수로 조절 가능 
#define M 3           // 빙고에서 이기는 조건 M은 기호 상수로 조절 가능 

// 빙고판을 만드는 함수 모임 


void initialize(){            // 빙고판 초기화 함수 
   srand((unsigned int)time(NULL));
   set_rand((int*)ubingo);
   set_rand((int*)cbingo);   
}

void set_rand(int*array){          //빙고판 만드는 함수 
   int i;
   
   for(i=0; i<N*N; i++){
      array[i] = i+1;
   }
   for(i=0; i<N*N; i++){
      swap(&array[i], &array[rand() %N*N]);        // 랜덤으로 바꿔주기 
   }  
}

void swap(int*x, int*y){    
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;  
}
