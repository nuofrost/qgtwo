#ifndef STACK_H_INCLUDED
#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
//��ջ
//�ɾ�����Ľ���

//��ʼ��ջ
Status initLStack(LinkStack *s) {
	s->top = (StackNode *)malloc(sizeof(StackNode));
	if (!s->top)
		exit(ERROR);//��top�����������ʧ�ܲ����˳�����
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s) {
	if (s->count == 0) //count��Ϊ���ȣ��ж�count��С
		return SUCCESS;
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s) {
	if (isEmptyLStack(s))	//�����޷���ȡ
		return ERROR;

	return s->top->data;
}

//���ջ
Status clearLStack(LinkStack *s) {
	StackNode *p = s->top;//����һ��ָ��ջ����ָ��p
	while (p->next) { //��Ϊ��ֱ�ӽ���
		s->top = s->top->next;//�Ƚ�ջ��ָ�����Ƶ�ջ������һ���ڵ�
		free(p);//ջ���ڵ��ͷ�
		p = s->top;//��pָ����һ���
	}
	s->count = 0;//����������Ϊ0
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack *s) {
	StackNode *p = s->top;//����һ��ָ��ջ����ָ��p
	while (p) { //��Ϊ��ֱ�ӽ�����ȫ��ɾ��
		s->top = s->top->next;//�Ƚ�ջ��ָ�����Ƶ�ջ������һ���ڵ�
		free(p);//ջ���ڵ��ͷ�
		p = s->top;//��pָ����һ���
	}
	s->count = 0;//����������Ϊ0
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s) {
	return s->count;//ֱ�Ӹ�count
}

//��ջ
Status pushLStack(LinkStack *s, ElemType data) {
	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
	if (!s) {
		printf("ջ�����ڣ����ȳ�ʼ��ջ\n");
		exit(ERROR);//�����ھ�ֱ���˳�
	}
	p->data = data;//����ֵ
	p->next = s->top;
	s->top = p;//��ջ��ָ���½��
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack *s) {
	if (isEmptyLStack(s))
		return ERROR;//�����޷���ջ
	StackNode *p = s->top;//����һ��ָ��ջ������ָ��
	ElemType data = p->data;
	s->top = s->top->next;
	free(p);//ָ�붨���ַ֮������ͷŽ��
	p = NULL; //���pֵ
	s->count--;
	return SUCCESS;
}


#endif
