#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tsp.h"
#include "tspserver.h"


int graph[10][10]={
	{1000,5,6,1000,1000,1000,1000,7,3,1},
	{5,1000,1,9,7,1000,1000,1000,1000,7},
	{6,1,1000,2,7,1000,1000,1000,1000,4},
	{1000,9,2,1000,2,7,8,1000,1000,1000},
	{1000,7,7,2,1000,6,7,1000,1000,1000},
	{1000,1000,1000,7,6,1000,2,7,1000,1000},
	{1000,1000,1000,8,7,2,1000,4,5,1000},
	{7,1000,1000,1000,1000,7,4,1000,3,6},
	{3,1000,1000,1000,1000,1000,5,3,1000,2},
	{1,7,4,1000,1000,1000,1000,6,2,1000},
};

int no_of_cities=10;


// int graph[4][4]={
// 	{1000,20,42,35},
// 	{20,1000,30,34},
// 	{42,30,1000,12},
// 	{35,34,12,1000}	
// };

// int no_of_cities=4;
int minimum;



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


void traverse(char *node, int depth, int length)
{
	int i,j;
	int flag,rpcreturn;
	char temp[1];
	if (length<minimum)
	{

		if(strlen(node)==no_of_cities)
		{
			minimum=length;
			printf("%s\t%d\n",node ,minimum);
		}
		else if(depth==0)
		{
			printf("NO MORE SUBCONTRACTORS\n");
		}
		else
		{	
			for (i = 0; i < no_of_cities; ++i)
			{
				
				flag=0;
				for(j=0;j<strlen(node);j++)
				{
					if(i==(node[j]-'0'))
					{
						flag=1;
						break;
					}
				}			

				if (!flag)
				{
					sprintf(temp,"%d",i);
					char *child = malloc(strlen(node)+strlen(temp)+1);
					child[0]='\0';
					strcat(child,node);
					strcat(child,temp);
					traverse(child,depth-1,length+graph[node[strlen(node)-1]-'0'][i]);
				}
			}

		}
	}
}


int* servtraverse_1_svc(char **node, struct svc_req *req)
{
	static int result;
	int length;
	minimum=1000;
	length=find_length(*node);
	traverse(*node,no_of_cities,length);

	result = minimum;
	return (&result);
}