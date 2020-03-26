#include <vector>
using namespace std;
template <class K>
struct KeyOfValue {
	const K& operator()(const K& key) {
		return key;
	}
};

// 数组+单链表

//单链表节点
template <class V>
struct HashNode {
	HashNode<V>* _next;
	V _data;

	HashNode(const V& data = V())
		:_data(data)
		, _next(nullptr)
	{}
};

//前置声明
template <class K, class V, class KeyOfValue>
class HashBucket;

template <class K, class V, class KeyOfValue>
struct HIterator {
	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef HashBucket<K，V, KeyOfValue> htable;

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
			//找到当前哈希表中下一个非空链表的头结点， 借助

			//计算当前节点在表中的位置
			KeyOfValue kov;
			//int idx = kov(_node->_data) % _ht->getTableSize();
			// 有元类可以直接访问私有成员
			int idx = kov(_node->_data) % _ht->_table.size();
			//从哈希表的下一个位置开始找到第一个非空链表的头结点
			++idx;
			for (; idx < _ht->_table.size(); ++idx) {
				if (_ht->_table[idx]) {
					//找到了第一个非空链表的头结点
					_node = _ht->_table[idx];
					break;
				}
			}
			//有可能后面的节点都为空节点
			if (idx == _ht->_table.size())
				_node = nullptr;  //表示是end迭代器的位置
		}
		return *this;
	}

};

template <class K, class V, class KeyOfValue>
class HashBucket {
public:
	//迭代器声明为哈希表的友元类
	template <class K, class V, class KeyOfValue>
	friend struct HIterator;

	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef HIterator<V> iterator;

	iterator begin() {

	}

	iterator end() {
		
	}

	//不允许插入重复元素
	bool insert(const V& data) {
		checkCapacity();

		//搜索key是否已经存在
		//计算位置
		KeyOfValue kov;
		int idx = kov(data) % _table.size();
		pNode cur = _table[idx];
		while (cur) {
			if (kov(cur->_data) == kov(data))
				return false;
			cur = cur->_next;
		}
		//插入, 头插
		cur = new Node(data);
		cur->_next = _table[idx];
		_table[idx] = cur;

		++_size;
		return true;
	}

	void checkCapacity() {
		//负载因子： 可以为1
		if (_size == _table.size()) {
			size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();

			//创建新的vector
			vector<pNode> newT;
			newT.resize(newC);
			KeyOfValue kov;
			//遍历旧表，旧表节点重新挂载到新表中
			for (int i = 0; i < _table.size(); ++i) {
				//获取当前位置的链表表头
				pNode cur = _table[i];
				//遍历当前链表的每一个节点，重新计算位置
				while (cur) {
					//首先保存旧表的next节点
					pNode next = cur->_next;

					int idx = kov(cur->_data) % newT.size();
					//头插
					cur->_next = newT[idx];
					newT[idx] = cur;

					cur = next;
				}
				//旧表当前位置变成空链表
				_table[i] = nullptr;
			}
			//交换表
			_table.swap(newT);
		}
	}

	size_t getTableSize() {
		return _table.size();
	}

	bool erase(const K& key);

	pNode find(const K& key);

private:
	//指针数组
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

	//哈希表实现
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

	//哈希表实现
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
