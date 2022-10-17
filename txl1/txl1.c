




#include "txl.h"

enum function

{
	Exit,
	Add,
	Del,
	Serch,
	Modify,
	Show,
	Sort,
	Save
};




int main()
{
	int input = 0;
	struct txl t;
	inittxl(&t);
	
	do
	{
		printf("*********************\n");
		printf("***1.add   2.del*****\n");
		printf("***3.serch 4.modify**\n");
		printf("***5.show  6.sort****\n");
		printf("***0.exit  7.save ***\n");
		printf("*********************\n");
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case Exit:
			printf("退出通讯录");
			return 0;
		case Add:
			add(&t);
			break;
		case Del:
			del(&t);
			break;
		case Serch:
			serch(t);
			break;
		case Modify:
			modify(&t);
			break;
		case Show:
			show(t);
			break;
		case Sort:
			sort(&t);
			break;
		case Save:
			save(&t);
				break;
		default:
			printf("输入错误");
		}
	} while (input);
	return 0;
}



