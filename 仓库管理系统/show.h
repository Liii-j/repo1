#pragma once

//显示所有商品
void show_all_goods() {
	
	if (product_count == 0) {
		printf("暂无商品信息！\n");
	}
	else {
		printf("所有商品信息:\n");
		printf("%-11s %-11s %-12s %-11s %-11s %-15s %-11s\n",
			"代码", "名称", "类别", "价格", "数量", "保质期(天)", "入库日期");
		printf("---------------------------------------------------------------------------------------\n");
		for (int i = 0; i < product_count; i++) {
			printf("% -11s % -11s % -11s % -11.2f % -11d % -16d % -11s \n",
				goods[i].code, goods[i].name, goods[i].category, goods[i].price, goods[i].totalstock, goods[i].shelfLife, goods[i].inDate);
		}
	}
	printf("输入任意键返回主菜单...");
	getch();
 }

//显示已过期商品
void show_expired_goods() {
	system("cls");
	int count = 0;
	char current_date[20];
	get_currentdate(current_date);

	printf("过期商品列表:\n");
	printf("%-11s %-11s %-12s %-11s %-11s %-15s %-11s\n",
		"代码", "名称", "类别", "价格", "数量", "保质期(天)", "入库日期");
	printf("---------------------------------------------------------------------------------------\n");
	for (int i = 0; i < product_count; i++) {
		int days = days_between_dates(goods[i].inDate, current_date);
		if (days > goods[i].shelfLife) {
			printf("% -11s % -11s % -11s % -11.2f % -11d % -16d % -11s \n",
				goods[i].code, goods[i].name, goods[i].category, goods[i].price, goods[i].totalstock, goods[i].shelfLife, goods[i].inDate);
			count = 1;
		}
	}
	if (count == 0) {
		system("cls");
		printf("暂无已过期商品!\n");
	}
	printf("输入任意键返回主菜单...");
	getch();
}

//按类别显示商品
void show_goods_bycategory() {
	system("cls");
	char category[20];
	int found = 0;
	printf("请输入要查询的类别:");
	scanf("%s",category);

	printf("类别'%s'的商品列表:\n",category );
	printf("%-11s %-11s %-12s %-11s %-11s %-15s %-11s\n",
		"代码", "名称", "类别", "价格", "数量", "保质期(天)", "入库日期");
	printf("---------------------------------------------------------------------------------------\n");
	for (int i = 0; i < product_count; i++) {
		if (strcmp(goods[i].category, category) == 0) {
			printf("% -11s % -11s % -11s % -11.2f % -11d % -16d % -11s \n",
				goods[i].code, goods[i].name, goods[i].category, goods[i].price, goods[i].totalstock, goods[i].shelfLife, goods[i].inDate);
			found = 1;
		}
	}
	if (found == 0)
		printf("该类别暂无商品！\n");

	printf("输入任意键返回主菜单...");
	getch();
}

//查询商品
void search_goods() {
	system("cls");
	char keyword[30];
	int found = 0;
	printf("请输入要查询的商品代码或名称:");
	scanf("%s", keyword);

	printf("查询结果:\n");
	printf("%-11s %-11s %-12s %-11s %-11s %-15s %-11s\n",
		"代码", "名称", "类别", "价格", "数量", "保质期(天)", "入库日期");
	printf("---------------------------------------------------------------------------------------\n");
	for (int i = 0; i < product_count; i++) {
		if (strcmp(goods[i].code, keyword) == 0 || strcmp(goods[i].name, keyword) == 0) {
			printf("% -11s % -11s % -11s % -11.2f % -11d % -16d % -11s \n",
				goods[i].code, goods[i].name, goods[i].category, goods[i].price, goods[i].totalstock, goods[i].shelfLife, goods[i].inDate);
			found = 1;
		}
	}
	if (found == 0)
		printf("未找到相关商品!\n");

	printf("输入任意键返回主菜单...");
	getch();
}

//查询商品出入库记录
void search_records() {
	system("cls");

	char code[20];
	int found = 0;

	printf("请输入要查询出入库记录的商品代码:");
	scanf("%s", code);

	printf("商品%s的出入库记录:\n",code);
	printf("%-7s %-15s %-8s %-14s %-11s\n",
		"代码", "日期", "数量", "经办人", "出库/入库");
	printf("---------------------------------------------------------------------------------------\n");
	for (int i = 0; i < record_count; i++) {
		if (strcmp(record[i].code,code)==0) {
			printf("%-7s %-15s %-8d %-14s %-11s\n",
				record[i].code,record[i].date,record[i].GoodsNum,record[i].operator_,record[i].type);
			found = 1;
		}
	}
	if (found == 0)
		printf("该商品暂无出入库记录!\n");

	printf("输入任意键返回主菜单...");
	getch();
}

//按时间查询出入库记录
void inventory_check() {
	system("cls");

	int choice;
	printf("1、查询入库记录\n2、查询出库记录\n请选择:");
	scanf("%d", &choice);

	char start_date[20], end_date[20];
	printf("请输入开始日期(格式为YYYY-MM-DD):");
	scanf("%s", start_date);
	printf("请输入结束日期(若查询当天则输入相同日期):");
	scanf("%s", end_date);
	if (strcmp(start_date, end_date) == 0) {
		int found = 0;
		printf("查询结果:\n");
		printf("%-7s %-14s %-15s %-8s %-14s %-11s\n",
			"代码", "名称", "日期", "数量", "经办人", "出库/入库");
		printf("---------------------------------------------------------------------------------------\n");
		for (int i = 0; i < record_count; i++) {
			if (strcmp(record[i].date, start_date) == 0) {
				if ((choice == 1 && strcmp(record[i].type, "入库") == 0) || (choice == 2 && strcmp(record[i].type, "出库")==0)) {
					char goods_name[20] = "未知";
					for (int j = 0; j < product_count; j++) {
						if (strcmp(record[i].code,goods[j].code) == 0) {
							strcpy(goods_name, goods[j].name);
							break;
						}
					}
					printf("%-7s %-14s %-15s %-8d %-14s %-11s\n",
						record[i].code, goods_name, record[i].date, record[i].GoodsNum, record[i].operator_, record[i].type);
					found = 1;
				}
			}
		}
		if (found == 0)
			printf("当天无出入库记录。\n");
	}
	else {
		int found = 0;
		printf("查询结果:\n");
		printf("%-7s %-14s %-15s %-8s %-14s %-11s\n",
			"代码","名称", "日期", "数量", "经办人", "出库/入库");
		printf("---------------------------------------------------------------------------------------\n");
		for (int i = 0; i < record_count; i++) {
			if (strcmp(record[i].date, start_date) >= 0 && strcmp(record[i].date, end_date) <= 0) {
				if ((choice == 1 && strcmp(record[i].type, "入库") == 0) || (choice == 2 && strcmp(record[i].type, "出库"))==0) {
					char goods_name[20] = "未知";
					for (int j = 0; j < product_count; j++) {
						if (strcmp(goods[j].code, record[i].code)==0) {
							strcpy(goods_name, goods[j].name);
							break;
						}
					}
					printf("%-7s %-14s %-15s %-8d %-14s %-11s\n",
						record[i].code, goods_name, record[i].date, record[i].GoodsNum, record[i].operator_, record[i].type);
					found = 1;
				}
			}
		}
		if (found == 0)
			printf("该时间段无出入库记录。\n");
	}

	printf("输入任意键返回主菜单...");
	getch();
}

//指定天数内过期商品
void expiry_check() {
	system("cls");
	int days;
	printf("请输入天数：");
	scanf("%d", &days);

	printf("%d天内即将过期的商品:\n",days);
	printf("%-11s %-11s %-12s %-11s %-11s %-15s %-11s\n",
		"代码", "名称", "类别", "价格", "数量", "保质期(天)", "入库日期");
	printf("---------------------------------------------------------------------------------------\n");
	int found = 0;
	char today[20];
	get_currentdate(today);
	for (int i = 0; i < product_count; i++) {
		int days1=days_between_dates(goods[i].inDate, today);
		if ((goods[i].shelfLife - days1) < days&& goods[i].shelfLife - days1>0) {
			printf("% -11s % -11s % -11s % -11.2f % -11d % -16d % -11s \n",
				goods[i].code, goods[i].name, goods[i].category, goods[i].price, goods[i].totalstock, goods[i].shelfLife, goods[i].inDate);
			found = 1;
		}
	}
	if (!found) {
		printf("\n未找到在%d天内即将过期的商品。\n",days);
	}

	printf("输入任意键返回主菜单...");
	getch();
}

