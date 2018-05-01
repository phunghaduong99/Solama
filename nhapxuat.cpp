#include<conio.h>
#include<stdio.h>
#include<string.h>
 
char s[80];
int n;
int num=2;
long length;






 int main()
{    
	const char *filePath = "C:/Users/ADMIN/Desktop";
	FILE *fp;
	fp=fopen("duong.txt", "w+");
	fprintf(fp, "DUongratdeptrai");
	n = fseek(fp,0L, SEEK_END);
	length = ftell(fp);
    fseek(fp, (length - num), SEEK_SET);
    if(n)
	printf("FAILED");
	else
	  if(fgets(s, 2, fp) != NULL) 
                printf("\n%s", s);
        else printf("lol");
     
		
	return 0;
	        
}
