#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
	//1.查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
		{
			return "";
		}

		//纵向扫描字符串数组，比较每个字符串同一位置字符是否相同，返回相同的最大子串
		int row = strs.size();
		int col = strs[0].size();
		
		for (int j=0;j<col;j++)
		{
			char c = strs[0][j];
			for (int i=1;i<row;i++)
			{
				if (strs[i][j] != c || j == strs[i].size()) //字符串出现字符不相同时取子串，或达到字符串最大长度
				{
					return strs[0].substr(0, j);
				}
			}
		}
		return strs[0];
	}

	//2.给你一个字符串 s，找到 s 中最长的回文子串 动态规划
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		string ans;
		for (int l = 0; l < n; ++l) {
			for (int i = 0; i + l < n; ++i) {
				int j = i + l;
				if (l == 0) {
					dp[i][j] = 1;
				}
				else if (l == 1) {
					dp[i][j] = (s[i] == s[j]);
				}
				else {
					dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
				}
				if (dp[i][j] && l + 1 > ans.size()) {
					ans = s.substr(i, l + 1);
				}
			}
		}
		return ans;
	}

	//3.给定一个字符串，逐个翻转字符串中的每个单词
	//无空格字符构成一个单词。输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
	string reverseWords(string s) {
		if (s.find(' ') == s.npos)
		{
			return s;
		}

		vector<string> words;
		for (size_t i=0;i<s.size();i++)
		{
			if (s[i]!=' ')
			{
				string word = "";
				for (size_t j=i;j<s.size();j++)
				{
					if (j == s.size() - 1) //取到最后一个字符时候的情况
					{
						word = s.substr(i, j - i+1);
						i = j;
						break;
					}

					if (s[j] == ' ') //找到空格开始截取字符
					{
						word = s.substr(i, j-i);
						i = j;
						break;
					}
				}
				words.push_back(word);
			}
		}

		string result = "";
		for (int i = words.size()-1;i>=0;i--)
		{
			if (i != 0)
			{
				result += words[i] + ' ';
			}
			else
			{
				result += words[i];
			}
		}
		return result;
	}
	
	//4.给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回-1。
	//当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符
	int strStr(string haystack, string needle) {
		if (needle.empty())
		{
			return 0;
		}
		//暴力枚举法直接在原字符串中取子串比较
		for (int i=0;i<haystack.size();i++)
		{
			string s = haystack.substr(i,needle.size());
			if (s == needle)
			{
				return i;
			}
		}
		return -1;

		// kmp字符串匹配算法
		/*
		int m = needle.length() , n = haystack.length();
		if(!m)return 0;
		vector <int> next(m , 0);
		next[0] = -1;
		int j = -1;
		for(int i = 0 ; i < m - 1 ; i++) {
			while(j >= 0 && needle[j] != needle[i])j = next[j];
			j++;
			next[i + 1] = j;
		}
		j = 0;
		for(int i = 0 ; i < n ; i++) {
			while(j >= 0 && haystack[i] != needle[j])j = next[j];
			j++;
			if(j == m)return i - m + 1;
		}
		return -1;
		*/
	}

	//5.编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
	//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题
	void reverseString(vector<char>& s) {
		int i = 0;
		int j = s.size() - 1;
		while (i<j)
		{
			char ch = s[i];
			s[i] = s[j];
			s[j] = ch;
		}
	}

};

int main() {

	Solution* s = new Solution();
	vector<char> sh = { 'a','b','b','v' };
	s->reverseString(sh);

	return 0;
}