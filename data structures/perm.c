#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct t{
        int data;
        int key;
};
int x,po,c=0;
int mob(struct t b[],int n,int p)
{
        int i=0,j,k,l=0,y;
        k=0;
        y=-1;
        for(i=0;i<n;i++)
        {

                if(b[i].data>=k && b[i].data<p)
                {
                        k=b[i].data;
                        x=i;
                        y=0;
                }
        }
        if(y==-1)
        return -1;
        else{

        if(x==0&&b[x].key==0||x==n-1&&b[x].key==1)
        {
                p=b[x].data;
                mob(b,n,p);
        }
        else if(b[x].key==0)
        {
                if(b[x].data<b[x-1].data)
                {
                        p=b[x].data;
                        mob(b,n,p);
                }
                else
        return b[x].data;
        }
        else if(b[x].key==1)
        {
                if(b[x].data<b[x+1].data)
                {
                        p=b[x].data;
                        mob(b,n,p);
                }
                else
        return b[x].data;
        }

}
}
void swap(int* a,int* b)
{
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
}
void permu(struct t b[],int n,int p)
{
        int l,k,z;

        l=mob(b,n,p);
                z=b[x].data;
        if(l==-1)
        return;
        else{

        if(l!=-1)
        {
                if(b[x].key==1)
                {
                        printf("mobile=%d\n",b[x].data);
                        swap(&b[x+1].data,&b[x].data);
                        swap(&b[x+1].key,&b[x].key);
                        for(k=0;k<n;k++)
                        {

                        printf("%d ",b[k].data);

                        }
                        c++;
                        printf("\n");
                }
                else{

                if(b[x].key==0)
                {
                                printf("mobile=%d\n",b[x].data);
                        swap(&b[x-1].data,&b[x].data);
                        swap(&b[x-1].key,&b[x].key);
                        for(k=0;k<n;k++)
                        {

                        printf("%d ",b[k].data);

                        }
                        c++;
                        printf("\n");
                }
        }
                for(k=0;k<n;k++)
                {
                        if(b[k].data>z)
                        {
                                if(b[k].key==1)
                                b[k].key=0;
                                else
                                b[k].key=1;
                        }
                }
        }
        permu(b,n,po);
}
}
int main()
{
        int n,x,p;
        printf("enter no of integers in ascending order" );
        scanf("%d",&n);
        struct t b[n];
        for(x=0;x<n;x++)
        {
                scanf("%d",&b[x].data);
                b[x].key=0;
        }
        po=b[n-1].data+1;
        p=po;
        permu(b,n,p);
        printf("\n no of permutations %d",c+1);
        return 0;
}

