// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     printf("test\n");

//     int a = 12;
//     int *p_a = &a;
    
//     printf("a: %d\n", a);
//     printf("a: %p\n\n", p_a);

//     printf("a: %d\n", *p_a);
//     printf("a: %p", &a);
// }


#include <stdio.h> 
#include <stdlib.h> 

typedef int StackElemType;

typedef struct stacknode StackNode;
struct stacknode
{ 
	StackElemType INFO;
 	StackNode *LINK;
};

struct stack
{ 
	StackNode *top;
};
typedef struct stack Stack;

void InitStack(Stack *S) 
{ 
	S->top=NULL;
}

int IsEmptyStack(Stack *S)
{ 
	return(S->top==NULL);
}

void StackOverflow(void)
{ 
	printf("Stack overflow detected.\n"); 
	exit(1);
}

void StackUnderflow(void)
{ 
	printf("Stack underflow detected.\n"); 
	exit(1);
}

void PUSH(Stack *S, StackElemType x)
{ 
	StackNode *alpha;
	alpha = (StackNode *) malloc(sizeof(StackNode));
 	if(alpha == NULL)
		StackOverflow();
	else {
		alpha ->INFO = x;
		alpha ->LINK = S ->top;
 		S ->top = alpha;
 	}
}

void POP(Stack *S, StackElemType *x)
{ 
	StackNode *alpha;
 	if(S->top == NULL)
		StackUnderflow();
	else {
		alpha = S ->top;
		*x = S ->top ->INFO;
		S ->top = S ->top ->LINK;
 		free(alpha);
 	}
}

int main()
{ 
	// example procedure that uses a stack
	Stack S; StackElemType x; int i; 
	InitStack(&S);
	for(i=1; i<=5; i++) PUSH(&S,100*i); 
	while(!IsEmptyStack(&S)) {
		POP(&S,&x);
		printf("%d\n",x); 
	} 
	return 0;
}
