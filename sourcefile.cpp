#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int answer;
void input_case(vector<vector<int> > &matrix){
    cin>>N;
    matrix.resize(N);
    for(int i=0;i<N;i++){
        matrix[i].resize(N);
        for(int j=0;j<N;j++){
            cin>>matrix[i][j];
        }
    }
}


void move_right(vector<vector<int> > &matrix){
    int temp=0;
    for(int i=0;i<N;i++){
        temp=N-1;
        for(int j=N-1;j>=0;j--){
           if(j==0) matrix[i][temp--]=matrix[i][0];
            if(matrix[i][j]!=0&&j>0){
                int tmp=0;
                for(tmp=j-1;tmp>0&&!matrix[i][tmp];tmp--);
                if(matrix[i][tmp]==matrix[i][j]) {
                    matrix[i][temp]=matrix[i][tmp]+matrix[i][j];
                    j=tmp;
                }else{
                    matrix[i][temp]=matrix[i][j];
                    j=tmp+1;
                }
                temp--;
            }
        }
        for(int j=temp;j>=0;j--) matrix[i][j]=0;
    }
}
void move_left(vector<vector<int> > &matrix){
    int temp=0;
    for(int i=0;i<N;i++){
        temp=0;
        for(int j=0;j<N;j++){
            if(j==N-1) matrix[i][temp++]=matrix[i][N-1];
            if(matrix[i][j]!=0&&j<N-1){
                int tmp=0;
                for(tmp=j+1;tmp<N-1&&!matrix[i][tmp];tmp++);
                if(matrix[i][tmp]==matrix[i][j]) {
                    matrix[i][temp]=matrix[i][tmp]+matrix[i][j];
                    j=tmp;
                }else{
                    matrix[i][temp]=matrix[i][j];
                    j=tmp-1;
                }
                temp++;
            }
        }
        for(int j=temp;j<N;j++) matrix[i][j]=0;
    }
}
void move_up(vector<vector<int> > &matrix){
    int temp=0;
    for(int j=0;j<N;j++){
        temp=0;
        for(int i=0;i<N;i++){
            if(i==N-1) matrix[temp++][j]=matrix[N-1][j];
            if(matrix[i][j]!=0&&i<N-1){
                int tmp=0;
                for(tmp=i+1;tmp<N-1&&!matrix[tmp][j];tmp++);
               if(matrix[tmp][j]==matrix[i][j]) {
                    matrix[temp][j]=matrix[tmp][j]+matrix[i][j];
                    i=tmp;
                }else{
                    matrix[temp][j]=matrix[i][j];
                    i=tmp-1;
                }
                temp++;
            }
        }
        for(int i=temp;i<N;i++) matrix[i][j]=0;
    }
}
void move_down(vector<vector<int> > &matrix){
    int temp=0;
    for(int j=0;j<N;j++){
        temp=N-1;
        for(int i=N-1;i>=0;i--){
            if(i==0) {
                matrix[temp--][j]=matrix[0][j];
            }
            if(matrix[i][j]!=0&&i>0){
                int tmp=0;
                for(tmp=i-1;tmp>0&&!matrix[tmp][j];tmp--);
                if(matrix[tmp][j]==matrix[i][j]) {
                    matrix[temp][j]=matrix[tmp][j]+matrix[i][j];
                    i=tmp;
                }else{
                    matrix[temp][j]=matrix[i][j];
                    i=tmp+1;
                }
                temp--;
            }
        }
        for(int i=temp;i>=0;i--) matrix[i][j]=0;
    }
}

void solution(vector<vector<int> > matrix,int next_case, int count){
    if(count==5) {
        for(int i=0;i<N;i++) answer=max(answer,(*max_element(matrix[i].begin(),matrix[i].end())));
        return;
    }
   if(next_case==0) move_down(matrix);
    else if(next_case==1) move_up(matrix);
    else if(next_case==2) move_left(matrix);
    else if(next_case==3) move_right(matrix);
    for(int i=0;i<4;i++){
        solution(matrix,i,count+1);
    }

}

int main(){
    vector<vector<int> > matrix;
    input_case(matrix);
    for(int i=0;i<4;i++){
        solution(matrix,i,0);
    }

    cout<<answer<<endl;
}