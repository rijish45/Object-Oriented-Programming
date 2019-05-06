#include "node.h"

void Node::buildMap(BitString b, std::map<unsigned, BitString> & Map) {
  if (sym != NO_SYM) {
    Map[sym] = b;
  }
  else {
    left->buildMap(b.plusZero(), Map);
    right->buildMap(b.plusOne(), Map);
  }
}
