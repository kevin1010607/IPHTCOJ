#include<stdio.h>
#include<stdlib.h>
int n, a[100005], q, x;
int cmp(const void *a, const void *b){
    return (*(const int*)a)-(*(const int*)b);
}
int lower(int x){
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(x <= a[mid]) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int upper(int x){
    int l = 0, r = n-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(x < a[mid]) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    qsort(a, n, sizeof(int), cmp);
    scanf("%d", &q);
    //for(int i = 0; i < n; i++) printf("%d ", a[i]);
    while(q--){
        scanf("%d", &x);
        //printf("%d %d\n", upper(x), lower(x));
        printf("%d\n", upper(x)-lower(x));
    }
    return 0;
}