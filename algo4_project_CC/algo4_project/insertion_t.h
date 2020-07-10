#pragma once

template<typename T>
bool less(T a, T b) {
	if (compare(a,b) == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
T compare(T a, T b) {
	if (a == b)
	{
		return 0;
	}
	else if (a > b)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}


template<typename T>
void exch(T* vT, int i, int j)
{
	T val = vT[i];
	vT[i] = vT[j];
	vT[j] = val;
}