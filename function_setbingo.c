#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5            // ���� ũ�� N�� ��ȣ����� ���� ���� 
#define M 3           // ������ �̱�� ���� M�� ��ȣ ����� ���� ���� 

// �������� ����� �Լ� ���� 


void initialize(){            // ������ �ʱ�ȭ �Լ� 
   srand((unsigned int)time(NULL));
   set_rand((int*)ubingo);
   set_rand((int*)cbingo);   
}

void set_rand(int*array){          //������ ����� �Լ� 
   int i;
   
   for(i=0; i<N*N; i++){
      array[i] = i+1;
   }
   for(i=0; i<N*N; i++){
      swap(&array[i], &array[rand() %N*N]);        // �������� �ٲ��ֱ� 
   }  
}

void swap(int*x, int*y){    
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;  
}
