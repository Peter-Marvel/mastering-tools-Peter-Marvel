#include<stdio.h>
#include<stdlib.h>
int main(void) {
	char ch,file_in_name[50],file_out_name[50];
	FILE *in=NULL;
	FILE *out=NULL;
	printf("Enter the infile name:\n");
	scanf("%s", file_in_name);
	in=fopen(file_in_name,"r");
	if(in==NULL){
		perror("Cannot find infile");
		exit(1);
	}
	printf("Enter the outfile name:\n");
	scanf("%s", file_out_name);
	out=fopen(file_out_name,"w");
	if(out==NULL){
			perror("Cannot open outfile");
			exit(1);
		}
	ch=fgetc(in);
	while(ch!=EOF){
		fputc(ch,out);
		ch=fgetc(in);
	}
	fclose(in);
	fclose(out);
	return 0;
}