#include<iostream>
#include<vector>
using namespace std;
//s: no. of states, P[s]: start probability, T[s1][s2]: s1->s2 (s*s), E[t][s] (|t|*s), int t: type of observations, o: observations, n: # of o
vector<int> viterbi_Patient_doc(int s, int *P, int **T, int **E, int t, int *o, int n){
	vector< vector<int> > v(n); //each vector represents v[o][s]
	for(int i=0; i<s; i++){
		v[0].push_back(P[i]*E[o[0]][i]);
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<s; j++){
			int max=0;
			for(int k=0; k<s; k++){
				max=max>T[k][j]*v[i-1][k]?max:T[k][j]*v[i-1][k];
			}
			v[i].push_back(max*E[o[i]][j]);
		}
	}
	
}
