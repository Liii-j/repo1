#pragma once

//商品入库
void storage_in() {
	system("cls");

	Goods p;
	Record r;
	int count;
	char people[30];

	printf("请输入要入库商品的代码:");
	scanf("%s", p.code);
	//分 已存在/不存在 该商品进行入库操作
	int index = find_goods_bycode(p.code);

	if (index != -1) { //商品已存在情况
		printf("商品:%s\n", goods[index].name);
		printf("商品库存:%d\n", goods[index].totalstock);

		//入库信息
		printf("请输入入库数量:");
		scanf("%d", &count);
		printf("请输入经办人:");
		scanf("%s", people);

		//更新商品信息
		goods[index].totalstock += count;

		//创建入库记录
		strcpy(r.code, p.code);
		get_currentdate(r.date);
		r.GoodsNum = count;
		strcpy(r.operator_, people);
		strcpy(r.type, "入库");
		record[record_count++] = r;

		printf("商品入库成功!\n");
	}
	else { //商品不存在情况
		printf("该商品不存在,请添加商品:");
		printf("请输入商品名称:");
		scanf("%s", p.name);
		printf("请输入商品类别:");
		scanf("%s", p.category);
		printf("请输入商品价格:");
		scanf("%f", &p.price);
		printf("请输入商品入库数量:");
		scanf("%d", &p.totalstock);
		printf("请输入商品保质期:");
		scanf("%d", &p.shelfLife);
		get_currentdate(p.inDate);

		//添加新商品到数组
		goods[product_count++] = p;

		//创建入库记录
		strcpy(r.code, p.code);
		get_currentdate(r.date);
		r.GoodsNum = p.totalstock;
		printf("请输入经办人:");
		scanf("%s", r.operator_);
		strcpy(r.type, "入库");
		record[record_count++] = r;

		printf("商品添加成功!\n");
	}

	printf("输入任意键返回主菜单...");
	getch();
}

//商品出库
void storage_out() {
	system("cls");

	Record r;
	Goods p;
	int count;
	char people[30];

	printf("请输入要出库商品的代码:");
	scanf("%s", p.code);

	int index =find_goods_bycode(p.code);
	if (index != -1) {
		printf("商品:%s\n", goods[index].name);
		printf("商品库存:%d\n", goods[index].totalstock);

		//出库信息
		printf("请输入出库数量:");
		scanf("%d", &count);
		if (goods[index].totalstock < count) {
			printf("商品库存不足!\n");
			return;
		}
		printf("请输入经办人:");
		scanf("%s", people);

		//更新商品信息
		goods[index].totalstock -= count;

		//创建出库记录
		strcpy(r.code, p.code);
		get_currentdate(r.date);
		r.GoodsNum = count;
		strcpy(r.operator_, people);
		strcpy(r.type, "出库");
		record[record_count++] = r;

		printf("出库成功!当前库存:%d\n", goods[index].totalstock);
	}
	else {
		printf("商品不存在!\n");
		return;
	}

	printf("输入任意键返回主菜单...");
	getch();
}
