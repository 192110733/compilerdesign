#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
int main()
{
    char prod[SIZE], alpha[SIZE], beta[SIZE];
    int non_term,i,j, idx=3;
    
    printf("enter the production as E->E|a :  ");
    scanf("%s",&prod);
    
    non_term=prod[0];
    if(non_term==prod[idx])
    {
    	for(i=idx+1,j=0;prod[i]!='|';i++,j++)
    	{
    		alpha[j]=prod[i];
		}
		alpha[j]='\0';
		i++;  
		for(j=i,i=0;prod[j]!='\0';i++,j++)
		{
			beta[i]=prod[j];
		}
		beta[i]='\0';
		
		printf("\nGrammar Without Left Recursion: \n\n");
        printf(" %c->%s%c'\n", non_term,beta,non_term);
    	printf(" %c'->%s%c'|epsilon\n", non_term,alpha,non_term);	
	}
}
