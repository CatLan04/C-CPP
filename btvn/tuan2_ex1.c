#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
clock_t s,e;
double time_use;
void copy_by_c(FILE *fin, FILE *fout)
{
    int c;
    while ((c = fgetc(fin)) != EOF)
        fputc(c,fout);
}
int size_line(char **buffer,FILE *fin)
{
    char *cs = NULL;
    int len = 0;
    int c;
    while ((c = fgetc(fin))!=EOF)
    {
        cs = (char *)realloc(cs, ++len+1);
        if ((*(cs + len - 1) = c) == '\n')
            {
                *(cs + len) = '\0';
                *buffer = cs;
                break;
            }
    }
    return len;
}
void copy_by_line(FILE *fin, FILE *fout)
{
    char *line_buf = NULL;
    int line_size;
    line_size = size_line(&line_buf,fin);
    while (line_size > 0)
    {
        fputs(line_buf,fout);
        line_size = size_line(&line_buf,fin);
    }
    free(line_buf);
    line_buf = NULL;
}
void copy_by_block(FILE *fin, FILE *fout)
{
    int num;
    char buff[81];
    while(!feof(fin))
    {
        num = fread(buff,sizeof(char),80,fin);
        buff[num*sizeof(char)] = '\0';
        fwrite(buff,sizeof(char),num,fout);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    FILE *fp1,*fp2;
    fp1 = fopen("file1.txt","r");
    fp2 = fopen("file2.txt","w");

    if (fp1==NULL)
    {
        printf("Error ! Cannot open file");
        return 1;
    }
    if (fp2==NULL)
    {
        printf("Error ! Cannot open file");
        return 1;
    }
    s = clock();
    switch(n)
    {
        case 1: copy_by_c(fp1,fp2); break;
        case 2: copy_by_line(fp1,fp2); break;
        case 3: copy_by_block(fp1,fp2); break;
        default: break;
    }
    e = clock();
    time_use = (double)(e - s) / CLOCKS_PER_SEC ;
    printf("Thoi gian sao chep cua chuc nang %d la %lf",n,time_use);
    return 0;
}
