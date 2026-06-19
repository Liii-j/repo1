#pragma once

void show_all_goods();

//通过商品代码查找商品
int find_goods_bycode(char* code) {
	for (int i=0;i< product_count; i++) {
		if (strcmp(goods[i].code, code) == 0) {
			return i;
		}
	}
	return -1;
}

//获取当前日期
void get_currentdate(char* date_str) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(date_str, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

//计算两个日期的天数差
int days_between_dates(char* date1, char* date2) {
	struct tm tm1 = { 0 }, tm2 = { 0 };
	sscanf(date1, "%4d-%2d-%2d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday);
	sscanf(date2, "%4d-%2d-%2d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday);
	tm1.tm_year -= 1900;
	tm1.tm_mon -= 1;
	tm2.tm_year -= 1900;
	tm2.tm_mon -= 1;

	time_t t1 = mktime(&tm1), t2 = mktime(&tm2);

	return abs((int)(difftime(t2, t1) / (24 * 60 * 60)));//秒数转为天数后返回
}

//商品排序
int partbyCategory(int low, int high) {
	char* index = goods[high].category;

	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (strcmp(goods[j].category,index)<0) {
			i++;
			Goods temp = goods[j];
			goods[j] = goods[i];
			goods[i] = temp;
		}
	}
	 Goods temp = goods[high];
	 goods[high] = goods[i + 1];
	 goods[i + 1] = temp;
	return i + 1;
}

int partbyPrice(int low, int high) {
	int index = goods[high].price;

	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (goods[j] .price<= index) {
			i++;
			Goods temp = goods[j];
			goods[j] = goods[i];
			goods[i] = temp;
		}
	}
	Goods temp = goods[high];
	goods[high] = goods[i + 1];
	goods[i + 1] = temp;
	return i + 1;
}

int partbyShelfLife(int low, int high) {
	int index = goods[high].shelfLife;

	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (goods[j].shelfLife <= index) {
			i++;
			Goods temp = goods[j];
			goods[j] = goods[i];
			goods[i] = temp;
		}
	}
	Goods temp = goods[high];
	goods[high] = goods[i + 1];
	goods[i + 1] = temp;
	return i + 1;
}

int partbyCode(int low, int high) {
	char* index = goods[high].code;

	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (strcmp(goods[j].code, index) < 0) {
			i++;
			Goods temp = goods[j];
			goods[j] = goods[i];
			goods[i] = temp;
		}
	}
	Goods temp = goods[high];
	goods[high] = goods[i + 1];
	goods[i + 1] = temp;
	return i + 1;
}

void quick_sortbyCategory(int low,int high) {
	if (low < high) {
		int mid = partbyCategory(low, high);

		quick_sortbyCategory(low, mid - 1);
		quick_sortbyCategory(mid + 1, high);
	}
}

void quick_sortbyPrice(int low, int high) {
	if (low < high) {
		int mid = partbyPrice(low, high);

		quick_sortbyPrice(low, mid - 1);
		quick_sortbyPrice(mid + 1, high);
	}
}

void quick_sortbyShelfLife(int low, int high) {
	if (low < high) {
		int mid = partbyShelfLife(low, high);

		quick_sortbyShelfLife(low, mid - 1);
		quick_sortbyShelfLife(mid + 1, high);
	}
}

void quick_sortbyCode(int low, int high) {
	if (low < high) {
		int mid = partbyCode(low, high);

		quick_sortbyCode(low, mid - 1);
		quick_sortbyCode(mid + 1,high);
	}
}

void sort_products() {
	system("cls");

	printf("1、按类别排序\n");
	printf("2、按价格排序\n");
	printf("3、按保质期排序\n");
	printf("4、按商品代码排序\n");
	printf("请输入选择：");
	int choice2;
	scanf("%d", &choice2);
	switch (choice2) {
	case 1:
		quick_sortbyCategory(0, product_count - 1);
		break;
	case 2:
		quick_sortbyPrice(0, product_count - 1);
		break;
	case 3:
		quick_sortbyShelfLife(0, product_count - 1);
		break;
	case 4:
		quick_sortbyCode(0, product_count - 1);
		break;
	}
	printf("排序完成\n");
	show_all_goods();
}