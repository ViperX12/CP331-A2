//
//  main.c
//  mergeTest
//
//  Created by Giovanni on 2016-03-08.
//  Copyright © 2016 Giovanni. All rights reserved.
//

#include <stdio.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int binarySearch (int target, int *Array, int bottom, int top) {
    // Given a low-to-high sorted Array[0..top],
    // Return i such that Array[i] = target.
    // Return -1 if target is not in Array.
    
    int lower, middle, upper;
    lower = bottom;    upper = top;
    
    // loop invariant: if there is actually an i, A[i]=target,
    //    then upper >= i >= lower. Otherwise don't care.
    // exits function when Array[middle] = value.
    // must find value using middle, otherwise eventually upper < lower and quit.
    
    while ( upper >= lower  ) {
        middle = ( upper + lower ) / 2;
        if (Array[middle] == target){
            return( middle );
        }
        if (Array[middle] < target){
            lower = middle + 1;
        }
        else{
           upper = middle - 1;
        }
    };
    
    // never found.
    return(lower);
}


void merge(int *a, int *b, int *c, int i, int j, int k, int l, int p, int q){
    
    int m, n, r, s, t;
    
    m = j - i;
    n = l - k;
    
    printf("m: %d \n", m);
    
    if (m < n) {
        int z = 0;
        for(z=0;z<8;z++){
            swap(&a[z], &b[z]);
        }
        swap(&m, &n);
    }
    
    if (m <= 0){
        return;
    }

    r = floor((i + j)/2);
    printf("r: %d \n", r);
    s = binarySearch(a[r], b, k, l);
    printf("s: %d \n", s);
    t = p + (r - i) + (s - k);
    printf("t: %d \n\n", t);
    c[t] = a[r];
    
    merge(a, b, c, i, r, k, s, p, t);
    merge(a, b, c, r+1, j, s, l, t+1, q);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int size = 8;
    
    int a[] = {5, 11, 12, 18, 20, 21, 99, 101};
    int b[] = {2, 4, 7, 11, 16, 23, 28, 42};
    int c[16];
    
    merge(a, b, c, 0, size - 1, 0, size - 1, 0, size*2 - 1);
    
    //printf("%d", binarySearch(a[3], a, 0, 7));
    int z = 0;
    while(z<16){
        printf("%d, ", c[z]);
        z += 1;
    }
    
    return 0;
}

