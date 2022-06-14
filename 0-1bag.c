#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void Random(int **w,int **v,int n){
    *w=(int*)malloc(sizeof(int)*n);
    *v=(int*)malloc(sizeof(int)*n);
    srand(time(0));
    for(int i=0;i<n;i++){
        (*w)[i]=rand()%100;
        (*v)[i]=rand()%100;
    }
}
int max(int x,int y){
    if(x>=y)return x;
    else return y;
}
void KnapsackDP(int *w,int *v,int c,int n){
    int res[n+1][c+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=c;j++){
            res[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<c;j++){
            if(j-w[i]>=0){
                res[i+1][j+1]=max(res[i][j+1],res[i][j-w[i]+1]+v[i]);
            }
        }
    }
    printf("结果为：%d\n",res[n-1][c-1]);
    system("Pause");
}
int main(){
    int n,c;
    int *w,*v;
    printf("请输入物品数量及背包容量:\n");
    scanf("%d %d",&n,&c);
    Random(&w,&v,n);
    printf("随机生成的w，v数组：\n");
    for(int i=0;i<n;i++){
        printf("%d %d\n",w[i],v[i]);
    }
    KnapsackDP(w,v,c,n);
    return 0;
}