#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
	string a,b;//char a[20] = "abc";
	//char b[20] = "bac";
	int a_len = 0;
	int b_len = 0;
	cout<<"enter first string:"<<endl;
	cin>>a;
	cout<<"enter second string:"<<endl;
	cin>>b;
	a_len = a.size();
	b_len = b.size();
	//char* ap = a.begin();
	//char* bp = b.begin();
	/*while(a[a_len] != '\0')
		a_len++;
	while(b[b_len] != '\0')
		b_len++;*/
	int** t = new int*[a_len+1];
	for(int i=0;i<=a_len;i++)
		t[i] = new int[b_len+1];
	for(int i=0; i<(a_len+1);i++)
		t[i][0] = 0;
	for(int i=0; i<(b_len+1);i++)
		t[0][i] = 0;
	for(int i=1;i<=a_len;i++){
		for(int j=1;j<=b_len;j++){
			if(a[i]==b[j])
				t[i][j] = t[i-1][j-1] + 1;
			else{
				t[i][j] = t[i-1][j]>t[i][j-1]? t[i-1][j] : t[i][j-1];
			}
			//ap++;
			//bp++;
		}
	}
	cout<<a_len<<'\t'<<b_len<<endl;
	//cout<<'\t';
	/*for(int i=0;i<b_len;i++)
		cout<<b[i]<<'\t';
	cout<<endl;
	for(int i=0;i<=a_len;i++)*/
	cout<<t[a_len][b_len]<<endl;
	for(int i=0;i<=a_len;i++)
		delete [] t[i];
	delete [] t;
	return 1;
}