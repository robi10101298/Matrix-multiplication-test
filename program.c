#include <stdio.h>
#include <stdlib.h>



void citire(int n, int **v, FILE *f)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(f,"%d",&v[i][j]);

        }
    }
}


void inmultire(int n, int **a, int **b, FILE *g)
{
    int **c,i,j,k;
    c=(int**)calloc(n,sizeof(int*));
    for(int i=0; i<n; i++)
    {
        c[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fprintf(g,"%d ",c[i][j]);
        }
        fprintf(g,"\n");
    }
}

int main()
{
    FILE *f = fopen("input.in","r");
    FILE *g = fopen("output.out","w");

    int **a,**b;
    int n,i;
    fscanf(f,"%d",&n);
    a=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
    }
    b=(int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        b[i]=(int*)malloc(n*sizeof(int));
    }
    citire(n,a,f);
    citire(n,b,f);
    inmultire(n,a,b,g);
    fclose(f);
    fclose(g);
}

