#include "ParInt.hh"
#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
  ParInt pi;
  while (pi.llegir()) l.push_back(pi);
}