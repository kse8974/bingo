
void print_bingo(int arr[N][N]){    // 빙고판 출력하는 함수 
   int x, y;

   for(y=0; y<N; y++){
      for(x=0; x<N; x++){
         if(arr[y][x] != 0){         //거의 대부분 그냥 출력 
            printf("%4d ", arr[y][x]);
         }
         else{                     //에러가 발생한 경우 //여기서 에러가 발생한 경우 외에 체크 된 경우에 마킹 출력됨
          printf("-1");
         }
      }
      printf("\n\n");       
   } 
}

void filled_bingo(int arr[N][N], int number){     //입력받은 number과 같은 수를 -1로 만드는 함수(색칠된 부분) 
   int x, y;
   
   for(y=0; y<N; y++){ // x,y를 일일이 바꿔가면서 number와 같은지 확인 
      for(x=0; x<N; x++){
         if(arr[y][x] == number){
            arr[y][x] = -1;
         }
      }
   }      
}

int get_number(int frm){          // 빙고 번호 입력 선택 
   int number1, number2;
   int x, retry;
   
   do{
      retry = 0;
      if(frm == 0) {                     // 0: 나 1: 컴퓨터 
         printf(">> 1~25 사이의 숫자를 입력하세요: ");
         scanf("%d", &number1);
         if(number1<1 || number1>25){      //retry=1이면 입력에러 다시입력해야함. 
            retry = 1;
         }
         else{
         	retry = 0;
		 }
      }
      
      if(retry == 0){				// 여기서 컴퓨터가 입력하는 부분				
         
		 number2 = rand() %N*N +1;
            if(number2 == number1){
            	retry = 1;				//retry=1이면 입력에러 
			}
            else{                         	
        		retry = 0;
            }
         }
      }
   while(retry ==1);            // retry=1 이면 다시 입력해야하므로 do구문으로 돌아감.
      
   
   if(frm ==0){
      printf("> 사용자가 '%d'를 선택했습니다. \n", number1);
   }
   else {
      printf("> 컴퓨터가 '%d'를 선택했습니다.\n \n", number2);
   }   
   return number1, number2;
}



int u_count_bingo(int arr[N][N]){         // 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
   int x, y, sum;                     // 한 줄의 합이 -1*N이 되면 빙고 이므로 sum 변수 선언
   int made_bingo = 0;
      
   for(y=0; y<N; y++){         //x축 확인 
      sum = 0;            //각 줄 마다 구해야하므로 sum 초기화 
      for(x=0; x<N; x++){
         sum += arr[y][x];
      }
      if(sum == -1*N){
        made_bingo++;
      }   
   } 
   
   for(x=0; x<N; x++){               //y축 확인 
      sum=0;                     //sum 초기화
      for(y=0; y<N; y++){
         sum += arr[y][x];
      } 
      if(sum == -1*N){
        made_bingo++;
      }
   }
   
   sum = 0;                  // 대각선은 한줄뿐이므로 for구문 밖에서 sum초기화
   for(x=0; x<N; x++){            // 대각선 확인 
      sum += arr[x][x];
   } 
   if(sum == -1*N){
    made_bingo++;
   }
   
   sum =0;
   for(x=0; x<N; x++){            // 대각선 확인 
      sum+= arr[x][N -x-1];
   }
   if(sum == -1*N){
    made_bingo++;
   }
   
   if(made_bingo >= M){                 //count된 숫자가 M값과 같은지 확인 
      return 1;                  // count_bingo =1 이되면 승자   
   }

   else{
      return 0;               // count_bingo=0 이되면 아직 승자가 없으므로 main함수에서 do_while문을 못 벗어남. 
   } 
}

int c_count_bingo(int arr[N][N]){         // 빙고 테이블이 채운 가로/세로/대각선 줄 수를 계산해서 반환 
   int x, y, sum;                     // 한 줄의 합이 -1*N이 되면 빙고 이므로 sum 변수 선언
   int made_bingo = 0;                        // 가로 세로 대각선 줄이 만들어진 갯수 

   for(y=0; y<N; y++){         //x축 확인 
      sum = 0;            //각 줄 마다 구해야하므로 sum 초기화 
      for(x=0; x<N; x++){
         sum += arr[y][x];
		}
      if(sum == -1*N){
      	 made_bingo++;
      }
   } 
   
   for(x=0; x<N; x++){               //y축 확인 
      sum = 0;                     //sum 초기화
      for(y=0; y<N; y++){
         sum += arr[y][x];   
      } 
      if(sum == -1*N){
        made_bingo++;
    }
	}
   
   sum = 0;                  		// 대각선은 for구문 밖에서 sum초기화
   for(x=0; x<N; x++){            	// 대각선 확인 
        sum += arr[x][x];
    } 
   if(sum == -1*N){
    	made_bingo++;
	}
   
   sum =0;
   for(x=0; x<N; x++){            // 대각선 확인 
      sum+= arr[x][N-x-1];
    }
   if(sum == -1*N){
      made_bingo++;
    }
   
   if(made_bingo >= M){                 //count된 숫자가 M값과 같은지 확인 
      return 1;                  // count_bingo =1 이되면 승자   
   }
   
   else{
      return 0;               // count_bingo=0 이되면 아직 승자가 없으므로 main함수에서 do_while문을 못 벗어남. 
   }   
}

void print_winner(int winner){  // 승자를 출력하는 함수
   switch(winner){
      case 1:                     //uwin =1 일때(사용자가 이긴경우) 
         printf("사용자가 이겼습니다.\n");
         break;
      case 2:                     //cwin=1 일때(컴퓨터가 이긴 경우) 
         printf("컴퓨터가 이겼습니다.\n");
         break;
      case 3:                   //uwin=cwin=1 일때  
         printf("비겼습니다.\n");
         break;
      default:
         printf("오류입니다. \n");  //에러가 발생한 경우
         break; 
   } 
}
