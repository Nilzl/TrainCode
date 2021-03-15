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
					if (s[j] == ' ' || j == s.size()-1)
					{
						word.append(s, i, j);
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
		
};

int main() {

	Solution* s = new Solution();
	string str = "  Hello World";
	cout << s->reverseWords(str) << endl;

	return 0;
}