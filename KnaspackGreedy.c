#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct good
{
    int w,v;
    double rela;
}*th,good;
void Random(th *g,int n){
    *g=(th)malloc(sizeof(good)*n);
    srand(time(0));
    for(int i=0;i<n;i++){
         (*g)[i].w=rand()%100;
         if((*g)[i].w==0){
            (*g)[i].w=1;
         }
        (*g)[i].v=rand()%100;
        (*g)[i].rela=1.0*(*g)[i].v/(*g)[i].w;
        printf("%d  %d %lf\n",(*g)[i].w,(*g)[i].v,(*g)[i].rela);
    }
    printf("\n\n");
}
void siftdown(th *g,int n,int P){
    if(P*2>n) return;
    if(P*2+1>n){
        if((*g)[P-1].rela<(*g)[P*2-1].rela){
            good temp=(*g)[P*2-1];
            (*g)[P*2-1]=(*g)[P-1];
            (*g)[P-1]=temp;
            siftdown(g,n,P*2);
        }
    }else{
        good temp;
        int t;
        if((*g)[P*2].rela>=(*g)[P*2-1].rela){
            temp=(*g)[P*2];
            t=P*2;
        }else{
            temp=(*g)[P*2-1];
            t=P*2-1;
        }
        if(temp.rela>(*g)[P-1].rela){
            temp=(*g)[t];
            (*g)[t]=(*g)[P-1];
            (*g)[P-1]=temp;
            siftdown(g,n,t+1);
        }
    }
}
void deleteTop(th *g,int *n){
    good temp=(*g)[0];
    (*g)[0]=(*g)[(*n)-1];
    (*g)[*n-1]=temp;
    (*n)-=1;
    siftdown(g,*n,1);
}
void cHeap(th *g,int n){
    for(int p=n/2;p>0;p--){
        siftdown(g,n,p);
    }
}
void KnaspackGreedy(th g,int n,float *x,int c){
    int m=n;
    int i=n-1;
    int weight=0;
    double value=0;
    cHeap(&g,m);
    while(m>0){
        good temp=g[0];
        deleteTop(&g,&m);
        if(weight+temp.w<=c){
            weight+=temp.w;
            value+=temp.v;
            x[i]=1;
        }else if(weight+temp.w>c){
            int t=c-weight;
            double k=1.0*t/temp.w;
            value+=k*temp.v;
            x[i]=k;
            break;
        }
        i--;
    }
    for(i=n-1;x[i]!=0;i--){
        printf("%f    %d    %d   %lf\n",x[i],g[i].w,g[i].v,g[i].rela);
    }
    printf("%lf\n",value);
}
int main(){
    int n,c;
    n=20;
    c=200;
    th g=NULL;
    float x[n];
    for(int i=0;i<n;i++){
        x[i]=0;
    }
    Random(&g,n);
    KnaspackGreedy(g,n,x,c);
    return 0;
}