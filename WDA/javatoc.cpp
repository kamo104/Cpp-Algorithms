# include <stdio.h>
# include <string.h>
# include <ctype.h>

char id[101];

char check()
{
	int i;

	if(strchr(id,'_'))
	{
		if(id[0]=='_'||id[strlen(id)-1]=='_')
			return 'W';
		for(i = 0; id[i+1]!='\0'; i++)
		{
			if(id[i]=='_'&&id[i]==id[i+1])
				return 'W';
		}
		for(i = 0; id[i]!='\0'; i++)
			if(isupper(id[i]))
				return 'W';
		return 'C';
	}
	else
	{
		if(isupper(id[0]))
			return 'W';
		return 'J';
	}
}

void output(char ch)
{
	int i;

	if(ch=='W')
		printf("Error!\n");
	else
		if(ch=='C')
		{
			for(i = 0; id[i]!='\0'; i++)
			{
				if(id[i]!='_')
				{
					if(id[i-1]=='_')
						id[i] -= ' ';
					printf("%c",id[i]);
				}
			}
			printf("\n");
		}
		else
		{
			for(i = 0; id[i]!='\0'; i++)
			{
				if(isupper(id[i]))
				{
					id[i] += ' ';
					printf("_");
				}
				printf("%c",id[i]);
			}
			printf("\n");
		}
}

void input()
{
	while(scanf("%s",id)==1)
	{
		output(check());
	}
}
int main()
{
	input();
	return 1;
}
