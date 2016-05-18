// Copyright 2016 Kochetova Dasha

#include "include\credit_calculator.h"
# include <string>

int main(int argc, const char** argv) {
    CreditCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}

