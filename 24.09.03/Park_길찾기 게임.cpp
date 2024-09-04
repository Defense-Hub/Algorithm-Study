// RE  : https://school.programmers.co.kr/learn/courses/30/lessons/42892#qna
// ref : https://yabmoons.tistory.com/639
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct node{
    int idx;
    int x;
    int y;
    node* left;
    node* right;
};

bool cmp(node a, node b){
    if(a.y == b.y) return a.x < b.x;
    else return a.y > b.y;
}

void makeBT(node* root, node* child){
    // left
    if(child -> x < root -> x){
        if(root -> left == NULL){
            root -> left = child;
            return;
        }
        makeBT(root -> left, child);
    }
    
    // right
    else{
        if(root -> right == NULL){
            root -> right = child;
            return;
        }
        makeBT(root -> right, child);
    }
}

void PreOrder(node *root, vector<int> &pre){
    if(root == NULL) return;
    pre.push_back(root->idx);
    PreOrder(root -> left, pre);
    PreOrder(root -> right, pre);
}

void PostOrder(node *root, vector<int> &post){
    if(root == NULL) return;
    PostOrder(root -> left, post);
    PostOrder(root -> right, post);
    post.push_back(root -> idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<node> nodes;
    // 정렬 활용
    // x좌표 정렬
    // [1,3]6 [2,2]9 [3,5]4 [5,3]1 [6,1]5 [7,2]8 [8,6]7 [11,5]2 [13,3]3 
    for(int k = 0; k < nodeinfo.size(); k++){
        nodes.push_back({k+1, nodeinfo[k][0], nodeinfo[k][1], NULL, NULL});
    }
    
    sort(nodes.begin(), nodes.end(),cmp);
    
    node* root = &nodes[0];
    
    for(int k = 1; k < nodes.size(); k++){
        makeBT(root, &nodes[k]);
    }
    
    vector<int> pre;
    PreOrder(root, pre);
    
    vector<int> post;
    PostOrder(root, post);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}