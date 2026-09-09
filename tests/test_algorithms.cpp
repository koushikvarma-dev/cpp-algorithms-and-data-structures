#include "algorithms.hpp"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> sorted{1, 2, 3, 4, 5};
    assert(algo::binary_search(sorted, 3) == 2);
    assert(algo::binary_search(sorted, 9) == -1);

    std::vector<int> values{5, 1, 4, 2, 3};
    algo::merge_sort(values);
    assert((values == std::vector<int>{1, 2, 3, 4, 5}));

    values = {8, 4, 6, 1, 7};
    algo::quick_sort(values);
    assert((values == std::vector<int>{1, 4, 6, 7, 8}));

    assert(algo::longest_unique_substring("abcabcbb") == 3);
    assert(algo::longest_unique_substring("") == 0);

    const std::vector<std::vector<int>> graph{{1, 2}, {3}, {3}, {}};
    assert((algo::bfs(graph, 0) == std::vector<int>{0, 1, 2, 3}));
    assert((algo::dfs(graph, 0) == std::vector<int>{0, 1, 3, 2}));

    algo::Stack stack;
    assert(stack.pop() == std::nullopt);
    stack.push(10);
    stack.push(20);
    assert(stack.pop() == 20);
    assert(stack.pop() == 10);

    algo::Queue queue;
    assert(queue.pop() == std::nullopt);
    queue.push(10);
    queue.push(20);
    assert(queue.pop() == 10);
    assert(queue.pop() == 20);

    std::cout << "All tests passed.\n";
    return 0;
}
