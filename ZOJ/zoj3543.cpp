//DP: 中等难度
//num[i][j] 表示1到i的全排列中，以j作末尾的符合前i-1个字符规则的排列数。
//sum[i][j] 表示1到i的全排列中,以不大于j作末尾的符合前i-1个字符规则的排列数.实际要求的是sum[len+1][len+1].
//我们有sum[i][j]=sum[i][j-1]+num[i][j]
//可以证明，当字符为'I'时,num[i][j]=sum[i-1][j-1]
//当字符为'?'时，num[i][j]=sum[i-1][i-1],相减即可得出'U'的情况
//证明基于以下两个结论：
//1:任何n个不重复的数的全排列数相同
//2:给定一个长度为i-1的字符串，由{1,2,...,i}组成的合法排列数和由{1,2,...,j-1,j+1,...,i+1}
//组成的合法排列数是相同的。


#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int main(){
	
	char str[1002];
	long long sum[1005][1005];
	sum[1][1]=1;
	while(scanf("%s",str)!=EOF){
		int len=strlen(str);
		for(int i=2;i<len+2;++i)
			sum[i][0]=0;
		for(int i=2;i<len+2;++i){
			for(int j=1;j<=i;++j){
				if(str[i-2]=='I'){
					sum[i][j]=sum[i][j-1]+sum[i-1][j-1];
					//printf("%d %d %d\n",i,j,sum[i][j]);
				}
				else if(str[i-2]=='D'){
					sum[i][j]=sum[i][j-1]+sum[i-1][i-1]-sum[i-1][j-1];
				}
				else{
					sum[i][j]=sum[i][j-1]+sum[i-1][i-1];
					//printf("%d %d %d\n",i,j,sum[i][j]);
				}
				sum[i][j]=(sum[i][j]+MOD)%MOD;
			}
		}
		printf("%lld\n",(sum[len+1][len+1]+MOD)%MOD);
	}
	return 0;
}
