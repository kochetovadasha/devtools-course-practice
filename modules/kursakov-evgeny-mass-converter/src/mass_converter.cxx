// Copyright 2016 Kursakov Evgeny

#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>

#include "include/mass_converter.h"

MassConverter::MassConverter(const std::vector<MassUnit> &units) {
    this->units_ = std::vector<MassUnit>(units);

    auto last = std::unique(this->units_.begin(),
                            this->units_.end(),
                            [](const MassUnit &a, const MassUnit &b) {
                                return a.Qualifier() == b.Qualifier();
                            });

    if (last != this->units_.end())
        throw std::invalid_argument("unit qualifiers must be unique");
}

void MassConverter::AddUnit(const MassUnit &new_unit) {
    for (auto &unit : units_) {
        if (unit.Qualifier() == new_unit.Qualifier())
            throw std::invalid_argument("unit is already added to converter");
    }

    units_.push_back(new_unit);
}

std::vector<MassUnit> MassConverter::GetUnits() const {
    return units_;
}

void MassConverter::ClearUnits() {
    units_.clear();
}

double MassConverter::Convert(const MassUnit &from,
                              const MassUnit &to,
                              double value) const {
    if (value < 0)
        throw std::invalid_argument("value must be not negative");

    double conversion_coefficient = from.Coefficient() / to.Coefficient();

    return value * conversion_coefficient;
}

std::string MassConverter::ConvertToString(const MassUnit &unit,
                                           double value,
                                           int precision) const {
    if (precision < 0)
        throw std::invalid_argument("precision must be positive");

    std::ostringstream stringStream;
    stringStream << std::fixed << std::setprecision(precision) << value;
    stringStream << " ";
    stringStream << unit.Qualifier();
    return stringStream.str();
}

double MassConverter::ConvertFromString(const std::string &input,
                                        const MassUnit &to_unit) const {
    std::pair<MassUnit, double> result = ParseString(input);
    return Convert(result.first, to_unit, result.second);
}

std::pair<MassUnit, double>
MassConverter::ParseString(const std::string &input) const {
    if (!CheckInputString(input))
        throw std::invalid_argument("Invalid input");

    double value;
    std::string qualifier;

    std::istringstream inputStringStream(input);
    inputStringStream >> value;
    inputStringStream >> qualifier;

    for (auto &unit : units_) {
        if (unit.Qualifier() == qualifier) {
            return std::pair<MassUnit, double>(unit, value);
        }
    }

    throw std::logic_error("Unit not found");
}

bool MassConverter::CheckInputString(const std::string &input) const {
    size_t space_pos = input.find_first_of(' ');
    size_t dot_pos = input.find_first_of('.');

    if (space_pos == std::string::npos)
        return false;
    if (input.substr(dot_pos + 1).find_first_of('.') != std::string::npos)
        return false;
    if (input.substr(space_pos + 1).find_first_of(' ') != std::string::npos)
        return false;

    for (auto &character : input.substr(0, space_pos)) {
        if (!std::isdigit(character) && character != '.') {
            return false;
        }
    }

    for (auto &character : input.substr(space_pos + 1)) {
        if (!std::isalnum(character)) {
            return false;
        }
    }

    return true;
}

