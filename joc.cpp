/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

// constraints
#define MAXN 20
using namespace std;
// input data
int N, K;
bool V[MAXN];
bool copV[MAXN];
vector<vector<int> > graph(MAXN);
int res = MAXN+1;
//preme il pulsante nodo
void solve(int nodo, int currRes, bool copV[])
{
    if (currRes>= res)
        return;

    bool fine=false;

    if(copV[K]==true)
    {
        fine=true;
        for(int ii=0; ii<N; ii++)
        {
            if(ii!=K && copV[ii]==true)
            {
                fine=false;
                break;
            }
        }
    }
    if(fine)
    {
        res=min(res,currRes);
        return;
    }


    currRes++;
    copV[nodo]=true;
    for(auto nc : graph[nodo])
    {
        copV[nc] = false; //spegne la lampadina nc
    }

    for(int ii=0; ii<N; ii++)
    {
        if(copV[ii]==false)  // se spenta
        {
            bool cop2V[MAXN];
            for(int j=0; j<N; j++)
            {
                cop2V[j]=copV[j];
                //cout << copV[j]<<" ";
            }
            solve(ii, currRes, cop2V);
        }

    }


}


int main()
{
    //  uncomment the following lines if you want to read/write from files
    freopen("input1.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);

    cin>>N>>K;
    K--; // 0 based

    for (int i = 0; i < N; i++)
    {
        cin>>V[i];
    }

    for (int i = 0; i < N; i++)
    {
        int t;
        cin>>t;

        for (int j = 0; j < t; j++)
        {
            int pos;
            cin>>pos;
            pos--; // 0 based
            graph[i].push_back(pos);
            // the i-th button will turn off the pos-th light
        }
    }

        for(int i=0;i<N;i++){
            cout<<i<<": ";
            for(auto a:graph[i]){
                cout << a<<" ";
            }
            cout<<endl;
        }


    for(int i=0; i<N; i++)
    {
        if(V[i]==false)
        {
            //copia le v
            for(int j=0; j<N; j++)
            {
                copV[j]=V[j];
                //cout << copV[j]<<" ";
            }
            solve(i, 0, copV);
        }
    }

    cout<<res<<endl;


    //printf("%d\n", 42);  // change 42 with actual answer
    return 0;
}
