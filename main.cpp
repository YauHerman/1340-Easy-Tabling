#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Table.h"
#include "TableManager.h"
using namespace std;

extern vector<Table> tables;

int main() {

  //TODO Scan input from text file and initialize table configuration

  //TODO Main menu

  //TODO Output daily report

  //Test codes below, to be removed
  Table table;
  table.table_num = 999;
  cout << testFunction(table) << endl;
  addTable(table);
  cout << tables.front().table_num << endl;
}
