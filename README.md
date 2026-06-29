# C++ based DEBUG.EXE Emulator

A command-line C++ emulator that replicates the classic **DEBUG.EXE** tool from MS-DOS. It simulates a 64KB virtual memory space and a set of CPU registers, accepting the same single-character commands as the original tool.

---

## 📋 Features

- **Memory Dump** — View memory contents in hex + ASCII format
- **Memory Compare** — Compare two memory regions and report differences
- **Memory Enter** — Write a value to a specific memory address
- **Memory Fill** — Fill a range of memory addresses with a value
- **Memory Move** — Copy a block of memory to another location
- **Memory Search** — Search for a specific value within a memory range
- **Register View & Edit** — Display all CPU registers or inspect/update individual ones
- **Hex Arithmetic** — Compute sum and difference of two hex values

---

## ⌨️ Commands

| Command | Syntax | Description |
|---------|--------|-------------|
| `d` | `d [start] [end]` | Dump memory (hex + ASCII view) |
| `c` | `c point1 point2 start` | Compare two memory ranges |
| `e` | `e address value` | Enter (write) a value into memory |
| `f` | `f point1 point2 value` | Fill memory range with a value |
| `m` | `m point1 point2 start` | Move (copy) a memory block |
| `s` | `s start end value` | Search memory for a value |
| `r` | `r [register]` | View all registers or edit one |
| `h` | `h val1 val2` | Hex arithmetic (sum & difference) |
| `q` | `q` | Quit |

> All numeric values are entered and displayed in **hexadecimal**.

---

## 💡 Example Usage

```
-d 100 12F         # Dump memory from 0x100 to 0x12F
-e 200 FF          # Write 0xFF to address 0x200
-f 100 1FF 00      # Fill 0x100–0x1FF with zeros
-r ax              # View and edit the AX register
-h 1A2B 0C4D       # Compute 1A2B + 0C4D and 1A2B - 0C4D
-q                 # Quit
```

---

## 🧠 Registers Supported

`AX` `BX` `CX` `DX` `SI` `DI` `SP` `BP` `DS` `CS` `ES` `SS` `IP`

---
