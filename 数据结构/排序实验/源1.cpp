#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int key;
	struct Node* next;
}Node;

typedef struct HashTable {
	int size;
	Node** table;
}HashTable;

Node* createNode(int key) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->next = NULL;
	return newNode;
}

HashTable* iniHashTable(int size) {
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->size = size;
	ht->table = (Node**)malloc(sizeof(Node*) * size);
	for (int i = 0; i < size; i++) {
		ht->table[i] = NULL;
	}
	return ht;
}

int hashFunction(HashTable* ht, int key) {
	return key % ht->size;
}

void insert(HashTable* ht, int key) {
	int index = hashFunction(ht, key);
	Node* newNode = createNode(key);
	if (ht->table[index] == NULL) {
		ht->table[index] = newNode;
	}
	else {
		Node* temp = ht->table[index];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int search(HashTable* ht, int key,int* count) {
	int index = hashFunction(ht, key);
	Node* temp = ht->table[index];
	while (temp != NULL) {
		(*count)++;
		if (temp->key == key)
			return 1;
		else
			temp = temp->next;
	}
	return 0;
}

int deleteNode(HashTable* ht, int key,int* count) {
	int index = hashFunction(ht, key);
	Node* temp = ht->table[index];
	Node* prev = NULL;
	while (temp != NULL && temp->key != key) {
		prev = temp;
		temp = temp->next;
		(*count)++;
	}
	if (temp == NULL)
		return 0;

	if (prev == NULL) {
		ht->table[index] = temp->next;
		(*count)++;
	}
	else {
		prev->next = temp->next;
		(*count)++;
	}
	free(temp);
	return 1;
}

void printHashTable(HashTable* ht) {
	for (int i = 0; i < ht->size; i++) {
		printf("索引%d:", i);
		Node* temp = ht->table[i];
		while (temp != NULL)
		{
			printf("%d->", temp->key);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void UniqueArray(int arr[], int n, int min, int max) {
	if (n > max - min + 1) return;

	int total = max - min + 1;
	int temp[10000];
	for (int i = 0; i < total; i++) {
		temp[i] = min + i;
	}
	srand((unsigned int)time(NULL));
	for (int i = total - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int t = temp[i];
		temp[i] = temp[j];
		temp[j] = t;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = temp[i];
	}
}



int main() {
	HashTable* ht = NULL;
	int arr[50];
	int searchCount;
	int delCount;

	int choice;
	do {
		printf("1、创建数据，2、建立哈希表，3、输出哈希表，4、在哈希表中查找关键字，5、在哈希表中删除关键字，0、关闭程序\n");
		printf("请选择哈希表操作：");
		scanf("%d", &choice);
		getchar();
		switch (choice) {
		case 1:
			UniqueArray(arr, 50, 10, 1000);
			printf("原始数据:\n");
			for (int i = 0; i < 30; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;

		case 2:
			ht = iniHashTable(61);
			for (int i = 0; i < 50; i++) {
				insert(ht, arr[i]);
			}
			printf("哈希表创建成功!\n");
			break;

		case 3:
			if (ht == NULL) {
				printf("请先执行2创建哈希表！\n");
				break;
			}
			printHashTable(ht);
			break;

		case 4:
			if (ht == NULL) {
				printf("请先执行2创建哈希表！\n");
				break;
			}
			searchCount = 0;
			int target;
			printf("请输入要查找的键值:");
			scanf("%d", &target);
			if (search(ht, target, &searchCount))
				printf("\n查找结果:键值%d存在于哈希表中\n操作次数：%d\n", target, searchCount);
			else
				printf("\n查找结果:键值%d不存在于哈希表中\n操作次数：%d\n", target, searchCount);
			break;

		case 5:
			if (ht == NULL) {
				printf("请先执行2创建哈希表！\n");
				break;
			}
			int delkey;
			delCount = 0;
			printf("请输入要删除的键值:");
			scanf("%d",&delkey);
			if (deleteNode(ht, delkey, &delCount)) {
				printf("\n删除结果：键值 %d 已成功删除\n操作次数：%d\n", delkey, delCount);
			}
			else {
				printf("\n删除结果：键值 %d 不存在，删除失败\n操作次数：%d\n", delkey, delCount);
			}
			break;
		case 0:
			printf("程序已关闭!\n");
			break;
		default:
			printf("无效选择，请重新输入!\n");
		}
	} while (choice != 0);
	
	return 0;
}
