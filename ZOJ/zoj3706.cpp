#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>

using namespace std;
int num_of_mass(int a, int b, int c){
	set<int> myset;
	for(int i=0;i<3;++i){
		int lefta=0;
		int righta=0;
		if(i==1)lefta+=a;
		else if(i==2)righta+=a;
		for(int j=0;j<3;++j){
			int leftb=lefta;
			int rightb=righta;
			if(j==1)leftb+=b;
			else if(j==2)rightb+=b;
			for(int k=0;k<3;++k){
				int leftc=leftb;
				int rightc=rightb;
				if(k==1)leftc+=c;
				else if(k==2)rightc+=c;
				int mass=abs(rightc-leftc);
				if(mass>0)myset.insert(mass);
			}
		}
	}
	//printf("CPLUSPLUS: %d %d %d %d\n",a,b,c,myset.size());
	return myset.size();
}
using namespace std;
int main(){
	//freopen("zoj3706_data","r",stdin);
	//freopen("out_cpp.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		int tmpmax=0;
		for(int j=1;j<a;++j){
			tmpmax=max(tmpmax,num_of_mass(j,a-j,b));
		}
		for(int j=1;j<b;++j){
			tmpmax=max(tmpmax,num_of_mass(j,b-j,a));
		}
		printf("%d\n",tmpmax);
	}
}
