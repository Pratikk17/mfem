#ifndef HYPSYS_PTOOLS
#define HYPSYS_PTOOLS

#include <fstream>
#include <iostream>
#include "../../../mfem.hpp"

using namespace std;
using namespace mfem;

void ParVisualizeField(socketstream &sock, const char *vishost, int visport,
                       string ProblemName, ParGridFunction &gf, string valuerange, bool vec = false);

#endif
