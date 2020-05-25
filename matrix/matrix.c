int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int maxRepeatingInts (int* arr, int len)
{
    int i,tmp,*tmpArr,currCount,maxCount;

    if (len == 1)
    {
        return 1;
    }

    tmpArr = (int*)malloc(len*sizeof(int*));
    for(i=0; i<len; i++){
        tmpArr[i]=arr[i];
    }

    currCount = 0;
    maxCount = currCount;

    qsort (tmpArr, len, sizeof(int), compare);

    for(i=0; i<len; i++)
    {
        if (tmp != tmpArr[i])
        {
            currCount = 0;
        }

        currCount++;

        if (currCount > maxCount)
        {
            maxCount = currCount;
        }
        tmp = tmpArr[i];
    }
    return maxCount;
}

int main(int argc,char* argv[])
{   
    int i,j,n,m,tmp,**a,*v;
 
    printf("m:");
    scanf("%d",&m);
    a=(int**)malloc(m*sizeof(int*));
    v=(int*)malloc(m*sizeof(int*));
    for(i=0; i<m; i++)
    {
        printf("n%d:",i+1);
        scanf("%d",&n);
        a[i]=(int*)malloc(n*sizeof(int));
        for(j=0; j<n; j++)
        {
            printf("a%d", i+1);
            printf("%d:", j+1);
            scanf("%d",&tmp);
            a[i][j]=tmp;
        }
        v[i]=maxRepeatingInts(a[i], n);
    }

    printf("matrix:\n");
    for(i=0; i<n; i++,printf("\n"))
    {
        m=*a[i];
        for(j=0; j<m; j++) printf("%3d",a[i][j]);
    }

    printf("vector:\n");
    for(i=0; i<n; i++)
    {
        printf("%3d", v[i]);
    }
    return 0;
}