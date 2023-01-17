#include "Queen.h"


void TsetQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	int sz = QueueSize(&q);

	printf("长度是%d\n", sz);


	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);


	sz = QueueSize(&q);
	printf("长度是%d\n", sz);
	QueueDestroy(&q);
}

void TsetQueue2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");
}

int main()
{
	//TsetQueue1();
	TsetQueue2();

	return 0;
}