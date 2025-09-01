#include <stdio.h>
#include <stdlib.h>
int main(){
int i,loc,n;
int *ar;
printf("Enter size of array: ");
scanf("%d",&n);
ar = (int*) malloc(n * sizeof(int));
printf("Enter array: \n");
for(i=0;i<n;i++){
    scanf("%d",&ar[i]);
}
printf("Enter the location to smite: ");
scanf("%d",&loc);
for(i=0;i<n;i++){
if(i>=loc){
ar[i]=ar[i+1];
}
}
n=n-1;
ar = (int*) realloc(ar, n* sizeof(int));
for(i=0;i<n;i++){
printf("%d\n",ar[i]);
}
free(ar);
return(0);
}