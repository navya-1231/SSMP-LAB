#include<stdio.h>
int main(){
int p,r,max[10][10],alloc[10][10],need[10][10],avail[10],flag,k=0,finish[10],seq[10];
printf("Enter the number of process:");
scanf("%d",&p);
printf("Enter the number of resources:");
scanf("%d",&r);
printf("Enter the allocation matrix:\n");
for(int i=0;i<p;i++){
printf("P%d:",i);
for(int j=0;j<r;j++){
scanf("%d",&alloc[i][j]);
}
}
printf("Enter the maximum matrix:\n");
for(int i=0;i<p;i++){
printf("P%d:",i);
for(int j=0;j<r;j++){
scanf("%d",&max[i][j]);
}
}
printf("______Need Matrix________");
for(int i=0;i<p;i++){
finish[i]=0;
printf("\nP%d\t",i);
for(int j=0;j<r;j++){
need[i][j]=max[i][j]-alloc[i][j];
printf("%d\t",need[i][j]);
}
}
printf("\nEnter available vector:");
for(int i=0;i<r;i++)
scanf("%d",&avail[i]);
for(int y=0;y<p;y++){
for(int i=0;i<p;i++){
flag=0;
if(finish[i]==0){
for(int j=0;j<r;j++){
if(need[i][j]<=avail[j]){
flag++;
}
}
if(flag==r){
seq[k]=i;
k++;
finish[i]=1;
for(int j=0;j<r;j++){
avail[j]+=alloc[i][j];

}
}
}
}
}
printf("\n___________Safe Sequence_________\n");
for(int i=0;i<k;i++)
printf("P%d\t",seq[i]);
printf("\n");
}

