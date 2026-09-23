*This project has been created as part of the 42 curriculum by andmarqu, audgiova.*

# 🔄 Push_swap - Because Swap_push doesn't feel as natural

[![42 São Paulo](https://img.shields.io/badge/42-SÃO%20PAULO-000000?style=for-the-badge)](https://www.42sp.org.br/)
![Language](https://img.shields.io/badge/LANGUAGE-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)

## 📝 Description
The **Push_swap** project is an algorithmic exercise focused on data sorting and computational complexity (Big-O notation). The goal is to sort a random list of integers on a stack using the lowest possible number of actions.

We are provided with two stacks:
* **Stack A**: Initially contains a random amount of negative and/or positive numbers without any duplicates.
* **Stack B**: Initially empty.

The objective is to sort the numbers in Stack A in ascending order. To do this, we are only allowed to use a strictly limited set of operations. 

### Available Operations
* **Push:**
  * `pa` (push a): Take the first element at the top of B and put it at the top of A.
  * `pb` (push b): Take the first element at the top of A and put it at the top of B.
* **Swap:**
  * `sa` (swap a): Swap the first two elements at the top of stack A.
  * `sb` (swap b): Swap the first two elements at the top of stack B.
  * `ss`: `sa` and `sb` at the same time.
* **Rotate:**
  * `ra` (rotate a): Shift up all elements of stack A by one (the first element becomes the last).
  * `rb` (rotate b): Shift up all elements of stack B by one.
  * `rr`: `ra` and `rb` at the same time.
* **Reverse Rotate:**
  * `rra` (reverse rotate a): Shift down all elements of stack A by one (the last element becomes the first).
  * `rrb` (reverse rotate b): Shift down all elements of stack B by one.
  * `rrr`: `rra` and `rrb` at the same time.

---

## ⚙️ Algorithms & Data Structure Justification

To handle different input sizes efficiently and strictly respect algorithmic complexity boundaries, this project implements a dynamic, multi-strategy approach. Before sorting, the program computes a **Disorder Metric** (a ratio between 0.0 and 1.0) by calculating the number of inverted pairs in the initial stack. Based on this metric, the program selects one of four strategies:

1. **Simple Algorithm $O(n^2)$**: 
   * **Target:** Low disorder (< 0.2) or very small inputs.
   * **Justification:** Baseline extraction sort . Identifies target extrema and pushes elements sequentially, suited for low permutation costs .

2. **Medium Algorithm $O(n\sqrt{n})$**:
   * **Target:** Medium disorder (0.2 ≤ disorder < 0.5).
   * **Justification:** A chunk-based partitioning method is used. The stack is divided into $\sqrt{n}$ chunks, pushing elements to Stack B in ranges before pushing them back in order. This balances execution time and operation count without the deep recursion depth of pure divide-and-conquer strategies.

3. **Complex Algorithm $O(n \log n)$**: 
   * **Target:** High disorder (≥ 0.5) and large inputs.
   * **Justification:** Implements the **Turk Algorithm** (a greedy cost-optimized insertion strategy). For every element, the algorithm calculates the exact cheapest cost of combined rotations (`rr`, `rrr`, simple rotates) to place it into its sorted target position across stacks. By continuously choosing the lowest-cost move, it guarantees optimal operation efficiency and comfortably satisfies the project limits (e.g., well under 5500 operations for 500 numbers).

4. **Adaptive Algorithm**: 
   * **Justification:** Acts as the default routing controller. It calculates the disorder metric at runtime and automatically routes the input to the most optimal strategy above, ensuring the absolute lowest operation count possible for any given stack configuration.

---

## 🛠️ Instructions

### Compilation
The project is compiled using the provided `Makefile`. It builds the binary with strict flags (`-Wall -Wextra -Werror`):

* `make` or `make all`: Compiles the `push_swap` binary.
* `make clean`: Removes intermediate object files in `obj/`.
* `make fclean`: Removes object files and the `push_swap` executable.
* `make re`: Performs a complete rebuild.

### Execution
Run the program by passing a list of integers. By default, it runs the **Adaptive** strategy:

```bash
./push_swap 2 1 3 6 5 8

```

**Optional Strategy Flags:**
You can force a specific algorithm by passing one of the following flags anywhere in the argument list:

* `--simple`: Forces the $O(n^2)$ algorithm.
* `--medium`: Forces the $O(n\sqrt{n})$ chunk-based algorithm.
* `--complex`: Forces the $O(n \log n)$ Turk algorithm.
* `--adaptive`: Default automatic routing based on disorder metric.

**Benchmark Mode:**
Use the `--bench` flag to print execution metrics (Disorder %, selected strategy, and operation count breakdown) to `stderr`:

```bash
./push_swap --bench --adaptive 4 67 3 87 23

```

**Validating with the Official Checker:**
Pipe the standard output into the 42 checker binary to verify sorting correctness (bench metrics on `stderr` will not disrupt the pipeline):

```bash
ARG="4 67 3 87 23"; ./push_swap --bench $ARG \vert{} ./checker_linux$ARG

```
---

## Team Contributions

- **audgiova**: Implemented CLI parsing (`parse_args.c`), flag detection (`flags.c`), error handling and memory sanitization (`clean_exit.c`), and adaptive routing logic (`sort_adaptive.c`)
- **andmarqu**: Implemented the disorder calculation engine (`computing_disorder.c`), primitive stack operations (`push.c`, `swap.c`, `rotate.c`, `reverse_rotate.c`), indexing logic, and Turk algorithm mechanics (`turk_cost.c`, `turk_move.c`).

---

## 🧠 Resources

* **Algorithmic Complexity:** "Introduction to Algorithms" by Thomas H. Cormen (Big-O notation fundamentals).


* **AI Usage:** In alignment with the 42 curriculum guidelines regarding foundational learning, AI was used solely as a structural documentation assistant. AI tools were not queried for direct code answers or logic solutions. Reasoning and peer-learning were the primary drivers for project completion, ensuring genuine intellectual effort.