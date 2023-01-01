#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
private:
	istream& is;
	T value;
public:
	CMyistream_iterator(istream& _is): is{_is}{
		is >> value;
	}
	istream& operator++(int){	//������ȫ�ڰѺ�׺��������ǰ׺����������Ŀ���
		return is >> value;
	}
	T operator*(){return value;}
};



int main()  
{ 
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //���� n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;   
		 n2 = * inputInt; //���� n2
		 inputInt ++;
		 n3 = * inputInt; //���� n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;  
}
