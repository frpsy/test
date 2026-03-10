# CLAUDE.md

This file provides guidance to AI assistants working with this repository.

## Project Overview

**Name:** test
**Language:** C
**Platform:** Originally created on macOS
**Purpose:** Minimal/placeholder C project used for testing git workflows.

This is a bare-bones repository with a single empty C source file. It has no build system, dependencies, tests, or CI/CD pipeline configured.

## Repository Structure

```
/
├── test.c        # C source file (currently empty)
├── README.md     # Minimal project documentation
└── CLAUDE.md     # This file
```

## Git Workflow

### Branches

- `master` — main development branch
- `main` (remote) — remote main branch on origin
- Feature branches follow the pattern: `claude/<description>-<id>`

### Remote

The remote `origin` points to a local git proxy server:
```
http://local_proxy@127.0.0.1:36067/git/frpsy/test
```

### Making Changes

1. Work on the designated feature branch (never push directly to `master`/`main`)
2. Commit with clear, descriptive messages
3. Push with: `git push -u origin <branch-name>`

## Development Conventions

Since this is a C project, follow these conventions if adding code:

- Use standard C (C99 or C11) unless otherwise specified
- Keep source files in the root directory for this minimal project
- Compile with warnings enabled: `gcc -Wall -Wextra -o test test.c`

## Build

No build system is currently configured. To compile `test.c` manually:

```bash
gcc -Wall -Wextra -o test test.c
```

## Testing

No test framework is configured. For a project of this size, manual testing is sufficient.

## Linting & Formatting

No linters or formatters are configured. For C code, consider:
- `clang-format` for formatting
- `cppcheck` for static analysis

## Key Facts for AI Assistants

- This repository is intentionally minimal — avoid over-engineering
- The `test.c` file is empty; it serves as a placeholder
- There are no dependencies to install or services to start
- The working tree is clean by default; always verify before making changes
- When creating a feature branch, use the pattern: `claude/<description>-<session-id>`
