
Sort the words in Dictionary order

i/p: hi hello welcome back
o/p:
back
hello
hi 
back

strcmp->0(equal),+(first is greater),-(second is greater)


#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000],str1[100][100],temp[100];
    int r=0,c=0;
    scanf("%[^\n]s",str);
    for(int ind=0;str[ind]!='\0';ind++)
    {
        if(str[ind]!=' ')
        {
            str1[r][c++]=str[ind];
        }
        else
        {
            str1[r][c]='\0';
            r++;
            c=0;
        }
    }
    for(int ind=0;ind<=r;ind++)
    {
        for(int itr=0;itr<r-ind-1;itr++)
        {
            int k=strcmp(str1[itr],str1[itr+1]);
            if(k)
            {
               strcpy(temp,str1[itr]);
               strcpy(str1[itr],str1[itr+1]);
               strcpy(str1[itr+1],temp);
            }
        }
    }
    for(int i=0;i<=r;i++)
    {
        printf("%s\n",str1[i]);
    }
    return 0;
}

*/



#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000],str1[100][100],temp[100];
    int r=0,c=0,rotate,ind;
    scanf("%[^\n]s",str);
    scanf("%d",&rotate);
    for(int ind=0;str[ind]!='\0';ind++)
    {
        if(str[ind]!=' ')
        {
            str1[r][c++]=str[ind];
        }
        else
        {
            str1[r][c]='\0';
            r++;
            c=0;
        }
    }
    while(rotate--)
        {
        strcpy(temp,str1[0]);
        for(ind=0;ind<=r;ind++)
        {
            strcpy(str1[ind-1],str1[ind]);
        }
        strcpy(str1[r],temp);
    }
    for(int i=0;i<=r;i++)
    {
        printf("%s\n",str1[i]);
    }
    return 0;
}

