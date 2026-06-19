//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//int moveCount = 0;
//int compareCount = 0;
//int quickSortMoveCount = 0;
//int quickSortCompareCount = 0;
//int mergeSortMoveCount = 0;
//int mergeSortCompareCount = 0;
//void heapify(int arr[], int n, int i) {
//	int smallest = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//	if (left < n && arr[left] < arr[smallest]) {
//		smallest = left;
//		compareCount++;
//	}
//	if (right < n && arr[right] < arr[smallest]) {
//		smallest = right;
//		compareCount++;
//	}
//	if (smallest != i) {
//		int temp = arr[i];
//		arr[i] = arr[smallest];
//		arr[smallest] = temp;
//		moveCount++;
//		compareCount++;
//		heapify(arr, n, smallest);
//	}
//}
//
//void heapSort(int arr[], int n) {
//	moveCount = 0;
//	compareCount = 0;
//	for (int i = n / 2 - 1; i >= 0; i--) {
//		heapify(arr, n, i);
//	}
//	for (int i = n - 1; i > 0; i--) {
//		int temp = arr[0];
//		arr[0] = arr[i];
//		arr[i] = temp;
//		moveCount++;
//
//		heapify(arr, i, 0);
//	}
//}
//
//void swap(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//	quickSortMoveCount++;
//}
//
//int partition(int arr[], int low, int high) {
//	int pivot = arr[low];
//	int left = low;
//	int right = high;
//
//	while (left < right) {
//		while (left < right && arr[right] <= pivot) {
//			right--;
//			quickSortCompareCount++;
//		}
//		while (left < right && arr[left] >= pivot) {
//			left++;
//			quickSortCompareCount++;
//		}
//
//		if (left < right) {
//			swap(&arr[left], &arr[right]);
//		}
//	}
//	swap(&arr[left], &arr[low]);
//	
//	return left;
//}
//
//void quickSort(int arr[], int low, int high) {
//	
//	if (low < high) {
//		int pivotPos = partition(arr, low, high);
//		quickSort(arr, low, pivotPos - 1);
//		quickSort(arr, pivotPos + 1, high);
//	}
//}
//
//void Merge(int arr[], int n, int swap[], int k) {
//	int m = 0, l2, u1, u2, i, j;
//	int l1 = 0;
//	while (l1 + k <= n - 1) {
//		l2 = l1 + k;
//		u1 = l2 - 1;
//		u2 = (l2 + k <= n - 1) ? l2 + k - 1 : n - 1;
//
//		for (i = l1, j = l2; i <= u1 && j <= u2; ) {
//			if (arr[i] > arr[j]) {
//				swap[m++] = arr[i++];
//				mergeSortMoveCount++;
//				mergeSortCompareCount++;
//			}
//			else {
//				swap[m++] = arr[j++];
//				mergeSortMoveCount++;
//				mergeSortCompareCount++;
//			}
//			while (i <= u1) {
//				swap[m++] = arr[i++];
//				mergeSortMoveCount++;
//			}
//			while (j <= u2) {
//				swap[m++] = arr[j++];
//				mergeSortMoveCount++;
//				mergeSortCompareCount++;
//			}
//			l1 = u2 + 1;
//		}
//		while (l1 < n) {
//			swap[m++] = arr[l1++];
//			mergeSortMoveCount++;
//			mergeSortCompareCount++;
//		}
//		for (i = 0; i < n; i++) {
//			arr[i] = swap[i];
//			mergeSortMoveCount++;
//		}
//	}
//}
//
//void mergeSort(int arr[], int n) {
//	int* swap = new int[n];
//	for (int k = 1; k < n; k *= 2) {
//		Merge(arr, n, swap, k);
//	}
//}
//
//int main() {
//    int choice;
//    int arr[1000];  // 最大支持1000个元素
//    int tempArr[1000];  // 临时数组存储原始数据
//    int length = 40;    // 默认数组长度
//
//    do {
//        printf("\n==================== 排序算法演示系统 ====================\n");
//        printf("1. 生成随机数组\n");
//        printf("2. 执行堆排序\n");
//        printf("3. 执行快速排序\n");
//        printf("4. 执行归并排序\n");
//        printf("5. 查看当前数组\n");
//        printf("0. 退出程序\n");
//        printf("==========================================================\n");
//        printf("请输入您的选择（0-5）：");
//        scanf("%d", &choice);
//        getchar(); 
//
//        switch (choice) {
//        case 1:
//			srand((unsigned int)time(NULL));
//			for (int i = 0; i < length; i++) {
//				arr[i] = rand() % 2001 - 1000;
//			}
//			printf("排序前数组 ：");
//			for (int j = 0; j < length; j++) {
//				printf("%d ", arr[j]);
//			}
//            printf("\n 随机数组生成成功！\n");
//            break;
//
//        case 2:
//            heapSort(arr, length);
//            printf("\n 堆排序结果：\n");
//            for (int j = 0; j < length; j++) {
//                printf("%d ", arr[j]);
//            }
//            printf("\n 比较次数=%d，移动次数=%d\n", compareCount, moveCount);
//            break;
//
//        case 3:
//			quickSortCompareCount = 0;
//			quickSortMoveCount = 0;
//			quickSort(arr, 0, length - 1);
//			printf("\n快速排序后数组 ：");
//			for (int j = 0; j < length; j++) {
//				printf("%d ", arr[j]);
//			}
//			printf("\n比较次数:%d 移动次数:%d", quickSortCompareCount, quickSortMoveCount);          
//            break;
//
//        case 4:
//			mergeSortCompareCount = 0;
//			mergeSortMoveCount = 0;
//			mergeSort(arr, length);
//			printf("\n归并排序后数组 ：");
//			for (int j = 0; j < length; j++) {
//				printf("%d ", arr[j]);
//			}
//			printf("\n比较次数:%d 移动次数:%d", mergeSortCompareCount,mergeSortMoveCount);
//            break;
//
//        case 5:
//			printf("当前数组:\n");
//			for (int j = 0; j < length; j++) {
//				printf("%d ", arr[j]);
//			}
//            printf("\n");
//            break;
//
//        case 0:
//            printf("\n 程序已退出！\n");
//            break;
//
//        default:
//            printf("\n 无效选择，请输入0-5之间的数字！\n");
//        }
//    } while (choice != 0);
//
//    return 0;
//}
