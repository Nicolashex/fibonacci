#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


void primerfactors(long long num){
    int count;
    int primero = 0;

    for(count = 2; num>1; count++){
        while(num % count == 0){
            if(primero==0){
                printf("%d ", count);
                primero = 1;
            }
            else{

                printf("x %d ", count);
            }

            num = num/count;
        }
    }
}
int fib(int n) {
    long long i, j;
    if (n < 2)
        return n;
    else {
        #pragma omp taks shared(i) firstprivate(n)
        i = fib(n - 1);
        #pragma omp task shared(j) firstprivate(n)
        j = fib(n - 2);
        #pragma omp taskwait
        return i + j;
    }
}
int main() {
    int n = 47;
    long long result;
    printf("result is ");

    #pragma omp parallel shared(n)
    {
        #pragma omp single
        result = fib(n);

    }
    primerfactors(result);
    return 0;
}
