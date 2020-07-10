#pragma once
#include "studyAlgoFourBase.h"


using namespace std;

//
#if 0

//****
void gcd_ptf(int& p, int& q, int& o);
void bs_ptf(vector<int>& nums, int nfid, int fid);
void showGcd();
void showBinarySearch();


int main()
{
	//showGcd();
	//showBinarySearch();
	int f = 0;
	int g = 1;
	for (int i = 0; i<=15;i++)
	{
		printf("%d, ", f);
		f = f + g;
		g = f - g;
	}

	return 1;
}

void gcd_ptf(int& p, int& q, int& o)
{
	printf(" %d 和 %d 的最大公约数为： %d ;\n", p, q, o);
}
void bs_ptf(vector<int>& nums, int nfid, int fid)
{
	int nsize = nums.size()-1;
	for (int i = 0; i < nsize; i++)
	{
		if (i == 0)
		{
			printf("数组nums[%d]：", nsize+1);
		}
		printf(" %d ,", nums[i]);
	}
	printf("\n需要查找数为：%d", nfid);
	printf("\n二分查找数为：%d, index = %d 。\n", nums[fid], fid);
}
void showGcd()
{
	mAlgoFourBase mAl;

	int p = 4321;
	int q = 78;
	int hcl = mAl.mGcd(p, q);
	gcd_ptf(p, q, hcl);
	p = 450;
	q = 50;
	hcl = mAl.mGcd(p, q);
	gcd_ptf(p, q, hcl);
	p = 9;
	q = 2;
	hcl = mAl.mGcd(p, q);
	gcd_ptf(p, q, hcl);
}

void showBinarySearch()
{
	mAlgoFourBase mAl;
	const int index = 30;
	int num[index] = { 23, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1 };
	vector<int> nums;
	for (int i = 0; i<index;i++)
	{
		nums.push_back(num[i]);
	}
	sort(nums.begin(), nums.end());
	int nfid = 8;
	int fid = mAl.binarySearch_rank(nfid, nums);
	bs_ptf(nums, nfid, fid);
}

#endif

//测试ArrayT.h 和 insertion_t.h
#if 0
#include "ArrayT.h"
#include "insertion_t.h"
#include <time.h>

int main()
{
	int nums[10] = { 1,4,6,0,8,2,9,5,3,7 };
	ArrayT<int, 10> arrayT;
	for (int i = 0; i < 10; i++)
	{
		arrayT.set(i, nums[i]);
	}
	int size = arrayT.len();
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			cout << "_arrayT: ";
		}
		cout << i << ", ";
		if (i == size-1)
		{
			cout << endl << endl;
		}
	}
	bool ret = compare(arrayT[0], arrayT[1]);
	arrayT.exch(0, 1);
	double time1 = clock();
	//arrayT.insertionSort();
	//arrayT.binarySelectionSort();
	//arrayT.selectionSort();
	//arrayT.shellSort();
	//arrayT.mergeSort();

	cout << "timeCost: " << clock() - time1 << " ms.\n";
	ret = arrayT.isSorted();
	if (ret)
	{
		cout << "arrayT is sorted!\n";
	}

	return 1;
}

#endif

//测试longlong类型值
#if 0

#define MAX_LLONG_VAL 9223372036854775807

bool compareLL(size_t a, size_t b)
{
	return a < b;
}

int main()
{
	long long val1 = 1;
	for (int i = 0; i < 40; i++)
	{
		val1 *= 2;
		printf("第%d次val1的值为：%lld.\n", i+1, val1);
	}
	bool bRet = false;
	bRet = compareLL(val1, MAX_LLONG_VAL);
	return 1;
}

#endif

//测试0%2 == 0
#if 01

int main()
{
	for (int i = 0; i < 5; i++)
	{
		if (i%2 == 0)
		{
			cout << i << endl;
		}
	}

	return 1;
}

#endif