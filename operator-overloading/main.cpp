#include "dstring.h"
#include <iomanip>

const int SIZE = 50;

void assert(const char * cstring, const DString & dstring)
{
    cout << endl;
    cout << setw(SIZE) << setfill(' ') << left << "EXPECTED: "  << right << cstring << endl;
    cout << setw(SIZE) << setfill(' ') << left << "RESULT: "  << right << dstring;

    if(DString(cstring) == dstring)
        cout << setw(SIZE - dstring.length()) << right << " [PASS]";
    else
        cout << setw(SIZE - dstring.length()) << right << " [FAIL]";
    cout << endl;
}

void assert(const char * operation, const bool expected, const bool toggle)
{
    cout << endl;
    cout << setw(SIZE) << setfill(' ') << left << "EXPECTED " << operation  << " " << right << expected << endl;
    cout << setw(SIZE) << setfill(' ') << left << "RESULT: "  << operation <<  " " << right << toggle;

    if(expected == toggle)
        cout << setw(SIZE - 9) << right << " [PASS]";
    else
        cout << setw(SIZE - 9) << right << " [FAIL]";
    cout << endl;
}

int main()
{
    const int bsize = 2 * SIZE;
    const char * c1 = "Hello";
    const char * c2 = "World";
    DString d1, d2, d3, d4, d5;

    // Copy test
    DString a("Copy Test");
    DString b = a;

    // Self assignment test
    a = a;

    // Blank string tests
    DString c;
    DString d = c;

    DString e(NULL);
    DString f = e;

    // Misc unit tests
    cout << setw(bsize) << setfill('-') << "" << endl;
    cout << setw(bsize) << setfill(' ')  << "UNIT TESTS" << endl;
    cout << setw(bsize) << setfill('-') << "" << endl;

    d1 = c1;
    d2 = c2;
    assert("Hello",d1);

    d3 = d1 + d2;
    assert("HelloWorld",d3);

    d4 = d1 + " World";
    assert("Hello World",d4);

    d3 = d3 - 'o';
    assert("HellWrld",d3);

    d5 = d3 + "abc";
    assert("HellWrldabc",d5);

    assert("d1 > d2", false, (d1 > d2));

    assert("d1 < d2", true, (d1 < d2));

    assert("d1 >= d1", true, (d1 >= d1));

    assert("d1 <= d1", true, (d1 <= d1));

    assert("d1 == d1", true, (d1 == d1));

    assert("d1 != d1", false, (d1 != d1));
}
