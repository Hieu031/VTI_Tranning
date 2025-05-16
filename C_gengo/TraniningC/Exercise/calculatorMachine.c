/*
 * poly_calc.c - Trình mô phỏng máy tính cầm tay đơn giản cho biểu thức số
 * Hỗ trợ: nhập biểu thức số với +, -, *, /, ^, ()
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
 
 #define MAX_EXPR_LEN 256
 #define MAX_STACK 256
 
 // Xác định độ ưu tiên toán tử
 int precedence(char op) {
     switch (op) {
         case '+': case '-': return 1;
         case '*': case '/': return 2;
         case '^': return 3;
     }
     return 0;
 }
 
 // Xác định tính chất trái-phải kết hợp
 int isLeftAssociative(char op) {
     return (op != '^');
 }
 
 // Áp dụng toán tử lên hai giá trị trên ngăn xếp
 void applyOp(double values[], int *v_top, char op) {
     double right = values[(*v_top)--];
     double left = values[*v_top];
     double res = 0;
     switch (op) {
         case '+': res = left + right; break;
         case '-': res = left - right; break;
         case '*': res = left * right; break;
         case '/': res = left / right; break;
         case '^': res = pow(left, right); break;
     }
     values[*v_top] = res;
 }
 
 // Hàm đánh giá biểu thức số với +, -, *, /, ^ và ()
 double eval_numeric(const char *expr) {
     double values[MAX_STACK];
     char ops[MAX_STACK];
     int v_top = -1, op_top = -1;
     int i = 0, len = strlen(expr);
 
     while (i < len) {
         if (isspace(expr[i])) { i++; continue; }
         if (isdigit(expr[i]) || expr[i] == '.') {
             char buf[64]; int bi = 0;
             while (i < len && (isdigit(expr[i]) || expr[i] == '.'))
                 buf[bi++] = expr[i++];
             buf[bi] = '\0';
             values[++v_top] = atof(buf);
         } else if (expr[i] == '(') {
             ops[++op_top] = expr[i++];
         } else if (expr[i] == ')') {
             while (op_top >= 0 && ops[op_top] != '(')
                 applyOp(values, &v_top, ops[op_top--]);
             op_top--; i++;
         } else {
             char op = expr[i++];
             while (op_top >= 0 && ops[op_top] != '(' &&
                   (precedence(ops[op_top]) > precedence(op) ||
                   (precedence(ops[op_top]) == precedence(op) && isLeftAssociative(op)))) {
                 applyOp(values, &v_top, ops[op_top--]);
             }
             ops[++op_top] = op;
         }
     }
 
     while (op_top >= 0)
         applyOp(values, &v_top, ops[op_top--]);
 
     return values[v_top];
 }
 
 int main() {
     char input[MAX_EXPR_LEN];
     while (1) {
         printf("Nhap bieu thuc so (voi +, -, *, /, ^, ()), q de thoat:\n> ");
         if (!fgets(input, sizeof(input), stdin)) break;
         input[strcspn(input, "\n")] = '\0';
         if (strcmp(input, "q") == 0) break;
 
         double result = eval_numeric(input);
         printf("Ket qua: %g\n\n", result);
     }
     printf("Chuong trinh ket thuc.\n");
     return 0;
 }
 