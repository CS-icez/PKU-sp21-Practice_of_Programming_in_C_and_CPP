#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int f(int n, int beg){  //��beg��ʼ�ֽ�n�������
	int res = 1;
	for (; beg*beg <= n; ++beg)
		if (n%beg == 0) res += f(n/beg, beg);
	return res;
}

int main(){
	int n, t;
	cin >> n;
	while (n--){
		cin >> t;
		cout << f(t, 2) << endl;
	} 
}
