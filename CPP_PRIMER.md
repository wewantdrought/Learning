# C++ for LeetCode: a practical quick primer

Use C++17 for these examples. Read sections 1–5 first, then Two Sum in section 9. Treat the rest as a reference while practicing. The snippets are independent examples unless labeled as a complete program.

You do not need to master all of C++ to start solving problems. The essentials are types, functions, containers, references, loops, and a few reusable algorithms.

## 1. What a C++ program looks like

This is a complete program you can save as `practice.cpp` and run locally:

```cpp
#include <iostream>              // declares input/output tools
#include <vector>                // declares vector
using namespace std;            // lets us write vector instead of std::vector

int main() {                    // execution starts here
    vector<int> nums = {2, 7, 11, 15};
    cout << nums[0] << '\n';     // prints 2 followed by a newline
    return 0;                   // successful exit
}
```

```sh
clang++ -std=c++17 -Wall -Wextra practice.cpp -o practice
./practice
```

`g++` works in place of `clang++` if that is your installed compiler.

- `#include` makes library declarations available; it is not Python's `import` mechanism.
- Statements usually end in `;`. Blocks use `{ ... }`, not indentation.
- `// comment` and `/* multiline comment */` are comments.
- `std::` means “in the standard-library namespace.” `using namespace std;` is convenient for practice; larger projects often use explicit `std::` names.
- LeetCode supplies the runner. Submit its `class Solution` method, without your own `main()`.

## 2. Values, operators, and control flow

```cpp
int count = 3;                   // integer, typically 32-bit on LeetCode
long long total = 0;             // at least 64-bit; useful for large sums
double average = 2.5;            // floating point
bool found = false;              // true or false
char letter = 'a';               // single quotes: one character
string name = "rain";            // double quotes: string; needs <string>
const int limit = 100;           // cannot reassign
auto x = 42;                    // compiler infers int; still statically typed
```

Initialize local variables: `int x;` does **not** reliably start at zero.

| Purpose | C++ | Python comparison |
|---|---|---|
| Arithmetic | `+ - * / %` | `/` on integers truncates toward zero: `7 / 2 == 3` |
| Comparison | `== != < <= > >=` | Same basic meaning |
| Boolean logic | `&&`, `||`, `!` | `and`, `or`, `not` |
| Assignment | `x = 3`, `x += 2` | Same basic meaning |
| Increment/decrement | `++x`, `--x` | Add/subtract one |
| Conditional value | `ok ? a : b` | `a if ok else b` |
| Bit operations | `&`, `\|`, `^`, `~`, `<<`, `>>` | AND, OR, XOR, NOT, shifts |

`++i` and `i++` both increment; as expressions, the first yields the new value and the second yields the old one. Prefer `++i` in simple loops.

```cpp
if (count > 0 && !found) {
    --count;
} else if (count == 0) {
    found = true;
} else {
    count = 0;
}

for (int i = 0; i < 5; ++i) {     // initialization; condition; update
    if (i == 2) continue;         // skip this iteration
    if (i == 4) break;            // leave the loop
}

while (count > 0) {
    --count;                     // ensure progress toward termination
}
```

Useful number rules:

```cpp
double ratio = 7.0 / 2;           // 3.5: one double operand makes this floating-point division
int a = 100000, b = 100000;
long long product = 1LL * a * b;  // both multiplications use long long
// long long product = a * b;     // wrong: int multiplication may overflow first

char ch = '7';
int digit = ch - '0';             // 7: digit characters are contiguous and ordered
```

`1LL` is the integer literal `1` with the `LL` suffix, which gives it the type
`long long`. Multiplication by one does not change the numeric value. Instead, the
literal changes the *type of the calculation*: in `1LL * a`, C++ converts `a` to
`long long` before multiplying. That result is also a `long long`, so `b` is
converted before the second multiplication. An explicit equivalent is:

```cpp
long long product = static_cast<long long>(a) * b;
```

The assignment's type cannot prevent an earlier overflow. In
`long long product = a * b`, both operands are `int`, so C++ computes an `int`
result first and converts it to `long long` only afterward. Signed integer overflow
during that first step is undefined behavior.

C++ guarantees that the character codes for `'0'` through `'9'` are consecutive.
Subtracting `'0'` therefore gives a digit's distance from zero:
`'0' - '0' == 0`, `'7' - '0' == 7`, and `'9' - '0' == 9`. Check that an arbitrary
character is a digit before using this rule:

```cpp
if (ch >= '0' && ch <= '9') {
    int digit = ch - '0';
}
```

Use `long long` for potentially large totals. C++ remainder can be negative:
`-3 % 2 == -1`; use `x % 2 != 0` to test oddness.

## 3. Functions, references, and const

```cpp
int add(int a, int b) {           // return type, function name, typed parameters
    return a + b;
}

void bump(int& x) {              // & here means reference to caller's variable
    ++x;                        // changes the original
}

int sum(const vector<int>& nums) {
    int total = 0;
    for (int x : nums) {         // range-based loop: each value in nums
        total += x;
    }
    return total;
}
```

| Parameter | Meaning | Typical use |
|---|---|---|
| `int x` | Copy a small value | Numbers, indices |
| `vector<int> v` | Copy the entire vector | When you intentionally want an independent copy |
| `vector<int>& v` | Refer to the original, allowing changes | Modify caller's vector |
| `const vector<int>& v` | Refer to original, disallow changes through this reference | Read without copying |

`const` is a promise enforced by the compiler. `&` means different things in different contexts: reference in a declaration, address-of in `&x`, and bitwise AND in `a & b`.

```cpp
for (int x : nums) { x *= 2; }          // modifies only a copy each iteration
for (int& x : nums) { x *= 2; }         // modifies actual elements
for (const auto& row : grid) { /* read row without copying it */ }
```

A variable declared inside `{ ... }` is scoped to that block. Never return a reference or pointer to a local variable that is about to be destroyed.

## 4. Sequences: vector, string, array, and matrix

### `vector<T>`: your default dynamic array (`<vector>`)

`T` is the element type. Angle brackets supply a type to a template: `vector<int>` stores integers; `vector<string>` stores strings.

```cpp
vector<int> v = {10, 20, 30};
vector<int> zeros(5, 0);          // five zeros
vector<int> single{5};           // one element, whose value is 5!
v.push_back(40);                 // append
v.pop_back();                    // remove last; requires nonempty vector
int first = v[0];                // indices start at zero
v[1] = 99;
int last = v.back();             // requires nonempty vector
int n = static_cast<int>(v.size()); // explicit conversion to int
bool empty = v.empty();
```

`v[i]` has no bounds checking. Valid indices are `0` through `n - 1`; negative indices do not count from the end. `v.at(i)` checks bounds and throws on an invalid index.

`size()` uses an unsigned integer type. For LeetCode-sized arrays, converting the size to `int` makes index arithmetic easier:

```cpp
for (int i = static_cast<int>(v.size()) - 1; i >= 0; --i) {
    // safe reverse loop even if v is empty
}
```

Growing a vector may invalidate pointers, references, and iterators to its elements. Avoid appending to a vector while range-looping over that same vector.

### `string`: a mutable sequence of characters (`<string>`)

```cpp
string s = "cat";
s[0] = 'b';                      // "bat"
s += 's';                       // "bats"
s += "!";                       // "bats!"
string part = s.substr(1, 2);    // "at": start index, length
if (s.find("at") != string::npos) { /* found substring */ }
int number = stoi("123");       // valid numeric text -> integer
string text = to_string(123);    // integer -> text
```

Strings support `.size()`, `.empty()`, `.push_back()`, and `.pop_back()`. `==` compares string contents. Copying or taking a substring generally costs time proportional to the copied length. These character examples assume simple ASCII input.

### Fixed arrays and grids

```cpp
array<int, 26> freq{};           // <array>; exactly 26 zero-initialized integers
++freq['c' - 'a'];               // lowercase a–z -> indices 0–25

vector<vector<int>> grid(3, vector<int>(4, 0)); // 3 rows, 4 columns
grid[1][2] = 7;
for (int r = 0; r < static_cast<int>(grid.size()); ++r) {
    for (int c = 0; c < static_cast<int>(grid[r].size()); ++c) {
        // use grid[r][c]
    }
}
```

Check that a grid is nonempty before accessing `grid[0]`.

## 5. Hash tables: fast lookup and counting

### `unordered_map<K, V>`: key -> value (`<unordered_map>`)

Think Python `dict`. Keys are unique; values can repeat. Iteration order is not sorted or guaranteed.

```cpp
unordered_map<int, int> freq;
++freq[7];                       // missing key inserts value 0, then increments
freq[9] = 4;

auto it = freq.find(7);          // iterator: a position in the container
if (it != freq.end()) {          // end() is past-the-end, NOT a valid element
    int key = it->first;
    int value = it->second;
}

if (freq.count(9) != 0) { /* key exists */ }
freq.erase(9);
for (const auto& [key, value] : freq) { // C++17 structured binding
    // use key and value
}
```

**Trap:** `freq[key]` inserts a default value when the key is missing. Use `find` or `count` if you only want to check existence. `.count(key)` is 0 or 1 for these unique-key containers; it does not return a frequency you stored as the value.

### `unordered_set<T>`: membership only (`<unordered_set>`)

```cpp
unordered_set<int> seen;
seen.insert(3);
seen.insert(3);                  // still only one 3
bool exists = seen.count(3) != 0;
seen.erase(3);
```

Hash lookup, insertion, and removal are **average O(1)**, but worst-case O(n) per operation. `map` (`<map>`) and `set` (`<set>`) keep keys sorted and offer O(log n) lookup/insertion/removal. Use them when ordering or ordered bounds matter.

## 6. Stack, queue, deque, heap, and pairs

```cpp
stack<int> st;                   // <stack>; last in, first out
st.push(5);
int top = st.top();
st.pop();                       // removes; returns nothing

queue<int> q;                    // <queue>; first in, first out
q.push(5);
int front = q.front();
q.pop();                        // removes; returns nothing

deque<int> dq;                   // <deque>; efficient operations at both ends
dq.push_front(1);
dq.push_back(2);
dq.pop_front();

priority_queue<int> maxHeap;     // <queue>; largest value on top
maxHeap.push(10);
maxHeap.push(3);
int largest = maxHeap.top();     // 10
maxHeap.pop();

// <functional> declares greater<int>; smallest value on top
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(3);

pair<int, int> cell = {2, 4};     // <utility>; two values, possibly different types
int row = cell.first;
auto [r, c] = cell;              // unpack into two new variables
queue<pair<int, int>> cells;     // useful for grid BFS
cells.push({2, 4});
```

These containers have `.size()` and `.empty()`. Check nonemptiness before reading or removing an element. A heap's `top()` is O(1), while `push()` and `pop()` are O(log n).

| Need | Usually choose |
|---|---|
| Indexed sequence | `vector` |
| Character sequence | `string` |
| Value -> index/count/result | `unordered_map` |
| Track whether a value exists | `unordered_set` |
| Sorted keys or ordered bounds | `map` / `set` |
| Matching brackets, undo, monotonic stack | `stack` or `vector` used as a stack |
| Breadth-first search | `queue` |
| Add/remove at both ends | `deque` |
| Repeatedly get smallest/largest | `priority_queue` |

## 7. Algorithms, iterators, and lambdas

Most of these need `<algorithm>`; `accumulate` needs `<numeric>`.

```cpp
sort(v.begin(), v.end());                         // ascending, O(n log n)
sort(v.begin(), v.end(), greater<int>());          // descending; <functional>
reverse(v.begin(), v.end());                      // O(n)
int small = min(3, 7);
int big = max(3, 7);
long long total = accumulate(v.begin(), v.end(), 0LL);
// 0LL makes the running total long long; 0 would make it int

if (!v.empty()) {
    int biggest = *max_element(v.begin(), v.end()); // * reads iterator's element
}

sort(v.begin(), v.end());                         // required before binary search
auto it = lower_bound(v.begin(), v.end(), 7);      // first value >= 7, O(log n)
if (it != v.end() && *it == 7) {
    int index = static_cast<int>(it - v.begin());
}
```

An iterator refers to a position. `[begin(), end())` is a **half-open range**: includes the beginning, excludes the end. Never dereference `end()`. `&&` short-circuits, so the check above does not read `*it` when `it == v.end()`.

A lambda is a small function defined where you need it:

```cpp
vector<pair<int, int>> intervals = {{3, 8}, {1, 5}, {2, 4}};
sort(intervals.begin(), intervals.end(),
     [](const auto& a, const auto& b) {
         return a.second < b.second;              // order by ending value
     });
```

`[]` is the capture list; `[&]` allows access to surrounding local variables by reference, `[x]` captures a copy of `x`. A sort comparator must express strict ordering: use `<`, not `<=`. Default pair sorting compares `.first`, then breaks ties with `.second`.

## 8. Pointers, linked lists, trees, and recursion

A reference is an alias. A pointer stores an address and can be `nullptr` (“points to nothing”).

```cpp
int x = 5;
int* p = &x;                    // * declares pointer; & takes address
*p = 9;                        // * dereferences pointer; x is now 9
```

For linked-list problems, LeetCode commonly supplies a node like this:

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} // constructor initializes fields
};

int listLength(ListNode* head) {
    int length = 0;
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
        ++length;
    }
    return length;
}
```

`cur->val` accesses a field through a pointer; `node.val` accesses a field on an object. `cur->val` means `(*cur).val`. Never dereference `nullptr`. Copying a node pointer copies the address, not the whole list; moving `cur` leaves `head` unchanged, but changing `cur->val` changes the shared node.

Trees add `left` and `right` pointers. Recursion solves a smaller instance, with a base case to stop:

```cpp
struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0; // base case: empty tree
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

This visits n nodes in O(n) time and uses O(h) call-stack space for tree height h. Very deep recursion can overflow the call stack; an explicit stack is an alternative.

LeetCode normally supplies node definitions; do not duplicate them in submissions. `new ListNode(5)` creates a dynamically allocated node; ordinary C++ programs must manage its lifetime (often with smart pointers). For arrays and hash tables, prefer the standard containers so you do not need manual allocation.

Graphs are often represented as `vector<vector<int>> adj(n)`, where `adj[u]` lists neighbors of node `u`. For an undirected edge, add both `adj[u].push_back(v)` and `adj[v].push_back(u)`. Track visited nodes in graph traversal to avoid cycles.

## 9. Two Sum: put the pieces together

Your Python solution tries pairs one by one. That takes O(n²) time in the worst case: about `n * (n - 1) / 2` pairs.

Instead, when you see `x`, ask: **“Have I already seen `target - x`?”** Store each earlier value's index in a hash map.

Complete LeetCode submission:

```cpp
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // number -> earlier index

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int need = target - nums[i];
            auto it = seen.find(need);

            if (it != seen.end()) {
                return {it->second, i};
            }

            seen[nums[i]] = i;
        }

        return {}; // empty vector; unreachable under the problem's guarantee
    }
};
```

Read the syntax:

- `class Solution { ... };` defines the class LeetCode calls. Note the final semicolon.
- `public:` makes the method callable by the runner. Class members are private by default; struct members are public by default.
- `vector<int>` before `twoSum` is its return type.
- `vector<int>& nums` accepts the input without copying it.
- `seen.find(need)` returns an iterator; `it->second` is the stored index.
- `return {a, b};` constructs the returned vector with two indices.

Trace for `[3, 2, 4]`, target `6`:

| i | nums[i] | Need | Map before lookup | Action |
|---|---|---|---|---|
| 0 | 3 | 3 | `{}` | Store `3 -> 0` |
| 1 | 2 | 4 | `{3 -> 0}` | Store `2 -> 1` |
| 2 | 4 | 2 | `{3 -> 0, 2 -> 1}` | Return `[1, 2]` |

**Look up before inserting.** Every stored index is less than `i`, so you cannot reuse the current element. For `[3, 3]`, the second 3 finds the first 3's index and returns `[0, 1]`.

Average time: **O(n)**. Extra space: **O(n)**. Pathological hash collisions can make worst-case time O(n²). With these specific input bounds, `target - nums[i]` fits the usual 32-bit `int`; wider input bounds may require `long long` keys and arithmetic.

## 10. Patterns to learn next

Syntax lets you express a solution; recognizing a pattern helps you find it. These are useful beyond Two Sum.

| Pattern | Clue | Core idea |
|---|---|---|
| Hash lookup/counting | Duplicates, complements, frequencies | Remember what you have seen |
| Two pointers | Sorted pairs, palindrome, in-place filtering | Move indices while maintaining an invariant |
| Sliding window | Contiguous substring/subarray | Expand right, shrink left to restore a condition |
| Prefix sums | Repeated range sums | Precompute cumulative totals |
| Binary search | Sorted input or monotone yes/no condition | Discard half the search range |
| Stack | Nested brackets or next greater element | Keep unresolved items |
| BFS | Shortest path in an unweighted graph | Explore one distance layer at a time |
| DFS / backtracking | Trees, components, combinations | Explore branches; undo choices when needed |
| Heap | Top k or repeated min/max | Keep the next best candidate available |
| Dynamic programming | Repeated subproblems | Store answers and build larger answers |

Three small templates worth understanding:

```cpp
// Prefix sums: sum of nums[l..r) is prefix[r] - prefix[l]
int n = static_cast<int>(nums.size());
vector<long long> prefix(n + 1, 0);
for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
}
```

```cpp
// Binary search: first index with nums[index] >= target, in SORTED nums
int lo = 0, hi = static_cast<int>(nums.size());
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] < target) lo = mid + 1;
    else hi = mid;
}
// lo may equal nums.size(); check before indexing
```

```cpp
// BFS from start in an unweighted graph; adj is its adjacency list
vector<int> distance(adj.size(), -1);
queue<int> q;
distance[start] = 0;
q.push(start);
while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
        if (distance[v] != -1) continue;
        distance[v] = distance[u] + 1; // mark when enqueuing, avoiding duplicates
        q.push(v);
    }
}
```

Do not apply templates blindly. For example, sum-based shrinking windows often depend on nonnegative numbers; negative numbers can break the reasoning. Sorting a Two Sum array also loses original positions unless you preserve indices.

## 11. Complexity and common mistakes

| Operation | Typical cost |
|---|---|
| Vector indexing | O(1) |
| Vector append | Amortized O(1) |
| Vector insertion/removal in the middle | O(n) |
| Hash lookup | Average O(1) |
| Ordered map/set lookup | O(log n) |
| Binary search in sorted vector | O(log n) |
| Sorting | O(n log n) |
| Traversal of a graph | O(V + E) with adjacency lists |

“Amortized” averages over a sequence of operations: some vector appends trigger an O(n) reallocation. “Average” hash complexity depends on how keys distribute among buckets.

For n = 10,000, scanning once is 10,000 iterations; checking all pairs is roughly 50 million. Count total work, not just nested loops: in a sliding window, two pointers that each only advance n times still give O(n) total movement.

Before submitting, check:

- Did I use `==` for comparison, rather than `=`?
- Can an index reach `size()` or become negative?
- Am I calling `top`, `front`, `back`, or `pop` on an empty container?
- Did I accidentally insert a map entry with `map[key]`?
- Did I copy a large container unnecessarily?
- Could arithmetic overflow before assignment to `long long`?
- Did I preserve original indices if the problem asks for them?
- Does every loop progress, and every recursion have a base case?
- Have I considered duplicates, zeros, negatives, and the smallest valid input?

## 12. A short practice route

1. **Two Sum, Contains Duplicate, Valid Anagram** — vector, map, set, frequency arrays.
2. **Valid Palindrome, Move Zeroes, Best Time to Buy and Sell Stock** — scanning and pointer invariants.
3. **Binary Search, Search Insert Position** — half-open bounds.
4. **Valid Parentheses, Merge Two Sorted Lists, Reverse Linked List** — stack and pointers.
5. **Maximum Depth of Binary Tree, Binary Tree Level Order Traversal** — DFS and BFS.
6. **Longest Substring Without Repeating Characters, Number of Islands** — sliding window and graph traversal.
7. **Climbing Stairs, House Robber** — simple dynamic programming.

For each problem: describe a brute-force solution, identify repeated work, choose a data structure, state why the algorithm is correct, then code. Re-solve it without looking at your previous answer.

Your first exercise: hide section 9 and implement Two Sum from memory. Explain why the map stores indices, why lookup precedes insertion, and why duplicates still work.
