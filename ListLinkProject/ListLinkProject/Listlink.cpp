#include "iostream"

using namespace std;

/*
链表是非线性存储的数据结构，对比单双链表
它们都无法在常量时间内随机访问数据
它们都能够在 O(1) 时间内在给定结点之后或列表开头添加一个新结点
它们都能够在 O(1) 时间内删除第一个结点
但是删除给定结点(包括最后一个结点)时略有不同

在单链表中，它无法获取给定结点的前一个结点，因此在删除给定结点之前我们必须花费 O(N) 时间来找出前一结点。
在双链表中，这会更容易，因为我们可以使用“prev”引用字段获取前一个结点。因此我们可以在 O(1) 时间内删除给定结点。

PS：此处的时间复杂度是直接对节点进行操作的时间复杂度 add(*Linklist,*node) 和 add(*Linklist,int val)时间复杂度不一样
*/

//单链表
class SinglyLinkedList {
private:
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) :val(x), next(nullptr) {}
	};
	ListNode* head;
public:
	/** Initialize your data structure here. */
	SinglyLinkedList() {
		head = nullptr;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. index从0开始 */
	int get(int index) {
		if (head == nullptr)
		{
			return -1;
		}
		else {
			ListNode* node = head;
			while (index != 0)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					return -1;
				}
				
				index--;
			}
			return node->val;
		}
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		if (head == nullptr)
		{
			ListNode* p = new ListNode(val);
			head = p;
		}
		else {
			ListNode* node = new ListNode(val);
			node->next = head;
			head = node;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (head == nullptr)
		{
			addAtHead(val);
		}
		else {
			ListNode* tail = new ListNode(val);
			ListNode* node = head;
			while (true)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					node->next = tail;
					break;
				}
			}
		}
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index == 0 || index < 0)
		{
			addAtHead(val);
		}

		ListNode* node = head;
		if (index == getLength())
		{
			addAtTail(val);
		}
		else
		{
			while (index != 1)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					return;
				}
				index--;
			}
			ListNode* addNode = new ListNode(val);
			ListNode* nextNode = node->next;
			node->next = addNode;
			addNode->next = nextNode;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= getLength() || index <0)
		{
			return;
		}
		else if(index == 0){
			head = head->next;
		}else if (index == getLength()-1){
			ListNode* node = head;
			while (index != 1)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					return;
				}
				index--;
			}
			ListNode* deleteNode = node->next;
			node->next = nullptr;
			delete deleteNode;
		}
		else
		{
			ListNode* node = head;
			while (index != 1)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					return;
				}
				index--;
			}
			ListNode* deleteNode = node->next;
			node->next = node->next->next;
			delete deleteNode;
		}
	}

	//返回链表长度
	int getLength() {
		ListNode* node = head;
		if (node == nullptr)
		{
			return 0;
		}
		int len = 1;
		while (true)
		{
			if (node->next)
			{
				node = node->next;
				len++;
			}
			else
			{
				return len;
			}
		}
	}

	//输出链表
	void printList() {
		ListNode* node = head;
		while (true)
		{
			cout << node->val << endl;
			if (node->next)
			{
				node = node->next;
			}
			else
			{
				cout << "end" << endl;
				return;
			}

		}
	}
};

//双链表
class DoubleLinkList {
private:
	struct ListNode {
		int val;
		ListNode *next, *prev;
		ListNode(int x) : val(x), next(NULL), prev(NULL) {}
	};
	ListNode* head;

public:
	/** Initialize your data structure here. */
	DoubleLinkList() {
		head = nullptr;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (head == nullptr)
		{
			return -1;
		}
		else
		{
			ListNode* node = head;
			while (index != 0)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					return -1;
				}
				index--;
			}
			return node->val;
		}
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		if (head == nullptr)
		{
			ListNode* node = new ListNode(val);
			head = node;
		}
		else
		{
			ListNode* node = new ListNode(val);
			node->next = head;
			head->prev = node;
			head = node;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		if (head == nullptr)
		{
			addAtHead(val);
		}
		else
		{
			ListNode* node = head;
			while (true)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					break;
				}
			}
			ListNode* tail = new ListNode(val);
			node->next = tail;
			tail->prev = node;
		}
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index<=0)
		{
			addAtHead(val);
		}else if (index>getLength())
		{
			return;
		}
		else if (index == getLength()) 
		{
			addAtTail(val);
		}
		else
		{
			ListNode* node = head;
			while (index>0)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					break;
				}
				index--;
			}
			ListNode* add = new ListNode(val);
			ListNode* prev = node->prev;
			prev->next = add;
			add->prev = prev;
			node->prev = add;
			add->next = node;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index<0||index>getLength()-1)
		{
			return;
		}
		else if (index == 0)
		{
			head = head->next;
			if (head != nullptr)
			{
				head->prev = nullptr;
			}	
		}
		else {
			ListNode* node = head;
			while (index>0)
			{
				if (node->next)
				{
					node = node->next;
				}
				else
				{
					break;
				}
				index--;
			}
			ListNode* deleteNode = node;
			ListNode* prev = node->prev;
			if (node->next)
			{
				prev->next = node->next;
				node->next->prev = prev;
				delete deleteNode;
			}
			else
			{
				prev->next = nullptr;
				delete deleteNode;
			}
		}

	}

	int getLength() {
		if (head == nullptr)
		{
			return 0;
		}
		else
		{
			ListNode* node = head;
			int index = 1;
			while (true)
			{
				if (node->next)
				{
					node = node->next;
					index++;
				}
				else
				{
					break;
				}
			}
			return index;
		}
	}

	void printList() {
		if (head == nullptr)
		{
			return;
		}
		ListNode* node = head;
		while (true)
		{
			cout << node->val << endl;
			if (node->next)
			{
				node = node->next;
			}
			else
			{
				return;
			}
		}
	}
};

//操作测试
int main(int argc, char* argv[]) {
	//SinglyLinkedList* linklist = new SinglyLinkedList();
	DoubleLinkList* linklist = new DoubleLinkList();
	linklist->addAtHead(1);
	linklist->addAtHead(2);
	linklist->addAtHead(3);
	linklist->addAtTail(4);
	linklist->addAtIndex(0,0);
	linklist->deleteAtIndex(4);
	cout << linklist->get(1) << endl;
	linklist->printList();
}