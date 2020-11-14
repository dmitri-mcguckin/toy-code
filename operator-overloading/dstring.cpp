#include "dstring.h"

// DString Implementation

// Default constructor
DString::DString() : data_length(0), data(NULL) {}

// Constructor with arguments
DString::DString(const char * src): data_length(0), data(NULL)
{
    // There is a chance that we return from this constructor early
    //    if src happens to be NULL, to account for this situation, we use
    //    an initialization list to always zero out the data first.
    //
    // With this, this->data always has defined behaviour, even if bad
    //    data is input by the user/client-programmer.
    if(!src) return; // Check if input is NULL

    data = new char[strlen(src) + 1];
    strcpy(data, src);
    data_length = strlen(data);
}

// Copy Constructor
DString::DString(const DString & src): data_length(0), data(NULL)
{
    // There is a chance that we return from this constructor early
    //    if src.data happens to be NULL, to account for this situation, we use
    //    an initialization list to always zero out the data first.
    //
    // With this, this->data always has defined behaviour, even if bad
    //    data is input by the user/client-programmer.
    if(this == &src) return; // Check for self assignment
    if(!src.data) return; // Check if src is an epty string

    // Do the copy
    //    Note: notice how we're able to access src's supposedly private data
    //        Why is it we're able to do that?
    //
    //    This is because `this` is a DString and so is src, because of this,
    //    we know the memory layout of a DString object, and are able to
    //    succesfully point to a valid location in memory inside src.
    //
    //    In other words, variable access is on a CLASS-TYPE basis not an
    //    INSTANCE basis.
    data = new char[strlen(src.data) + 1];
    strcpy(data, src.data);
    data_length = src.data_length;
}

// Destructor
DString::~DString()
{
    // Only delete the char* if it exists
    if(data) delete [] data;
}

// A getter for data_length
const int DString::length() const
{
    return data_length;
}

// An internal utility function for getting the ASCII sum of the data
//    Primarily used for bolean operators.
inline const int DString::count() const
{
    int sum = 0;
    for(int i = 0; i < data_length; ++i)
       sum += data[i];
    return sum;
}

// Overloaded assignment operator
DString & DString::operator= (const DString & src)
{
    if(this == &src) return *this; // Check for self-assignment

    // Check if data exists
    //    Note: it is imperative to remeber that this overloaded operater
    //    is not a constructor, so `this` could very well have been constructed
    //    already with perfectly valid data.
    if(data) delete [] data;

    // Do the copy
    //    Note: notice how we're able to access src's supposedly private data
    //        Why is it we're able to do that?
    //
    //    This is because `this` is a DString and so is src, because of this,
    //    we know the memory layout of a DString object, and are able to
    //    succesfully point to a valid location in memory inside src.
    //
    //    In other words, variable access is on a CLASS-TYPE basis not an
    //    INSTANCE basis.
    data = new char[src.data_length + 1];
    strcpy(data, src.data);
    data_length = src.data_length;

    return *this;
}

// Overloaded subscript operator
//    Just returns a copy of a char at a given location, notice how it
//    does not check bounds, or that `data` exists at all. In what ways
//    might we be able to improve this?
inline const char DString::operator[] (const int position)
{
    return data[position];
}

// Overloaded add operator
//    Works as a concatenator. but returns a copy of the result,
//    not a reference to the first object.
DString DString::operator+ (const DString & src)
{
    char * t_char = new char[strlen(data) + strlen(src.data) + 1];
    strcpy(t_char,data);
    strcat(t_char,src.data);
    DString ret_val(t_char);
    delete [] t_char;
    return ret_val;
}

// Overloaded add operator
//    Works as a concatenator. but returns a copy of the result,
//    not a reference to the first object.
DString DString::operator+ (const char * src)
{
    char * t_char = new char[strlen(data) + strlen(src) + 1];
    strcpy(t_char,data);
    strcat(t_char,src);
    DString ret_val(t_char);
    delete [] t_char;
    return ret_val;
}

// Overloaded subtraction operator
//    Works as an all-occurences char remover and returns the original object modified.
DString & DString::operator- (const char t_remove)
{
    for(int i = 0; i < data_length; ++i)
    {
        if(data[i] == t_remove)
          for(int j = i; j < data_length; ++j)
            data[j] = data[j + 1];
    }

    return *this;
}

// Overloaded insertion operator (ex: cout << obj)
ostream & operator<< (ostream & buffer, const DString & src)
{
    if(src.length() != 0)
        buffer << src.data;
    return buffer;
}

// Boolean operators
//   Just compares literal ASCII sums of strings
//   What other ways could boolean operators be implemented?

const bool DString::operator< (const DString & src)
{
    return (count() < src.count());
}

const bool DString::operator<= (const DString & src)
{
    return (count() <= src.count());
}

const bool DString::operator> (const DString & src)
{
    return (count() > src.count());
}

const bool DString::operator>= (const DString & src)
{
    return (count() >= src.count());
}

const bool DString::operator== (const DString & src)
{
    return (count() == src.count());
}

const bool DString::operator!= (const DString & src)
{
    return (count() != src.count());
}
