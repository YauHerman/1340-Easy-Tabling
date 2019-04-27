#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include "Table.h"
#include "TableManager.h"
#include "TableSearcher.h"
#include "TableService.h"
using namespace std;

void printTableStatus(table *t) {

  cout << left;
  cout << setw(10) << "Table No." << setw(10) << "Capacity" << setw(10) << "Status" << setw(10) << "Amount" << setw(15) << "Starting Time" << endl;

  while (t != NULL) {
    time_t time = chrono::system_clock::to_time_t(t->time);
    cout << setw(10) << t->table_no << setw(10) << t->no_of_cus << setw(10) << t->status << setw(10) << t->amount << setw(15) << ctime(&time);
    t = t->next;
  }

}

int main() {

  table * head = NULL;
  table * tail = NULL;
  int idleMins = 120;

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
    addTable(head, tail, n, x);
    n++;
  }
  fin.close();

  char in;
  while (true) {

    cout << endl;
    printTableStatus(head);
    checkIdleTable(head, idleMins);

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
      cout << "Please input symbol: > ";

      cin >> in;
      if (in == '+') {

        cout << endl << "What table number to occupy? > ";
        cin >> x;
        occupy_table(head, x);

      } else if (in == '*') {

        cout << endl << "What table number to reserve? > ";
        cin >> x;
        reserve_table(head, x);

      } else if (in == '-') {

        cout << endl << "What table number to release? > ";
        cin >> x;
        int amount = release_table(head, x);
        cout << "[i] Table " << x << " has been released, the total amount is $" << amount << "." << endl;

      } else if (in == '/') {

        cout << endl << "What table number to change configuration? > ";
        cin >> x;
        cout << endl << "Change to what capacity? > ";
        cin >> n;
        changeTable(head, x, n);

      } else continue;

    } else if (x == 2) {

      cout << endl << "TABLE SEARCHING" << endl;
      cout << "-----" << endl;
      cout << "!. Get next avaliable table" << endl;
      cout << "?. Check status of a table" << endl;
      cout << "0. Back" << endl << endl;
      cout << "Please input symbol: > ";

      cin >> in;
      if (in == '!') {

        cout << endl << "How many customers? > ";
        cin >> x;

        if (x <= 0) {
          cout << endl << "[!] Number of customers must be larger than 0." << endl;
        }

        int tableNum = search_for_avaliable(head, x);
        if (tableNum <= 0) {
          cout << endl << "[i] No avaliable for " << x << " customers right now." << endl;
        } else {
          cout << endl << "[i] Table " << tableNum << " is avaliable for " << x << " customers." << endl;
        }

      } else if (in == '?') {

        cout << endl << "Which table to search for? > ";
        cin >> x;
        check_table_status(x, head);

      } else continue;

    } else if (x == 3) {

      cout << endl << "TABLE SERVICE" << endl;
      cout << "-----" << endl;
      cout << "+. Add order amount" << endl;
      cout << "@. Change table idle notification time" << endl;
      cout << "0. Back" << endl << endl;
      cout << "Please input symbol: > ";

      cin >> in;
      if (in == '+') {

        cout << endl << "Which table is ordering? > ";
        cin >> x;
        cout << endl << "How much is the amount of the order? ($) > ";
        cin >> n;
        ordering(head, x, n);
        cout << endl << "[i] $" << n << " has been added for table " << x << ".";

      } else if (in == '@') {

        cout << endl << "[i] Current idle minutes is " << idleMins << "." << endl;
        cout << "How many minutes should a occupied table considered idle? > ";
        cin >> x;
        if (x <= 0) {
          cout << "[!] Idle minutes time has to be larger than 0!" << endl;
        }
        idleMins = x;
        cout << endl << "[i] The idle time has been set to " << x << " minutes." << endl;

      } else continue;

    } else continue;

  }

  ofstream fout;
  fout.open("report.txt");
  if (fout.fail()) {
    cout << "Failed to generate the report!" << endl;
    cout << "The program will end now..." << endl;
    exit(1);
  }

  fout << left;
  fout << setw(10) << "Table No." << setw(10) << "Capacity" << setw(10) << "Total ($)" << endl;
  table *current = head;
  while (current != NULL) {
    fout << setw(10) << current->table_no << setw(10) << current->no_of_cus << setw(10) << current->total_amount << endl;
    table * tmp = current;
    current = current->next;
    delete tmp;
  }
  fout.close();

}
