#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace::std;

class leetcode
{
public:
	leetcode();
	~leetcode();
	int addDigits(int num);
	bool canWinNim(int n);
	bool containsDuplicate(vector<int>& nums);
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
	void rotate(vector<int>& nums, int k);
	void rotatehelper(vector<int>& nums, int k);
	string convertToTitle(int n);
	int titleToNumber(string s);
	int hammingWeight(uint32_t n);
	int removeElement(vector<int>& nums, int val);
	
};

