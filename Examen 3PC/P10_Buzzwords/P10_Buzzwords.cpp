//https://open.kattis.com/problems/buzzwords

#include <bits/stdc++.h>
using namespace std;

class Node{
private:
	Node*	ch[26];
	int 	c=0;
	int 	d=0;
public:
	Node(){
		for(int i = 0; i < 26; ++i) 
			ch[i] = NULL;
	}
	void insert(string &s, int i = 0){
		while(i<s.length() && s[i]==' ') 
			i++;
		if(i==s.length()){ 
			c++; 
			return; 
		}
		else{
			c++;
			int v=s[i]-'A';
			if(ch[v] == NULL){
				ch[v] = new Node();
				ch[v]->d=d+1;
			}
			ch[v]->insert(s,i+1);
		}
	}
	void cleanup(){
		for(int i=0;i<26;++i){
			if (ch[i] != NULL) 
				ch[i]->cleanup();
			delete ch[i];
		}
	}
	void count(vector<int>&count){
		count[d]=max(c, count[d]);
		for (int i=0;i<26;++i)
			if (ch[i]!=NULL)
				ch[i]->count(count);
	}
};

string S;
void Buzzwords(){
	Node root;
	for(int i = 0;i<S.length();++i){
		if(S[i]!=' ')
			root.insert(S, i);
	}

	vector<int> dpth(S.length()+3,0);
	root.count(dpth);
	for(int i=1;i<=S.length()+1;++i){
		if(dpth[i]>1) 
			cout<<dpth[i]<<"\n";
		else
			return;
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while(getline(cin,S)){
		Buzzwords();
		cout<<"\n";
	}
	
	return 0;
}