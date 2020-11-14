#ifndef DSTRING_H
#define DSTRING_H

#include <iostream>
#include <string.h>

using namespace std;

class DString
{
    private:
        int data_length;
        char * data;
        inline const int count() const;
    public:
        // Constructors/Destructors
        DString();
        DString(const char *);
        DString(const DString &);
        ~DString();

        // Functions
        const int length() const;

        // Operators
        DString & operator = (const DString &);
        inline const char operator [] (const int);
        DString operator + (const DString &);
        DString operator + (const char *);
        DString & operator - (const char);
        friend ostream & operator << (ostream &, const DString &);
        friend istream & operator >> (istream &, DString &);
        const bool operator < (const DString &);
        const bool operator <= (const DString &);
        const bool operator > (const DString &);
        const bool operator >= (const DString &);
        const bool operator == (const DString &);
        const bool operator != (const DString &);
};

#endif
