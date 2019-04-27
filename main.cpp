#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Table.h"
#include "TableManager.h"
using namespace std;

table *head;

void printTableStatus(table *t) {

  cout << setw(10) << "Table No." << setw(10) << "Capacity" << setw(10) << "Status" << setw(10) << "Amount" << endl;

  while (t != NULL) {
    cout << left;
    cout << setw(10) << t->table_no << setw(10) << t->no_of_cus << setw(10) << t->status << setw(10) << t->amount << endl;
    t = t->next;
  }

}

int main() {

  ifstream fin;
  fin.open("config.txt");

  if (fin.fail()) {
    cout << "Failed to read the configuration file!" << endl;
    cout << "The program will end now..." << endl;
    exit(1);
  }

  string tmp;
  int n = 1, x;
  getline(fin,tmp);
  while (fin >> x) {
    table table;
    table.table_no = n;
    table.no_of_cus =  x;
    if (n == 1) head = &table;
  }

  char in;
  while (true) {

    printTableStatus(head);

    cout << endl << "MAIN MENU" << endl;
    cout << "-----" << endl;
    cout << "1. Table Operation" << endl;
    cout << "2. Table Searching" << endl;
    cout << "3. Table Service" << endl;
    cout << "0. End Program" << endl << endl;
    cout << "Please input number (0 - 3): > ";

    cin >> x;
    if (x == 0) {
      cout << endl << "Program will end, are you sure? (Y/N): > ";
      cin >> in;
      if (in == 'Y') break;
      else continue;
    } else if (x == 1) {

      cout << endl << "TABLE OPERATION" << endl;
      cout << "-----" << endl;
      cout << "+. Occupy table" << endl;
      cout << "*. Reserve table" << endl;
      cout << "-. Release table" << endl;
      cout << "/. Change table configuration" << endl;
      cout << "0. Back" << endl << endl;
      cout << "Please input symbol: >";

      cin >> in;
      if (in == '+') {

      } else if (in == '*') {

      } else if (in == '-') {

      } else if (in == '/') {

      } else continue;

    } else if (x == 2) {

      cout << endl << "TABLE SEARCHING" << endl;
      cout << "-----" << endl;
      cout << "!. Get next avaliable table" << endl;
      cout << "?. Check status of a table" << endl;
      cout << "0. Back" << endl << endl;
      cout << "Please input symbol: >";

      cin >> in;
      if (in == '!') {

      } else if (in == '?') {

      } else continue;

    } else if (x == 3) {

      cout << endl << "TABLE SERVICE" << endl;
      cout << "-----" << endl;
      cout << "+. Add order amount" << endl;
      cout << "@. Change table idle notification time" << endl;
      cout << "0. Back" << endl << endl;
      cout << "Please input symbol: >";

      cin >> in;
      if (in == '+') {

      } else if (in == '@') {

      } else continue;

    } else continue;
  }

  //TODO Output daily report

}
