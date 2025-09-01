#include <stdio.h>
#include <stdlib.h>
int main(){
int n,i,j,index,input_element,temp;
int *ar;
printf("Enter size of array: ");
scanf("%d",&n);
ar = (int*) malloc(n * sizeof(int));
printf("Enter the element to be inserted: ");
scanf("%d %d",&index,&input_element);
printf("Array input:\n");
for(i=0;i<n;i++){
scanf("%d",&ar[i]);
}
//for sorting
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
if(ar[j] > ar[j+1]){
temp=ar[j];
ar[j]=ar[j+1];
ar[j+1]=temp;

}
    }
}

//for insertion
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
return(0);
}