#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5            // ���� ũ�� N�� ��ȣ����� ���� ���� 
#define M 3           // ������ �̱�� ���� M�� ��ȣ ����� ���� ���� 

void initialize();
void set_rand(int*array);
void swap(int*x, int*y);
void print_bingo(int arr[N][N]);
int get_number(int frm);				// 0:USER 1:COM 
void filled_bingo(int arr[N][N], int number);
int count_bingo(int arr[N][N]);
void print_winner(int winner);

int count = 0;							//=���������� 
int checked[N*N];

int ubingo[N][N];					//������� ������ = ��������	 
int cbingo[N][N];					//��ǻ���� ������ 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main() {
	int number, uwin, cwin;
	
	initialize();			//������ �ʱ�ȭ
	
	do{
		printf("--<����� ������>--\n");
		print_bingo(ubingo);  		//����� ������ ��� 
		
		number = get_number(0); //������� ��ȣ ���� 
		
		filled_bingo(ubingo, number);
		filled_bingo(cbingo, number);
		
		number = get_number(1);	//��ǻ���� ��ȣ ����
		filled_bingo(ubingo, number);
		filled_bingo(cbingo, number);
		
		uwin = count_bingo(ubingo);		// ���� �ϼ� Ȯ�� 
		cwin = count_bingo(cbingo); 
	} 
	while((uwin == 0) && (cwin ==0));	//1�� �Ǹ� ���ڰ� ����ϱ� �̴�� ���� 
	
	print("--<����� ���-->\n");
	print_bingo(ubingo);			//������� ������ ��� 
	print("--<��ǻ�� ���>--\n");
	print_bingo(cbingo);			//��ǻ���� ������ ��� 
	
	print_winner(cwin*2 + uwin);
	// ����ڰ� �̱��(uwin=1), case=1
	// ��ǻ�Ͱ� �̱��(cwin=1), case=2
	// ����(uwin=cwin=1), case=3 , �� �ܴ̿� ���� 
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
		swap(&array[i], &array[rand() %N*N]);
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
				printf("%d", arr[y][x]);
			}
			else{							//������ �߻��� ��� 
				printf("ERROR");
			}
		}
		printf("\n\n");
		 
	} 
}

int get_number(int frm){ 			// ���� ��ȣ �Է� ���� 
	int number;
	int x, retry;
	
	do{
		retry = 0;
		if(frm == 0) {							// 0: �� 1: ��ǻ�� 
			printf(">> 1~25 ������ ���ڸ� �Է��ϼ���: __");
			scanf("%d", number);
			if(number<1 || number>25){		//retry=1�̸� �Է¿��� �ٽ��Է��ؾ���. 
				retry = 1;
			}
		}
		else{
			number= rand() %N*N +1;
		}
		
		if(retry==0){
			for(x=0; x<N; x++){
				if(checked[x] == number){
					retry = 1;
					break;
				}
			}
		}
	}
	while(retry ==1);				// retry=1 �̸� �ٽ� �Է��ؾ��ϹǷ� do�������� ���ư�.
		
	checked[count++] = number;
	
	if(frm ==0){
		printf("> ����ڰ�  '%d'�� �����߽��ϴ�. \n", number);
	}
	else {
		printf("> ��ǻ�Ͱ� '%d'�� �����߽��ϴ�.\n \n", number);
	}	
	return number;
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

int count_bingo(int arr[N][N]){			// ���� ���̺��� ä�� ����/����/�밢�� �� ���� ����ؼ� ��ȯ 
	int x, y, sum;							// �� ���� ���� -1*N�� �Ǹ� ���� �̹Ƿ� sum ���� ����
	int try_count = 0;								// ���� ���� �밢�� ���� ������� ���� 
		
	for(y=0; y<N; y++){			//x�� Ȯ�� 
		sum = 0;				//�� �� ���� ���ؾ��ϹǷ� sum �ʱ�ȭ 
		for(x=0; x<N; x++){
			sum += arr[y][x];
			try_count = try_count + 1;
		}
		if(sum == -1*N){
			printf("�� �õ�Ƚ���� %d �Դϴ�.", try_count);
			return try_count;
		}
	
	} 
	
	for(x=0; x<N; x++){					//y�� Ȯ�� 
		sum=0;							//sum �ʱ�ȭ
		for(y=0; y<N; y++){
			sum += arr[y][x];	
			try_count = try_count +1;
		} 
		if(sum == -1*N){
			printf("�� �õ�Ƚ���� %d �Դϴ�.", try_count);
			return try_count;
			
		}
	}
	
	sum = 0;						// �밢���� ���ٻ��̹Ƿ� for���� �ۿ��� sum�ʱ�ȭ
	for(x=0; x<N; x++){				// �밢�� Ȯ�� 
		sum += arr[x][x];
		try_count = try_count +1;
	} 
	if(sum == -1*N){
		printf("�� �õ�Ƚ���� %d �Դϴ�.", try_count);
		return try_count;
	}
	
	sum =0;
	for(x=0; x<N; x++){				// �밢�� Ȯ�� 
		sum+= arr[x][N -x-1];
		try_count = try_count +1;
	}
	if(sum == -1*N){
		printf("�� �õ�Ƚ���� %d �Դϴ�.", try_count);
		return try_count;
	}
	
	if(count >= M){			        //count�� ���ڰ� M���� ������ Ȯ�� 
		return 1;						// count_bingo =1 �̵Ǹ� ����	
	}
	
	else{
		return 0;					// count_bingo=0 �̵Ǹ� ���� ���ڰ� �����Ƿ� main�Լ����� do_while���� �� ���. 
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

