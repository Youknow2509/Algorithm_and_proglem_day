#include <stdio.h>
 int main(){
   int a[1000];
   int i, j,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]); 
   } 
   for(i=0;i<n;i++)
   {
    if(a[i]==0)
    printf("NULL\n");
 if(a[i]>0)
 {
  if(a[i]%2==0)
  printf("EVEN POSITIVE\n");
  else
  printf("ODD POSITIVE\n"); 
   }     
 if(a[i]<0) 
 {
   if(a[i]%2==0)
   printf("EVEN NEGATIVE\n");
   else
   printf("ODD NEGATIVE\n"); 
 }
 } 
 
 }