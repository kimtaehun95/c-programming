 #include <stdio.h>
 #include <stdlib.h>          // malloc 
 #include <string.h>          // puts, gets 


 #define MAX 8                  // ������ ���� 
          // BOOL 
 #define TRUE 1
 #define FALSE 0

 ////////////  ��� �� �� ü //////////////////////// 
 typedef struct Node *P_Node;                   // ��������� 
 typedef struct Node
 {
	 P_Node link;                                     // ����� ������ ��ũ 
	int vtx;                                               // ���� ��ȣ 
 }Node;
 


 ////////////  �� �� �� �� ////////////////////////// 

 P_Node graph[MAX];                    // ��������Ʈ ���� �ʱ� �����͹迭 
 short int mark[MAX];                   // �˻��� �̿�� ��ŷ�迭 
 int Que[MAX];                              // bfs�� �̿�� ȯ��ť 

 int matrix[MAX][MAX] = {          // ������� 
	                  {0,1,1,0,0,0,0,0},
	                  {1,0,0,1,1,0,0,0},
	                  {1,0,0,0,0,1,1,0},
	                  {0,1,0,0,0,0,0,1},
	                  {0,1,0,0,0,0,0,1},
	                  {0,0,1,0,0,0,0,1},
	                  {0,0,1,0,0,0,0,1},
	                  {0,0,0,1,1,1,1,0}
 };


 //////////// �� ��       /////////////////////////////// 

 void init();                    // ��������� �̿��ؼ� ��������Ʈ �ʱ�ȭ 
 void Clear_mark();          // ��ŷ FALSE�� Ŭ���� 
 //-------------------------------------- Ž�� 
 void dfs(int v);                   // ����Ž��  
 void bfs(int v);                   // �ʺ�Ž�� 

 //-------------------------------------- QUEUE 
 void enq(int *rear, int vtx);
 int deq(int *front);


 int main()
 {
	           int v;                     // Ž�� ���� 
	           Clear_mark();          // ��ŷŬ���� 
	          init();         // ��������� ������� ���� ����Ʈ ����  
	
		           puts("���� �켱Ž�� �ʱ� ����");
	          scanf_s("%d", &v);
	          dfs(v);
	          puts("");
	
		
		
		          Clear_mark();         // ��ŷ Ŭ���� 
	
		
		
		          puts("�ʺ� �켱Ž�� �ʱ� ����");
	         scanf_s("%d", &v);
	          bfs(v);
	          puts("");

		          return 0;
	
		
		 }


 // ��������� ��������Ʈ�� �ʱ�ȭ 
 void init()
 {
	          int x, y;
	
		
		      P_Node move;         // �̵������� 
	          P_Node st;          // �� ������ 
	          P_Node tmp;          // �����Ҵ� 
	
		
		          for (x = 0; x<MAX; x++)
		         {
		                   st = graph[x];         // �����̸鼭 ���� ���� 
		
			                   printf("V%d  ---> ", x);
		
			                   for (y = 0; y<MAX; y++)
			                   {
			                            if (matrix[x][y] != FALSE)  // matrix[x][y] == TRUE 
				                            {
			
					                                 tmp = (P_Node)malloc(sizeof(Node));
				                                     tmp->vtx = y;     // vtx���� �� ��ȣ  
				
					                                     if (graph[x] == st)   // �ʱ⿡ �ƹ����ᵵ ������ 
					                                     {     // move�� tmp�ּҰ� �����ϰ� graph���� tmp�� �ּҰ� ������. 
					                                              move = tmp;
					                                              graph[x] = tmp;
					                                              printf("%5d", tmp->vtx);
					                                     }
				                                     else       // ������ ����������� 
					                                     {     // ��带 �����Ŵ 
					                                              move->link = tmp;
					                                              move = tmp;
					                                              printf("%5d", tmp->vtx);
					
						                                     }
				
					                            }
			                   }
		                   tmp->link = NULL;      // �������� NULL�� 
		                   puts("\n");
		          }
	
		
		
		 //  ����ƴ��� Ȯ�� ����ƴ���.. graph[x]���� ����Ȱ��� ���ʷ� ������ �˻�.. 
		
		 // �߿��� �ƴٸ� ���� ��¹��� ������ ��µǾ�� �Ѵ�. [Debug �ҽ�] 
		 /* for(x=0; x<MAX; x++)
			  {
			           move = graph[x];
			           printf("V%d -----> ", x);
			           while(move)
			           {
			                    printf("%5d", move->vtx);
			                    move = move->link;
			           }
			           puts("\n");
			  }*/
		
		
		
		 }


 // ���̿켱Ž�� 
 void dfs(int v)
 {
	          P_Node w;
	          mark[v] = TRUE;
	          printf("%3d", v);
	
	          for (w = graph[v]; w; w = w->link)
		      if (!mark[w->vtx])
			  dfs(w->vtx);
 }



 //�ʺ�켱Ž�� 
 void bfs(int v)
 {
	          P_Node w;
	          int front, rear;
	          front = rear = -1;
	          printf("%3d", v);
	          mark[v] = TRUE;
	          enq(&rear, v);
          while (front != rear)
		          {
		                   v = deq(&front);
			                   for (w = graph[v]; w; w = w->link)
			                   {
			                            if (!mark[w->vtx])  // ��ŷ�������� �����̸�(FALSE) 
				                            {
				                                     printf("%3d", w->vtx);
				                                     enq(&rear, w->vtx);
				                                    mark[w->vtx] = TRUE;
				                           }
		
				                   }
		          }
	 }

 ////////////////// Q U E U E ////////////////// 
 void enq(int *rear, int vtx)      // 
 {
	 * rear = (*rear) % MAX;   //enqueue 
	          Que[++(*rear)] = vtx;
	 }

 int deq(int *front)    // dequeue 
 {
	
		          return Que[++(*front) % MAX];
	 }

 void Clear_mark()     // ǥ�� û�� 
 {
	          int i;
	          for (i = 0; i<MAX; i++)
		          {
		                   mark[i] = FALSE;
		          }
	 }

