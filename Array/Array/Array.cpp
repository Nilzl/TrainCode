#include "iostream"
#include "vector"
#include < algorithm>


using namespace std;

/*
集合 列表 数组
集合一般被定义为：由一个或多个确定的元素所构成的整体，集合里的元素类型不一定相同，集合里的元素没有顺序
数组会用一些名为 索引 的数字来标识每项数据在数组中的位置，且在大多数编程语言中，索引是从 0 算起的。我们可以根据数组中的索引，快速访问数组中的元素。
数组中的元素在内存中是连续存储的，且每个元素占用相同大小的内存
列表中没有索引，这是数组与列表最大的不同点。列表中的元素在内存中可能彼此相邻，也可能不相邻

数组常用操作时间复杂度
读取 O(1) 查找 O(N)  插入 O(N) 最后一个元素后插入O(1)  删除 O(N)

*/

class Solution {
public:

	//1.查找数组中心索引，没有中心索引返回-1 定义中心索引左边的元素累加和等于索引右边的累加和

	//思路1：遍历数组并对数组元素左右两边的和进行累加，判断是否left==right，时间复杂度O(n*n)
	int pivotIndexS(vector<int>& nums) {
		int left = 0;
		int len = nums.size();
		int right = 0;
		if (len<=2)
		{
			return -1;
		}

		//如果第一个元素后的所有元素累加和为0，返回索引0
		for (int i=1;i<len;i++)
		{
			right += nums[i];
		}
		if (right == 0)
		{
			return 0;
		}
		else {
			right = 0;
		}

		for (int i=0;i<len-1;i++)
		{
			left += nums[i];
			right = 0;
			for (int j=i+2;j<len;j++)
			{
				right += nums[j];
			}

			if (left == right)
			{
				return i + 1;
			}
		}

		right = 0;
		//如果最后一个元素前的所有元素累加和为0，返回最后一个元素索引
		for (int i = len - 2; i >= 0; i--)
		{
			right += nums[i];
		}
		if (right == 0)
		{
			return len - 1;
		}
		else
		{
			return -1;
		}

	}

	//思路2：后缀法，计算出数组元素总和sum,sum = left + x + right,若left = right,则left = sum - x - left
	//只需判断是否left == sum - x - left，时间复杂度O(n)
	int pivotIndex(vector<int>& nums) {
		int left=0,sum = 0;
		int len = nums.size();
		for (int i=0;i<len;i++)
		{
			sum += nums[i];
		}
		for (int i=0;i<len;i++)
		{
			if (left == sum - left - nums[i])
			{
				return i;
			}
			left += nums[i];
		}
		return -1;
	}

	//2.搜索插入位置 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		for (int i=0;i<len;i++)
		{
			if (target == nums[i])
			{
				return i;
			}
			else if(target > nums[len-1])
			{
				return len;
			}
			else if (target < nums[0])
			{
				return 0;
			}
			else if (target>nums[i] && target < nums[i+1])
			{
				//nums.insert(nums.begin() + i, target);
				return i + 1;
			}
			return 0;
		}

	}

	//3.合并所有重叠区间 给出一个区间的集合，合并所有重叠的区间
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() == 0) {
			return {};
		}
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> merged;
		for (int i = 0; i < intervals.size(); ++i) {
			int L = intervals[i][0], R = intervals[i][1];
			if (!merged.size() || merged.back()[1] < L) {
				merged.push_back({ L, R });
			}
			else {
				merged.back()[1] = max(merged.back()[1], R);
			}
		}
		return merged;
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> vec{ 1,3,5,6};
	//vector<vector<int>> interval = { {1,3},{2,6},{15,18} };
	//cout << s->pivotIndex(vec) << endl;
	//cout << s->searchInsert(vec, 0) << endl;
	return 0;
}