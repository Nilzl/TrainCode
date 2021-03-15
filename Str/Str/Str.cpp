#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
	//1.�����ַ��������е������ǰ׺����������ڹ���ǰ׺�����ؿ��ַ��� ""
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
		{
			return "";
		}

		//����ɨ���ַ������飬�Ƚ�ÿ���ַ���ͬһλ���ַ��Ƿ���ͬ��������ͬ������Ӵ�
		int row = strs.size();
		int col = strs[0].size();
		
		for (int j=0;j<col;j++)
		{
			char c = strs[0][j];
			for (int i=1;i<row;i++)
			{
				if (strs[i][j] != c || j == strs[i].size()) //�ַ��������ַ�����ͬʱȡ�Ӵ�����ﵽ�ַ�����󳤶�
				{
					return strs[0].substr(0, j);
				}
			}
		}
		return strs[0];
	}

	//2.����һ���ַ��� s���ҵ� s ����Ļ����Ӵ� ��̬�滮
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

	//3.����һ���ַ����������ת�ַ����е�ÿ������
	//�޿ո��ַ�����һ�����ʡ������ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ���������������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
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