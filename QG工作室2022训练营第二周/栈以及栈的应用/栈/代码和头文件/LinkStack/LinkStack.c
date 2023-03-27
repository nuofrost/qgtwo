#ifndef STACK_H_INCLUDED
#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
//链栈
//干净整洁的界面

//初始化栈
Status initLStack(LinkStack *s) {
	s->top = (StackNode *)malloc(sizeof(StackNode));
	if (!s->top)
		exit(ERROR);//若top不存在则分配失败并且退出程序
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s) {
	if (s->count == 0) //count即为长度，判断count大小
		return SUCCESS;
	else
		return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s) {
	if (isEmptyLStack(s))	//空则无法获取
		return ERROR;

	return s->top->data;
}

//清空栈
Status clearLStack(LinkStack *s) {
	StackNode *p = s->top;//定义一个指向栈顶的指针p
	while (p->next) { //若为空直接结束
		s->top = s->top->next;//先将栈顶指针下移到栈顶的下一个节点
		free(p);//栈顶节点释放
		p = s->top;//将p指向下一结点
	}
	s->count = 0;//将长度设置为0
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack *s) {
	StackNode *p = s->top;//定义一个指向栈顶的指针p
	while (p) { //若为空直接结束，全部删光
		s->top = s->top->next;//先将栈顶指针下移到栈顶的下一个节点
		free(p);//栈顶节点释放
		p = s->top;//将p指向下一结点
	}
	s->count = 0;//将长度设置为0
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s) {
	return s->count;//直接给count
}

//入栈
Status pushLStack(LinkStack *s, ElemType data) {
	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
	if (!s) {
		printf("栈不存在！请先初始化栈\n");
		exit(ERROR);//不存在就直接退出
	}
	p->data = data;//赋新值
	p->next = s->top;
	s->top = p;//让栈顶指向新结点
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s) {
	if (isEmptyLStack(s))
		return ERROR;//空则无法出栈
	StackNode *p = s->top;//定义一个指向栈顶结点的指针
	ElemType data = p->data;
	s->top = s->top->next;
	free(p);//指针定向地址之后可以释放结点
	p = NULL; //清空p值
	s->count--;
	return SUCCESS;
}


#endif
