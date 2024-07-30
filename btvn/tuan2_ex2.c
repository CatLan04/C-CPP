#include<stdio.h>

typedef struct
{
    char name[20];
    char telephone[12];
    char mail[30];
} phoneadress;
void slip(FILE *fin, FILE *fout1, FILE *fout2)
{

}
int main(int argc, char *argv[])
{
    FILE *fp1,*fp2,*fp3;
    phoneadress *parray;
    if (argc != 5)
    {
        printf("Error!!!");
        return 1;
    }
    int n;
    fp1 = fopen(argv[1],"r+b");
    fp2 = fopen(argv[3],"w+b");
    fp3 = fopen(argv[4],"w+b");
    n = atoi(argv[2]);
    if (fp1 == NULL)
    {
        printf("Cannot open file!!!");
        return 1;
    }
    parray = (phoneadress *)malloc(n*sizeof(phoneadress));

    int irc;
    irc = fread(parray,sizeof(phoneadress),1,fp1);
    printf("%d\n",n);
    for (int i = 0; i < 2; i++)
    {
        printf("%s-",parray[i].name);
        printf("%s-",parray[i].telephone);
        printf("%s-\n",parray[i].mail);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp2);
    return 0;

}
