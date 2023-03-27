#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

int judge_int(void) { //防止用户乱输入其他的字符
	int len, num = 0, arg = 1;
	char word[10];
	int m, j = 1, k;
	while (j) {
		scanf("%s", word);
		len = strlen(word);
		for (m = 0; m < len; m++) {
			if (word[m] < '0' || word[m] > '9') { //检验是否有乱输入其他字符
				printf("请输入整数：");
				break;
			} else {
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	for (m = 0; m < len; m++) { // 将字符重新转换为数字
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}

void traversestack(LinkStack *s) {
	StackNode *p = s->top; // 定义一个指向栈顶结点的指针p

	while (p !=
	        NULL) { // // 只要p指向的结点的的指针域为空，则证明p已经指向最后一个不存放数据的节点，则p->next存在即为执行该循环的条件
		printf("%d\t", p->data); // 每次循环都调用传递给指针变量visit的函数
		p = p->next; // p指向下一结点
	}

	printf("\n");
}


int main() {
	LinkStack *s;
	int flag = 0;
	ElemType e;
	while (SUCCESS) { //头文件中的名字
		system("cls");//清屏
		printf("\n\n------------------------------\n");
		printf(">>> 1.initLStack              \n");//初始化栈
		printf(">>> 2.isEmptyLStack           \n");//判断栈是否为空
		printf(">>> 3.getTopLStack            \n");//得到栈顶元素
		printf(">>> 4.clearLStack             \n");//清空栈
		printf(">>> 5.destroyLStack           \n");//清空栈
		printf(">>> 6.LStackLength            \n");//检测栈长度
		printf(">>> 7.pushLStack              \n");//入栈
		printf(">>> 8.popLStack               \n");//出栈
		printf(">>> 9.Exit                    \n");//退出
		printf("------------------------------\n");
		if (flag) {
			traversestack(s); //如果存在链表的话就输出链表
		} else {
			printf("栈未初始化\n");//否则输出没有
		}
		printf("------------------------------\n");
		printf("----->>> 请输入你的选择：");
		switch (judge_int()) {
			case 1:
				if (initLStack(s)) {
					printf("栈初始化成功。\n");
					flag = 1;
				} else {
					printf("栈初始化失败。\n");
				}
				break;
			case 2:
				if (isEmptyLStack(s))
					printf("栈已存在");
				else
					printf("栈未空");
				traversestack(s);
				break;
			case 3:
				if (flag) {
					if (getTopLStack(s))
						printf("栈顶元素为%d\n", e);
					else
						printf("栈顶不存在\n");
					break;
				} else {
					printf("栈不存在\n");
				}
				break;
			case 4:
				if (flag) {
					clearLStack(s);
					printf("已清空栈\n");
				} else {
					printf("栈不存在\n");
				}
				break;
			case 5:
				if (flag) {
					destroyLStack(s);
					printf("已销毁栈\n");
					break;
				} else {
					printf("栈不存在。\n");
				}
				break;
			case 6: {
				printf("当前栈的长度为%d\n", LStackLength(s));
				break;
			}
			case 7: {
				if (flag) {
					printf("请输入入栈数据:\n");
					scanf("%d", &e);
					pushLStack(s, e);
					printf("入栈成功\n");
				} else
					printf("栈不存在\n");
				break;
			}
			case 8: {
				if (flag) {

					if (popLStack(s))
						printf("塔顶元素出栈成功，出栈元素为%d\n", e);
					else
						printf("出栈失败\n");
				} else {
					printf("栈不存在\n");
				}
				break;
			}
			case 9:
				exit(0);
			default:
				break;
		}
		system("pause");
	}
	return 0;
}


