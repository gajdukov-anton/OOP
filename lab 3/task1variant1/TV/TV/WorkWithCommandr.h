#pragma once

#include <string>

std::string RemoveBlanks(const std::string& strWithCommand);
int GetNumberOfChannel(const std::string& strWithCommand, size_t positionOfNumber);
bool CheckCommand(const std::string& command);
