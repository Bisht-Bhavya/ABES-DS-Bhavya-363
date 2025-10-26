#include <stdio.h>
#include <stdlib.h>
int main(){
int n,i,index,input_element,temp1,temp2;
int *ar;
printf("Enter size of array: ");
scanf("%d",&n);
ar = (int*) malloc(n * sizeof(int));
printf("Array input:\n");
for(i=0;i<n;i++){
    scanf("%d",&ar[i]);
}
printf("Enter the element to be inserted: ");
scanf("%d %d",&index,&input_element);
ar = (int*) realloc(ar, (n+1) * sizeof(int));
for(i=n;i>0;i--){
    if(i>index){
       ar[i]=ar[i-1];
    }
}

ar[index]=input_element;

for(i=0;i<n;i++){
printf("%d\t",ar[i]);
} 
free(ar);
return(0);
}