#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 10000

void tolowercase(char str[])
{
	int i;
	for(i=0;str[i];i++)
	{
		str[i]=tolower(str[i]);
	}
}
void readfile(char filename[],char text[])
{
	FILE *fp;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("error in opening file\n");
		return;
	}
	else
	{
		fgets(text, max, fp);   
        fclose(fp);
	}
}

int LCS(char x[],char y[])
{
	int m;
	m=strlen(x);
	int n;
	n=strlen(y);
	int dp[m+1][n+1];
	
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]=0;
			}
			else if(x[i-1]==y[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				if(dp[i][j-1]>dp[i-1][j])
				{
					dp[i][j]=dp[i][j-1];
				}
				
				else
				{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}
	return dp[m][n];
}



int main()
{
	char file1[100];
	char file2[100];
	char text1[max];
	char text2[max];
	
	
	printf("Enter file 1 name\n");
	scanf("%s",file1);
	
	printf("Enter file 2 name\n");
	scanf("%s",file2);
	
	readfile(file1,text1);
	readfile(file2,text2);
	
	
	tolowercase(text1);
	tolowercase(text2);
	
	int lcsstr;
	lcsstr=LCS(text1,text2);
	int str1,str2;
	str1=strlen(text1);
	str2=strlen(text2);
	
	double similarity;
	similarity=(2.0*lcsstr/(str1+str2))*100;
	
	if(similarity>50)
	{
		printf("Plagiarism high %f",similarity);
	}
	else
	{
		printf("plagiarism is %f",similarity);
	}
	return 0;
}







