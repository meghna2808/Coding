#include <bits/stdc++.h> 
void pathToGates(vector<vector<int>> &a, int i , int j)
{
    cout<<"ekdshflds"<<endl;
    int n=a.size();
    int m=a[0].size();
    queue<pair<int,int>>q;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    q.push({i,j});
    visited[i][j]=true;
    while(!q.empty())
    {
        
        int size=q.size();
        
        for(int k=0;k<size;k++)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x+1<n && a[x+1][y]!=0 && a[x+1][y]!=-1 && visited[x+1][y]==false)
            {
                // if(a[x+1][y]=2147483647)a[x+1][y]=a[x][y]+1;
                // cout<<a[x+1][y]<<endl;
                a[x+1][y]=min(a[x][y]+1,a[x+1][y]);
                visited[x+1][y]=true;
                cout<<a[x+1][y]<<endl;
                q.push({x + 1, y});
            }
            if(x-1>=0 && a[x-1][y]!=0 && a[x-1][y]!=-1 && visited[x+1][y]==false)
            {
                a[x-1][y]=min(a[x][y]+1,a[x-1][y]);
                q.push({x-1,y});
                cout<<a[x-1][y]<<endl;
                visited[x-1][y]=true;

            }
            if(y-1>=0 && a[x][y-1]!=0 && a[x][y-1]!=-1 && visited[x][y-1]==false)
            {
                a[x][y-1]=min(a[x][y]+1,a[x][y-1]);
                q.push({x,y-1});
                cout<<a[x][y-1]<<endl;
                visited[x][y-1]=true;

            }
            if(y+1<m && a[x][y+1]!=0 && a[x][y+1]!=-1 && visited[x][y+1]==false)
            {
                a[x][y+1]=min(a[x][y]+1,a[x][y+1]);
                q.push({x,y+1});
                cout<<a[x][y+1]<<endl;
                visited[x][y+1]=true;

            }


        }
        
    }

}
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    // Write your code here.
    queue<pair<int,int>>q;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                q.push({i,j});
                visited[i][j]=true;
            }
            if(a[i][j]==-1) visited[i][j]=true;
        }
    }
    
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x-1>=0 && visited[x-1][y]==false)
            {
                visited[x-1][y]=true;
                a[x-1][y]=a[x][y]+1;
                q.push({x-1,y});
            }
            if(x+1<n && visited[x+1][y]==false)
            {
                visited[x+1][y]=true;
                a[x+1][y]=a[x][y]+1;
                q.push({x + 1, y});
            }
            if(y-1>=0 && visited[x][y-1]==false)
            {
                visited[x][y-1]=true;
                a[x][y-1]=a[x][y]+1;
                q.push({x , y-1});
            }
            if(y+1<m && visited[x][y+1]==false)
            {
                visited[x][y+1]=true;
                a[x][y+1]=a[x][y]+1;
                q.push({x , y+1});
            }

        }
    }
    return a;

}
//space :O(m*n)
//time :O(m*n)