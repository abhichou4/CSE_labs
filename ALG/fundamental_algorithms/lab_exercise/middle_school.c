#include <stdio.h>
#include <stdlib.h>

//Return prime numbers in [2, n]
int* primes(int n, int* size) {
    int* arr = (int*)calloc(n+1, sizeof(int));
    for (int i=0; i<n+1; i++)
        arr[i] = i;
    
    int k;
    for(int j=2; j*j<=n; j++) {
        if (arr[j]!=0) {
            k = j*j;
            while (k < n+1) {
                arr[k] = 0;
                k += j;
            }
        }
    }

    int count=0;
    for (int k=0; k<n+1; k++) {
        if (arr[k]==0) count++;
    }

    *size = n-count; //-1 for 1 
    int* res = (int*)calloc(*size, sizeof(int));
    for (int l=2, m=0; l<n+1; l++) {
        if (arr[l]!=0) 
            res[m++] = arr[l];
    }
    free(arr);
    return res;
}

int* prime_factors(int n, int* size) {
    int s;
    int* prime_arr = primes(n, &s);
    int * prime_fac = (int*)calloc(s, sizeof(int));
    int k=0;
    for (int i=0; i<s; i++) {
        int num = n;
        while (num%prime_arr[i]==0) {
            prime_fac[k++] = prime_arr[i];
            num /= prime_arr[i];
        }
    }
    *size = k;
    return prime_fac;
}

int gcd(int m, int n) {
    int s1, s2, gcd=1;
    int* pf_m = prime_factors(m, &s1);
    int* pf_n = prime_factors(n, &s2);
    
    for (int i=0; i<s1; i++) {
        for (int j=0; j<s2; j++) {
            if (pf_m[i]==pf_n[j]) {
                gcd *= pf_n[j];
                pf_n[j] = 0; //zero-out factors used
                break;
            }
        }
    }
    free(pf_m); free(pf_n);
    return gcd;
}

int main(void) {
    int m, n;
    printf("Enter Numbers:\n");
    scanf("%d %d", &m, &n);
    printf("GCD: %d\n", gcd(m, n));
    return 0;
}