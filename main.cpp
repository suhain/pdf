#include <iostream>
#include <fstream>
#include <string>

#include "utils/PdfStreamReader.h"

int main () {
  std::ifstream fin("../files/Hello.pdf", std::ios::binary | std::ios::in);
  pdf::reader r(fin);
  fin.close();
  return 0;
}