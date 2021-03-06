#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 30;

int n=4,k=2,x=6,maxSumSqu = -1,A[maxn]={2,3,3,4};
vector<int> temp,ans;

void DFS(int index, int nowK, int sum,int sumSqu){
	if(nowK == k && sum == x){
		if(sumSqu>maxSumSqu){
			maxSumSqu = sumSqu;
			ans = temp;
		}
		return;
	}
	if(index == n || nowK > k || sum >x) return;
	//ѡȡindex
	temp.push_back(A[index]);
	DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
	temp.pop_back();
	DFS(index+1,nowK,sum,sumSqu); 
}
int main(){
	
	DFS(0,0,0,0);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	return 0;
}




