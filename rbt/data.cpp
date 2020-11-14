#include "data.h"

Data::Data() : data(-1) {}

Data::Data(const int data): data(data) {}

const int Data::get() {
  return this->data;
}

bool Data::operator <(const Data& src) {
  return data < src.data;
}

bool Data::operator <=(const Data& src) {
  return data <= src.data;
}

bool Data::operator >(const Data& src) {
  return data > src.data;
}

bool Data::operator >=(const Data& src) {
  return data >= src.data;
}

bool Data::operator ==(const Data& src) {
  return data == src.data;
}

std::ostream& operator << (std::ostream& buffer, const Data& src) {
  buffer << src.data;
  return buffer;
}
