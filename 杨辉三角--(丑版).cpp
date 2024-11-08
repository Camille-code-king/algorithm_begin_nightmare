#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"输入杨辉三角的行数:"<<endl;
	cin>>n;
	int arr[n+1][2*n]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2*n-1;j++){
			if(i==1&&j==n){
				cout<<1;
				arr[i][j]=1;
			}else if(i==1){
				cout<<" ";
			}
			else if(i==2&&(j==n+1||j==n-1)){
				cout<<1;
				arr[i][j]=1;
			}
			else if(i==2){
				cout<<" ";
			}
			else if(i>2&&arr[i-1][j+1]!=0&&arr[i-1][j-1]!=0){
				arr[i][j]=arr[i-1][j+1]+arr[i-1][j-1];
				cout<<arr[i][j];
			}else if(i>2&&j==n-i+1||j==n+i-1){
				cout<<1;
				arr[i][j]=1;
			}else if(i>2){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	
	return 0;
}
