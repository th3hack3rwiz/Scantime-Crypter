#include <stdlib.h>
#include <stdio.h>
#define XOR_VAR 0xAA
void xoring(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    str[i]^=XOR_VAR;
}
int main (int argc,char *argv[])
{
	char *buffer=0, input_file[20], output_file[20];
	FILE *fp;//creating a file pointer
	fp=fopen(argv[1],"rb");
	if (fp==NULL)
	{
		printf("File failed to open!");
		exit(0);
	}
	else
	{
		fseek (fp, 0, SEEK_END);//pointing file pointer to the end char
		long length = ftell (fp);//storing it's position value
		fseek (fp, 0, SEEK_SET);;//setting file pointer back to the start
		buffer = (char*)malloc(length*sizeof(char));//buffer will store file's contents
		if (buffer)
		{
			fread (buffer, 1, length, fp);//reading from file and storing in buffer
		}
		printf("%s",buffer);//printing the resultant string 
		fclose (fp);
	}
	FILE *fr;
	fr=fopen(argv[2],"wb");
	if(fr == NULL)
	{
		printf("File failed to open!");   
		exit(1);             
	}
   else
   {
		xoring(buffer);
		fputs(buffer,fr);
		fclose (fr);
		system("cls");
		system(argv[2]);
	}
}
