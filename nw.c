#include<stdio.h>
int cs(char a,char b)//±È½ÏÁ½¸ö×Ö·ûÊÇ·ñÏàÍ¬
{
    if(a==b)
        return 1;
    else
        return 0;
}
int max(int a,int b,int c)//·µ»ØÈý¸öÊýÖÐ×î´óµÄ
{
    if(a>=b&&a>=c)
        return a;
    if(b>=a&&b>=c)
        return b;
    if(c>=a&&c>=b)
        return c;
}
void NW(char s1[],char s2[])
{
    int f[9][9];
    int d=-1,i,j,t1,t2,t3,count=0;
    char ns1[20],ns2[20];
    for(i=0;i<9;i++)//³õÊ¼»¯µÚÒ»ÐÐºÍµÚÒ»ÁÐ
    {
        f[i][0]=i*(-1);
        f[0][i]=i*(-1);
    }
    for(i=0;i<8;i++)//½¨Á¢µÃ·Ö¾ØÕó
    for(j=0;j<8;j++)
    {
        t1=f[i+1][j]+d;
        t2=f[i][j+1]+d;
        t3=f[i][j]+cs(s1[i],s2[j]);
        f[i+1][j+1]=max(t1,t2,t3);
    }
    for(i=0;i<9;i++)//´òÓ¡³öµÃ·Ö¾ØÕó
    {
        for(j=0;j<9;j++)
        {
            printf("%d\t",f[i][j]);
        }
        printf("\n");
    }
    for(i=8,j=8;i>0&&j>0;)//»ØËÝÀ´Ô´
    {
        if((f[i-1][j-1]+cs(s1[i-1],s2[j-1]))>=(f[i-1][j]+d)&&(f[i-1][j-1]+cs(s1[i-1],s2[j-1]))>=(f[i][j-1]+d))//À´×Ô¶Ô½ÇÏß
        {
            ns1[count]=s1[i-1];
            ns2[count]=s2[j-1];
            count++;
            i--,j--;
            continue;
        }
        else if((f[i-1][j]+d)>=(f[i][j-1]+d))//À´×ÔÉÏ²¿
        {
            ns1[count]=s1[i-1];
            ns2[count]=' ';
            count++;
            i--;
            continue;
        }
        else//À´×Ô×ó²¿
        {
            ns1[count]=' ';
            ns2[count]=s2[j-1];
            count++;
            j--;
            continue;
        }
    }
    for(count--;count>=0;count--)//´òÓ¡³ö×îÓÅ±È¶Ô½á¹û
    {
        printf("%c-%c\n",ns1[count],ns2[count]);
    }
}
int main()
{
    char s1[]="AGCACACA",s2[]="ACACACTA";
    printf("%s\n%s\n",s1,s2);
    NW(s1,s2);
    return 0;
}
