#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "Table.h"
#include <vector>
using namespace std;

vector<Table> tables;

//TODO Change table configuration
void change_table_config( string order, table *head, int target_table, int no_of_customers){
  // this first read an order ("add"-add a table , "delete"-delete a table, "change" - change no of customers)
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table and new no. of customers.
if (order == "add"){
  for (int i=0; i< target_table
}

//TODO Reserve a table
void reserve_table (table *head, int target_table){
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table
  
}
//TODO Occupy a table
void occupy_table (table *head, int target_table){
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table, 
}
  
  //TODO Release a table
void release_table (table *head, int target_table){
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table
}

void addTable(Table t) {
  tables.push_back(t);
}

int testFunction(Table t) {
  return t.table_num;
}

#endif
