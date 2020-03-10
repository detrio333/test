#pragma once

using SomeDateType = int;

struct List
{
    List(SomeDateType payload) : payload_(payload) {}

    void push_back(SomeDateType);
    void filter5();

    struct List* next_ = nullptr;
    SomeDateType payload_;
};
