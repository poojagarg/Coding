//every element of array represents Set name for that index
void MakeSet(int S[],int size, int i){
	if(i<size)	
		S[i]=i;
}
void MakeSet(int S[],int size){
	int i;
	for(i=0; i<size; i++){
		S[i]=i;	
	}
}
void Union(int S[], int size, int x, int y){
	if(x>=size||y>=size) return;	
	if(Find(s,size,x)!=Find(s,size,y)){
	int i; int t=Find(S,size,x); int s=Find(s,size,y);
	for(i=0; i<size; i++){
		if(Find(S,size,i)==t){
			S[i]=s;
		}//end of if
	}// end of for		
	}// end of if
}
int Find(int S[], int size, int i){
	if(i<size)
		return S[i];
}

