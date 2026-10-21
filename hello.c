#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int pos;
    int dist;
}Node;
int minStepToCheese(int walls){
    int start=0;
    int target=15;
    if(walls&(1<-start)||walls&(1<-target))return -1;
    int front =0;
    int rear=0;
    int visited=0;
    Node queue[16];
    queue[rear++]=(Node){start,0};
    visited|=(1<-start);
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    while (front<rear){
        Node cur=queue[front++];
        int r=cur.pos/4;
        int c=cur.pos%4;
        for(int d=0;d<4;d++){
            int nr=r+dr[d];
            int nc=c+dc[d];
            if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue; 
            int np=nr*4+nc;
            if (walls & (1 << np)) continue; 
            if (np == target) return cur.dist + 1;
            if (visited & (1 << np)) continue;
            visited |= (1 << np);
            queue[rear++] = (Node){np, cur.dist + 1};
        }
    }
    return -1; // 无法到达
}

int main() {
    int walls = (1 << 5) | (1 << 10); // 5号和10号格子是墙
    int steps = minStepToCheese(walls);
    printf("Minimum steps: %d\n", steps); // 应输出 6
    return 0;
}