#pragma once
#include <bitset>

inline std::tuple<uint32_t, uint32_t> getMinMaxBit(const uint32_t number)
{
    const auto fill = std::bitset<32>(number);
    const auto count = fill.count();
    std::bitset<32> maxbit, minbit;
    for (int i = 0; i < count; i++)
    {
        minbit[i] = 1;
        maxbit[32 - i - 1] = 1;
    }

    auto min = static_cast<uint32_t>(minbit.to_ulong());
    auto max = static_cast<uint32_t>(maxbit.to_ulong());

    return { min, max };
}