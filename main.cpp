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
  int i;
  int chr = 0, num = 0, oc = 0, sp = 0;

  std::vector<unsigned char> indata;
//  while (fin) {
//    fin.get(ch);
//    if (fin.eof()) {
//      break;
//    }
  while (fin.get(ch)) {
    indata.push_back(ch);
    i = ch;
//    if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
//    if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')) {
    if (std::isalpha(i)) {
      chr++;
      std::cout << (unsigned char) i << ' '
                << chr << '\n';
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
    else if (std::isspace(i)) {
      sp++;
    }
  }

  std::cout << "The number of characters is "
            << chr << std::endl;
  std::cout << "The number of integer numbers is "
            << num << std::endl;
  std::cout << "The number of space characters is "
            << sp << std::endl;
  std::cout << "The number of other characters is "
            << oc << std::endl;
  std::cout << "total: " << chr + num + sp + oc << std::endl;
  std::cout << "input [size " << indata.size() << "]:"
            << std::endl;
  size_t col;
  size_t constexpr col_max(10);
  std::for_each(indata.begin(), indata.end(), [&col](auto c_) {
    std::vector<std::string> const ctrl {
    /*  00     01     02     03     04     05     06     07 */
      "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    /*  08     09     0a     0b     0c     0d     0e.    0f */
       "BS",  "HT",  "LF",  "VT",  "FF",  "CR",   "SO", "SI",
    /*  10     11     12     13     14     15.    16.    17 */
      "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    /*  18     19     1a     1b     1c     1d     1e     1f */
      "CAN",  "EM", "SUB", "ESC"   "FS",  "GS",  "RS",  "US",
    };
    std::string cv;
    if (std::iscntrl(c_)) {
      switch (c_) {
        case 0x7f:
          cv = "DEL";
          break;
        default:
          cv = ctrl[c_];
          break;
      }
    }
    else {
      cv.push_back(c_);
    }
    std::cout << std::setw(2)
              << '\'' << cv << '\''
              << ((++col % col_max == 0) ? '\n' : ' ');
  });
  std::cout << std::endl;

  return 0;
}
