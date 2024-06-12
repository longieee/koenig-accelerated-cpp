#ifndef GUARD_grade_h
#define GUARD_grade_h

// `grade.h'
#include "Student_info.h"
#include <vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

#endif
