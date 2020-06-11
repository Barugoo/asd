int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int maxRepeatingInts (int* arr)
{
    int i,tmp,len,*tmpArr,currCount,maxCount;

    len = arr[0];
    if (len == 1)
    {
        return 1;
    }

    tmpArr = (int*)malloc(len*sizeof(int*));
    for(i=1; i<=len; i++){ // пропускаем элемент с длиной
        tmpArr[i-1]=arr[i];
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
        a[i]=(int*)malloc((n+1)*sizeof(int));
        a[i][0]=n; // первый элемент будет хранить количество элементов в строке
        for(j=1; j<=n; j++)
        {
            printf("a%d", i+1);
            printf("%d:", j);
            scanf("%d",&tmp);
            a[i][j]=tmp;
        }
        v[i]=maxRepeatingInts(a[i]);
    }

    printf("matrix:\n");
    for(i=0; i<m; i++,printf("\n"))
    {
        n=a[i][0];
        for(j=1; j<=n; j++) printf("%3d",a[i][j]);
    }

    printf("vector:\n");
    for(i=0; i<m; i++)
    {
        printf("%3d", v[i]);
    }
    return 0;
}