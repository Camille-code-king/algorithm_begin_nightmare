#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fast_pow(ll x,ll n,ll mod){
	ll res=1;
	while(n){
		if(n&1)res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
bool MillerRabin(ll n){
	if(n<=1||n%2==0)return false;
	if(n==2)return true;
	ll base[]={2,3,5,7,11,13,17,19,23,29};
	ll u=n-1,k=0;
	while(u%2==0)u/=2,k++;
	for(auto x: base){
		if(x%n==0)continue;
		ll v=fast_pow(x,u,n);
		if(v==1||v==n-1)continue;
		for(int j=0;j<k;j++){
			ll last=v;
			v=v*v%n;
			if(v==1){
				if(last!=n-1)return false;
				break;
			}
		}
		if(v!=1)return false;
	}
	return true;
}
int main(){
	ll n;
	cout<<"请输入一个数:"<<endl;
	cin>>n;
	if(MillerRabin(n))
		cout<<"这个数是一个质数"<<endl;
	else
	cout<<"这个数是一个合数"<<endl;
}
