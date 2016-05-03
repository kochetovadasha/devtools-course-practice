// Copyright 2016 Kursakov Evgeny

#ifndef MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
#define MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

#include <vector>
#include <string>
#include <utility>

#include "include/mass_unit.h"

using std::vector;

class MassConverter {
 public:
    explicit MassConverter(
        const std::vector<MassUnit> &units = kDefaultMassUnits);

    void AddUnit(const MassUnit &unit);

    std::vector<MassUnit> GetUnits() const;

    void ClearUnits();

    double Convert(const MassUnit &from,
                   const MassUnit &to,
                   double value) const;

    std::string ConvertToString(const MassUnit &unit,
                                double value,
                                int precision = 2) const;

    double ConvertFromString(const std::string &input,
                             const MassUnit &to_unit) const;

 private:
    vector<MassUnit> units_;

    std::pair<MassUnit, double>
        ParseString(const std::string &input) const;
    bool CheckInputString(const std::string &input) const;
};

#endif  // MODULES_KURSAKOV_EVGENY_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
