#include <stdio.h>
int count;
void nhuanghou(int n,int row,int col,int pie,int na){
    if(row==n){
        count ++;
        return;
    }
    int pos=~(col|pie|na)&((1<<n)-1);
    while(pos!=0){
        int p=pos&-pos;
        pos^=p;
        nhuanghou(n,row+1,col|p,(pie|p)<<1,(na|p)>>1);
    }

}
int main(){
    int n;
    printf("输入层数");
    scanf("%d",&n);
    nhuanghou(n,0,0,0,0);
    printf("共有%d种结果",count);
    return 0;
}