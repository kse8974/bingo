#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5            // ���� ũ�� N�� ��ȣ����� ���� ���� 
#define M 3           // ������ �̱�� ���� M�� ��ȣ ����� ���� ���� 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	
	return 0;
}

void initialize(){   			// ������ �ʱ�ȭ �Լ� 
	srand((unsigned int)time(NULL));
	set_rand((int*)ubingo);
	set_rand((int*)cbingo); 
	
}

void set_rand(int*array){    		//������ ����� �Լ� 
	int i;
	
	for(i=0; i<N*N; i++){
		array[i] = i+1;
	}
	for(i=0; i<N*N; i++){
		swap(&array[i], &array[rand() %25]);
	}
	
}

void swap(int*x, int*y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	
}

void print_bingo(int arr[N][N]){ 	// ������ ����ϴ� �Լ� 
	int x, y;
	
	for(y=0; y<N; y++){
		for(x=0; x<N; x++){
			if(arr[y][x] != -1){			//���� ��κ� �׳� ��� 
				printf("%7d", arr[y][x]);
			}
			else{							//������ �߻��� ��� 
				printf("ERROR");
			}
		}
		printf("\n\n");
		 
	} 
}

void get_number_byMe(int frm){ 			// ���� ���� ��ȣ �Է� ���� 
	int number;
	int x, retry;
	
	do{
		retry=0;
		if(frm ==0) {							// 0: �� 1: ��ǻ�� 
			printf(">> 1~25 ������ ���ڸ� �Է��ϼ���: __");
			scanf("%d", number);
			if(number<1 || number>25){		//retry=1�̸� �Է¿��� �ٽ��Է��ؾ���. 
				retry =1;
			}
		}
	}
	
}

void get_number_byCom(){			// ��ǻ�Ͱ� ���Ƿ� ���� ��ȣ ���� 
	
	
}

void filled_bingo(int arr[N][N], int number){ //�Է¹��� number�� ���� ���� -1�� ����� �Լ�(��ĥ�� �κ�) 
	int x, y;
	
	for(y=0; y<N; y++){ // x,y�� ������ �ٲ㰡�鼭 number�� ������ Ȯ�� 
		for(x=0; x<N; x++){
			if(arr[y][x] == number){
				arr[y][x] = -1;
			}
		}
	}	
	
}

void print_winner(int winner){ // ���ڸ� ����ϴ� �Լ�
	switch(winner){
		case 1:							//uwin =1 �϶�(����ڰ� �̱���) 
			printf("����ڰ� �̰���ϴ�.\n");
			break;
		case 2:							//cwin=1 �϶�(��ǻ�Ͱ� �̱� ���) 
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
			break;
		case 3: 						//uwin=cwin=1 �϶�  
			printf("�����ϴ�.\n");
			break;
		default:
			printf("�����Դϴ�. \n");  //������ �߻��� ���
			break; 
	} 
}

void 
