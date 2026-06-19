#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<conio.h>
#include "struct.h"
#include "init.h"
#include "tools.h"
#include "storage.h"
#include "show.h"

int main() {
	init_system();

	int choice;
	do {
		show_welcome();
		printf("请输入选择:");
		while (scanf("%d", &choice) != 1 || choice < 0 || choice>10) {//接收用户选择并判断有效性
			printf("输入无效！请重新输入:");
			while (getchar() != '\n');
		}

		switch (choice) {
		case 1:
			storage_in();//商品入库
			break;
		case 2:
			storage_out();//商品出库
			break;
		case 3:
			system("cls");
			show_all_goods();//显示所有商品
			break;
		case 4:
			show_expired_goods();//显示已过期商品
			break;
		case 5:
			show_goods_bycategory();//显示某一类别商品
			break;
		case 6:
			search_goods();//按商品代码或名称查询商品信息
			break;
		case 7:
			search_records();//查询出入库记录
			break;
		case 8:
			inventory_check();//仓库盘点
			break;
		case 9:
			expiry_check();//保质期查询
			break;
		case 10:
			sort_products();//商品排序
			break;
		case 0:
			save_data();
			printf("----------------------------------------------------------------------------\n");
			printf("                               程序关闭，再见                               \n");
			printf("============================================================================\n");
			break;
		}
	} while (choice != 0);
		return 0;
	
}