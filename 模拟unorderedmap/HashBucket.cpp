#include <vector>
using namespace std;
template <class K>
struct KeyOfValue {
	const K& operator()(const K& key) {
		return key;
	}
};

// ����+������

//������ڵ�
template <class V>
struct HashNode {
	HashNode<V>* _next;
	V _data;

	HashNode(const V& data = V())
		:_data(data)
		, _next(nullptr)
	{}
};

//ǰ������
template <class K, class V, class KeyOfValue>
class HashBucket;

template <class K, class V, class KeyOfValue>
struct HIterator {
	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef HashBucket<K��V, KeyOfValue> htable;

	typedef HIterator<V> Self;

	pNode _node;
	htable* _ht;

	HIterator(pNode node, htable* ht)
		:_node(node)
		, _ht(ht)
	{}

	V& operator*() {
		return _node->_data;
	}

	V* operator->() {
		return *_node->_data;
	}

	bool operator!=(const Self& it) {
		return _node != it._node;
	}

	Self& operator++() {
		if (_node->_next) {
			_node = _node->_next;
		} else{
			//�ҵ���ǰ��ϣ������һ���ǿ������ͷ��㣬 ����

			//���㵱ǰ�ڵ��ڱ��е�λ��
			KeyOfValue kov;
			//int idx = kov(_node->_data) % _ht->getTableSize();
			// ��Ԫ�����ֱ�ӷ���˽�г�Ա
			int idx = kov(_node->_data) % _ht->_table.size();
			//�ӹ�ϣ�����һ��λ�ÿ�ʼ�ҵ���һ���ǿ������ͷ���
			++idx;
			for (; idx < _ht->_table.size(); ++idx) {
				if (_ht->_table[idx]) {
					//�ҵ��˵�һ���ǿ������ͷ���
					_node = _ht->_table[idx];
					break;
				}
			}
			//�п��ܺ���Ľڵ㶼Ϊ�սڵ�
			if (idx == _ht->_table.size())
				_node = nullptr;  //��ʾ��end��������λ��
		}
		return *this;
	}

};

template <class K, class V, class KeyOfValue>
class HashBucket {
public:
	//����������Ϊ��ϣ�����Ԫ��
	template <class K, class V, class KeyOfValue>
	friend struct HIterator;

	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef HIterator<V> iterator;

	iterator begin() {

	}

	iterator end() {
		
	}

	//����������ظ�Ԫ��
	bool insert(const V& data) {
		checkCapacity();

		//����key�Ƿ��Ѿ�����
		//����λ��
		KeyOfValue kov;
		int idx = kov(data) % _table.size();
		pNode cur = _table[idx];
		while (cur) {
			if (kov(cur->_data) == kov(data))
				return false;
			cur = cur->_next;
		}
		//����, ͷ��
		cur = new Node(data);
		cur->_next = _table[idx];
		_table[idx] = cur;

		++_size;
		return true;
	}

	void checkCapacity() {
		//�������ӣ� ����Ϊ1
		if (_size == _table.size()) {
			size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();

			//�����µ�vector
			vector<pNode> newT;
			newT.resize(newC);
			KeyOfValue kov;
			//�����ɱ��ɱ�ڵ����¹��ص��±���
			for (int i = 0; i < _table.size(); ++i) {
				//��ȡ��ǰλ�õ������ͷ
				pNode cur = _table[i];
				//������ǰ�����ÿһ���ڵ㣬���¼���λ��
				while (cur) {
					//���ȱ���ɱ��next�ڵ�
					pNode next = cur->_next;

					int idx = kov(cur->_data) % newT.size();
					//ͷ��
					cur->_next = newT[idx];
					newT[idx] = cur;

					cur = next;
				}
				//�ɱ�ǰλ�ñ�ɿ�����
				_table[i] = nullptr;
			}
			//������
			_table.swap(newT);
		}
	}

	size_t getTableSize() {
		return _table.size();
	}

	bool erase(const K& key);

	pNode find(const K& key);

private:
	//ָ������
	vector<pNode> _table;
	size_t _size = 0;
};

template <class K, class V>
class UnorderedMap {

	struct MapKeyOfValue {
		const K& operator()(const pair<K, V>& data) {
			return data.first;
		}
	};
public:
	bool insert(const pair<K, V>& data) {
		return _hb.insert(data);
	}

	//��ϣ��ʵ��
private:
	HashBucket<K, pair<K, V>, MapKeyOfValue> _hb;
};

template <class V>
class UnorderedSet {

	struct SetKeyOfValue {
		const V& operator()(const V& data) {
			return data;
		}
	};
public:
	bool insert(const V& data) {
		return _hb.insert(data);
	}

	//��ϣ��ʵ��
private:
	HashBucket<V, V, SetKeyOfValue> _hb;
};



void testHB() {
	HashBucket<int, int, KeyOfValue<int>> hb;
	hb.insert(21);
	hb.insert(48);
	hb.insert(36);
	hb.insert(43);
	hb.insert(5);
	hb.insert(61);
	hb.insert(78);
	hb.insert(15);
	hb.insert(6);
	hb.insert(23);
	hb.insert(51);
	hb.insert(52);
	hb.insert(53);
	hb.insert(54);
	hb.insert(55);
	hb.insert(56);
}

void testMap2() {
	UnorderedMap<int, int> mp;
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(2, 2));
	mp.insert(make_pair(3, 3));
	mp.insert(make_pair(4, 4));
	mp.insert(make_pair(5, 5));
}

int main() {
	//testHB();
	testMap2();
	return 0;
}
