#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct peo
{
	char name[20];
	int age;
	char sex[10];
	char tel[16];
	char addr[15];
};
struct txl
{
	struct peo* p;
	int size;
	int capacity;
};






void inittxl(struct txl* t);
void add(struct txl* t);
void del(struct txl* t);
void serch(struct txl t);
void modify(struct txl* t);
void serch(struct txl t);
void show(struct txl t);
void sort(struct txl* t);
void save(struct txl* t);