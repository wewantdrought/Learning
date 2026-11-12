# C++ Learning Block — Created November 10, 2026

## Status

In progress. This block can continue across multiple days; its folder name is
the date it was created, not a deadline or a requirement to finish in one day.

## Context

This learning block includes both the lesson and its practice. Sections 1–4 of
`CPP_PRIMER.md` are in scope; stop before Section 5. The purpose of the practice
is to turn that syntax into working knowledge, so no hash tables or new
algorithms are required yet. Continue in this folder on later days until the
block is complete.

## Session files

- `../LEARNING_WORKFLOW.md` — master structure and persistent learning rules.
- `CPP_PRIMER.md` — lesson and reference material for today.
- `practice.cpp` — the program used to complete today's exercises.
- `run.sh` — learner-written compile-and-run shortcut for today's program.
- `SESSION.md` — goals, progress, reflections, and the next-session handoff.

## What I am trying to learn

- Write and run a complete C++17 program.
- Use variables, arithmetic, conditions, and loops without copying an example.
- Read and modify `vector<int>` values safely.
- Write small functions with appropriate parameters and return values.
- Treat a `string` as a sequence of characters.
- Map lowercase letters `a`–`z` to indices `0`–`25` with `letter - 'a'`.
- Explain why `long long` conversion must happen before a large calculation.
- Build and use a one-command compile-and-run script.

## What I have learned so far

- Basic types: `int`, `long long`, `double`, `bool`, `char`, and `string`.
- Output with `std::cout` and `\n`.
- `if`, `else`, `for`, `while`, `break`, and `continue`.
- Functions, return values, references, and `const` references.
- `vector`, `string`, fixed `array`, and two-dimensional vectors.
- `1LL * a * b` makes the multiplication use `long long` before overflow can
  occur; it does not numerically scale the result.
- For lowercase letters, `letter - 'a'` produces the corresponding array index.

## Structured practice path

The complete questions, restrictions, and success checks are comments in
`practice.cpp`. Build the entire program from scratch beneath those comments.

- [ ] Exercise 1 — output and a vector
- [ ] Exercise 2 — sum and floating-point average
- [ ] Exercise 3 — count even values
- [ ] Exercise 4 — find the largest value and explain `const` references
- [ ] Exercise 5 — reverse a string manually
- [ ] Exercise 6 — count lowercase-letter frequencies
- [ ] Assemble and test the complete program in `main()`
- [ ] Create `run.sh` so it compiles with C++17 warnings and runs only on success

## How to work

1. Predict the result before compiling.
2. Create `run.sh` in this directory. It must perform these two operations in one
   conditional command: compile `practice.cpp` with C++17 and warnings enabled,
   then run the output only if compilation succeeds.
3. Make it executable once:

   ```sh
   chmod +x run.sh
   ```

4. After each save, compile and run with `./run.sh`.
5. Fix one compiler error at a time, starting with the first.
6. After an exercise works, explain each line aloud or in a comment.
7. Check its box here and briefly note what was difficult.
8. Do not use starter code today: write the includes, `main()`, and every function.

## What I practiced

- Exercise 1 was attempted: wrote `printValues` and a `main()` that creates the
  sample vector and calls the function. The program compiled and printed the
  expected values. Initially the shell prompt's `%` appeared right after the
  output because there was no newline; this was a shell prompt, not program text.
- The exercise remains unchecked until I confirm I understand and consider it
  complete. Continue adding actual practice, mistakes, and discoveries here.
- I will make and push my own Git commits; use this record to track learning, not
  to imply that files have been committed.

## Questions and sticking points

- How to distinguish program output from the shell prompt when the program does
  not print a final newline.
- Add new questions here as they arise.

## Where to pick up next session

1. Review Exercise 1 and make sure I can explain its parameter, loop, spacing,
   and output before checking it off.
2. Continue with Exercise 2 in `practice.cpp`; do not rush to finish the whole
   learning block in one day.
3. Later, finish any remaining exercises and redo the hardest one without
   referring to a solution.
4. If all six exercises feel comfortable, begin Section 5 of the primer:
   hash tables and frequency maps.

