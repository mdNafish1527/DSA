#include <bits/stdc++.h>
using namespace std;

void fill_up(vector<bool>& chk){
	for(int i = 2 ; i * i < chk.size() ; i++){
		if(chk[i]){
			for(int j = i * i ; j <= chk.size() ; j += i) chk[j] = false;
		}
	}
	return;
}

int main(){
	int n;
	cin >> n;
	vector<bool> chk(n + 1);
	for(int i = 2 ; i <= n ; i++) chk[i] = true;

	fill_up(chk);

	for(int i = 2 ; i <= n ; i++){
		if(chk[i]) cout << i << " ";
	}

	return 0;
}
