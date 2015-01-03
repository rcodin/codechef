#include<stdio.h>
/*Author=Ronit Halder
Here GCD is calculated by euclid's algorithm
*/
#define SIZE 100001
int euclid(int m,int n){
  if(n==0)
    return m;
  else return euclid(n,m%n);
}
int main(void){
  int T,N,Q,L,R;
  int i,j,k;
  int gcdl,gcdr,ans;
/*gcdl is gcd of the right part
  and gcdr is gcd of the left part
*/
  int fgcd[SIZE],rgcd[SIZE],A[SIZE];
  scanf("%d",&T);
  while(T--){
    scanf("%d%d",&N,&Q);
    for(i=1;i<=N;i++) scanf("%d",&A[i]);
    fgcd[1]=A[1];
    for(i=2;i<=N;i++) 
      fgcd[i]=euclid(fgcd[i-1],A[i]);
    rgcd[N]=A[N];
    for(i=N-1;i>0;i--)
      rgcd[i]=euclid(rgcd[i+1],A[i]);
    for(i=0;i<Q;i++){
      scanf("%d%d",&L,&R);
      if(L==1) ans=rgcd[R+1];
      else if(R==N) ans=fgcd[L-1];
      else ans=euclid(fgcd[L-1],rgcd[R+1]);
      printf("%d\n",ans);
    }
  }
  return 0;
}
