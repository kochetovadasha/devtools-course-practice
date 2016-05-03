// Copyright 2016 Sirotkin_Nikita
#ifndef MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_
#define MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_

#include <string>
#include "./list.hpp"
#include "./note.h"

using std::string;

class notepad {
 public:
  explicit notepad(float pouch);
  void addNote(date notes_date, float sum, string category,
               string comment = "");
  float getPouch() const;
  float getPotentialPouch();
  string notesFromCategoryToFormatedString(string category);
  float sumFromCategory(string category);
  string toFormatedString();
  string formatedStringGroupedByCategories();
  void sortByDate();
  bool operator++();
  note getCurrentNote() const;
 private:
  lite_list<note> notes;
  category_table table_of_categories;
  float pouch;
};

#endif  // MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_FINANCE_NOTEPAD_H_
