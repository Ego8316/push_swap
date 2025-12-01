<p align="center">
  <img src="https://github.com/Ego8316/Ego8316/blob/main/42-badges/push_swap.png" height="150" alt="42 push_swap Badge"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/42-Project-blue" height="32"/>
  <img src="https://img.shields.io/github/languages/code-size/Ego8316/push_swap?color=5BCFFF" height="32"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Linux-0a97f5?style=for-the-badge&logo=linux&logoColor=white" height="32"/>
  <img src="https://img.shields.io/badge/WSL-0a97f5?style=for-the-badge&logo=linux&logoColor=white" height="32"/>
</p>

# push_swap

### 🎓 42 School – Final Grade: **125/100**

Stack-based sorting challenge: given a list of integers, output the shortest possible sequence of stack operations (`sa`, `pb`, `rra`, …) that sorts them. The program must reject invalid inputs (duplicates, non-ints) and exit with a colored error message.

The bonus adds a `checker` program that reads operations from stdin, applies them to the input stacks, and reports `OK` or `KO`.

---

## 📦 Features
- Validates input: rejects duplicates, overflows, and malformed integers.
- Core program `push_swap` prints the sequence of moves only (no extra text).
- Supports the full operation set: swaps, pushes, rotations, and reverse rotations.
- Small-size specialization (3–5 elements) for optimal micro-sorting.
- Bonus `checker` to replay instructions and verify the final order.

---

## 🧠 Algorithm
- **Ranking**: Each value is mapped to a rank to operate on relative order only.
- **Chunked push**: Elements are pushed from A to B in rank-based batches (chunk size tuned by the `chunk` parameter).
- **Cost model**: For every node in B, the algorithm computes the combined rotation cost (`cost_a`, `cost_b`) and overlaps rotations when both stacks move in the same direction.
- **Greedy selection**: Always move the element with the lowest weighted cost back to A.
- **Finishing move**: Rotate A to bring the smallest rank to the top.

Typical performance (random data):
- ~530 moves for `n = 100`
- ~4200 moves for `n = 500`

---

## 🛠️ Building
```bash
make            # build push_swap
make bonus      # build push_swap and checker
make clean      # remove object files
make fclean     # remove objects and binaries
```

---

## 🚀 Usage
```bash
./push_swap 2 1 3 6 5 8
./push_swap 3 2 1 | ./checker_linux 3 2 1   # using the 42 checker
```

Bonus checker alone:
```bash
./checker 3 2 1 < instructions.txt
```

---

## ✅ Testing
- `make tests` to run multiple push_swap scenarios (requires `checker_linux` or `checker_mac` from 42, placed in the repo root as `checker_$(OS)`).
- `make btests` for the bonus checker vs. the official 42 checker; outputs diffs and runs valgrind logs.
- `norminette` for style compliance.

---

## 📄 License
MIT License — see `LICENSE` for details.
