#include "algorithms.hpp"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{9, 3, 7, 1, 8, 2};
    algo::merge_sort(values);

    std::cout << "Sorted values: ";
    for (int value : values) std::cout << value << ' ';
    std::cout << "\nIndex of 7: " << algo::binary_search(values, 7) << '\n';
    std::cout << "Longest unique substring in 'abcabcbb': "
              << algo::longest_unique_substring("abcabcbb") << '\n';

    const std::vector<std::vector<int>> graph{
        {1, 2}, {0, 3}, {0, 3}, {1, 2, 4}, {3}
    };
    const auto order = algo::bfs(graph, 0);
    std::cout << "BFS: ";
    for (int node : order) std::cout << node << ' ';
    std::cout << '\n';

    algo::Stack stack;
    stack.push(10);
    stack.push(20);
    std::cout << "Stack pop: " << *stack.pop() << '\n';

    algo::Queue queue;
    queue.push(100);
    queue.push(200);
    std::cout << "Queue pop: " << *queue.pop() << '\n';
}
