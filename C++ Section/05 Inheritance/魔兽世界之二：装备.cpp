#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//ȫ�ֱ���
int Time;	//ʱ��
const int N = 5;	//����
enum type_w{dragon, ninja, iceman, lion, wolf};	//��ʿ��ö��
const char* name_w[N] = {"dragon", "ninja", "iceman", "lion", "wolf"};	//��ʿ���ַ���
int hp[N];	//��ʿ��ʼ����ֵ
enum type_weapon{sword, bomb, arrow};
const char* name_weapon[3] = {"sword", "bomb", "arrow"};
enum type_side{red, blue};
const char* name_side[2]{"red", "blue"};

class Creature{
protected:
	int id, health, side;
public:
	Creature(int tot, int h, int col): id{tot}, health{h}, side{col}{}
//	virtual ~Creature(){}
};

class Weapon{
public:
	int id, strength;
};

class Dragon: public Creature{
private:
	Weapon w;
	double morale;
public:
	Dragon(int tot, int ele, int col): Creature(tot, hp[dragon], col){
		w.id = tot%3;
		morale = (double)ele/hp[dragon];
		printf("It has a %s,and it's morale is %.2f\n", name_weapon[w.id], morale);
	}
};

class Ninja: public Creature{
private:
	Weapon w[2];
public:
	Ninja(int tot, int ele, int col): Creature(tot, hp[dragon], col){
		w[0].id = tot%3, w[1].id = (tot+1)%3;
		printf("It has a %s and a %s\n", name_weapon[w[0].id], name_weapon[w[1].id]);
	}
};

class Iceman: public Creature{
private:
	Weapon w;
public:
	Iceman(int tot, int ele, int col): Creature(tot, hp[dragon], col){
		w.id = tot%3;
		printf("It has a %s\n", name_weapon[w.id]);
	}
};

class Lion: public Creature{
private:
	int loyalty;
public:
	Lion(int tot, int ele, int col): Creature(tot, hp[dragon], col){
		loyalty = ele;
		printf("It's loyalty is %d\n", loyalty);
	}
};

class Wolf: public Creature{
public:
	Wolf(int tot, int ele, int col): Creature(tot, hp[dragon], col){}
};

class Headquarter{
private:
	type_side side;
	type_w name[N];	//��ʿ��
	int total[N];	//ĳ����ʿ��������type_w˳��
	int sum_total;	//������ʿ����
	int ele;	//����Ԫ
	int can_create;
	int now;	//����˭��
	Creature* warrior[1010];
	
	void generate(int pos){	//��ʵ���ɺ���
		++total[pos]; ++sum_total;
		ele -= hp[pos];
		printf("%03d ", Time);
		cout << name_side[side];
		printf(" %s %d born with strength %d,%d %s in ",name_w[pos], sum_total, hp[pos], total[pos], name_w[pos]);
		cout << name_side[side];
		printf(" headquarter\n");
		switch(pos){
			case dragon: warrior[sum_total-1] = new Dragon(sum_total, ele, side); break;
			case ninja: warrior[sum_total-1] = new Ninja(sum_total, ele, side); break;
			case iceman: warrior[sum_total-1] = new Iceman(sum_total, ele, side); break;
			case lion: warrior[sum_total-1] = new Lion(sum_total, ele, side); break;
			case wolf: warrior[sum_total-1] = new Wolf(sum_total, ele, side); break;
			
		}
		
	}
public:
	Headquarter(type_side s, type_w id[5]){
		side = s;
		for (int i = 0; i < N; ++i)
			name[i] = id[i];
	}
	void reset(int x){
		memset(total, 0, sizeof total);
		sum_total = 0;
		ele = x;
		can_create = 1;
		now = 0;
	}
	~Headquarter(){
		for (int i = 0; i < sum_total; ++i)
			delete warrior[i];
	}
	
	int create(){	//������ʿ�ⲿ�ӿڣ������Ƿ�ɹ��������Ϣ
		if (!can_create) return 0;
		for (int i = 0; i < N; ++i)
			if (hp[name[now]] <= ele){
				generate(name[now]);
				now = (now+1)%N;
				return 1;
			}
			else now = (now+1)%N;
		printf("%03d ", Time);
		cout << name_side[side];
		printf(" headquarter stops making warriors\n");
		return can_create = 0;
	}
};

int main(){
	int T;	//��������
	scanf("%d", &T);
	if (!T) return 0;
	int T1 = 1;	//Ŀǰ������������
	
	type_w name_of_red[N]{iceman, lion, wolf, ninja, dragon};
	type_w name_of_blue[N]{lion, dragon, ninja, iceman, wolf};
	
	Headquarter redH(red, name_of_red);
	Headquarter blueH(blue, name_of_blue);
	int maxEle;
	string name;
	
Case:
	printf("Case:%d\n", T1++);
	Time = 0;
	scanf("%d", &maxEle);
	redH.reset(maxEle);
	blueH.reset(maxEle);
	
	for (int i = 0; i < N; ++i)
		scanf("%d", hp+i);
	
	for (bool f1 = true, f2 = true; f1||f2; ++Time){
		f1 = redH.create();
		f2 = blueH.create();
	}
	
	if (T1 <= T) goto Case;
}
