#include <iostream>
#include <string>
#include <fstream>
#include <tablemanager>
#include "Table.h"
#include "TableManager.h"
using namespace std;

int main(){
  Table table = new Table;
  table.table_num = 999;
  cout << testFunction(table) << endl;
}
