#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100011;
int price[N];
int dp1[N], dp2[N];
//dp1[i]��ʾ��[1, i]����һ�ι�Ʊ�������������
//dp2[i]��ʾ��[i, n]����һ�ι�Ʊ�������������

int main(){
	int T;
	cin >> T;
	while (T--){
		memset(dp2, 0, sizeof dp2);
		
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			scanf("%d", price+i);
		
		for (int i = 2, t = price[1]; i <= n; ++i){
			t = min(t, price[i]);
			dp1[i] = max(dp1[i-1], price[i]-t);	//�Ե�i���Ƿ����˹�Ʊ����
		}
		
		for (int i = n-1, t = price[n]; i; --i){
			t = max(t, price[i]);
			dp2[i] = max(dp2[i+1], t-price[i]);	//�Ե�i���Ƿ����˹�Ʊ����
		}
		
		int res = 0;
		for (int i = 1; i <= n; ++i)
			res = max(res, dp1[i]+dp2[i]);
		cout << res << endl;
	}
}
