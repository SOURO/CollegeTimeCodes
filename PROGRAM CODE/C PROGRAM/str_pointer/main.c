#include<stdio.h>
int f(char *x) {
x++;
*x = 'a';
return 0;
}
int main() {
char str[]= {"hello"};
f(str);

printf("%s", str);
return 0;
}
