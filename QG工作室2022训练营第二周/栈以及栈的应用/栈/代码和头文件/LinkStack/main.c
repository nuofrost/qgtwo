#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <malloc.h>

int judge_int(void) { //��ֹ�û��������������ַ�
	int len, num = 0, arg = 1;
	char word[10];
	int m, j = 1, k;
	while (j) {
		scanf("%s", word);
		len = strlen(word);
		for (m = 0; m < len; m++) {
			if (word[m] < '0' || word[m] > '9') { //�����Ƿ��������������ַ�
				printf("������������");
				break;
			} else {
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	for (m = 0; m < len; m++) { // ���ַ�����ת��Ϊ����
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (word[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}

void traversestack(LinkStack *s) {
	StackNode *p = s->top; // ����һ��ָ��ջ������ָ��p

	while (p !=
	        NULL) { // // ֻҪpָ��Ľ��ĵ�ָ����Ϊ�գ���֤��p�Ѿ�ָ�����һ����������ݵĽڵ㣬��p->next���ڼ�Ϊִ�и�ѭ��������
		printf("%d\t", p->data); // ÿ��ѭ�������ô��ݸ�ָ�����visit�ĺ���
		p = p->next; // pָ����һ���
	}

	printf("\n");
}


int main() {
	LinkStack *s;
	int flag = 0;
	ElemType e;
	while (SUCCESS) { //ͷ�ļ��е�����
		system("cls");//����
		printf("\n\n------------------------------\n");
		printf(">>> 1.initLStack              \n");//��ʼ��ջ
		printf(">>> 2.isEmptyLStack           \n");//�ж�ջ�Ƿ�Ϊ��
		printf(">>> 3.getTopLStack            \n");//�õ�ջ��Ԫ��
		printf(">>> 4.clearLStack             \n");//���ջ
		printf(">>> 5.destroyLStack           \n");//���ջ
		printf(">>> 6.LStackLength            \n");//���ջ����
		printf(">>> 7.pushLStack              \n");//��ջ
		printf(">>> 8.popLStack               \n");//��ջ
		printf(">>> 9.Exit                    \n");//�˳�
		printf("------------------------------\n");
		if (flag) {
			traversestack(s); //�����������Ļ����������
		} else {
			printf("ջδ��ʼ��\n");//�������û��
		}
		printf("------------------------------\n");
		printf("----->>> ���������ѡ��");
		switch (judge_int()) {
			case 1:
				if (initLStack(s)) {
					printf("ջ��ʼ���ɹ���\n");
					flag = 1;
				} else {
					printf("ջ��ʼ��ʧ�ܡ�\n");
				}
				break;
			case 2:
				if (isEmptyLStack(s))
					printf("ջ�Ѵ���");
				else
					printf("ջδ��");
				traversestack(s);
				break;
			case 3:
				if (flag) {
					if (getTopLStack(s))
						printf("ջ��Ԫ��Ϊ%d\n", e);
					else
						printf("ջ��������\n");
					break;
				} else {
					printf("ջ������\n");
				}
				break;
			case 4:
				if (flag) {
					clearLStack(s);
					printf("�����ջ\n");
				} else {
					printf("ջ������\n");
				}
				break;
			case 5:
				if (flag) {
					destroyLStack(s);
					printf("������ջ\n");
					break;
				} else {
					printf("ջ�����ڡ�\n");
				}
				break;
			case 6: {
				printf("��ǰջ�ĳ���Ϊ%d\n", LStackLength(s));
				break;
			}
			case 7: {
				if (flag) {
					printf("��������ջ����:\n");
					scanf("%d", &e);
					pushLStack(s, e);
					printf("��ջ�ɹ�\n");
				} else
					printf("ջ������\n");
				break;
			}
			case 8: {
				if (flag) {

					if (popLStack(s))
						printf("����Ԫ�س�ջ�ɹ�����ջԪ��Ϊ%d\n", e);
					else
						printf("��ջʧ��\n");
				} else {
					printf("ջ������\n");
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


