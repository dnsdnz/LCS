#include <stdio.h>
#include<string.h>

int i,j,len_x,len_y,c[20][20];
char x[15],y[15],b[20][20];

void print_lcs(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print_lcs(i-1,j-1);
        printf(" %c",x[i-1]);
    }
    else if(b[i][j]=='u')
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}
void lcs_length(void)
{
    len_x=strlen(x);  
    len_y=strlen(y);
    for(i=0;i<=len_x;i++)
        c[i][0]=0;
    for(i=0;i<=len_y;i++)
        c[0][i]=0;
    for(i=1;i<=len_x;i++)
        for(j=1;j<=len_y;j++)
        {
            if(x[i-1]==y[j-1])  
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            }
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    print_lcs(len_x,len_y);   
}

int max(int a, int b);

int lcs( char *x, char *y, int len_x, int len_y )
{
    if (len_x == 0 || len_y == 0)
        return 0;
    if (x[len_x-1] == y[len_y-1])
        return 1 + lcs(x, y, len_x-1, len_y-1);
    else
        return max(lcs(x, y, len_x, len_y-1), lcs(x, y, len_x-1, len_y));
}

int max(int a, int b) 
{
    return (a > b)? a : b;
}

void subArray_x(int arr[], int m) 
{
    for (int i=0; i <m; i++)
    {
        for (int j=i; j<m; j++)
        {
            for (int k=i; k<=j; k++)
                printf("%c\n",x[k]);
            
        }
    }
}

void subArray_y(int arr[], int n)     
{
    for (int i=0; i <n; i++)
    {
        for (int j=i; j<n; j++)
        {
            for (int k=i; k<=j; k++)
                printf("%c",y[k]);
            
        }
    }
}



int main(void)
{
    
    printf("Enter 1st sequence : ");
    gets(x);
    printf("Enter 2nd sequence : ");
    gets(y);
    printf("\nlongest common subsequence is : ");
    lcs_length();  
    
    printf("\nLength of LCS is %d", lcs( x, y, len_x, len_y ) );
    
    int m = sizeof(x)/sizeof(x[0]);
    int n = sizeof(y)/sizeof(y[0]);
    
    printf("\nAll Non-empty Subarrays of strings(brute force):\n");
    subArray_x(x, n);
    return 0;
}
