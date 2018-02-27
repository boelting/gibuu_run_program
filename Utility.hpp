#ifndef UTILITY_H
#define UTILITY_H

#include "stdlib.h"
#include <string>
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sstream>
#include <iomanip>

using namespace std;

namespace util{
	string ZeroPadding(int i, int n_zero=4);
	string GetEnv(string name);
	string GetExecPath(bool withName = false);
	string GetHomePath();
	string FormatInputPath(string in);
	void CreateDir(string Path, bool ThrowError=false);
	void ShowProgressBar(float progress);
	
	template <typename T>
	string to_string_with_precision(const T a_value, const int n = 6){
		ostringstream out;
		out << fixed << setprecision(n) << a_value;
		return out.str();
	}
}

#endif
