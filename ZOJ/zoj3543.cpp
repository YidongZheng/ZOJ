//DP: �е��Ѷ�
//num[i][j] ��ʾ1��i��ȫ�����У���j��ĩβ�ķ���ǰi-1���ַ��������������
//sum[i][j] ��ʾ1��i��ȫ������,�Բ�����j��ĩβ�ķ���ǰi-1���ַ������������.ʵ��Ҫ�����sum[len+1][len+1].
//������sum[i][j]=sum[i][j-1]+num[i][j]
//����֤�������ַ�Ϊ'I'ʱ,num[i][j]=sum[i-1][j-1]
//���ַ�Ϊ'?'ʱ��num[i][j]=sum[i-1][i-1],������ɵó�'U'�����
//֤�����������������ۣ�
//1:�κ�n�����ظ�������ȫ��������ͬ
//2:����һ������Ϊi-1���ַ�������{1,2,...,i}��ɵĺϷ�����������{1,2,...,j-1,j+1,...,i+1}
//��ɵĺϷ�����������ͬ�ġ�


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
