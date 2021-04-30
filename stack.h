//
// Created by Bryan Erazo on 4/30/21.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

/* Expresion for check the correctness of the expresion
   Note: This function does not check for expression precedence.
   Therefore the expresion ([]) and [()] are both valid
 */
bool isExpressionValid(char str[]);


// Data Structure
struct Stack {
    unsigned int capacity;
    char *arr;
    unsigned int max;
};

// Stack Data structure functions
struct Stack* createStack();
void push(struct Stack **stack, char data);
char pop(struct Stack *stack);
int top(struct Stack *stack);
bool isFull();
bool isEmpty();

// Unit test stack
bool unitTest();
bool test1();
bool test2();


struct Stack* createStack(unsigned int cap){
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->capacity = cap;
    stack->max = cap;
    stack->arr = malloc(cap*sizeof(char));

    return stack;
}

bool isExpressionValid(char str[]){

    int unsigned size = strlen(str);

    struct Stack *stack = createStack(size);
    for (int i = 0; i < size; ++i) {
        if (str[i] == '}'){
            if (top(stack)+2 == '}' && !isEmpty(stack)){
                pop(stack);
            } else{
                push(&stack, str[i]);
            }

        } else if (str[i] == ']'){
            if (top(stack)+2 == ']' && !isEmpty(stack)){

                pop(stack);
            } else{
                push(&stack, str[i]);
            }

        } else if (str[i] == ')'){
            if (top(stack)+1 == ')' && !isEmpty(stack)){

                pop(stack);
            } else{
                push(&stack, str[i]);
            }
        }
        else{
            push(&stack, str[i]);
        }
    }
    return (isEmpty(stack));
}

void push(struct Stack **stack, char data){
    struct Stack *stk = *stack;
    assert(data > 0);
    if (!isFull(stk)){
        stk->capacity--;
        stk->arr[stk->capacity] = data;
    } else{
        printf("Stack is full data:%d not inserted\n", data);
    }
}

char pop(struct Stack *stack){

    if(stack->capacity == stack->max){
        //printf("Stack is empty\n");
        return 0;
    }
    char val = stack->arr[stack->capacity];
    stack->capacity++;
    return val;
}

bool isFull(struct Stack *stack){

    assert(stack != NULL);

    if (stack->capacity == 0 ){
        return true;
    }
    return false;
}
bool isEmpty(struct Stack *stack){
    if (stack->capacity == stack->max){
        return true;
    } else{
        return false;
    }
}

int top(struct Stack *stack){
    if (stack->capacity == stack->max){
        return 0;
    }
    return stack->arr[stack->capacity];
}

bool test1(){
    struct Stack *stack = createStack(1);
    char a = 'a';
    push(&stack, a);
    if (pop(stack) == a){
        return true;
    }
    return false;
}

bool test2(){
    struct Stack *stack = createStack(2);

    char arr[2];
    char correct[2] = "ba";
    push(&stack, 'a');
    push(&stack, 'b');
    arr[0] = pop(stack);
    arr[1] = pop(stack);

    for (int i = 0; i < 2; ++i) {
        if (arr[i] != correct[i]){
            return false;
        }
    }
    return true;

}

bool unitTest(){
    // Unit test for the stack data structure
    if (test1()){
        printf("Passed test 1 [a]\n");
    }
    if (test2()){
        printf("Passed test 2 [a, b]\n");
    }
    return true;
}


#endif //STACK_STACK_H
