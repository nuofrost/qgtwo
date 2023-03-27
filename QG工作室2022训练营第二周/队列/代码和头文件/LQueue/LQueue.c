#ifndef LQUEUE_H_INCLUDED
#include "../head/LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q) {
	Q->front = (Node *)malloc(sizeof(Node) * 10);
	Q->front->next = NULL;
	Q->rear = Q->front;
	return TRUE;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q) {

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q) {
	if (Q->front == Q->rear) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e) {
	if(Q->front==Q->rear){
		printf("队列不存在\n");
		return FALSE;
	}
	e = Q->front->next->data;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q) {
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data) {
	Node *p;
	p = (Node *)malloc(sizeof(Node) * 10);
	p->data = data;
	p->next = NULL;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q) {
	Node *p;
	if (Q->front == Q->rear) {
		return ERROR;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) {
		Q->rear = Q->front;
	}
	free(p);
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q) {

}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q )
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q) {
	Node *p;
	if (Q->front == Q->rear) {
		printf("队列不存在\n");
	}
	p = Q->front->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void *q) {
	printf("%d\n",q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


