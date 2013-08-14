#include <stdio.h>
#include <algorithm>

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		long long left[3];
		for(int i=0;i<3;++i)
			left[i]=0;
		long long num_left=0;
		long long count=0;
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			++left[x%3];
			num_left+=x/3;
		}
		count=num_left;
		while(num_left!=0){
			long long tmp_cnt;
			while(left[2]!=0){
				tmp_cnt=std::min(num_left,left[2]);
				count+=tmp_cnt;
				left[2]-=tmp_cnt;
			}
			while(num_left>=2&&left[1]!=0){
				tmp_cnt=std::min(num_left/2,left[1]);
				count+=tmp_cnt;
				left[1]-=tmp_cnt;
				num_left-=tmp_cnt;
			}
			tmp_cnt=num_left/3;
			count+=tmp_cnt;
			num_left-=2*tmp_cnt;
			if((num_left<=1&&left[2]==0) || (num_left<=2 && left[1]==0))break;
		}
		printf("%lld\n",count);
	}
	return 0;
}
