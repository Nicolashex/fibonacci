#include<stdio.h>
#include<omp.h>



void primerfactors(long long num){
    int count;
    int primero = 0;

    for(count = 2; num>1; count++){
        while(num % count == 0){
            if(primero==0){
                printf("= %d", count);
                primero = 1;
            }
            else{

                printf(" x %d", count);
            }

            num = num/count;
        }

    }
}

void fibonacci(long long A[], long long N){
    unsigned long long i;
    A[0] = 0;
    A[1] = 1;
    for(i = 2; i < N; i++){
        A[i] = A[i - 1] + A[i - 2];
    }
}


int main(){
    long long N = 47;
    long long fib[N];
    long long i;


    
    #pragma omp parallel sections
    {
       
        #pragma omp section
        {
            fibonacci(fib, N);
        }
    }


    printf("Fibonacci Series:\n");
    for(i = 0; i < N; i++){
        printf("Fibonacci(%d): %d ", i+1, fib[i]);
        primerfactors(fib[i]);
        printf("\n");

    }
    printf("\n");

    return 0;
}
