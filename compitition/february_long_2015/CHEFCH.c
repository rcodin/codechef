//Chef and Chain
#include <stdio.h>
#include <string.h>
int main(){
	int T,i,j,len,cnt1,cnt2;
	char S[100001],p,c;
	scanf("%ld",&T);
	while(T--){
		scanf("%s",S);
		len=strlen(S);
		// strcpy(tmp,S);
		cnt1=0;
		p=S[0];
		if(S[0]=='-'){
			cnt1=1;
			p='+';
		}
		for(i=0;i<len-1;i++){
			c=S[i+1];
			if(p==c){
				cnt1++;
				if(c=='+') c='-';
				else c='+';
			}
			p=c;
		}
		// strcpy(tmp,S);
		cnt2=0;
		p=S[0];
		if(S[0]=='+'){
			cnt2=1;
			p='-';
		}
		for(i=0;i<len-1;i++){
			c=S[i+1];
			if(p==c){
				cnt2++;
				if(c=='+') c='-';
				else c='+';
			}
			p=c;
		}
		printf("%ld\n",(cnt1>cnt2)?cnt2:cnt1);
	}
	return 0;
}