#pragma once
#include <string>
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE };

// Parallel array pops out a string for each type - use the program types an an index
static const std::string degreeTypeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };