#include <iostream>
using namespace std;
int getByte(int x, int i){
    return
(unsigned)x>>i*8<<24>>24  // ��͵����, ������ʽ������int��32λ��
;
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int x, i;
        cin >> x >> i;
        cout << getByte(x, i) << endl;
    }
    return 0;
}
