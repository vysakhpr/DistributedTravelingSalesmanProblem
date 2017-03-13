#include <stdio.h>
#include <time.h>
#include "tsp.h"

int graph[4][4]={
	{100,20,42,35},
	{20,100,30,34},
	{42,30,100,12},
	{35,34,12,100}	
};

int minimum=1000;

int find_length( const char * s)
{
	int i=0,l=0;
	while(s[i+1]!='\0')
	{
		l=l+graph[s[i]-'0'][s[i+1]-'0'];
		i++;
	}	
	return l;
}


void main(int argc, char const *argv[])
{
	CLIENT *clnt;
	int *result;
	char *node=argv[1],*server="127.0.0.1";
	clock_t start, end;
    double cpu_time_used;


	clnt=clnt_create(server,TSPPROG,TRAVERSEVERS,"tcp");
	if (clnt == (CLIENT *)NULL) 
	{
		clnt_pcreateerror(server);
		exit(1);
	}

	start = clock();
	result=traverse_1(&node,clnt);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


	if (result == (int *)NULL) {
		clnt_perror(clnt, server);
		exit(1);
	}
	printf("Message delivered to %s with returned value %d in %f sec\n",server,*result, cpu_time_used);
	clnt_destroy( clnt );
}