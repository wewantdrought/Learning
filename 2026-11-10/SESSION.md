# C++ Practice Session — November 10, 2026

## Context

This session includes both the lesson and its practice. Sections 1–4 of
`CPP_PRIMER.md` are today's lesson; stop before Section 5. The purpose of the
practice is to turn that syntax into working knowledge, so no hash tables or new
algorithms are required yet.

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

Not started yet. Update this section with the exercises completed, mistakes made,
and ideas that became clearer. Do not record an exercise as practiced merely
because its instructions were read.

## Questions and sticking points

- Add questions here as they arise.

## Where to pick up next session

1. Finish any unchecked exercises from this session.
2. Redo the hardest exercise once without referring to the earlier solution.
3. If all six exercises feel comfortable, begin Section 5 of the primer:
   hash tables and frequency maps.

