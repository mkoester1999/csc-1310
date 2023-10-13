#include <iostream>
#include <cassert>

void test_mergesort() {
    List<int> list;
    list.push_back(5);
    list.push_back(2);
    list.push_back(7);
    list.push_back(3);
    list.push_back(1);
    list.push_back(8);
    list.push_back(6);
    list.push_back(4);

    List<int>::listNode* sorted = list.mergesort(list.head, list.tail->next);

    // Check that the list is sorted
    List<int>::listNode* current = sorted;
    while (current->next != nullptr) {
        assert(current->data <= current->next->data);
        current = current->next;
    }

    std::cout << "All tests passed!\n";
}