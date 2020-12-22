#include "iostream"
#include "vector"
#include "algorithm"


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
		//使用sort函数对vector进行排序，按左端从小到大排列的排列
		sort(intervals.begin(), intervals.end());

		vector<vector<int>> merged;

		//然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
		//如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
		//否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。
		for (int i = 0; i < intervals.size(); i++) {
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

	//4. 旋转矩阵 给定一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节，将图像旋转 90 度

	//思路1：使用辅助矩阵 对于矩阵中第i行的第j个元素，在旋转后，它出现在倒数第i列的第j个位置 vect[col][n-row-1] = martix[row][col]
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size(); // 行数
		int column = matrix[0].size(); //列数

		//为旋转后的矩阵分配内存
		vector<vector<int>> vect;
		vect.resize(column);
		for (int i = 0;i < column;i++)
		{
			vect[i].resize(row);
		}

		//矩阵旋转 将列转成行 
		for (int j=0;j<column;j++)
		{
			for (int i=row-1;i>=0;i--)
			{
				vect[j][row-i-1] = matrix[i][j];
			}
		}

		/*
		matrix.resize(column);
		for (int i = 0; i < column; i++)
		{
			matrix[i].resize(row);
		}
		
		*/
		matrix = vect;
		for (int i=0;i<column;i++)
		{
			for (int j=0;j<row;j++)
			{
				//matrix[i][j] = vect[i][j];
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}

	//思路2：用翻转替代旋转 空间复杂度由O(N*N)变成O(1) 
	//将矩阵先水平翻转一次，matrix[row][col] = matrix[n−row−1][col]；主对角线翻转一次matrix[row][col] = matrix[col][row]。联立得到martix[col][n-row-1] = martix[row][col]和思路1一致
	void rotate2(vector<vector<int>>& matrix) {
		int n = matrix.size();
		// 水平翻转
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n; ++j) {
				swap(matrix[i][j], matrix[n - i - 1][j]);
			}
		}
		// 主对角线翻转
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}

	//5. 零矩阵 若M × N矩阵中某个元素为0，则将其所在的行与列清零
	void setZeroes(vector<vector<int>>& matrix) {
		vector<vector<int>> vec = matrix;
		int row = matrix.size();
		int col = matrix[0].size();

		for (int i=0;i<row;i++)
		{
			for (int j=0;j<col;j++)
			{
				if (matrix[i][j] == 0)
				{
					continue;
				}
			}
		}
	}
};

int main()
{
	Solution* s = new Solution();
	//vector<int> vec{ 1,3,5,6};
	//vector<vector<int>> interval = { {1,3},{2,6},{15,18} };
	//cout << s->pivotIndex(vec) << endl;
	//cout << s->searchInsert(vec, 0) << endl;
	vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9},{11,12,13} };
	s->rotate(matrix);
	return 0;
}