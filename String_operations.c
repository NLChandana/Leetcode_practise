/*
PROGRAM-1
i/p:
str[] = hi hello welcome back 
o/p: 
back 
hello
hi 
welcome 
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000],str1[100][100],temp[100];
    scanf("%[^\n]s",str);
    int ind,itr,r=0,c=0;
    for(ind=0;str[ind]!='\0';ind++)
    {
        if(str[ind]!=' ')
            str1[r][c++] = str[ind];
        else 
        {
            str1[r][c]='\0';
            r++;
            c=0;
        }
    }
    for(ind=0;ind<=r;ind++)
    {
        for(itr=0;itr<=r-1-ind;itr++)
        {
            int K=strcmp(str1[itr],str1[itr+1]);
            if(K>0)
            {
                strcpy(temp,str1[itr]);
                strcpy(str1[itr],str1[itr+1]);
                strcpy(str1[itr+1],temp);
            }
        }
    }
    for(ind=0;ind<=r;ind++)
        printf("%s\n",str1[ind]);
    return 0;
}

/*
PROGRAM-2
i/p:
str[] : hi hello welcome back 
rotate: 3 
o/p: 
str[] : back hi hello welcome
*/

#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000],str1[100][100],temp[100];
    scanf("%[^\n]s",str);
    int ind,r=0,c=0,rotate;
    scanf("%d",&rotate);
    for(ind=0;str[ind]!='\0';ind++)
    {
        if(str[ind]!=' ')
            str1[r][c++] = str[ind];
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
        for(ind=1;ind<=r;ind++)
            strcpy(str1[ind-1],str1[ind]);
        strcpy(str1[r],temp);
    }
    for(ind=0;ind<=r;ind++)
        printf("%s\n",str1[ind]);
    return 0;
}

/*
PROGRAM-3
i/p:
str[] : a13d2s4a1x2
o/p:
str[] : aaaddssssaxx 
*/

#include <stdio.h>
int main()
{
    char str[100],ans;
    scanf("%s",str);
    ans=str[0];
    int ind,K=0;
    for(ind=1;str[ind]!='\0';ind++)
    {
        if(str[ind]>='0'&&str[ind]<='9')
        {
            K= K*10+(str[ind]-48);
        }
        else
        {
            while(K--)
                printf("%c",ans);
            ans=str[ind];
            K=0;
        }
    }
    while(K--)
        printf("%c",ans);
    return 0;
}
