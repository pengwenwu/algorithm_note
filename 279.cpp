#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=100;
struct node{
	int x,y;
	int step;
}S,T,Node;

int n,m; //n*m
char A[maxn][maxn];
bool isqueue[maxn][maxn]={false};
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};

bool test(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return false;
	if(A[x][y] == '*' || isqueue[x][y] == true) return false;
	return true;
}
int BFS(){
	queue<node> Q;
	Q.push(S);
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		if(top.x==T.x && top.y==T.y){
			return top.step;
		}
		for(int i=0;i<4;i++){
			int NewX = top.x+X[i];
			int NewY = top.y+Y[i];
			if(test(NewX,NewY)){
				Node.x=NewX,Node.y=NewY;
				Node.step= top.step+1;
				Q.push(Node);
				isqueue[NewX][NewY] = true;
			}
		}
	}
	return -1;//无法到达终点 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar(); //过滤掉每行后面的换行符 
		for(int j=0;j<m;j++){
			A[i][j] = getchar();
		}
		A[i][m+1] = '\0';
	}
	scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
	S.step=0; //初始化为0
	printf("%d\n",BFS());
	return 0; 
}
 