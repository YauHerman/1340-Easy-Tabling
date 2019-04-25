#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "Table.h"
#include <vector>
using namespace std;

vector<Table> tables;

void addTable(Table t) {
  tables.push_back(t);
}

int testFunction(Table t) {
  return t.table_num;
}

#endif
