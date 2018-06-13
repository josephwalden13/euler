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
  short (number) [512];
  void add (bignumber i);
  void multiply(bignumber i);
  void subtract(bignumber i);
  bignumber (string s);
  bignumber (int i);
  bignumber ();
  bignumber& operator + (bignumber i);
  bignumber& operator += (bignumber i);
  bignumber& operator - (bignumber i);
  bignumber& operator -= (bignumber i);
  bignumber& operator << (int i);
  bignumber& operator = (string s);
  bignumber& operator = (int i);
  bignumber& operator ++ (int i);
  bool operator == (int i);
  bool operator != (int i);
  bool operator == (bignumber i);
  bool operator != (bignumber i);
  string value ();
};
#undef LZZ_INLINE
#endif
