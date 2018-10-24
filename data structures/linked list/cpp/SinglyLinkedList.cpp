#include "SinglyLinkedList.h"
#include <iostream>

using namespace std;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2)
{
	if (info1.x == info2.x) return 0;
	if (info1.x < info2.x) return -1;
	return 1;
}

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l)
{
	return (l.pHead == NULL);
}

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char* str)
{
	cout << str << endl;
	Node *head = l.pHead;
	while (head) {
		cout << head->info.x << " ";
		head = head->pNext;
	}
}

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node* CreateNode(Data info)
{
	Node *newNode = new Node();
	newNode->pNext = NULL;
	newNode->info = info;

	return newNode;
}

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info)
{
	Node *head = l.pHead;
	while (head) {
		if (CompareData(info, head->info) == 0) return head;
		head = head->pNext;
	}
	return NULL;
}

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index)
{
	Node *p = l.pHead;
	while (index > 0) {
		if (p == NULL) return p;
		p = p->pNext;
		index--;
	}
	return p;
}

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	int index = 0;
	Node *p = l.pHead;
	while (p) {
		if (pNode == p) return index;
		index++;
		p = p->pNext;
	}
	return -1;
}

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	Node *p = l.pHead;
	Node *preP = NULL;
	while (p){
		if (p == pNode) return preP;
		preP = p;
		p = p->pNext;
	}
	return NULL;
}

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List& l, Node* pNewNode)
{
	pNewNode->pNext = l.pHead;
	l.pHead = pNewNode;
	if (l.pTail == NULL) l.pTail = l.pHead;
}

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info)
{
	Node *pNewNode = CreateNode(info);
	AddHead(l, pNewNode);
	return pNewNode;
}

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List& l, Node* pNewNode)
{
	if (IsEmptyList(l)) AddHead(l, pNewNode);
	else {
		pNewNode->pNext = NULL;
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info)
{
	Node *pNewNode = CreateNode(info);
	AddTail(l, pNewNode);
	return pNewNode;
}

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(List& l, Node* q, Node* pNewNode)
{
	if (q == l.pHead) AddHead(l, pNewNode);
	else if (q == l.pTail) AddTail(l, pNewNode);
	else {
		pNewNode->pNext = q->pNext;
		q->pNext = pNewNode;
	}
}

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAfter(List& l, Node* q, Data info)
{
	Node * pNewNode = CreateNode(info);
	AddAfter(l, q, pNewNode);
	return pNewNode;
}

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddBefore(List& l, Node* q, Node* pNewNode)
{
	Data info = pNewNode->info;
	*pNewNode = *q;
	q->pNext = pNewNode;
	q->info = info;
	if (q == l.pTail) l.pTail = pNewNode;
}

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, Data info)
{
	Node *pNewNode = CreateNode(info);
	AddBefore(l, q, pNewNode);
	return pNewNode;
}

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List& l, Node* pNewNode)
{
	Node *p = l.pHead;
	while (p) {
		if (CompareData(p->info, pNewNode->info) == 1) {
			AddBefore(l, p, pNewNode);
			return;
		}
		p = p->pNext;
	}
	AddTail(l, pNewNode);
}

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, Data info)
{
	Node* pNewNode = CreateNode(info);
	AddAscendingList(l, pNewNode);
	return pNewNode;
}

// 20. Hàm hủy một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveHead(List& l)
{
	Node *p = l.pHead;
	l.pHead = p->pNext;
	return p;
}

// 21. Hàm hủy một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveTail(List& l)
{
	if (IsEmptyList(l)) return NULL;
	if (l.pHead->pNext == NULL) {
		return RemoveHead(l);
	}
	Node *p = l.pHead;
	while (p->pNext != l.pTail) {
		p = p->pNext;
	}
	
	Node *tmp = l.pTail;
	p->pNext = NULL;
	l.pTail = p->pNext;
	return tmp;
}

// 22. Hàm hủy một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveAfter(List& l, Node* q)
{
	if (q == l.pTail) return NULL;
	Node *p = q->pNext;
	q->pNext = p->pNext;
	return p;
}

// 23. Hàm hủy một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node* RemoveNode(List& l, Data info)
{  
	if (CompareData(l.pHead->info, info) == 0) {
		return RemoveHead(l);
	}

	Node *p = l.pHead;
	Node *preP = NULL;

	while (p) {
		if (CompareData(info, p->info) == 0) break;
		preP = p;
		p = p->pNext;
	}

	if (p == NULL) return NULL;
	return RemoveAfter(l, preP);
}

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void RemoveAll(List& l)
{
	while (!IsEmptyList(l)) {
		delete RemoveHead(l);
	}
}