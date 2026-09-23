*This project has been created as part of the 42 curriculum by audgiova, andmarqu.*

# Push_swap

## Description
Push_swap is an algorithmic project designed to sort integer sequences using two stacks (`a` and `b`) and a restricted set of stack instructions. The program must generate the shortest possible sequence of operations while adhering to strict time and space complexity constraints .

The program measures the initial state of disorder in stack `a` to dynamically select the most efficient sorting strategy, or alternatively executes a strategy dictated by command-line flags .

---

## Instructions

### Compilation
Compile the project with the mandatory flags (`-Wall -Wextra -Werror`) using:
\`\`\`bash
make
\`\`\`
This builds the binary `push_swap` .

### Execution
Execute the binary followed by the list of integers to sort :
\`\`\`bash
./push_swap 3 2 1 6 5
\`\`\`

#### Command-Line Flags
- `--simple`: Forces the execution of the $O(n^2)$ algorithm .
- `--medium`: Forces the execution of the $O(n\sqrt{n})$ algorithm .
- `--complex`: Forces the execution of the $O(n \log n)$ algorithm .
- `--adaptive`: Evaluates the disorder metric at runtime and routes to the appropriate regime (default behavior) .
- `--bench`: Outputs detailed execution metrics to `stderr` .

Running with benchmark analysis:
\`\`\`bash
./push_swap --bench 4 67 3 87 23
\`\`\`

---

## Algorithms & Complexity Justifications

### 1. Disorder Metric
Disorder is measured before executing any stack operation by determining the ratio of inverted pairs relative to the total possible pairs :
$$\text{Disorder} = \frac{\text{mistakes}}{\text{total\_pairs}}$$
- A metric of `0.0` indicates an already sorted sequence .
- A metric of `1.0` indicates a reverse-sorted sequence .

### 2. Strategy Breakdown
- **Simple ($O(n^2)$)** :
  - *Method*: Baseline extraction sort . Identifies target extrema and pushes elements sequentially, suited for low permutation costs .
  - *Operation Complexity*: Generates at most $O(n^2)$ stack instructions .
- **Medium ($O(n\sqrt{n})$)** :
  - *Method*: Chunk-based partitioning using index ranges proportional to $\sqrt{n}$ . Elements are pushed to stack `b` within designated value windows to constrain rotation overhead .
  - *Operation Complexity*: $O(n\sqrt{n})$ generated instructions .
- **Complex ($O(n \log n)$)** :
  - *Method*: The **Turk algorithm** (`turk_cost.c`, `turk_move.c`). Computes the combined rotational distance (`rr`, `rrr`, single rotations) for every node in `a` to its target position in `b`, executing the lowest-cost move iteratively .
  - *Operation Complexity*: Efficiently bounds operations to an $O(n \log n)$ scaling profile .
- **Adaptive Strategy (Learner's Design)** :
  - **Low Disorder ($< 0.2$)**: Uses Simple sort, avoiding high overhead when very few inversions exist.
  - **Medium Disorder ($0.2 \le \text{disorder} < 0.5$)**: Uses Chunk-based sorting, balancing partitioning cost against element distribution.
  - **High Disorder ($\ge 0.5$)**: Uses the Turk algorithm to resolve complex entropy with minimal operations.

---

## Team Contributions

- **audgiova**: Implemented CLI parsing (`parse_args.c`), flag detection (`flags.c`), error handling and memory sanitization (`clean_exit.c`), and adaptive routing logic (`sort_adaptive.c`)
- **andmarqu**: Implemented the disorder calculation engine (`computing_disorder.c`), primitive stack operations (`push.c`, `swap.c`, `rotate.c`, `reverse_rotate.c`), indexing logic, and Turk algorithm mechanics (`turk_cost.c`, `turk_move.c`).

---

## Resources & AI Usage

- **References**:
  - 42 Push_swap Subject documentation (v1.1) .
  - Knuth, Donald. *The Art of Computer Programming, Volume 3: Sorting and Searching* .
  - Stack-based sorting and greedy cost heuristics (Turk Algorithm).
- **AI Usage**:
  - Formulating parsing control flow to decouple `--bench` flags from algorithm selector flags .
  - Refactoring safe node cleanup routines to prevent memory leaks and dangling pointer dereferencing during error cascades .