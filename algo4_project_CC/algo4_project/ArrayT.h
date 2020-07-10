#pragma once
template<typename T, int N>
class ArrayT
{
	T p_array[N];

public:
	int len();
	bool set(int index, T value);
	bool get(int index, T& value);
	T& operator[] (int index);
	T operator[] (int index) const;
	virtual ~ArrayT();

	bool less(int i, int j);
	bool less1(T& val1, T& val2);
	void exch(int i, int j);
	void exch1(T aus[], int i, int j);
	bool isSorted();
	void insertionSort();
	void binarySelectionSort();
	void selectionSort();
	void shellSort();
	void mergeSort();
	void mergeSort_index();

	void show();

private:
	void mSort(T aus[], int lo, int hi);
	void mMerge(T aus[], int lo, int mid, int hi);
	void mSort_index(int index[], int aus[], int lo, int hi);
	void mMerge_index(int index[], int aus[], int lo, int mid, int hi);
	void insertSort(T aus[], int lo, int hi);

};

template<typename T, int N>
int ArrayT<T, N>::len()
{
	return N;
}

template<typename T, int N>
bool ArrayT<T, N>::set(int index, T value)
{
	bool ret = (index >= 0) && (index < N);
	if (ret)
	{
		p_array[index] = value;
	}
	return ret;
}

template<typename T, int N>
bool ArrayT<T, N>::get(int index, T& value)
{
	bool ret = (index >= 0) && (index < N);
	if (ret)
	{
		value = p_array[index];
	}
	return ret;
}

template<typename T, int N>
T& ArrayT<T, N>::operator[] (int index)
{
	if (index >= 0 && index < N)
	{
		return p_array[index];
	}
	else
	{
		throw 0;
	}
}

template<typename T, int N>
T ArrayT<T, N>::operator[] (int index) const
{
	if (index >= 0 && index < N)
	{
		return p_array[index];
	}
	else
	{
		throw 0;
	}
}

template<typename T, int N>
ArrayT<T, N>::~ArrayT()
{
}

template<typename T, int N>
bool ArrayT<T, N>::less(int i, int j)
{
	if (p_array[i] < p_array[j])
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T, int N>
bool ArrayT<T, N>::less1(T& val1, T& val2)
{
	if (val1 < val2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T, int N>
void ArrayT<T, N>::exch(int i, int j) 
{
	T a1 = p_array[i];
	p_array[i] = p_array[j];
	p_array[j] = a1;
}

template<typename T, int N>
void ArrayT<T, N>::exch1(T aus[], int i, int j)
{
	T a1 = aus[i];
	aus[i] = aus[j];
	aus[j] = a1;
}

template<typename T, int N>
bool ArrayT<T, N>::isSorted()
{
	int n = len();
	for (int i = 0; i < n-1; i++)
	{
		if (less(i,i+1))
		{
			continue;
		}
		else
		{
			return false;
		}
		if (i == n-2)
		{
			return true;
		}
	}
}

template<typename T, int N>
void ArrayT<T, N>::insertionSort()
{
	int n = len();
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0 && less(k,k-1); k--)
		{
			exch(k, k-1);
			show();
		}
	}
}

template<typename T, int N>
void ArrayT<T, N>::binarySelectionSort()
{
	int n = len();
	for (int i = 1; i < n; i++)
	{
		T v = p_array[i];
		int lo = 0;
		int hi = i;
		while (lo < hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (less1(v,p_array[mid]))
			{
				hi = mid;
			}
			else
			{
				lo = mid + 1;
			}
		}
		for (int k = i; k > lo; --k)
		{
			p_array[k] = p_array[k - 1];
			show();
		}
		p_array[lo] = v;
		show();
	}
}

template<typename T, int N>
void ArrayT<T, N>::selectionSort()
{
	int n = len();
	for (int i = 0; i < n; i++)
	{
		int min1 = i;
		for (int k = i+1; k < n; k++)
		{
			if (less1(p_array[k], p_array[min1]))
			{
				min1 = k;
			}
		}
		exch(i, min1);
		show();
	}
}

//h=3x+1
template<typename T, int N>
void ArrayT<T, N>::shellSort()
{
	int n = len();

	// 3x+1 increment sequence:  1, 4, 13, 40, 121, 364, 1093, ... 
	int h = 1;
	while (h < n/3)
	{
		h = 3 * h + 1;
	}
	while (h>=1)
	{
		for (int i = h; i < n; i++)
		{
			for (int k = i; k >= h && less1(p_array[k],p_array[k-h]); k-=h)
			{
				exch(k, k - h);
				show();
			}
		}
		h /= 3;
	}
}

//top-bottom
template<typename T, int N>
void ArrayT<T, N>::mergeSort()
{
	int n = len();
	T* aus = new T[n];
	mSort(aus, 0, n - 1);
}

//top-bottom
template<typename T, int N>
void ArrayT<T, N>::mergeSort_index()
{
	int n = len();
	int* index = new int[n];
	for (int i = 0; i < n; i++)
	{
		index[i] = i;
	}
	int* aus = new int[n];
	mSort(index, aus, 0, n - 1);
}

template<typename T, int N>
void ArrayT<T, N>::show()
{
	for (int i = 0; i < len(); i++)
	{
		if (i == 0)
		{
			printf("p_array: ");
		}
		std::cout << p_array[i] << ", ";
		if (i == len()-1)
		{
			printf("\n");
		}
	}
}

template<typename T, int N>
void ArrayT<T, N>::mSort(T aus[], int lo, int hi)
{
	if (hi <= lo)
	{
		return;
	}
	int mid = lo + (hi - lo) / 2;
	mSort(aus, lo, mid);

	mSort(aus, mid + 1, hi);

	mMerge(aus, lo, mid, hi);
	show();
}

template<typename T, int N>
void ArrayT<T, N>::mSort_index(int index[], int aus[], int lo, int hi)
{
	if (hi <= lo)
	{
		return;
	}
	int mid = lo + (hi - lo) / 2;
	mSort_index(index, aus, lo, mid);
	
	mSort_index(index, aus, mid + 1, hi);
	
	mMerge_index(index, aus, lo, mid, hi);
	
}

//原地归并
template<typename T, int N>
void ArrayT<T, N>::mMerge(T aus[], int lo, int mid, int hi)
{
	for (int k = lo; k <= hi; k++)
	{
		aus[k] = p_array[k];
	}
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++)
	{
		if (i > mid)
		{
			p_array[k] = aus[j++];  //赋值aus[j]给index[k]后j++
		}
		else if(j > hi)
		{
			p_array[k] = aus[i++];
		}
		else if(less1(aus[j], aus[i]))
		{
			p_array[k] = aus[j++];
		}
		else
		{
			p_array[k] = aus[i++];
		}
	}
}

template<typename T, int N>
void ArrayT<T, N>::mMerge_index(int index[], int aus[], int lo, int mid, int hi)
{
	for (int k = lo; k <= hi; k++)
	{
		aus[k] = index[k];
	}
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++)
	{
		if (i > mid)
		{
			index[k] = aus[j++];  //赋值aus[j]给index[k]后j++
		}
		else if (j > hi)
		{
			index[k] = aus[i++];
		}
		else if (less1(p_array[aus[j]], p_array[aus[i]]))
		{
			index[k] = aus[j++];
		}
		else
		{
			index[k] = aus[i++];
		}
	}
}

template<typename T, int N>
void ArrayT<T, N>::insertSort(T aus[], int lo, int hi)
{
	int n = len();
	for (int i = 1; i < n; i++)
	{
		for (int k = i; k > 0 && less(k, k - 1); k--)
		{
			exch(k, k - 1);
		}
	}
}