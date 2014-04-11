#include <stdio.h>
#include <string.h>
#include<cmath> 
// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n, FILE* fp)
{int count=0;
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                fprintf(fp,"%d, ", i+1);
                markMultiples(arr, i+1, n);
		count++;
            }
        }
    }
 fprintf(fp,"%d, ", count);}
 
// Driver Program to test above function
int main()
{
    int n = sqrt(99999);
FILE* fp=fopen("PrimeGenerator.txt","w");	
    fprintf(fp,"{");
    SieveOfEratosthenes(n,fp);
fprintf(fp,"}");	
    return 0;
}	
