#pragma once
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <random>
#include <ddraw.h>

enum myChapter
{
	ONE_P_ONE = 1,
};

class mAlgoFourBase
{
public:

	static int mGcd(int& p, int& q);

	static int binarySearch_rank(int& fid, std::vector<int>& nums);
	static int binarySearch_rank(int& fid, std::vector<int>& nums, int lo, int hi);

	//返回[a,b)之间随机值
	static double uniform(double a, double b);
	static float uniform(float a, float b);
	static int uniform(int N);
	static int uniform(int lo, int hi);



protected:
	//生成[0.0,1.0)随机数
	static double random_d();
	static float random_f();

private:


};

