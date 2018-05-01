#include<conio.h>
#include<stdio.h>
#include<string.h>
char X[] = "X" ;
char I[] = "I" ;
char V[] = "V" ;
char L[] = "L" ;
char C[] = "C" ;
char D[] = "D" ;
char M[] = "M" ;




char s[20];

void docfile( int num)
{
	int n;
	long length;
	
	FILE *fp;
	
	fp=fopen("chuoiLaMa.txt", "r");
	n = fseek(fp,0L, SEEK_END);
	length = ftell(fp);
    fseek(fp, (length - num), SEEK_SET);
    if(n)
	printf("FAILED");
	else
	  if(fgets(s, 2, fp) != NULL) 
                printf("\n%s", s);
        else printf("lol");

    
	
}


int doigiatri( char a[] )
{
	int m;
	if ( strcmp(a,X) == 0)
	m=10;
	else if ( strcmp(a,I) == 0)
	m=1;
	else if ( strcmp(a,V) == 0)
	m=5;
	else if ( strcmp(a,L) == 0)
	m=50;
	else if ( strcmp(a,C) == 0)
	m=100;
	else if ( strcmp(a,D) == 0)
	m=500;
	else if ( strcmp(a,M) == 0)
	m=1000;
	return m;
	
}




void filechuoiLaMa( char c[20])
{	
	FILE *fp;

   fp = fopen("chuoiLaMa.txt", "w+");
   fprintf(fp, "%s",c);
   fclose(fp);
}


 int main()
{   
	char chuoilama[20];
	printf("Nhap vao chuoi La Ma: ");
	gets(chuoilama);
	
	filechuoiLaMa(chuoilama);
	
	docfile(2);
	
	doigiatri(s); 
	
	printf(" %d", doigiatri(s));
	
	//	if( docfile(1) == 'X' )
	//	printf("yes");
	

	
	getch();
	return 0;
	
	        
}
