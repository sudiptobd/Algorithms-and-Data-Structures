
//LIBRARIES
#include <bits/stdc++.h>
//MACROS
#define for(i,n) for(int i=0;i<n;i++)
#define INF 9999
using namespace std;

void floydWarshall(int matrix[][100],int n,int next[][100]){
 for(k,n){
        for(i,n){
            for(j,n){
                next[i][j] = matrix[i][k]+matrix[k][j]< matrix[i][j] ? next[i][k]:next[i][j] ;
                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);

            }
        }
    }
}

vector<int> pathFinder(int next[][100],int a,int b){
    vector<int> path;
    path.push_back(a);
    do{
        a = next[a][b];
        if(a==INF){
            path.clear();
            break;
        }
        path.push_back(a);
    }while(a!=b && a!=INF);
    return path;
}

int main()
{
    freopen("C:\\Users\\User\\Documents\\Algo\\Practice\\in.txt","r",stdin);
    int n,e;
    cin >> n >> e;
    int matrix[100][100];
    int next[100][100];

    ///INITIAL VALUE
    for(i,n){
        for(j,n){
            matrix[i][j] = i!=j ? INF:0;
            next[i][j] = i==j ? i: INF;
        }
    }

    ///INPUT MATRIX
    for(i,e){
        int a,b,v;
        cin >> a >> b >> v;
        matrix[a][b] = v;
        next[a][b] = b;
    }

    ///FLOYD-WARSHALl
    floydWarshall(matrix,n,next);
    ///PRINT
    for(i,n){
        for(j,n){
            if(matrix[i][j] == INF){
                cout << "x ";
            }else{
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    ///PATH FINDING
    ///PRINTING
    for(i,n){
        for(j,n){
            cout<<i<<" to " << j << " : ";
            vector<int> paths = pathFinder(next,i,j);
            for(x,paths.size()){
                cout << paths[x] << " ";
            }
            cout<< endl;
        }
    }

    return 0;
}
