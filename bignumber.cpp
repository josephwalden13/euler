// bignumber.cpp
//
#include <iostream>
#include "bignumber.h"
#define LZZ_INLINE inline
using namespace std;
bignumber& bignumber::operator = (string s)
{
    for (int i = 0; i != 512; i++)
    {
        number[i] = 0;
    }
    for(int i = s.length() - 1, j = 0; i >= 0; i--, j++)
    {
        number[i] = s[j] - '0'; 
    }
}
bignumber& bignumber::operator = (int i)
{
    string s = to_string(i);
    for (int i = 0; i != 512; i++)
    {
        number[i] = 0;
    }
    for(int i = s.length() - 1, j = 0; i >= 0; i--, j++)
    {
        number[i] = s[j] - '0'; 
    }
}
bignumber::bignumber ()
{
    for (int i = 0; i != 512; i++)
    {
        number[i] = 0;
    }
}
bignumber::bignumber (string s)
{
    for (int i = 0; i != 512; i++)
    {
        number[i] = 0;
    }
    for(int i = s.length() - 1, j = 0; i >= 0; i--, j++)
    {
        number[i] = s[j] - '0'; 
    }
}
bignumber::bignumber (int i)
{
    string s = to_string(i);
    for (int i = 0; i != 512; i++)
    {
        number[i] = 0;
    }
    for(int i = s.length() - 1, j = 0; i >= 0; i--, j++)
    {
        number[i] = s[j] - '0'; 
    }
}
void bignumber::add (bignumber i)
{
    for (int j = 0; j != 512; j++)
    {
        number[j] += i.number[j];
        while(number[j] > 9)
        {
            number[j+1]++;
            number[j]-=10;
        }
    }        
}
void bignumber::subtract (bignumber i)
{
    for (int j = 0; j != 512; j++)
    {
        number[j] -= i.number[j];
        while (number[j] < 0)
        {
            number[j+1]--;
            number[j]+=10;
        }
    }
}
bignumber& bignumber::operator << (int i)
{
    int temp[512];
    for (int j = 0; j != 512; j++)
    {
        temp[j] = 0;
    }
    for (int j = 0; j != 512; j++)
    {
        temp[j+i] = number[j];
    }
    for (int j = 0; j != 512; j++)
    {
        number[j] = temp[j];
    }
}
void bignumber::multiply(bignumber i)
{

}
bignumber& bignumber::operator + (bignumber i)
{
    add(i);
}
bignumber& bignumber::operator += (bignumber i)
{
    add(i);
}
bignumber& bignumber::operator - (bignumber i)
{
    subtract(i);
}
bignumber& bignumber::operator -= (bignumber i)
{
    subtract(i);
}
bignumber& bignumber::operator ++ (int i)
{
    add(bignumber(1));
}
bool bignumber::operator == (bignumber i)
{
    return value() == i.value();
}
bool bignumber::operator != (bignumber i)
{
    return (value() != i.value());
}
bool bignumber::operator == (int i)
{
    return value() == bignumber(i).value();
}
bool bignumber::operator != (int i)
{
    return (value() != bignumber(i).value());
}
string bignumber::value ()
{
    string s;
    int i = 511;
    while(!number[i])
    {
        i--;
    }
    while(i != -1)
    {
        s += to_string(number[i]);
        i--;
    }
    return s;
}
#undef LZZ_INLINE
