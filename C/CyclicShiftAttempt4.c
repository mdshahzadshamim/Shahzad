int binval(int n, char *a)
{
    int sum=0,i=n-1;
    while(i>=0)
    {sum += (a[i]-'0')*pow(2,n-1-i);i--;}
    return sum;
}
int main()
{
    int t; scanf("%d",&t);
    for(int itr=0;itr<t;itr++){
    int n; scanf("%d",&n);    
    long unsigned int k; scanf("%lu",&k);
    char a[n]; scanf("%s",a);
    int val[n],high=0,count=0,result=0;;val[0]=binval(n,a);
    for(int c=0;c<n-1;c++)
        {
            char temp=a[0];
            for(int i=0;i<n-1;i++)
            {
                a[i]=a[i+1];
            }
            a[n-1]=temp;

            val[c+1]=value(n,a);
            if(val[c+1]>val[c]){high=c+1;count=1;result=0;}
            else if(val[c+1]==val[high]){count++;result=0;}
            else if(val[c+1]<val[high])result++;
        }
    int result2=0;
    long unsigned int constant=(k/count); int variable=(k%count);
    long unsigned int output;
    if(variable==0) output=n*constant-result;
    else if(variable>0)
    {
        for(int c=0;c<n && variable>0;c++)
        {
            if(val[c]!=val[high])
            {
                result2++;
            }
            else if(val[c]==val[high])
            {
                variable--;
            }
        }
        output=n*constant+result2;
    }
    printf("%lu\n",output);}
    return 0;
}