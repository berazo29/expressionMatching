#include "stack.h"

int main() {

    // Some examples
    printf("Expression: %s Valid: %d\n", "()", isExpressionValid("()") );
    printf("Expression: %s Valid: %d\n","(", isExpressionValid("(") );
    printf("Expression: %s Valid: %d\n", "(){}[]", isExpressionValid("(){}[]") );
    printf("Expression: %s Valid: %d\n", "())", isExpressionValid("())") );
    printf("Expression: %s Valid: %d\n", "[())", isExpressionValid("[())") );
    printf("Expression: %s Valid: %d\n", "{[()][()]}", isExpressionValid("{[()][()]}") );
    printf("Expression: %s Valid: %d\n", "((()(())))", isExpressionValid("((()(())))") );
    return 0;
}
