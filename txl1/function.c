#include "txl.h"




void inittxl(struct txl* t)
{
	t->size = 0;
	t->capacity = 3;
	t->p = (struct peo*)malloc(3 * sizeof(struct peo));

	FILE* pfread = fopen("txl.txt", "rb");
	if (pfread == NULL)
	{
		return;
	}
	struct peo ret = { 0 };
	while (fread(&ret, sizeof(struct peo), 1, pfread))
	{
		if (t->size == t->capacity)
		{
			realloc(t->p, (t->capacity + 2) * sizeof(struct peo));
			t->capacity += 2;
			printf("增容成功\n");
		}
		t->p[t->size] = ret;
		t->size++;
	}
	fclose(pfread);
	pfread = NULL;
	 

}

void add(struct txl* t)
{
	if (t->size < t->capacity)
	{
		FILE* pf = fopen("txl.txt","wb");

		printf("请输入姓名\n");
		scanf("%s", t->p[t->size].name);
		printf("请输入年龄\n");
		scanf("%d", &(t->p[t->size].age));
		printf("请输入性别\n");
		scanf("%s", t->p[t->size].sex);
		printf("请输入电话\n");
		scanf("%s", t->p[t->size].tel);
		printf("请输入地址\n");
		scanf("%s", t->p[t->size].addr);
		t->size++;
	}
	else
	{
		realloc(t->p, (t->capacity + 2) * sizeof(struct peo));
		t->capacity += 2;
		printf("增容成功\n");
		printf("请输入姓名\n");
		scanf("%s", t->p[t->size].name);
		printf("请输入年龄\n");
		scanf("%d", &(t->p[t->size].age));
		printf("请输入性别\n");
		scanf("%s", t->p[t->size].sex);
		printf("请输入电话\n");
		scanf("%s", t->p[t->size].tel);
		printf("请输入地址\n");
		scanf("%s", t->p[t->size].addr);
		t->size++;
	}
}



void del(struct txl* t)
{
	int i = 0;
	char arr[20] = { 0 };
	printf("请输入姓名:");
	scanf("%s", arr);
	for (i = 0; i < t->size; i++)
	{
		int ret=strcmp(arr, t->p[i].name);
		if (ret == 0)
			break;
	}
	if (i == t->size)
	{
		printf("未找到联系人\n");
	}
	else
	{
		for (int j = 0; j < t->size - 1 - i; j++)
		{
			t->p[i] = t->p[i + 1];
		}
		t->size--;
	}
}


void serch(struct txl t)
{

	int i = 0;
	char arr[20] = { 0 };
	printf("请输入姓名:");
	scanf("%s", arr);
	for (i = 0; i < t.size; i++)
	{
		int ret = strcmp(arr, t.p[i].name);
		if (ret == 0)
		{
			printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\n", t.p[i].name, t.p[i].age, t.p[i].sex, t.p[i].tel, t.p[i].addr);
			break;
		}
	}
	if (i == t.size)
	{
		printf("没找到联系人\n");
	}
}





void modify(struct txl* t)
{
	int i = 0;
	char arr[20] = { 0 };
	printf("请输入姓名:");
	scanf("%s", arr);
	for (i = 0; i < t->size; i++)
	{
		int ret = strcmp(arr, t->p[i].name);//即使用memcmp，也要限定对比的字节不能超过名字长度，要不然memcmp会继续往后对比，而arr数组除了名字外都是0，p[i].name除了名字外却是随机值
		if (ret == 0)                         //而之前之所以用memcmp也能运行，是因为p[i].name都被初始化为0，即两个数组都是除了名字，其他都是0,故不会报错
		{
			printf("请输入姓名\n");
			scanf("%s", t->p[i].name);
			printf("请输入年龄\n");
			scanf("%d", &(t->p[i].age));
			printf("请输入性别\n");
			scanf("%s", t->p[i].sex);
			printf("请输入电话\n");
			scanf("%s", t->p[i].tel);
			printf("请输入地址\n");
			scanf("%s", t->p[i].addr);
			printf("修改成功\n");
			break;
		}
	}
	if (i == t->size)
	{
		printf("没找到联系人\n");
	}

}




void show(struct txl t)
{
	printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "姓名", "年龄", "性别", "电话", "地址");
	for (int i = 0; i < t.size; i++)
	{
		printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\n", t.p[i].name, t.p[i].age, t.p[i].sex, t.p[i].tel, t.p[i].addr);
	}
}




void sort(struct txl* t)
{
	for (int j = 0; j < t->size - 1; j++)
	{
		for (int i = 0; i < t->size-j-1; i++)
		{
			if (memcmp(t->p[i].name, t->p[i + 1].name,20) > 0)//此处用memcmp不报错是因为用名字来排序，而每个人名字不一样，虽然是要对比20个字节，但一上来两组的名字不一样，直接得出结果了
			{
				struct peo ret = t->p[i];
				t->p[i] = t->p[i + 1];
				t->p[i + 1] = ret;

			}
		}
	}
}



void save(struct txl* t)
{
	FILE* pfwrite = fopen("txl.txt", "w");
	if (pfwrite == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}

	for (int i = 0; i < t->size; i++)
	{
		fwrite(&t->p[i], sizeof(struct peo), 1, pfwrite);
	}
	fclose(pfwrite);
	pfwrite = NULL;

}