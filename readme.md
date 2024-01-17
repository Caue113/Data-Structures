# Study of Data Structures

This repo is a self study with a collection of different data structures, their implementation and use cases.

Sometimes implementations may vary because of experimentation and note taking, meaning they aren't standardized.

It's also part of the "Computer Science Roadmap" at [Roadmap.sh](https://roadmap.sh/computer-science)

# Navigating this repo

The repo is divided in many folders containing their respective data structure.

Inside them, different files will be found, such as:
- C files. For low level studies
- Js files. For high level studies
- Markdown notes.

# To do
- [ ] Array
- [x] Vector (Dynamic Array)
- [x] Linked List
- [ ] Stack
- [ ] Queue
- [ ] HashTable
- [ ] Tree
  - [ ] Binary Tree
- [ ] Graph
- [ ] Heap

# Tests

## C Files

With C files ``(.c)`` you'll need a compiler to compile it as an executable (``.exe``). This is to prevent any kind of issues with .exe programs. The one I used is GCC.

To edit and test yourself, do the following:

1. Change directory to the desired data structure

```bash
cd ./folder
```

2. Compile the C file with GCC
```bash
gcc filename.c -o output.exe
```

3. Run the file

```bash
./output.exe
```

## JS Files (WIP)
JavaScript files can run directly on Node.js enviroment.

To test JS files, you can run the test file directly

```bash
cd folder
node ./data-structure.test.js
```