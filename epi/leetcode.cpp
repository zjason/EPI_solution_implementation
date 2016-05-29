#include "leetcode.h"



leetcode::leetcode()
{
	vector<int> test;
}


leetcode::~leetcode()
{
}
// we should know that 10^n%9 = 1 which means 10^n will not influence the result
// one example 512 = 5*100+10+2, we know that 100%9=1 and 10%9=1, so 512%9 = (5+1+2)%9 = 8
// single digit will not influenced by mod 9 except 9, so we need handle 9 seperately
int leetcode::addDigits(int num)
{
	if (num == 0) {
		return 0;
	}
	int result;
	result = num % 9;
	if (result == 0) {
		result = 9;
	}
	cout << result << endl;
	return result;
}

// if both of player are smart enough, then the other player can always take away
// stones to achive 4
bool leetcode::canWinNim(int n)
{
	if (n % 4 != 0) {
		return true;
	}
	return false;
}

// hash table will have time complexity of O(n), space complexity of O(n)
bool leetcode::containsDuplicate(vector<int>& nums)
{
	unordered_map <int, int> set;
	for (int i = 0; i < nums.size(); i++) {
		set[nums[i]]++;
		if (set[nums[i]] > 1) {
			return true;
		}
	}
	return false;
}

// use hash table to slove this problem, if nums1.size is n, nums2.size is m,
// then the time complexity is O(n+m), space complexity is O(n+m)
vector<int> leetcode::intersection(vector<int>& nums1, vector<int>& nums2)
{
	unordered_map<int, int> mp;
	vector<int> result;
	for (int i = 0; i < nums1.size(); i++) {
		if (mp[nums1[i]] == 0) {
			mp[nums1[i]]++;
		}
	}
	for (int i = 0; i < nums2.size(); i++) {
		if (mp[nums2[i]] == 1) {
			mp[nums2[i]]++;
			result.push_back(nums2[i]);
		}
	}
	return result;
}

// case1: rotate 0 position, return the original vector
// case2: rotate k mod size of vector equal to zero, in this case the array will not change
// case3: rotate k mod size not equal to zero, rotate k mode size position to create new array
void leetcode::rotate(vector<int>& nums, int k)
{
	if (k == 0) {
		return;
	}
	int vector_size = nums.size();
	if (vector_size - k < 0) {
		if (k%vector_size == 0) {
			return;
		} else {
			int newshift = k%vector_size;
			rotatehelper(nums, newshift);
		}
	}else{
		rotatehelper(nums, k);
	}
}
// a helper function that rotate the vector
void leetcode::rotatehelper(vector<int>& nums, int k)
{
	vector<int> newnum;
	for (int i = nums.size() - k; i < nums.size(); i++) {
		newnum.push_back(nums[i]);
	}
	for (int j = 0; j < nums.size() - k; j++) {
		newnum.push_back(nums[j]);
	}
	nums = newnum;

	for (int t = 0; t < nums.size(); t++) {
		cout << nums[t] << " ";
	}
	cout << endl;
}

// function string(n, 5+'A') will generate n number of 'F'
string leetcode::convertToTitle(int n)
{
	string result;
	while (n) {
		result = string(1, ((n - 1) % 26 + 'A')) + result;
		n = (n - 1) / 26;
		cout << "n is: " << n << " " << "result is: " << result << endl;
	}
	cout << result << endl;
	//char test;
	//test = 'A' + 6;
	//cout << test << endl;
	return result;
}

int leetcode::titleToNumber(string s)
{
	int result = 0;
	for (int i = 0; i < s.length(); i++) {
		result *= 26;
		result += s[i] - 'A' + 1;
	}
	cout << "result is: " << result;
	return result;
}

// change unsigned 32 bit integer to binary and count the number of 1
int leetcode::hammingWeight(uint32_t n)
{
	int result = 0;
	while (n)
	{
		if (n % 2 == 1) {
			result++;
		}
		n = n / 2;		
		cout << n << " " << result << endl;
	}
	return result;
}

// remove element from array,
int leetcode::removeElement(vector<int>& nums, int val)
{
	int array_len = 0;
	int count = 0;
	while (count < nums.size()) {
		if (nums[count] == val) {
			nums.erase(nums.begin() + count);
			count = 0;
		} else{
			count++;
		}
		
		cout << "i: " << count << " size: " << nums.size() << endl;
	}
	array_len = nums.size();
	return array_len;
}

