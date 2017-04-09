#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 10000

int saldo = 100;
//pthread_mutex_t m;

void *retira(void *str) {
	int i, b;
 	for (i=0; i<N; i++) {
 		//pthread_mutex_lock(&m);
 		b = saldo; 
		b = b - 1; 
		saldo = b;
 		//pthread_mutex_unlock(&m);
 	}
 	printf("\nExecutou Retira. Saldo = %d", saldo);
}

void *deposita(void *str) {
 	int i, a;
 	for(i=0; i<N; i++) {
 		//pthread_mutex_lock(&m);
 		a = saldo; 
		a = a + 1; 
		saldo = a;
 		//pthread_mutex_unlock(&m);
 	}
 	printf("\nExecutou Deposita. Saldo = %d", saldo);
}

int main() {
	int tDeposita = 1;
 	int tRetira = 1;
	
	pthread_t thread[tDeposita+tRetira];
 	//pthread_mutex_init(&m, NULL);
 	
 	int i;
 	
 	for(i=0; i<tDeposita; i++){
 		pthread_create(&thread[i], NULL, deposita, NULL);	
	}
	
	for(i=tDeposita; i<tDeposita+tRetira; i++){
		pthread_create(&thread[i], NULL, retira, NULL);
	}
 	
 	for(i=0; i<tDeposita+tRetira; i++){
 		pthread_join(thread[i], NULL);	
	}
	/*if ((pthread_create(&thid1, NULL, deposita, NULL) != 0) || (pthread_create (&thid2, NULL, retira, NULL) != 0)) {
 		printf("Error!\n");
 		exit(0);
 	}
 	
	pthread_join(thid1, NULL);
 	pthread_join(thid2, NULL); */
 	
 	printf("\nSALDO ATUAL = %d\n", saldo);
 	return 0;
}
