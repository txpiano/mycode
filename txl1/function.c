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
			printf("���ݳɹ�\n");
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

		printf("����������\n");
		scanf("%s", t->p[t->size].name);
		printf("����������\n");
		scanf("%d", &(t->p[t->size].age));
		printf("�������Ա�\n");
		scanf("%s", t->p[t->size].sex);
		printf("������绰\n");
		scanf("%s", t->p[t->size].tel);
		printf("�������ַ\n");
		scanf("%s", t->p[t->size].addr);
		t->size++;
	}
	else
	{
		realloc(t->p, (t->capacity + 2) * sizeof(struct peo));
		t->capacity += 2;
		printf("���ݳɹ�\n");
		printf("����������\n");
		scanf("%s", t->p[t->size].name);
		printf("����������\n");
		scanf("%d", &(t->p[t->size].age));
		printf("�������Ա�\n");
		scanf("%s", t->p[t->size].sex);
		printf("������绰\n");
		scanf("%s", t->p[t->size].tel);
		printf("�������ַ\n");
		scanf("%s", t->p[t->size].addr);
		t->size++;
	}
}



void del(struct txl* t)
{
	int i = 0;
	char arr[20] = { 0 };
	printf("����������:");
	scanf("%s", arr);
	for (i = 0; i < t->size; i++)
	{
		int ret=strcmp(arr, t->p[i].name);
		if (ret == 0)
			break;
	}
	if (i == t->size)
	{
		printf("δ�ҵ���ϵ��\n");
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
	printf("����������:");
	scanf("%s", arr);
	for (i = 0; i < t.size; i++)
	{
		int ret = strcmp(arr, t.p[i].name);
		if (ret == 0)
		{
			printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-10s\t%-10d\t%-10s\t%-10s\t%-10s\n", t.p[i].name, t.p[i].age, t.p[i].sex, t.p[i].tel, t.p[i].addr);
			break;
		}
	}
	if (i == t.size)
	{
		printf("û�ҵ���ϵ��\n");
	}
}





void modify(struct txl* t)
{
	int i = 0;
	char arr[20] = { 0 };
	printf("����������:");
	scanf("%s", arr);
	for (i = 0; i < t->size; i++)
	{
		int ret = strcmp(arr, t->p[i].name);//��ʹ��memcmp��ҲҪ�޶��Աȵ��ֽڲ��ܳ������ֳ��ȣ�Ҫ��Ȼmemcmp���������Աȣ���arr������������ⶼ��0��p[i].name����������ȴ�����ֵ
		if (ret == 0)                         //��֮ǰ֮������memcmpҲ�����У�����Ϊp[i].name������ʼ��Ϊ0�����������鶼�ǳ������֣���������0,�ʲ��ᱨ��
		{
			printf("����������\n");
			scanf("%s", t->p[i].name);
			printf("����������\n");
			scanf("%d", &(t->p[i].age));
			printf("�������Ա�\n");
			scanf("%s", t->p[i].sex);
			printf("������绰\n");
			scanf("%s", t->p[i].tel);
			printf("�������ַ\n");
			scanf("%s", t->p[i].addr);
			printf("�޸ĳɹ�\n");
			break;
		}
	}
	if (i == t->size)
	{
		printf("û�ҵ���ϵ��\n");
	}

}




void show(struct txl t)
{
	printf("%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
			if (memcmp(t->p[i].name, t->p[i + 1].name,20) > 0)//�˴���memcmp����������Ϊ�����������򣬶�ÿ�������ֲ�һ������Ȼ��Ҫ�Ա�20���ֽڣ���һ������������ֲ�һ����ֱ�ӵó������
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