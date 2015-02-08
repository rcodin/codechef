//Chef and Chain
#include <stdio.h>
#include <string.h>
int main(){
	long int T,i,j,len;
	char S[100001],cnt1,cnt2,tmp[100001];
	scanf("%ld",&T);
	while(T--){
		scanf("%s",S);
		len=strlen(S);
		strcpy(tmp,S);
		cnt1=0;
		if(tmp[0]=='-'){
			cnt1=1;
			tmp[0]='+';
		}
		for(i=0;i<len-1;i++){
			if((tmp[i]==tmp[i+1])){
				cnt1++;
				if(tmp[i]=='+') tmp[i+1]='-';
				else tmp[i+1]='+';
			}
		}
		strcpy(tmp,S);
		cnt2=0;
		if(tmp[0]=='+'){
			cnt2=1;
			tmp[0]='-';
		}
		for(i=0;i<len-1;i++){
			if((tmp[i]==tmp[i+1])){
				cnt2++;
				if(tmp[i]=='+') tmp[i+1]='-';
				else tmp[i+1]='+';
			}
		}
		printf("%d\n",(cnt1>cnt2)?cnt2:cnt1);
	}
	return 0;
}