#ifndef TABLESEARVICE_H
#define TABLESEARVICE_H

#include "Table.h"
#include "TableManager.h"
#include <vector>
using namespace std;

//TODO Add order
void ordering(table*head, int table_no, int amount){
  table *current = head;
  while (current != NULL) {
    if (current -> table_no == table_no){
      current -> amount += amount;
      return;}
current = current->next;}
cout<< "Table does not exist"<<endl;}
//TODO notify when occupy too long

//extern vector<Table> tables;

#endif
