#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
sem_t chopstick[5];

void eat(int ph){
	printf("Philosopher %d begins eating\n",ph);
}

void think(int ph){
	printf("Philosopher %d begins thinkin\n",ph);
}

void *philos(void*n){
	int ph=*(int*)n;
	printf("Philosopher %d wants to eat\n",ph);
	printf("Philosopher %d tries to pick left chopstick\n",ph);
	sem_wait(&chopstick[ph]);
	printf("Philosopher %d takes left chopstick\n",ph);
	printf("Philosopher %d tries to pick right chopstick\n",ph);
	sem_wait(&chopstick[(ph+1)%5]);
	printf("Philosopher %d takes right chopstick\n",ph);
	eat(ph);
	sleep(2);
	printf("Philosopher %d finished eating\n",ph);
		printf("Philosopher %d leaves to pick right chopstick\n",ph);
	sem_post(&chopstick[(ph+1)%5]);
		printf("Philosopher %d leaves to pick right chopstick\n",ph);
	sem_post(&chopstick[ph]);
	think(ph);
}


void main(){
		int i,n[5];

	for(i=0;i<5;i++){
		sem_init(&chopstick[i],0,1);
	}
	pthread_t T[5];
	for(i=0;i<5;i++){
		n[i]=i;
		pthread_create(&T[i],NULL,philos,(void*)&n[i]);
	}
	for(i=0;i<5;i++){
		
		pthread_join(T[i],NULL);
	}
	
}




