     #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<string>
    #include<stack>
    #include<vector>
    #include<algorithm>
    #include<iostream>
    using namespace std;
    #define push_back pb
    //vector<int>::iterator it
    //#define tr(container, it) \
    // for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
    #define all(c) c.begin(), c.end()
    #define present(container, element) (container.find(element) != container.end()) //in set
    #define cpresent(container, element) (find(all(container),element) != container.end()) //in vector
    int mat[4][4];
    bool fun ()
    {
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
    if(mat[i][j]^mat[i][j+1]^mat[i+1][j]^mat[i+1][j+1]==1) {return true;}
    if(mat[i][j]==mat[i][j+1] && mat[i+1][j] == mat[i+1][j+1] && mat[i][j] == mat[i+1][j]) { return true;}//,mat[i][j],mat[i][j+1],mat[i+1][j],mat[i+1][j+1]); return true;}
    }
    return false;
    }
    int main()
    {
    for(int i=0;i<4;i++)
    {
    char c;
    for(int j=0;j<4;j++)
    {
    scanf("%c",&c);
    if(c=='a') mat[i][j] = 0;
    else mat[i][j] = 1;
    }
    scanf("%c",&c);
    }
    // for(int i=0;i<4;i++) for(int j=0;j<4;j++) printf("<%d> ",mat[i][j]);
    bool val = fun();
    if(val==true) printf("POSSIBLE\n");
    else printf("NOT POSSIBLE\n");
    return 0;
    } 
