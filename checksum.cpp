#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char car='0';
int check(char *n,char *m,int len)
{
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(n[i]==m[i])
		cnt=1;
		else
		cnt=0;
	}
	if(cnt==1)
	return 1;
	else
	return 0;
}
char find_or(char d1,char d2,char d3)
{
	if(d3=='0'){
	if (d1=='0' && d2=='0')
	return '0';
	else if ((d1=='0' && d2=='1')||(d1=='1' && d2=='0'))
	return '1';
	else if (d1=='1' && d2=='1'){
		car='1';
	return '0';}}
	
	else{
		if (d1=='0' && d2=='0'){
		car='0';
	return '1';}
	else if ((d1=='0' && d2=='1')||(d1=='1' && d2=='0')){
	car='1';
	return '0';}
	else if (d1=='1' && d2=='1'){
		car='1';
	return '1';}
	}
	
	
}

char find_comp(char y)
{
	if (y=='0')
	return '1';
	else 
	return '0';
}
int main()
{
	int i=0,c=0,j=0;
	int n=0,len=0,ch;
	printf("enter number of datas you want to insert : ");
	scanf("%d",&n);
	
	printf("enter the length of each data : ");
	scanf("%d",&len);
	
	char **a=(char**)malloc(len*sizeof(char*));
	char *d=(char*)malloc(len*sizeof(char));
	char ex[50],ex1[50];
	
	for(i=0;i<=n;i++)
	{
		a[i]=(char *)malloc(n*sizeof(char));
	}
	
	printf("enter the datas : \n");
	
	for(i=0;i<n;i++)
	{
		
		scanf("%s",a[i]);
		}
		
		
	
	
	for(i=0;i<len-1;i++)
	{
		
		ex[i]='0';
		}
		ex[len-1]='1';
		
		for(i=0;i<len;i++)
	{
		
		ex1[i]='0';
		}
		
		
		
			
	for(i=0;i<n;i++)
	{
	if (strlen(a[i])>len){
	
	printf("wrong data");
	exit(0);}
	}
	
	for(i=0;i<n;i++)
	{
	for(j=0;j<len;j++)
	{
		if(a[i][j]!='1'&& a[i][j]!='0'){
		
		printf("wrong data");
		exit(0);}
		}	}
		
	

		
	

	printf("***************SENDER SIDE*******************\n");
do{
	if(c==0){
	
	for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(a[c][i],a[c+1][i],car);
	 
	}

	if (car=='1')
	{
		car='0';
	for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(d[i],ex[i],car);
	 
	}
	}
	
c=c+2;}
else
{
for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(a[c][i],d[i],car);
	 
	}

	if (car=='1')
	{
		car='0';
	for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(d[i],ex[i],car);
	 
	}
	}
	c=c+1;	
}


}while(c!=n);

for(i=0;i<len;i++)
	{
		
	d[i]=find_comp(d[i]);
	}


for(i=0;i<len;i++)
	{
	 a[n][i]=d[i];
	}

printf("CHECKSUM= ");	
for(i=0;i<len;i++)
	{
		
	 printf("%c",d[i]);
	}
printf("\n***************RECEIVER SIDE*******************\n");
c=0;
do{
	if(c==0){
	
	for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(a[c][i],a[c+1][i],car);
	 
	}

	if (car=='1')
	{
		car='0';
	for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(d[i],ex[i],car);
	 
	}
	}
	
c=c+2;}
else
{
for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(a[c][i],d[i],car);
	 
	}

	if (car=='1')
	{
		car='0';
	for(i=len-1;i>=0;i--)
	{
		
	d[i]=find_or(d[i],ex[i],car);
	 
	}
	}
	c=c+1;	
}



}while(c!=n+1);

for(i=0;i<len;i++)
	{
		
	d[i]=find_comp(d[i]);
	}
	
	printf("CHECKSUM= ");
	
for(i=0;i<len;i++)
	{
		
	 printf("%c",d[i]);
	}
ch=check(d,ex1,len);
if(ch==1)
printf("\nDATA IS ERROR FREE");
else
printf("\nDATA IS NOT ERROR FREE");	
	return 0;
}
