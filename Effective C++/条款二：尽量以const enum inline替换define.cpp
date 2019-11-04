//�����Ա������滻Ԥ������

#include<iostream>
using namespace std;

//�����ƴ�δ��������������Ҳ���ڱ�������ʼ����Դ����֮ǰ���ͱ�������������
#define ASPECT_RATIO 1.653
const double AspectRatio = 1.653;

//���峣��ָ��
//��һ��const�����޸�ָ����ָ���ݣ��ڶ���const���ܸı�ָ��ָ�� 
const char* const authorName = "Rose";
//string����ͨ����ǰ��char*-based����
const string AuthorName("Rose");

//classר��������������Ϊ�˽�������������(scope)������class�ڣ�����������Ϊclass��һ����Ա
//ȷ���˳���ֻ��һ��ʵ�壬����������Ϊһ��static��Ա
class GamePlayer {
private:
public:
	static const int NumTurns = 5;	//��������
	int scores[NumTurns];			//ʹ�øó���
};
//C++Ҫ��ʹ�õ��κζ����ṩ�����ǣ������Ǹ�classר����������static��Ϊ������(int,char,bool),�������⴦��
//ֻҪ��ȡ���ǵĵ�ַ������������ʹ�����������ṩ����ʽ
//ȡĳ��ר�������ĵ�ַ������ı�����ȴ���Ҫ����һ������ʽ�������ṩһ������ʽ
//const int GamePlayer::NumTurns;

//��ʽ���������ܲ�֧��static��Ա��ó�ֵ�����Խ���ֵ�ŵ�����ʽ
class A {
public:
	static const int a;
};
const int A::a = 100;

//�޷�ʹ��#define����һ��classר����������Ϊ#define������������(scope)

//�����ڱ����ڼ���Ҫһ��class����ֵ����������������С����һ��ı�����������static����������ֵ�趨
//�ɸ���"the enum hack"����������һ������ö�����͵���ֵ��Ȩ��ints��ʹ��
class B {
private:
	enum { NumTurns = 10 };
	int scores[NumTurns];
};
//ȡenum�ĵ�ַ���Ϸ�����������ñ��˻��һ��pointer��referenceָ�����ĳ������������enum����ʵ�����Լ��

void f(int a) {
	cout << a << endl;
}
//�����סΪ���е�����ʵ�μ���С���ţ�������������鷳����main������
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

//template inline ���Ի�ú������Ч���Լ�һ�㺯�������п�Ԥ����Ϊ�����Ͱ�ȫ��
template<typename T>
inline void callWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}


int main() {
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);			//a���ۼ�����
	CALL_WITH_MAX(++a, b + 10);		//a���ۼ�һ��
	GamePlayer g;
	cout << g.NumTurns << endl;	//5
	A aa;
	cout << aa.a << endl;

	return 0;
}