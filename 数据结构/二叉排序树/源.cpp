#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char  date_str[100];
	time_t t= time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(date_str, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	printf("%s", date_str);
	return 0;
}
//
//void UniqueArray(int arr[], int n, int min, int max) {
//	if (n > max - min + 1) return;
//
//	int total = max - min + 1;
//	int temp[10000];
//	for (int i = 0; i < total; i++) {
//		temp[i] = min + i;
//	}
//	srand((unsigned int)time(NULL));
//	for (int i = total - 1; i > 0; i--) {
//		int j = rand() % (i + 1);
//		int t = temp[i];
//		temp[i] = temp[j];
//		temp[j] = t;
//	}
//	for (int i = 0; i < n; i++) {
//		arr[i] = temp[i];
//	}
//}
//
//typedef struct node {
//	int data;
//	struct node* leftChild;
//	struct node* rightChild;
//} BiTreeNode;
//
//int Insert(BiTreeNode** root, int item) {
//	BiTreeNode* current, * parent = NULL, * p;
//	current = *root;
//	while (current != NULL) {
//		if (current->data == item) return 0;
//		parent = current;
//		if (current->data < item) current = current->rightChild;
//		else current = current->leftChild;
//	}
//
//	p = (BiTreeNode*)malloc(sizeof(BiTreeNode));
//	p->data = item;
//	p->leftChild = NULL;
//	p->rightChild = NULL;
//
//	if (parent == NULL)
//		*root = p;
//	else if (item < parent->data)
//		parent->leftChild = p;
//	else
//		parent->rightChild = p;
//	return 1;
//}
//
//
//
//void inOrderTraverse(BiTreeNode* T) {
//	if (T) {
//		inOrderTraverse(T->leftChild);
//		printf("%d ", T->data);
//		inOrderTraverse(T->rightChild);
//	}
//}
//
//void indentPrint(BiTreeNode* T) {
//	if (T == NULL) return;
//
//	BiTreeNode* Queue[100];
//	int depth[100];
//	int front = 0, rear = 0;
//
//	Queue[rear] = T;
//	depth[rear] = 0;
//	rear++;
//
//	while (front < rear) {
//		BiTreeNode* node = Queue[front];
//		int depth2 = depth[front];
//		front++;
//
//		for (int i = 0; i < depth2; i++)printf("  ");
//		printf("%d\n", node->data);
//
//		if (node->leftChild) {
//			Queue[rear] = node->leftChild;
//			depth[rear] = depth2 + 1;
//			rear++;
//		}
//		if (node->rightChild) {
//			Queue[rear] = node->rightChild;
//			depth[rear] = depth2 + 1;
//			rear++;
//		}
//	}
//}
//
//int Search(BiTreeNode* root, int item, int compareCount) {
//	BiTreeNode* p;
//	if (root != NULL) {
//		p = root;
//		while (p != NULL) {
//			if (p->data == item) {
//				compareCount++;
//				return 1;
//			}
//			if (item > p->data) {
//				compareCount++;
//				p = p->rightChild;
//			}
//			else {
//				compareCount++;
//				p = p->leftChild;
//			}
//		}
//	}
//	return 0;
//}
//
//int Delete(BiTreeNode** root, int item, int* count) {
//	BiTreeNode* current = *root;
//	BiTreeNode* parent = NULL;
//	(*count) = 0; // 初始化操作次数计数器
//
//	// 步骤1：查找待删除节点及其父节点
//	while (current != NULL && current->data != item) {
//		(*count)++; // 查找过程计数（比较+移动）
//		parent = current;
//		if (item < current->data) {
//			current = current->leftChild;
//		}
//		else {
//			current = current->rightChild;
//		}
//	}
//
//	// 待删除节点不存在
//	if (current == NULL) {
//		(*count)++; // 记录最终判断次数
//		return 0;
//	}
//
//	// 步骤2：分三种情况删除节点
//	// 情况1：待删除节点为叶子节点（无左右子树）
//	if (current->leftChild == NULL && current->rightChild == NULL) {
//		(*count)++; // 记录判断叶子节点的操作
//		if (parent == NULL) { // 树中仅根节点
//			*root = NULL;
//		}
//		else if (parent->leftChild == current) {
//			parent->leftChild = NULL;
//		}
//		else {
//			parent->rightChild = NULL;
//		}
//		free(current); // 释放节点内存
//		(*count)++; // 记录释放内存操作
//	}
//
//	// 情况2：待删除节点仅有右子树
//	else if (current->leftChild == NULL) {
//		(*count)++; // 记录判断单右子树的操作
//		if (parent == NULL) { // 根节点仅有右子树
//			*root = current->rightChild;
//		}
//		else if (parent->leftChild == current) {
//			parent->leftChild = current->rightChild;
//		}
//		else {
//			parent->rightChild = current->rightChild;
//		}
//		free(current);
//		(*count)++; // 记录释放内存操作
//	}
//
//	// 情况3：待删除节点仅有左子树
//	else if (current->rightChild == NULL) {
//		(*count)++; // 记录判断单左子树的操作
//		if (parent == NULL) { // 根节点仅有左子树
//			*root = current->leftChild;
//		}
//		else if (parent->leftChild == current) {
//			parent->leftChild = current->leftChild;
//		}
//		else {
//			parent->rightChild = current->leftChild;
//		}
//		free(current);
//		(*count)++; // 记录释放内存操作
//	}
//
//	// 情况4：待删除节点有左右子树（找右子树最小节点替换）
//	else {
//		(*count)++; // 记录判断双子女节点的操作
//		BiTreeNode* successorParent = current;
//		BiTreeNode* successor = current->rightChild;
//
//		// 查找右子树的最小节点（最左节点）
//		while (successor->leftChild != NULL) {
//			(*count)++; // 记录查找后继节点的操作
//			successorParent = successor;
//			successor = successor->leftChild;
//		}
//
//		// 替换待删除节点的值
//		current->data = successor->data;
//		(*count)++; // 记录值替换操作
//
//		// 删除后继节点（后继节点最多仅有右子树）
//		if (successorParent == current) {
//			successorParent->rightChild = successor->rightChild;
//		}
//		else {
//			successorParent->leftChild = successor->rightChild;
//		}
//		free(successor);
//		(*count)++; // 记录释放后继节点内存操作
//	}
//
//	return 1;
//}
//
//int main() {
//	int arr[30];
//	UniqueArray(arr, 30, -1000, 1000);
//	printf("原始数据:\n");
//	for (int i = 0; i < 30; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//	BiTreeNode* T = NULL;
//	for (int i = 0; i < 30; i++) {
//		Insert(&T, arr[i]);
//	}
//
//	printf("凹入法输出二叉排序树:\n");
//	indentPrint(T);
//
//	printf("中序遍历输出二叉排序树的节点:\n");
//	inOrderTraverse(T);
//
//	int compareCount = 0;
//	int item = 133;
//	if (Search(T, item, compareCount) == 1)printf("\n%d查找成功,比较次数:%d", item, compareCount);
//	else printf("\n%d查找失败,比较次数:%d", item, compareCount);
//	int key,count;
//	printf("输入删除的键值：");
//	scanf("%d", &key);
//	if (Delete(&T, key, &count)) {
//		printf("删除成功，操作次数：%d\n", count);
//	}
//	else {
//		printf("键值不存在，操作次数：%d\n", count);
//	}
//	return 0;
//}
