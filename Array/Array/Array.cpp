#include "iostream"
#include "vector"
#include < algorithm>


using namespace std;

/*
���� �б� ����
����һ�㱻����Ϊ����һ������ȷ����Ԫ�������ɵ����壬�������Ԫ�����Ͳ�һ����ͬ���������Ԫ��û��˳��
�������һЩ��Ϊ ���� ����������ʶÿ�������������е�λ�ã����ڴ������������У������Ǵ� 0 ����ġ����ǿ��Ը��������е����������ٷ��������е�Ԫ�ء�
�����е�Ԫ�����ڴ����������洢�ģ���ÿ��Ԫ��ռ����ͬ��С���ڴ�
�б���û�������������������б����Ĳ�ͬ�㡣�б��е�Ԫ�����ڴ��п��ܱ˴����ڣ�Ҳ���ܲ�����

���鳣�ò���ʱ�临�Ӷ�
��ȡ O(1) ���� O(N)  ���� O(N) ���һ��Ԫ�غ����O(1)  ɾ�� O(N)

*/

class Solution {
public:

	//1.������������������û��������������-1 ��������������ߵ�Ԫ���ۼӺ͵��������ұߵ��ۼӺ�

	//˼·1���������鲢������Ԫ���������ߵĺͽ����ۼӣ��ж��Ƿ�left==right��ʱ�临�Ӷ�O(n*n)
	int pivotIndexS(vector<int>& nums) {
		int left = 0;
		int len = nums.size();
		int right = 0;
		if (len<=2)
		{
			return -1;
		}

		//�����һ��Ԫ�غ������Ԫ���ۼӺ�Ϊ0����������0
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
		//������һ��Ԫ��ǰ������Ԫ���ۼӺ�Ϊ0���������һ��Ԫ������
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

	//˼·2����׺�������������Ԫ���ܺ�sum,sum = left + x + right,��left = right,��left = sum - x - left
	//ֻ���ж��Ƿ�left == sum - x - left��ʱ�临�Ӷ�O(n)
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

	//2.��������λ�� ����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ��
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

	//3.�ϲ������ص����� ����һ������ļ��ϣ��ϲ������ص�������
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