// YASH ASHOK SHIRSATH
// Implement a program for Graph Coloring using Backtracking

#include<stdio.h>
int G[50][50],x[50];  //G:adjacency matrix,x:colors
void next_color(int k){
   int i,j;

   x[k]=1;  //coloring vertex with color1
   for(i=0;i<k;i++){ //checking all k-1 vertices-backtracking
     if(G[i][k]!=0 && x[k]==x[i])  //if connected and has same color
       x[k]=x[i]+1;  //assign higher color than x[i]
   }
}

int main(){
  int n,e,i,j,k,l;
  printf("Enter no. of vertices : ");
  scanf("%d",&n);  //total vertices
  printf("Enter no. of edges : ");
  scanf("%d",&e);  //total edges

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j]=0;  //assign 0 to all index of adjacency matrix

  printf("Enter indexes where value is 1-->\n");
  for(i=0;i<e;i++){
    scanf("%d %d",&k,&l);
    G[k][l]=1;
    G[l][k]=1;
  }

  for(i=0;i<n;i++)
    next_color(i);  //coloring each vertex

  printf("Colors of vertices -->\n");
  for(i=0;i<n;i++)  //displaying color of each vertex
    printf("Vertex[%d] : %d\n",i+1,x[i]);

  return 0;
}
