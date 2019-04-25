#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "Table.h"
#include <vector>
using namespace std;

vector<Table> tables;

//TODO Change table configuration

//TODO Reserve a table

//TODO Occupy a table

//TODO Release a table

void addTable(Table t) {
  tables.push_back(t);
}

int testFunction(Table t) {
  return t.table_num;
}

#endif
