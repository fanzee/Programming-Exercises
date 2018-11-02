#include "linkstack.h"
char buffer[256] = { 0 };

LinkStack create()
{
	LinkStack stack = (LinkStack)malloc(sizeof(Stack));
	if (stack == NULL)
		return NULL;
	else
	{
		stack->top = NULL;
		stack->size = 0;
		return stack;
	}
}

int isEmpty(LinkStack stack)
{
	if (stack->top == NULL || stack->size == 0)
		return 1;
	else
		return 0;
}

int getSize(LinkStack stack)
{
	return stack->size;
}

pNode getTop(LinkStack stack)
{
	if (stack->size == 0)
		return NULL;
	else
		return stack->top;
}

int push(LinkStack stack, ElemType x)
{
	pNode node = (pNode)malloc(sizeof(Node));
	if (node == NULL)
		return 0;
	else
	{
		node->data = x; 
		node->next = getTop(stack);
		stack->top = node;
		stack->size++;
	}
	return 1;
}

pNode pop(LinkStack stack)
{
	if (isEmpty(stack) == 1)
		return NULL;
	else
	{
		pNode node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		return node;
	}
}

void destory(LinkStack stack)
{
	if (isEmpty(stack) == 1)
		free(stack);
	else
	{
		pNode node;
		while (stack->size)
		{
			node = pop(stack);
			free(node);
		}
	}
}

void Put(char ch)
{
	static int index = 0;
	buffer[index++] = ch;
}

int Priority(char ch)
{
	int ret=0;
	switch (ch)
	{
		case '+':
		case '-':
			ret = 1;
			break;
		case '*':
		case '/':
			ret = 2;
			break;
		default:
			break;
	}
	return ret;
}

int isNumber(char ch)
{
	return (ch >= '0'&& ch <= '9');
}

int isOperator(char ch)
{
	return(ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int isLeft(char ch)
{
	return (ch == '(');
}

int isRight(char ch)
{
	return (ch == ')');
}

int Transform(const char *str)
{
	LinkStack stack = create();

	int i = 0;
	while (str[i] != '\0')
	{
		if (isNumber(str[i]))
			Put(str[i]);

		else if (isOperator(str[i]))
		{
			if (!isEmpty(stack))
			{
				while (!isEmpty(stack) && Priority(getTop(stack)->data) >= Priority(str[i]))
				{
					Put(pop(stack)->data);
				}			
			}
			push(stack, str[i]);
		}
		else if(isLeft(str[i]))
		{
			push(stack, str[i]);
		}
		else if (isRight(str[i]))
		{
			while (!isLeft(getTop(stack)->data))
			{
				Put(pop(stack)->data);
				if (isEmpty(stack))
				{
					printf("没有匹配到左括号！\n");
					return -1;
				}
			}
			pop(stack);
		}
		else
		{
			printf("有不能识别的字符！\n");
			return -1;
		}
		i++;
	}
	if (str[i] == '\0')
	{
		while (!isEmpty(stack))
		{
			if (getTop(stack)->data == '(')
			{
				printf("有尚未匹配的左括号，缺少一个右括号\n");
				return -1;
			}
			else
			{
				Put(pop(stack)->data);
			}
		}
	}
	return 1;
}

int operation(int left, int right, char op)
{
	switch (op)
	{
	case '+':return left + right;
	case '-':return left - right;
	case '*':return left * right;
	case '/':return left / right;
	default:
		break;
	}
	return -1;
}

int calculate(const char *str)
{
	LinkStack stack = create();
	int left,right,ret,i = 0;
	while (str[i])
	{
		if (isNumber(str[i]))
			push(stack, str[i] - '0');
		else if (isOperator(str[i]))
		{
			right = pop(stack)->data;
			left = pop(stack)->data;
			ret = operation(left, right, str[i]);
			push(stack, ret);
		}
		else
		{
			printf("Error!\n");
			break;
		}
		i++;
	}

	if (str[i] == '\0'&&getSize(stack) == 1)
		return getTop(stack)->data;
	else
		return -1;
}