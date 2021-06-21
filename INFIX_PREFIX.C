#include"stdio.h"
#include"string.h"
int precedence(char);
main()
{
	char x[20];
	char opd[20],opr[20];
	int i=-1,j=-1,k,len=0;
	int a,b;
	printf("\n entere an expression:");
	scanf("%s",x);
	len=strlen(x);
	for(k=len;k>=0;k--)
	{
		if(x[k]>=48 && x[k]<=57)
		{    
			i++;
			opd[i]=x[k];
	        }
		else
		{

			if(j==-1)
			{
				j++;
				opr[j]=x[k];
			}
			else
			{
				a=precedence(x[k]);
				b=precedence(opr[j]);
				while(j>=0 && a<b)
				{
					i++;
					opd[i]=opr[j];
					j--;
					if(j==-1)
						break;
					b=precedence(opr[j]);
				}		
				j++;
				opr[j]=x[k];
			}     
		}
		
	}
	while(j>=0)
	{
		i++;
		opd[i]=opr[j];
		j--;
	}
	for(j=i;j>=0;j--)
	{
		printf("%c",opd[j]);
		
	}

}

int precedence(char x)
{
	switch(x)
	{
		case '%':
		case '/':
		case '*':
			 return 5;

		case '-':
		case '+':
			return 4;
	}
}