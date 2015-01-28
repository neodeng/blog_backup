/*Comparison of Eratosthenes and Euler seive of prime numbers.*/
 #include "stdio.h"
 #include "time.h"
 #include "string.h"
 #define N 100000
 /* check: prime=0;not prime=1;
    primes: store primes;
	cnt: the number of primes. */
 int check[N];
 long primes[N];
 long cnt; 
 long Eratosthenes(long n);
 long Euler(long n);
 
 main(){
	double st, ed, runtime;
	st=clock();
	memset(check,0,N);memset(primes,0,N);cnt=0;
	cnt=Eratosthenes(N);
	ed=clock();
	runtime=(ed-st)/CLOCKS_PER_SEC;
	printf("Eratosthenes:\t\t%10d\t\t%.10f\n",cnt,runtime);
	st=clock();
	memset(check,0,N);memset(primes,0,N);cnt=0;
	cnt=Euler(N);
	ed=clock();
	runtime=(ed-st)/CLOCKS_PER_SEC;
	printf("Euler:\t\t\t\%10d\t\t%.10f\n",cnt,runtime);
	return 0;
 }
 
 long Eratosthenes(long n){
	long i,j;
	check[0]=1;
	check[1]=1;
	for (i=2;i<n;i++){
		if(!check[i])
			primes[cnt++]=i;
		for(j=i*i;j<n;j+=i)
			check[j]=1;
	}
	return cnt;
 }
 
long Euler(long n){
	long i,j;
	check[0]=1;
	check[1]=1;
	for (i=2;i<n;i++){
		if(!check[i])
			primes[cnt++]=i;
		for (j=0;i*primes[j]<n && j<cnt;j++){
			check[i*primes[j]]=1;
			if(i%primes[j]==0)
				break;
		}
	}
	return cnt;
 }