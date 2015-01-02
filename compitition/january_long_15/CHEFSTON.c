#include<stdio.h>
#define SIZE 100005
int main(){
	long int N,K;
	long int T;
	long int tt[SIZE],profit[SIZE];//tt is time taken to pick 
//stone of kind i
	long int i,j,k;
	long long int m_profit,t_profit;
	scanf("%ld",&T);
	while(T--){
		m_profit=0;
		t_profit=0;
		scanf("%ld%ld",&N,&K);
		for(i=0;i<N;i++) scanf("%ld",&tt[i]);
		for(i=0;i<N;i++) scanf("%ld",&profit[i]);
		for(i=0;i<N;i++){
			t_profit=(K/tt[i])*(long long int)profit[i];
			if(m_profit<t_profit) m_profit=t_profit;
		}
		printf("%lld\n",m_profit);
	}
	return 0;
}
