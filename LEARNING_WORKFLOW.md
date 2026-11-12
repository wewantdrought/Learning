# Master Learning Workflow

## Purpose

This document defines the overall learning system. It is the source of truth for
how learning sessions are organized and conducted. When the workflow changes,
update this file so it reflects the latest agreed structure instead of leaving
the change only in one daily session.

The goal is active learning: understand a small amount of material, build with it
from scratch, reflect on mistakes, and leave a clear starting point for the next
session.

## Directory structure

Each session gets one date-based directory under `learning`:

```text
learning/
├── LEARNING_WORKFLOW.md
└── YYYY-MM-DD/
    ├── SESSION.md
    ├── practice.cpp
    ├── run.sh
    └── lesson or reference files
```

All material specific to a session belongs in that session's directory. Lessons
and practice are not split into separate top-level folders.

## Required session files

### `SESSION.md`

The learning record and handoff document. It contains:

1. Context for the session.
2. What I am trying to learn.
3. What I have learned.
4. A short ordered practice checklist.
5. What I actually practiced.
6. Questions, mistakes, and sticking points.
7. Where to pick up next session.

Do not claim that something was practiced merely because it was read. Record
completed work and actual observations honestly.

### `practice.cpp`

The canonical home for the complete practice questions. Every programming
question assigned for a session must appear directly in this file as comments,
including requirements, restrictions, and expected output. The short checklist
in `SESSION.md` may refer to the exercises, but the full prompts belong here.

Each question must be followed immediately by its own clearly marked answer area.
Do not put all questions at the top and one shared workspace at the bottom. Design
the file so the learner can read a requirement and write its code directly below
it without scrolling back to recover the prompt. When several exercises form one
program, prefer one function-sized answer per question and put the `main()` runner
prompt after those functions.

Unless a future session explicitly chooses a different form of practice, the
file must not contain starter solution code. The learner writes everything from
scratch, including:

- `#include` directives;
- namespace choices or `std::` prefixes;
- function declarations and definitions;
- `main()`;
- variables, containers, loops, and conditions;
- calls that test the solution.

Comments containing the questions are allowed and should remain in the file.

### `run.sh`

The daily compile-and-run shortcut. It must compile `practice.cpp` as C++17 with
warnings enabled and run the resulting program only if compilation succeeds.
This keeps the feedback loop to save, run one command, and inspect the output.

The learner writes the first runner from scratch as part of learning the local
workflow. Later session folders may copy the established runner unless changing
or understanding the script is itself a learning goal.

### Lesson and reference files

Reading material used that day belongs beside `SESSION.md` and `practice.cpp`.
The session record must state which sections are in scope and where to stop.

## Session cycle

### 1. Orient

- Read the previous session's “Where to pick up next session.”
- Identify unfinished exercises and unresolved questions.
- Define a small, realistic learning target.

### 2. Learn

- Read only the material needed for the current target.
- Ask questions when a concept is unclear.
- Add useful explanations to the day's lesson or session notes.
- Stop adding new material when cognitive load becomes too high.

### 3. Practice from scratch

- Open `practice.cpp` and work through its questions in order.
- Begin with a blank implementation beneath the prompt comments.
- Predict behavior before compiling.
- Compile after small changes with warnings enabled.
- Fix the first compiler error first.
- Use the lesson as a reference, but do not copy a complete solution.
- Be able to explain each completed line.

Run the daily shortcut with:

```sh
./run.sh
```

If the script is not executable yet, make it executable once with
`chmod +x run.sh`. The script must use conditional command chaining so a failed
compile never runs an older executable.

### 4. Verify

- Compare the program's output with each question's success check.
- Test at least one additional input when appropriate.
- Mark an exercise complete only after it compiles, runs, and can be explained.

### 5. Reflect and hand off

- Update “What I practiced” with completed work and discoveries.
- Record mistakes and unresolved questions.
- Update the checklist truthfully.
- Write a precise next-session starting point.

## Current learning principles

- Prefer building over passively rereading.
- Practice new ideas in small, ordered steps.
- Build C++ programs from scratch to learn the full program structure.
- Keep lesson, practice, and reflection together by session date.
- Put every complete practice prompt in `practice.cpp`.
- Put a writing area immediately below every practice prompt.
- Keep a `run.sh` compile-and-run shortcut in every C++ session directory.
- Do not introduce advanced material merely to make an exercise shorter.
- Treat compiler errors as feedback and resolve them one at a time.
- Update this master document whenever the workflow changes.

## How to evolve this workflow

New preferences raised during later sessions should be applied at two levels:

1. Update the affected daily session files.
2. Update this master document when the preference is intended to persist.

Session-specific exceptions should stay in that session's `SESSION.md` and should
not silently replace the general rule.

