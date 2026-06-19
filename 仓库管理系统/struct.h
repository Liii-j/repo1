#pragma once

typedef struct {
	char code[20];//商品代码
	char name[20];//商品名称
	char category[20];//商品类别
	float price;//商品价格(元)
	int totalstock;//商品总量
	int shelfLife;//保质期(天)
	char inDate[20];//入库时间
}Goods;

typedef struct {
	char code[20];//商品代码
	char date[20];//出/入库时间,日期格式XXXX-YY-ZZ
	int GoodsNum;//出/入库数量
	char operator_[20];//经办人
	char type[10];//入库/出库 
}Record;