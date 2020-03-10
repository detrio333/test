#include "list.h"

void List::filter5()
{
    auto* head = this;
    List* prev = nullptr;

    unsigned int counter = 0;
    while (head)
    {
        List* next = head->next_;
        counter++;
        if (counter == 5)
        {
            counter = 0;
            prev->next_ = next;
            delete head;
            head = next;
        }
        prev = head;
        head = next;
    }
}

void List::push_back(const SomeDateType payload)
{
    if (!next_)
        next_ = new List(payload);
    else
    {
        auto next = next_;
        while (next)
        {
            if (next->next_ == nullptr)
            {
                next->next_ = new List(payload);
                break;
            }
            next = next->next_;
        }
    }
}
