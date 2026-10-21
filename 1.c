/*P1. 二叉树的顺序存储与四种遍历（综合�?
题目：给定完全二叉树相关操作，一次性实现并说明�?

顺序存储（根下标 1）：set_right_child(parent, data) �? 2*parent+1 写数据；
递归先序遍历（根-�?-右）�?
递归中序、后序遍历；
层序遍历（队�? BFS）；
用显式栈（非递归）模拟先序遍历�?
考点：c-easy-3 二叉树（顺序存储 + �?/�?/后序递归 + 层序 BFS + 栈模拟递归）。——此为树主题唯一一道综合题，覆盖原 P1–P4�?*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 100

int count;

typedef struct{
    int data;
    bool used;
}DOT;

typedef struct{
    DOT  dot[max];
    int size;
}TREE;

void init_tree(TREE* tree){
    for(int i=0;i<max;i++){
        tree->dot[i].used=false;
    }
    tree->size=max;
}

bool set_root(TREE* tree,int data){
    tree->dot[1].data=data;
    tree->dot[1].used=true;
    return true;
}

bool set_left_child(TREE* tree,int parent,int data){
    if(tree->dot[parent].used==false)return false;
    tree->dot[2*parent].data=data;
    tree->dot[2*parent].used=true;
    return true;
}

bool set_right_child(TREE* tree,int parent,int data){
    if(tree->dot[parent].used==false)return false;
    tree->dot[2*parent+1].data=data;
    tree->dot[2*parent+1].used=true;
    return true;
}

void level_order(TREE* tree){
    int i=1,end=1;
    int count=1;
    while(i<max){
        if(tree->dot[i].used){
            printf("%d      ",tree->dot[i].data);
        }else{
            printf(" ");
        }
        if(i==end){
            printf("\n");
            count++;
            end=(1<<count)-1;
        }
        i++;
    }
}

int main(){
    TREE tree;
    init_tree(&tree);
    set_root(&tree,1);
    set_left_child(&tree,1,2);
    set_left_child(&tree,2,4);
    set_left_child(&tree,4,8);
    set_right_child(&tree,1,3);
    set_right_child(&tree,2,5);
    set_left_child(&tree,3,6);
    set_right_child(&tree,3,7);

    level_order(&tree);
    printf("\n����%d��",count);
    return 0;

}