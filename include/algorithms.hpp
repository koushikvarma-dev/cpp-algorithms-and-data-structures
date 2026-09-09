#pragma once

#include <cstddef>
#include <optional>
#include <string>
#include <vector>

namespace algo {

int binary_search(const std::vector<int>& values, int target);
void merge_sort(std::vector<int>& values);
void quick_sort(std::vector<int>& values);
std::size_t longest_unique_substring(const std::string& text);
std::vector<int> bfs(const std::vector<std::vector<int>>& graph, int start);
std::vector<int> dfs(const std::vector<std::vector<int>>& graph, int start);

class Stack {
public:
    void push(int value);
    std::optional<int> pop();
    bool empty() const;
    std::size_t size() const;
private:
    std::vector<int> data_;
};

class Queue {
public:
    void push(int value);
    std::optional<int> pop();
    bool empty() const;
    std::size_t size() const;
private:
    std::vector<int> data_;
    std::size_t head_{0};
};

} // namespace algo
