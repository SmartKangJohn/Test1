#pragma once
#include "studyAlgoFourBase.h"

//欧几里得算法求最大公约数
int mAlgoFourBase::mGcd(int & p, int & q)
{
	if (q == 0)
	{
		return p;
	}
	int r = p % q;
	return mGcd(q, r);
}

//二分查找-递归
int mAlgoFourBase::binarySearch_rank(int & fid, std::vector<int>& nums)
{
	int nsize = nums.size() - 1;
	return binarySearch_rank(fid, nums, 0, nsize);
}
int mAlgoFourBase::binarySearch_rank(int & fid, std::vector<int>& nums, int lo, int hi)
{
	if (lo > hi)
	{
		return -1;
	}
	int mid = lo + (hi - lo) / 2;
	if (fid < nums[mid])
	{
		return binarySearch_rank(fid, nums, lo, mid - 1);
	}
	else if(fid > nums[mid])
	{
		return binarySearch_rank(fid, nums, mid + 1, hi);
	}
	else
	{
		return mid;
	}
}

double mAlgoFourBase::uniform(double a, double b)
{
	if (a < 0 || b < 0 || a >= b)
	{
		printf("uniform区间范围输入有误： %d.\n", -1);
		return -1;
	}
	return a + random_d()*(b - a);
}

float mAlgoFourBase::uniform(float a, float b)
{
	if (a < 0 || b < 0 || a >= b)
	{
		printf("uniform区间范围输入有误： %d.\n", -1);
		return -1;
	}
	return a + random_f()*(b - a);
}

int mAlgoFourBase::uniform(int N)
{
	if (N < 0)
	{
		printf("uniform区间范围输入有误： %d.\n", -1);
		return -1;
	}
	return (int)(random_f()*N);
}

int mAlgoFourBase::uniform(int lo, int hi)
{
	if (lo < 0 || lo < 0 || lo >= hi)
	{
		printf("uniform区间范围输入有误： %d.\n", -1);
		return -1;
	}
	return (int)(lo + random_f()*(hi - lo));
}

double mAlgoFourBase::random_d()
{
	std::default_random_engine e;
	std::uniform_real_distribution<double> u(0, 1);//随机数分布对象
	return u(e);
}

float mAlgoFourBase::random_f()
{
	std::default_random_engine e;
	std::uniform_real_distribution<float> u(0, 1);//随机数分布对象
	return u(e);
}

