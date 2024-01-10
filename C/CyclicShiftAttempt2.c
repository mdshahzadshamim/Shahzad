#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int value(int length, char a[])//Binary Value
{
    int decval = 0, temp = 0;//Convert string into integer form if convertible
    //int length = strlen(a);
    while(temp<length)
    {
        if((int)a[temp] > 47 && (int)a[temp] < 50)//Check if it is binary
        {
            int tempint = a[temp] - '0';//temporary integer value
            decval += tempint * pow(2,length-temp-1);//adding the decimal values
            //printf("\nOneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
        }
        else
        {
            printf("\nInvalid Input\n");exit(1);//the ascii value is not of an int
        }
        
        temp++;
    }
    //printf("%d\n",decval);
    return(decval);
}

int main()
{
    int t;scanf("%d",&t);//Number of TCs
    for(int itr=0;itr<t;itr++)
    {
        int n;scanf("%d",&n);//Size of String
        int k;scanf("%d",&k);//No of times string-value needs to be largest
        char a[n]; scanf("%s",a);//Scanning the String
        
        int val[n],high=0;
        for(int c=0;c<n-1;c++)//Shifting n-1 number of times
        {
            if(c==0)val[c]=value(n,a);//Checking value of Binary String
            
            //printf("\n\nTwo\n\n");

            int temp=a[0];//Shifting start - Copying first value to temp
            for(int i=0;i<n-1;i++)
            {
                a[i]=a[i+1];//Shifting each element once to left
            }
            a[n-1]=temp;//Shifting end - Copying temp value to last element

            //printf("\n\nThree\n\n"); 

            val[c+1]=value(n,a);//Checking value of Binary String
            if(val[c+1]>val[c])high=c+1;//Comparing for greatest
        }

        int no_of_high_values=0,x=0,output=0;
        while(no_of_high_values<k)
        {
            //printf("%d %d\n",val[x],val[high]);
            if(val[x] == val[high])
            no_of_high_values++;//printf("   True   \n");}
            if(x==n-1) x=0;
            else x++;
            output++; 
        }output--;
        
        //int output=(high)+n*(k-1);//printf("\n\nFour\n\n");
        printf("%d\n",output);
    }

	return 0;
}