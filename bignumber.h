// bignumber.h
//
#include <string>
#ifndef LZZ_bignumber_h
#define LZZ_bignumber_h
#define LZZ_INLINE inline

using namespace std;
class bignumber
{
public:
  int (number) [512];
  bignumber& operator = (string s);
  bignumber& operator = (int i);
  bignumber (string s);
  bignumber ();
  void add (bignumber i);
  bignumber& operator + (bignumber i);
  bignumber& operator += (bignumber i);
  string value ();
};
#undef LZZ_INLINE
#endif
