/*
  *nsl.h is my standard library. Thanks to
  *a huge error with multiple function definition
  *I had to throw some lexic.h functions from Langdiff
  *in here. For now this is just going to be a storage
  *garage for all sorts of functions that this program
  *calls for. The plan is to keep all plugin-related functions
  *contained in here.
  */

#ifndef NSL_H
#define NSL_H
#include <iostream>
using namespace std;
class nsl
{
public:
    nsl();
    int linec(string);
    void orderFile(string);
    void compile(string fileName,int lines,string toWriteTo,string magichar);
    void loadLanguage(string filename,int lines);
};

#endif // NSL_H
