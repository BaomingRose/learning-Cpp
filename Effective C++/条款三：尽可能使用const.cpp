#if 0
#include<iostream>
#include<vector>
using namespace std;

class Widget{};
//�������ֲ���һ��
void f1(const Widget* pw) {}
void f2(Widget const *pw) {}

int main() {
#if 0
	char greeting[] = "Hello";
	char* p = greeting;
	//*��ߵ�const��ʾָ����ָ���ǳ���
	//*�ұߵ�const��ʾָ�������ǳ���
	const char* cptr = greeting;	//���ܸı�ָ��ָ�������
	char* const ptrc = greeting;	//���ܸı�ָ���ָ��
	const char* const cptrc = greeting;	//�Ȳ��ܸı�ָ��Ҳ���ܸı�����
	cout << p << endl;
	cout << cptr << endl;
	cout << ptrc << endl;
	cout << cptrc << endl;
#endif

	vector<int> v{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	//�����������þ����T*ָ�룬����������Ϊconst��������ָ��Ϊconstһ����T* const ָ�룩
	const vector<int>::iterator iv = v.begin();
	cout << *iv << endl;

	//���ϣ����������ָ�Ķ������ɸĶ�: const_iterator
	vector<int>::const_iterator civ = v.begin();
	while (civ != v.end()) {
		cout << *civ << " ";
		++civ;
	}
	
	
	return 0;
}
#endif


//const��Ա����

//const��Ա�����������и��
//bitwise constness:�����Ը��Ķ������κ�non-static��Ա����
				//�����в�ʮ��߱�const����ȴ��ͨ��bitwise����
				//��ָ��Ϊ��Ա����ʱ��ָ��ָ��û�б䣬����ָ����ָ���ݸı�
//logical constness:
#include<iostream>
using namespace std;

#if 0
class CTextBlock {
public:
	CTextBlock(const char* s = "") : pText(new char[strlen(s) + 1]) {
		strcpy(pText, s);
	}

	char& operator[](size_t position) const {	//const��Ա����
		pText[position] = 'Z';		//��Ȼû���޸�ָ���ָ�򣬵���Ҳ�ı���ָ�������
		return pText[position];
	}

	friend ostream& operator<<(ostream& os, const CTextBlock& c);

private:
	char* pText;
};

ostream& operator<<(ostream& os, const CTextBlock& c) {
	os << c.pText;
	return os;
}

int main() {
	CTextBlock c("hello");
	cout << c << endl;
#if 0
	char* pc = &c[1];
	cout << c << endl;
	*pc = 'E';
	cout << c << endl;
#endif

#if 1
	cout << c[3] << endl;
	cout << c << endl;
#endif
	return 0;
 }
#endif

#if 0
class CTextBlock {
public :
	size_t length() const;
private:
	char* pText;
	mutable size_t textLength;		//C++��const��صİڶ�����mutable���ɱ�ģ���mutable�ͷŵ�non-staitic��Ա������bitwise constnessԼ��
	mutable bool lengthIsValid;
};

size_t CTextBlock::length() const {
	if (!lengthIsValid) {
		textLength = std::strlen(pText);	//const��Ա�����޸�mutable��Ա
		lengthIsValid = true;
	}
	return textLength;
}

int main() {

	return 0;
}
#endif

//��const��non-const��Ա�����б����ظ�
#if 0
class TextBlock {
public:
	const char& operator[](std::size_t position) const {
		//�߽����
		if (position > text.size() - 1) {

		}
		//־�Ǳ�Ƿ���
		//��������������
		return text[position];
	}
	const char& operator[](std::size_t position) const {
		//�߽����
		if (position > text.size() - 1) {

		}
		//־�Ǳ�Ƿ���
		//��������������
		return text[position];
	}

private:
	std::string text;
};
#endif
//���������ظ��Լ��������ʱ�䡢ά�����������͵�����
//operator����һ�β�ʹ�������Σ���������һ��������һ�������ʹ���ǽ��������Ƴ�

//ת�ͣ�casting����һ�������뷨�����Ǳ�����const operator[]��ȫ������non-const�汾������һ�У�Ψһ��ͬ�Ƿ������Ͷ���һ��const����
//������non-const operator[]������const�ֵ���һ����������ظ��İ�ȫ����
class TextBlock {
public:
	const char& operator[](std::size_t position) const {
		return text[position];
	}
	char& operator[](std::size_t position) {
		return
			const_cast<char&>(		//��operator[]����ֵ��const�Ƴ�
				static_cast<const TextBlock&>(*this)[position]	//Ϊ*this����const������const operator[]
				);
	//�����������ת�ͣ�Ϊ�˱���һֱ�����Լ��ݹ飬������ȷָ������const operator[],���Խ�*this��ԭʼ����TextBlock&ת��Ϊconst TextBlock&
	//��һ��Ϊ*this��const
	//�ڶ��δ�const operator[]�ķ���ֵ���Ƴ�const
	}

private:
	std::string text;
}; 

//���const����һ��ת��ǿ�Ƚ�����һ�ΰ�ȫת�ͣ���non-const����תΪconst���󣩣�����ʹ��static_cast
//�Ƴ���const���Ǹ�����ֻ���Խ���const_cast��ɣ�û������ѡ��һ��C-styleת��Ҳ�е�ͨ