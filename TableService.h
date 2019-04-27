#ifndef TABLESEARVICE_H
#define TABLESEARVICE_H

#include "Table.h"
#include "TableManager.h"
#include <chrono>
#include <iostream>
using namespace std;

void ordering(table*head, int table_no, int amount) {
  table *current = head;
  while (current != NULL) {
    if (current -> table_no == table_no) {
      current -> amount += amount;
      return;
    }
    current = current->next;
  }
  cout<< "Table does not exist"<<endl;
}

void checkIdleTable(table *head, int minutes) {
  auto now = chrono::system_clock::now();
  while (head != NULL) {
    if (head->status != 'O') {
      head = head->next;
      continue;
    }
    chrono::duration<double> seconds = now - head->time;
    if (seconds.count() > minutes * 60) {
      cout << "[i] Table " << head->table_no << " has been occupied for more than " << minutes << " minutes!" << endl;
    }
    head = head->next;
  }
}

#endif
