//#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<malloc.h>

#define DataType char
#define size_t int 

#define INC_SIZE 4
#define DEFAULT_SIZE 8

void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif /*_COMMON_H_*/