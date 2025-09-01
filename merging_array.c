#include <stdio.h>
int main(){
int i=0,j=0,k=0,n,m;
printf("Enter the size of two arrays: ");
scanf("%d %d",&n,&m);
k=m+n;
printf("Enter the two sorted array: ");
int ar1[n],ar2[m],ar3[k];
for(i=0 ; i<n ; i++){
    scanf("%d",&ar1[i]);
}
for(i=0 ; i<n ; i++){
scanf("%d",&ar2[i]);
}
while( i < n && j < m){
    if(ar1[i] <= ar2[j]){
     ar3[k]=ar1[i];
     i++;
     k++;
    }else if(ar2[j] < ar1[i]){
        ar3[k] = ar2[j];
        j++;
        k++;
    }
}
while (i<n)
{
    ar3[k]=ar1[i];
    i++;
    k++;
}
while (j<m){
ar3[k]=ar2[j];
    j++;
    k++;
}

    return 0;
}