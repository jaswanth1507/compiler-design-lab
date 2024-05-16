#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int type;
  int value;
} Symbol;

typedef struct {
  char *op;
  Symbol *arg1;
  Symbol *arg2;
  Symbol *result;
} ICode;

Symbol *new_symbol(char *name, int type, int value) {
  Symbol *symbol = malloc(sizeof(Symbol));
  symbol->name = name;
  symbol->type = type;
  symbol->value = value;
  return symbol;
}

ICode *new_icode(char *op, Symbol *arg1, Symbol *arg2, Symbol *result) {
  ICode *icode = malloc(sizeof(ICode));
  icode->op = op;
  icode->arg1 = arg1;
  icode->arg2 = arg2;
  icode->result = result;
  return icode;
}

void print_icode(ICode *icode) {
  printf("%s %s %s %s\n", icode->op, icode->arg1->name, icode->arg2->name, icode->result->name);
}

int main() {
  Symbol *a = new_symbol("a", 1, 10);
  Symbol *b = new_symbol("b", 1, 20);
  Symbol *c = new_symbol("c", 1, 0);

  ICode *icode1 = new_icode("+", a, b, c);
  ICode *icode2 = new_icode("*", c, b, a);

  print_icode(icode1);
  print_icode(icode2);

  return 0;
}
