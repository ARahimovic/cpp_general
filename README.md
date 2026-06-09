# C++ General Projects

A collection of C++ projects focused on software design, OOP principles, systems programming, and C++ internals.
Each project demonstrates a different dimension of C++ expertise — from clean domain modelling and SOLID design to reimplementing standard library components from scratch.

Each project lives in its own folder with its own source, and where applicable, unit tests.

---

## 📂 Projects

### ✅ Done

---

#### [Bank Management System](BankManagement/)
A multi-class OOP system modelling a simplified banking backend.
`BankManager` acts as a facade coordinating two managers: `AccountManager` (owns all `BankAccount` instances with O(1) lookup by both ID and name via dual maps) and `TransactionManager` (processes deposits and withdrawals, maintains a full transaction log).
Demonstrates: facade pattern, separation of concerns, bidirectional map lookup, exception handling via a custom `BankException` hierarchy, and clean ownership semantics.

---

#### [Library Management System](LibraryManagement/)
A domain-modelling project built around two core entities — `Book` (title, author, publication year, total/available copies) and `User` (name, birth date, borrowed books list).
`BookManager` and `UserManager` handle their respective entities independently; `LibraryManager` coordinates the two for borrow and return operations, enforcing availability checks and keeping both sides in sync.
Demonstrates: multi-manager architecture, entity relationships, business rule enforcement, and exception-driven error handling (`BookException`).

---

#### [Custom STL — Vector & String](Custom_STL/)
Ground-up reimplementations of `std::vector` and `std::string` to understand C++ internals deeply.
`MyVector` implements the rule of five (copy constructor, move constructor, copy assignment, move assignment, destructor), dynamic resizing with capacity doubling, `push_back`, `insert`, `resize`, `reserve`, random access via `operator[]` and `at()`, and STL-compatible iterators (`begin`/`end`/`cbegin`/`cend`).
`MyString` covers similar ground for character buffer management.
Demonstrates: heap ownership, copy-swap idiom, move semantics, iterator design, and the mechanics behind `std::vector`'s amortized O(1) push.

---

### 🔨 Planned (in priority order)

---

#### [1. Shell Interpreter](shell_interpreter/)
A functional Unix shell built from scratch in C++.
Implements the full pipeline: input tokenization and command parsing, process creation via `fork`/`exec`, I/O redirection (`<`, `>`, `>>`), pipe chaining (`cmd1 | cmd2 | cmd3`), background processes (`&`), environment variable expansion, and a built-in command set (`cd`, `exit`, `export`, `echo`).
A second pass adds a command history buffer (navigable with arrow keys via raw terminal mode) and basic tab completion.
Demonstrates deep systems-level C++: file descriptors, process management, signal handling, and POSIX APIs — the kind of knowledge that underpins every daemon, build tool, and embedded Linux application.

---

#### [2. Custom STL — Containers & Algorithms (extension)](Custom_STL/)
Extend the existing `vector` and `string` with a full suite of containers and algorithms implemented from scratch.

**Containers:**
- `deque` — double-ended queue with O(1) push/pop on both ends, block-based internal storage
- `map` — ordered associative container backed by a red-black tree (insert, erase, find all O(log n))
- `unordered_map` — hash table with open addressing or chaining, configurable load factor and rehashing

**Algorithms:**
- Sorting: quicksort, mergesort, heapsort, insertion sort
- Searching: binary search, lower/upper bound
- Others: `transform`, `filter`, `reduce`, `partition`

Each container is templated and follows STL iterator conventions so it composes with standard algorithms.
Demonstrates: tree balancing, hashing, iterator categories, template metaprogramming, and the internals that `#include <map>` hides from you.

---

## 🛠 Build Instructions

Most projects use CMake:
```bash
mkdir build && cd build
cmake ..
make
```
