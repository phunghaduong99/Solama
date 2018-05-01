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



/* Tao file "chuoiLaMa.txt". */
void filechuoiLaMa( char c[20])
{	
	FILE *fp;

   fp = fopen("chuoiLaMa.txt", "w+");
   fprintf(fp, "%s",c);
   fclose(fp);
}

/* Tinh so ki tu La Ma trong chuoi La Ma da cho. */
int dodaichuoi(char h[])
{	
	int n;
	int length;
	
	FILE *fp;
	
	fp=fopen("chuoiLaMa.txt", "r");
	n = fseek(fp,0L, SEEK_END);
	length = ftell(fp);
	return length;
}


char s[20];
/* Chon tu duoi len cac ki tu tu chuoi da cho. Ham giup doi ki tu La Ma ve gia tri chu so A Rap. */
int docfile( int num)
{
	/*Doc ki tu La Ma thu n tu duoi len trong chuoi ki tu da cho.*/
	int n;
	int length;
	
	FILE *fp;
	
	fp=fopen("chuoiLaMa.txt", "r");
	n = fseek(fp,0L, SEEK_END);
	length = ftell(fp);
    fseek(fp, (length - num), SEEK_SET);
    if(n)
	printf("FAILED");
	else if(fgets(s, 2, fp) == NULL) 
       printf("FAILED");
        
    /*Doi ki tu La Ma sang chu so A Rap.*/   
   	int m;
	if ( strcmp(s,X) == 0)
	m=10;
	else if ( strcmp(s,I) == 0)
	m=1;
	else if ( strcmp(s,V) == 0)
	m=5;
	else if ( strcmp(s,L) == 0)
	m=50;
	else if ( strcmp(s,C) == 0)
	m=100;
	else if ( strcmp(s,D) == 0)
	m=500;
	else if ( strcmp(s,M) == 0)
	m=1000;
	return m;
}




 int main()
{   
	char chuoilama[20];
	printf("Nhap vao chuoi La Ma: ");
	gets(chuoilama);
	
	filechuoiLaMa(chuoilama);
	
	int a =0;
	int i =1 ;
	int j =0;
	int giatri[4];
	
	
	if(dodaichuoi(chuoilama) >1 )
	{
			do
			{
			if (docfile(i) > docfile(i+1) )
				{
				giatri[j] = docfile(i) - docfile(i+1);
				i=i+2; 
				}
			else if ( docfile(i) < docfile(i+1) )
				{ 
				giatri[j] = docfile(i);
			  	i++;	
				} 
			else if ( docfile(i) == docfile(i+1))
				{	
				if(docfile(i+1)== docfile(i+2))
						{ 
						giatri[j] = 3*docfile(i);
						i=i+3;
						}
				else if(docfile(i+1) != docfile(i+2)) 
						{
						giatri[j] = 2*docfile(i);
						i=i+2;
						}
				}
			
			a = a+ giatri[j];
		
			j++;
			}  while (i < dodaichuoi(chuoilama));
			
			if(i == dodaichuoi(chuoilama) ) 
			{
				a=a + docfile(i);
			}
		}
	else if (dodaichuoi(chuoilama) == 1 ) 
	a = a + docfile(1);
	
	printf("So A Rap sau khi chuyen: %d", a) ;
	
	return 0;	        
}
