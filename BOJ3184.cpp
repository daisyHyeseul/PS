#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

#define MAX 250
#define MIN 3


int map[MAX][MAX] = {0,};
int check[MAX][MAX] = {0,};
int R, C =0;

void count(int* finalnum);
void DFS(int x, int y, int* sheepwolf);

/*
. = 비어있는 field = 0
# = 울타리 = 1
o = 양 = 2
v = 늑대 = 3
*/ 

int main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int i, j =0;

    cin >> R >> C;

    for(i=0;i<R; i++){
        for(j=0; j<C; j++){
            char tmp;
            cin >> tmp;
            if (tmp == '.')
                map[i][j] = 0;
            else if (tmp == '#')
                map[i][j] = 1;
            else if (tmp == 'o')
                map[i][j] = 2;
            else if (tmp == 'v')
                map[i][j] = 3;

        }
    }
    int n, m  = 0;

    // cout <<"map------\n" ;
    // for(n=0; n<R; n++){
    //     for(m=0;m<C;m++){
    //         cout << map[n][m]<<" ";
    //     }
    //     cout <<"\n";
    // }

    // cout <<"\n";
    int finalnum[2]= {0,0};
    count(finalnum);
    cout << finalnum[0] << " " << finalnum[1];

}

void count(int* finalnum){
    int i, j=0;
    int n, m=0;
    int sheepwolf[2] = {0,0}; //{양의 수, 늑대수}

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            if(check[i][j]==0){
                DFS(i, j, sheepwolf);

                // cout << "check ------\n";
                // for(n=0; n<R; n++){
                //     for(m=0;m<C;m++){
                //         cout<<check[n][m]<<" ";
                //     }
                //     cout <<"\n";
                // }
                // cout <<"\n";

                if(sheepwolf[0]>sheepwolf[1]){
                    finalnum[0] += sheepwolf[0];
                }
                else {
                    finalnum[1] += sheepwolf[1];
                }
                sheepwolf[0] = 0 ; sheepwolf[1] = 0;
            }
        }
    }

}



void DFS (int x, int y, int* sheepwolf){
    if(check[x][y] == 1 || map[x][y] == 1)
        return;
    if (map[x][y] == 2) sheepwolf[0] ++;
    if (map[x][y]==3) sheepwolf[1] ++;

    check[x][y] = 1;

    if(x>0) DFS(x-1, y, sheepwolf);
    if(y>0) DFS(x, y-1, sheepwolf);
    if(x<R-1) DFS(x+1,y, sheepwolf);
    if(y<C-1) DFS(x,y+1, sheepwolf);

}