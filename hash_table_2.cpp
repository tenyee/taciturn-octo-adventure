//hash_table   by tenyee   2015.6.1

//use the vector and list to create the hash_table
//说明：这里的哈希表只是给出一个值通过这个值找到直接内存地址，而在这个内存地址中，我们存放这个值而已，这个与hash_map有什么不一样呢?
//区别就在于，hash_map 中通过这个值key，找到的地址，里面存放的是别一个东西，不是key,所以说，hash_map是由hash_table封装而来的！！
//后面我们可以自己实现一个hash_map.
//template <class T, class V, container = vector< list<V> > >:这里就像是hash_map的模板

//这里实现的是一个动态的hash_table,也就是说其大小会自动变化的，按两倍大小变化
template<class T, class container = vector< list<T> > >
class hash_table{
public:
    hash_table();
	hash_table(unsigned int nTableSize);//设置表的大小
	~hash_table():
	
	//常用操作
	bool insert(T& n);
	void insert(T *pFirst, T* pSecond);
	bool erase(T& n);
	bool find(T& n);
	void resize(int nNewTableSize);
	int size() const;
	unsigned int hashFunc(T& n);

private:
    unsigned int m_nDataCount;//记录当前数据大小，如果比哈希表的大小要大，则重新生成一个哈希表
	unsigned int m_nTableSize;//记录哈希表大小
	container m_Table;        //哈希表--由vector组成，元素为list<T>
};

template<class T, class container>//这个与类声明一致，只是默认参数可以不写
unsigned int hash_table<T, container>::hashFunc(T& n)
{
	return ( n ^ 0xdeadbeef) % m_nTableSize;//也就是返回vector的下标，这个下标范围由哈希表大小来定义
}

template<class T, class container>
int hash_table<T, container>::size() const
{
    return m_nDataCount;	
}

template<class T, class container>
hash_table<T, container>::hash_table()
{
	m_nDataCount = 0;
	m_nTableSize = 4096;//哈希表大小，你要创建一个哈希表！因为这里是第一次创建哈希表对象，所以，完全可以直接修改大小resize的，但这个函数container不一定提供。。。。
	m_Table.resize(m_nTableSize);//如此创建
}

template<class T, class container>
hash_table<T, container>::hash_table(unsigned int nTableSize)
{
	m_nDataCount = 0;
	m_nTableSize = nTableSize;//哈希表大小，你要创建一个哈希表！因为这里是第一次创建哈希表对象，所以，完全可以直接修改大小resize的，但这个函数container不一定提供。。。。
	m_Table.resize(m_nTableSize);//如此创建
}

template<class T, class container>
bool hash_table<T, container>::insert(T& n)
{
    //先通过这个值找到关键码，也就是直接地址
	unsigned int key = hashFunc(n);
	//通过这个key定位到哈希表相应位置，访问这个list,查看是否存在这个值，有则返回false,没有则插入并返回true，在list中没有find函数，在这里你要自己遍历List
	if (m_Table[key].empty)//当前位置链表为空，直接接入
	{
		m_Table[key].push_back(n);	
		m_nDataCount++;
		if (m_nDataCount >= m_nTableSize)
			resize(m_nTableSize * 2);
		return true;
	}
	else{
		list<T>::iterator iter = m_Table[key].begin();
		for(; iter != m_Table[key].end(); iter++)
		{
			if (*iter == n)
				return false;
		}
		m_Table[key].push_back(n);
		m_nDataCount++;
		if (m_nDataCount >= m_nTableSize)
			resize(m_nTableSize * 2);
		return true;
	}
}

template<class T, class container>
void hash_table<T, container>::insert(T *pFirst, T *pSecond)//把这个范围内的元素加到哈希表中
{
	for (T *p = pFirst; p != pSecond; ++p)
        insert(*p);
}

template<class T, class container>
bool hash_table<T, container>::erase(T& n)
{
	unsigned int key = hashFunc(n);
	if (m_Table[key].empty())//不存在这个数
	{
		cout << "no this element" <<endl;
		return false;
    }	
	list<T>::iterator iter = m_Table[key].begin();
	for (; iter != m_Table[key].end(); iter++)
	{
	    if (*iter == n)
		{
		      //erase(iter),删除iter迭代器并返回下一个元素的迭代器，当前迭代器失效，也就是不能再有iter++了
              //作用同erase(),remove()也会使迭代器失效，返回空
              m_Table[key].erase(iter);
			  m_nDataCount--;
              return true;			  
		}
	}
	cout << "no this element" <<endl;
	return false;
}

template<class T, class container>
bool hash_table<T, container>::find(T& n)
{
	unsigned int key = hashFunc(n);
	list<T>::iterator iter = m_Table[key].begin();
	for (; iter != m_Table[key].end(); iter++)
	{
	    if (*iter == n)
		{  
            return true;			  
		}
	}
	return false;
}

template<class T, class container>
void hash_table<T, container>::resize(unsigned int nNewTableSize)
{
	unsigned int oldTableSize = m_nTableSize;
	m_nTableSize = nNewTableSize;
	container tmpContainer(m_nTableSize);//创建一个更大的哈希表
	//重新计算key并把所以元素移到新表中去
	for (int i = 0; i < oldTableSize; ++i)
	{
		list<T>::iterator iter = m_Table[i].begin();//遍历所有元素，并重新计算key置于新表中
		unsigned int key;
		for(; iter != m_Table[i].end(); ++iter)
		{
			key = hashFunc(*iter);
			tmpContainer[key].push_back(*iter);
		}
	}
}







