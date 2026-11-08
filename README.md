*This project has been created as part of the 42 curriculum by maltahay.*

# Push_swap

## Description
Push_swap is an algorithmic project designed to sort a set of integer values using two stacks (`a` and `b`) and a restricted set of stack manipulation instructions, generating the minimum possible number of operations.

The program calculates and outputs the optimal sequence of operations on standard output (`stdout`) to sort stack `a` in ascending order, with the smallest number at the top. It embeds four distinct sorting strategies, computes an initial **disorder metric** before executing any moves, and features an optional **benchmark mode** (`--bench`) that outputs detailed analytical metrics to standard error (`stderr`).

Additionally, a bonus **checker** utility is provided to verify the correctness of any sequence of operations read from standard input (`stdin`).

---

## Instructions

### Compilation
The project includes a Makefile adhering strictly to 42 standards with flags `-Wall -Wextra -Werror` using `cc`.

- Build `push_swap`:
  ```bash
  make
  ```
- Build bonus `checker`:
  ```bash
  make bonus
  ```
- Clean object files:
  ```bash
  make clean
  ```
- Full cleanup:
  ```bash
  make fclean
  ```
- Recompile:
  ```bash
  make re
  ```

### Execution

#### 1. Standard Sorting (Default Adaptive Strategy)
```bash
./push_swap 2 1 3 6 5 8
```
or with space-separated quoted string:
```bash
./push_swap "2 1 3 6 5 8"
```

#### 2. Strategy Selectors
You can explicitly force any of the four strategies:
- `--simple`: Forces the $O(n^2)$ selection/insertion sort baseline.
  ```bash
  ./push_swap --simple 5 4 3 2 1
  ```
- `--medium`: Forces the $O(n\sqrt{n})$ chunk-based sorting algorithm.
  ```bash
  ./push_swap --medium 4 67 3 87 23
  ```
- `--complex`: Forces the $O(n \log n)$ Bounce optimization algorithm.
  ```bash
  ./push_swap --complex 4 67 3 87 23
  ```
- `--adaptive`: Automatically selects the optimal strategy according to the measured disorder metric (default).
  ```bash
  ./push_swap --adaptive 4 67 3 87 23
  ```

#### 3. Benchmark Mode (`--bench`)
Displays disorder percentage, chosen strategy, theoretical complexity class, total operations count, and breakdown per operation to `stderr`:
```bash
./push_swap --bench --adaptive 4 67 3 87 23
```
Output:
```
ra
ra
pb
ra
ra
pb
rra
pa
pa
[bench] disorder:   40.00%
[bench] strategy:   Adaptive / O(n\sqrt{n})
[bench] total_ops:  9
[bench] sa:  0  sb:  0  ss:  0  pa: 2  pb: 2
[bench] ra: 4  rb: 0  rr:  0  rra:  1  rrb: 0  rrr:  0
```

#### 4. Verifying with Checker
Pipe the output of `push_swap` directly into `checker`:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Prints: OK
```

---

## Detailed Explanation and Justification of Algorithms

### 1. Disorder Metric
Disorder is computed strictly before performing any moves on stack `a`. It quantifies how far the initial array is from being sorted:
$$\text{disorder} = \frac{\text{mistakes}}{\text{total\_pairs}}$$
where $\text{total\_pairs} = \frac{n(n - 1)}{2}$, and a mistake is counted whenever $i < j$ and $a[i] > a[j]$.
- $\text{disorder} = 0.0$: stack is already perfectly sorted.
- $\text{disorder} = 1.0$: stack is in reverse order.
- Thresholds:
  - Low disorder ($< 0.20$): stack is nearly sorted.
  - Medium disorder ($0.20 \le \text{disorder} < 0.50$): stack has moderate inversions.
  - High disorder ($\ge 0.50$): stack has extensive disorder.

### 2. Simple Algorithm ($O(n^2)$)
- **Concept**: Selection sort adaptation.
- **Mechanism**: Iteratively locates the minimum element in stack `a`, calculates its distance from the top, performs the minimal number of rotations (`ra` or `rra`), pushes it to stack `b` (`pb`), sorts the remaining 3 elements in stack `a`, and pushes all elements back to `a` (`pa`).
- **Complexity**: For $n$ elements, each extraction requires $O(n)$ rotations, producing an upper bound of $O(n^2)$ Push_swap operations.
- **Justification**: Ideal baseline for small inputs or low-disorder profiles where minimal stack overhead is desired.

### 3. Medium Algorithm ($O(n\sqrt{n})$)
- **Concept**: Chunk-based / range-based partitioning.
- **Mechanism**:
  1. Assigns 0-based normalized index ranks ($0 \dots n-1$) to each element.
  2. Divides the index range into $\approx \sqrt{n}$ chunks with dynamic window sizing ($15$ for $n \le 100$, $32$ for $n > 100$).
  3. Pushes elements within the sliding index window from `a` to `b`: elements in the lower half of the window are pushed and rotated to the bottom of `b` (`pb` + `rb`), while upper half elements stay on top (`pb`), forming an hourglass distribution.
  4. Pushes back to `a` in strictly descending order from $n - 1$ down to 0 using the shortest rotation (`rb` vs `rrb`).
- **Complexity**: $O(n\sqrt{n})$ Push_swap operations.

### 4. Complex Algorithm ($O(n \log n)$) — The Bounce Algorithm
- **Concept**: Mechanical cost-evaluation and synchronized dual-stack rotation (Turk / Bounce algorithm).
- **Mechanism**:
  1. Pushes the first two elements from `a` to `b` to initialize stack `b`.
  2. For every remaining element in stack `a`, finds its exact target position in stack `b` (the closest smaller element in `b`, or the maximum element in `b` if none is smaller).
  3. Calculates the cost of rotating both stacks:
     - When both elements are above their stack's median, rotations are merged using `rr`.
     - When both elements are below their stack's median, rotations are merged using `rrr`.
     - Remaining single rotations are executed, followed by `pb`.
  4. Always selects the **cheapest node** to execute next (minimizing total moves greedily at each step).
  5. When 3 elements remain in stack `a`, sorts them optimally using `sort_three`.
  6. **Bounce Back**: Restores elements from `b` into `a` by finding each element's exact insertion spot in `a` (closest larger element, or minimum in `a`), rotating `a` minimally, and executing `pa`.
  7. Brings the minimum element of `a` to the top.
- **Performance Benchmark**:
  - **100 random integers**: $\approx 520 - 610$ operations (exceeds the 42 excellence threshold of $< 700$).
  - **500 random integers**: $\approx 4800 - 5250$ operations (exceeds the 42 excellence threshold of $< 5500$).

---

## Resources
- [Donald E. Knuth, The Art of Computer Programming, Volume 3: Sorting and Searching](https://www-cs-faculty.stanford.edu/~knuth/taocp.html)
- 42 Push_swap Subject v1.2 specification
- 42 Norm v2.0.1 coding standard documentation
- "The Turk / Bounce Algorithm" cost-optimization documentation

### AI Usage Disclosure
AI was utilized during this project for:
1. Architectural decomposition of operations and modules to adhere strictly to the 42 Norm (enforcing 5 functions per `.c` file and max 25 lines per function).
2. Derivation and verification of the mathematical disorder metric equation and dual rotation cost calculations.
3. Automated test script generation for validating operation boundaries on 100 and 500 permutations against evaluation checker binaries.
