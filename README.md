# Homework 1 – Simple C-to-Assembly Transpiler

**Course:** Programming 2  
**Author:** Margarit Andrei — 315CD  
**Deadline:** Soft – April 6, 2025 · Hard – April 11, 2025

## Overview

This project implements a minimal **C-to-Assembly transpiler**, designed to translate simple C-like statements into x86-style assembly instructions. The goal is to understand how high-level language constructs map to low-level operations.

The transpiler supports arithmetic operations, logic, data movement, comparisons, and control flow structures including conditional statements and loops.

## ✅ Implemented Functionality

### 🟩 Basic Register Mapping

| Variable | Register |
|----------|----------|
| `a`      | `eax`    |
| `b`      | `ebx`    |
| `c`      | `ecx`    |
| `d`      | `edx`    |

---

### 📥 Data Movement: `MOV`
```c
a = 1;           // MOV eax, 1
b = a;           // MOV ebx, eax
```

---

### 🧠 Logical Operations: `AND`, `OR`, `XOR`
```c
a = a & 0xFF;    // AND eax, 0xFF
b = b | a;       // OR ebx, eax
c = a ^ c;       // XOR ecx, eax
```

---

### ➕ Arithmetic: `ADD`, `SUB`, `MUL`, `DIV`
```c
a = a + 5;       // ADD eax, 5
b = b - a;       // SUB ebx, eax

a = a * 3;       // MUL 3
b = b * c;       // MOV eax, ebx; MUL ecx; MOV ebx, eax

a = a / 3;       // MOV eax, a; XOR edx, edx; DIV 3; MOV a, eax
b = b / c;       // MOV eax, ebx; XOR edx, edx; DIV ecx; MOV ebx, eax
```

---

### 🧮 Bit Shifts: `SHL`, `SHR`
```c
a = a << 1;      // SHL eax, 1
b = b >> 2;      // SHR ebx, 2
```

---

### 🧾 Comparisons: `CMP` and Conditional Jumps
```c
if (a == b) {
    CMP eax, ebx
    JNE else_label
    ; ... code ...
    JMP end_if
else_label:
    ; ... else code ...
}
end_if:
```

---

### 🔁 Loops: `for`, `while`
```c
for (a = 0; a < 10; a++) {
    MOV eax, 0
start_loop:
    CMP eax, 10
    JGE end_loop
    ; ... loop body ...
    ADD eax, 1
    JMP start_loop
end_loop:
}
```

```c
while (b < 5) {
start_loop:
    CMP ebx, 5
    JGE end_loop
    ; ... loop body ...
    JMP start_loop
end_loop:
}
```

---

## 🧰 Project Structure

```
transpiler/             # Main implementation folder
├── src/                # Core transpiler logic
├── tests/              # Input/output test cases
├── Makefile            # Build system
├── transpiler          # Final executable
└── README.md           # This file
```

---

## 🚀 Build & Run

```bash
make            # Compile the transpiler
./transpiler    # Run the executable
```

---

## 🔍 Coding Style & Memory

- ✅ All checker tests passed
- ✅ Valgrind clean (no memory leaks)
- ✅ Coding style compliant (no errors, warnings or checks)

---

## 🧪 Checker Usage

- `C` – Run coding style checker
- `v` – Toggle Valgrind mode (must be ON)
- `make pack` – Creates submission ZIP

---

## 🧠 Notes

- Implemented entirely in `src/`
- All translation logic written in C
- The executable must be named `transpiler`
- Transpiler behaves like a source-to-source translator, not a full compiler

---

## 📎 Authors

Original Assignment: Robert Grancsa, Adelina Alexe  
This Implementation: Margarit Andrei – 315CD
