
#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "lib/json.hpp"

using i32 = int32_t;
using ui32 = uint32_t;

using f32 = float;
using f64 = double;

using string = std::string;

template <typename T>
using ptr = std::unique_ptr<T>;
template <typename T>
using array = std::vector<T>;
template <typename T, typename Q>
using map = std::unordered_map<T, Q>;

using json = nlohmann::json;