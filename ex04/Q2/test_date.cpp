#include "Date.h"

int main(void) {
  /*-----------Way1----------*/
  Date d;
  d.set(10, 1, 1998);
  d.print();

  /*-----------Way2----------*/
  Date2 dd;
  dd.set(10, 1, 1998);
  dd.print();
}

