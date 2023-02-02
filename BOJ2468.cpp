#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int height[100][100] = {0,};
int safe_zone[100][100] = {0,};


int N = 0; 

void make_safezone(int rain_height);
int count_safezone();
void DFS(int a, int b);

int main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int rain_height = 0;
   int i, j =0;
   int m, n ;
   int max_safezone = 0;
   cin >> N;
   
   for(i=0; i<N; i++){
    for(j=0; j<N; j++){
        cin >> height[i][j];
    }
   }
    for(rain_height=0; rain_height<=100; rain_height++){
        make_safezone(rain_height);
                // cout << "\n safezone \n";
                // for(n=0; n<N; n++){
                //     for(m=0;m<N;m++){
                //         cout<<safe_zone[n][m]<<" ";
                //     }
                //     cout <<"\n";
                // }
        int num_safezone = count_safezone();
        if (max_safezone < num_safezone)
            max_safezone = num_safezone;
    }
    cout << max_safezone;
}

void make_safezone(int rain_height){
    int i, j = 0;

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(height[i][j] > rain_height)
                safe_zone[i][j] = 1;
            else
                safe_zone[i][j] = 0;
        }
    }
}

int check[100][100] = {0,};
int count_safezone(){
    int i, j=0;
    int n,m;
    int count = 0;
    memset(check, 0, sizeof(check));
    for(i = 0; i<N; i++){
        for(j=0; j<N; j++){
            if(safe_zone[i][j] && !check[i][j]){
                DFS(i, j);
                // cout << "\n DFS CHECK \n";
                // for(n=0; n<N; n++){
                //     for(m=0;m<N;m++){
                //         cout<<check[n][m]<<" ";
                //     }
                //     cout <<"\n";
                // }
                count ++;
            }
        }
    }
    return count;
}

void DFS (int a, int b){
    if(check[a][b]==1 || safe_zone[a][b] == 0){
        return;
    }
    check[a][b] = 1;

    if(b<N-1) DFS(a, b+1);
    if(a<N-1) DFS(a+1, b);
    if(a>0) DFS(a-1,b);
    if(b>0) DFS(a,b-1);
}