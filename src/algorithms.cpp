#include "algorithms.hpp"

#include <algorithm>
#include <queue>
#include <unordered_set>

namespace algo {

int binary_search(const std::vector<int>& values, int target) {
    std::size_t left = 0;
    std::size_t right = values.size();
    while (left < right) {
        const std::size_t mid = left + (right - left) / 2;
        if (values[mid] == target) return static_cast<int>(mid);
        if (values[mid] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}

void merge_sort(std::vector<int>& values) {
    if (values.size() < 2) return;
    const std::size_t mid = values.size() / 2;
    std::vector<int> left(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(mid));
    std::vector<int> right(values.begin() + static_cast<std::ptrdiff_t>(mid), values.end());
    merge_sort(left);
    merge_sort(right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), values.begin());
}

void quick_sort(std::vector<int>& values) {
    if (values.size() < 2) return;
    std::sort(values.begin(), values.end());
}

std::size_t longest_unique_substring(const std::string& text) {
    std::unordered_set<char> window;
    std::size_t left = 0;
    std::size_t best = 0;
    for (std::size_t right = 0; right < text.size(); ++right) {
        while (window.count(text[right])) {
            window.erase(text[left++]);
        }
        window.insert(text[right]);
        best = std::max(best, right - left + 1);
    }
    return best;
}

std::vector<int> bfs(const std::vector<std::vector<int>>& graph, int start) {
    if (start < 0 || static_cast<std::size_t>(start) >= graph.size()) return {};
    std::vector<int> result;
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    q.push(start);
    visited[static_cast<std::size_t>(start)] = true;
    while (!q.empty()) {
        const int node = q.front();
        q.pop();
        result.push_back(node);
        for (int next : graph[static_cast<std::size_t>(node)]) {
            if (next >= 0 && static_cast<std::size_t>(next) < graph.size() && !visited[static_cast<std::size_t>(next)]) {
                visited[static_cast<std::size_t>(next)] = true;
                q.push(next);
            }
        }
    }
    return result;
}

namespace {
void dfs_impl(const std::vector<std::vector<int>>& graph, int node, std::vector<bool>& visited, std::vector<int>& result) {
    visited[static_cast<std::size_t>(node)] = true;
    result.push_back(node);
    for (int next : graph[static_cast<std::size_t>(node)]) {
        if (next >= 0 && static_cast<std::size_t>(next) < graph.size() && !visited[static_cast<std::size_t>(next)]) {
            dfs_impl(graph, next, visited, result);
        }
    }
}
}

std::vector<int> dfs(const std::vector<std::vector<int>>& graph, int start) {
    if (start < 0 || static_cast<std::size_t>(start) >= graph.size()) return {};
    std::vector<int> result;
    std::vector<bool> visited(graph.size(), false);
    dfs_impl(graph, start, visited, result);
    return result;
}

void Stack::push(int value) { data_.push_back(value); }

std::optional<int> Stack::pop() {
    if (data_.empty()) return std::nullopt;
    const int value = data_.back();
    data_.pop_back();
    return value;
}

bool Stack::empty() const { return data_.empty(); }
std::size_t Stack::size() const { return data_.size(); }

void Queue::push(int value) { data_.push_back(value); }

std::optional<int> Queue::pop() {
    if (head_ >= data_.size()) return std::nullopt;
    const int value = data_[head_++];
    if (head_ > 64 && head_ * 2 > data_.size()) {
        data_.erase(data_.begin(), data_.begin() + static_cast<std::ptrdiff_t>(head_));
        head_ = 0;
    }
    return value;
}

bool Queue::empty() const { return head_ >= data_.size(); }
std::size_t Queue::size() const { return data_.size() - head_; }

} // namespace algo
