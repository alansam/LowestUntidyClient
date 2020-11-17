// Q2 input: a s w d 1 2 3 ^ 2 * 2 d ) j # k > w ? | S I M - ! B W
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

//using namespace std;

int main() {
  std::ifstream  fin("./Q2input.txt");
  char ch;
  int i, c = 0, num = 0, oc = 0, sp = 0;

  std::vector<unsigned char> indata;
  while (fin) {
    fin.get(ch);
    if (fin.eof()) {
      break;
    }
    indata.push_back(ch);
    i = ch;
//    if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
//    if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')) {
    if (std::isalpha(i)) {
      c++;
      std::cout << (unsigned char) i << ' '
                << c << '\n';
    }
//    else if (i >= 48 && i <= 57)
//    else if (i >= 48 && i <= 57) {
    else if (std::isdigit(i)) {
      num++;
    }
//    else if ((i >= 33 && i <= 47)
//          || (i >= 58 && i <= 64)
//          || (i >= 91 && i <= 96)
//          || (i >= 123 && i <= 126))
//    else if ((i >= 0x21 && i <= 0x2f)   /* ! - / */
//          || (i >= 0x3A && i <= 0x40)   /* : - @ */
//          || (i >= 0x5b && i <= 0x60)   /* [ - ` */
//          || (i >= 0x7b && i <= 0x7e))  /* { - ~ */ {
    else if (std::ispunct(i)) {
      oc++;
    }
  }

  std::cout << "The number of characters is "
            << c << std::endl;
  std::cout << "The number of integer numbers is "
            << num << std::endl;
  std::cout << "The number of other characters is "
            << oc << std::endl; 
  std::cout << "input:" << std::endl;
  size_t col;
  size_t constexpr col_max(32);
  std::for_each(indata.begin(), indata.end(), [&col](auto c_) {
    std::cout << std::setw(2)
              << c_ 
              << ((++col % col_max == 0) ? "\n" : "");
  });
  std::cout << std::endl;

  return 0;
}
