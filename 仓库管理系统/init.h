#pragma once
#include"struct.h"

Record record[1000];//储存记录数组
Goods goods[1000];//储存商品数组
int product_count = 0;//商品数量
int record_count = 0;//记录数量
#define FILE_PATH "Stock.txt"
#define RECORD_PATH "Record.txt"

//主界面
void show_welcome() {
	int choice;
	system("cls");
	printf("============================================================================\n");
	printf("                                  仓库管理系统                              \n");
	printf("----------------------------------------------------------------------------\n");
	printf("                                     主菜单                                 \n");
	printf("----------------------------------------------------------------------------\n");
	printf("    1、商品入库                 2、商品出库              3、显示所有商品    \n");
	printf("\n    4、显示已过期商品           5、按类别显示商品        6、查询商品信息   \n");
	printf("\n    7、查询出/入库记录          8、仓库盘点              9、保质期查询     \n");
	printf("\n    10、商品排序                0、保存并退出                          \n");
	printf("============================================================================\n");
}

void load_data() {//从文件载入商品数据，出入库记录
	FILE* fp;
	char line[256];

	fp = fopen(FILE_PATH, "r");
	if (fp == NULL) {
		printf("提示：数据文件不存在，程序退出时将自动创建\n");
		return;
	}
	if (fp) {
		//从第一行内容获取商品数量并赋值到product_count
		if (fgets(line, sizeof(line), fp)) {
			sscanf(line, "%d", &product_count);
		}
		//将每行数据提取并存入商品数组goods中
		for (int i = 0; i < product_count; i++) {
			if (fgets(line, sizeof(line), fp)) {
				sscanf(line, "%[^,],%[^,],%[^,],%f,%d,%d,%s",
					goods[i].code,
					goods[i].name,
					goods[i].category,
					&goods[i].price,
					&goods[i].totalstock,
					&goods[i].shelfLife,
					goods[i].inDate);
			}
		}
	}
	fclose(fp);

	fp = fopen(RECORD_PATH, "r");
	if (fp == NULL) {
		printf("提示：记录文件不存在，程序退出时将自动创建\n");
		return;
	}
	if (fp) {
		//从第一行内容获取出入库记录数量并赋值到record_count
		if (fgets(line, sizeof(line), fp)) {
			sscanf(line, "%d", &record_count);
		}
		//将每行数据提取并存入商品记录数组record中
		for (int i = 0; i < record_count; i++) {
			if (fgets(line, sizeof(line), fp)) {
				sscanf(line, "%[^,],%[^,],%d,%[^,],%s",
					record[i].code,
					record[i].date,
					&record[i].GoodsNum,
					record[i].operator_,
					record[i].type);
			}
		}
	}
	fclose(fp);
}

void save_data() {//保存商品数据，出入库记录到文件
	system("cls");
	FILE* fp;

	fp = fopen(FILE_PATH, "w");
	if (fp == NULL) {
		printf("提示：数据文件不存在，程序退出时将自动创建\n");
		return;
	}
	if (fp) {
		fprintf(fp, "%d\n", product_count);
		
		for (int i = 0; i < product_count; i++) {
			fprintf(fp, "%s,%s,%s,%.2f,%d,%d,%s\n",
				goods[i].code,
				goods[i].name,
				goods[i].category,
				goods[i].price,
				goods[i].totalstock,
				goods[i].shelfLife,
				goods[i].inDate);
		}
		fclose(fp);
		printf("============================================================================\n");
		printf("商品数据已保存到%s\n", FILE_PATH);
	}
	else {
		printf("============================================================================\n");
		printf("商品数据保存失败!\n");
	}

	fp = fopen(RECORD_PATH, "w");
	if (fp == NULL) {
		printf("提示：记录文件不存在，程序退出时将自动创建\n");
		return;
	}
	if (fp) {
		fprintf(fp, "%d\n", record_count);

		for (int i = 0; i < record_count; i++) {
			fprintf(fp, "%s,%s,%d,%s,%s\n",
				record[i].code,
				record[i].date,
				record[i].GoodsNum,
				record[i].operator_,
				record[i].type);
		}
		fclose(fp);
		printf("商品出入库数据已保存到%s\n", RECORD_PATH);
	}
	else {
		printf("商品出入库数据保存失败!\n");
	}
}

void init_system() {
	load_data();
	if (product_count == 0) {
		printf("系统初始化完成，无商品数据。\n");
	}
	else {
		printf("系统初始化完成，已加载%d个商品。\n", product_count);
	}
}