#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tsp.h"

int graph[4][4]={
	{100,20,42,35},
	{20,100,30,34},
	{42,30,100,12},
	{35,34,12,100}	
};

int no_of_cities=4;
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
	int flag;
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
			printf("NO SUBCONTRACTORS LEFT\n");
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


int* traverse_1_svc(char **node, struct svc_req *req)
{
	static int result;
	int length;
	minimum=1000;
	length=find_length(*node);
	traverse(*node,no_of_cities/2,length);

	result = minimum;
	return (&result);
}