#include <stdio.h>

int N;          // 棋盘大小（全局，方便递归用）
int full;       // �? N 位全 1 的掩�?
int count = 0;  // 解的个数（全局计数，同您之前学的计数版�?

/* 位运算回溯：cols=列占�?, diag1=左上对角�?, diag2=右上对角�?, row=当前�? */
void solve(int cols, int diag1, int diag2, int row){
    if(row == N){            // 所有行都放�? �? 找到一个解
        count++;
        return;
    }
    int available = full & ~(cols | diag1 | diag2);  // �? 本行可用�?
    while(available){                                 // 逐列尝试
        int p = available & -available;              // �? 取最低位�? 1（下一候选列�?
        available ^= p;                              // �? 摘掉该候�?
        // �? 递归：放 p 列；对角线随行下移分别左�?/右移
        solve(cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, row + 1);
    }
}

int main(void){
    N = 8;
    full = (1 << N) - 1;     // 0b11111111
    solve(0, 0, 0, 0);
    printf("N=%d ʱ���� %d �ֽ�\n", N, count);
    return 0;
}