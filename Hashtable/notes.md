# Hashtables

Hashtables are an efficient data structure where you want to create a pair of Key/Value, where ``Key`` is the identifier of a given value, and ``Value`` is whatever data you want to store.

It's important to say that the ``Key`` doesn't necessaliry have to be an integer, but a string as well.

An example is hashing the value: "Hello" using the hashing function SHA-1. The result will always be ``f7ff9e8b7bb2e09b70935a5d785e0cc5d9d0abf0`` if no collisions interfer.

> Do note: a ``Key`` **is not** the same as the ``index`` of the array used to store data.

# Purpose

The hashtable's main purposes are:

- To give a quick access to a data given a specific **key**
- Possibly: reduce huge keys into smaller ones

# Applications

Many of it's usages are into cryptography and safety, but nothing impedes in using in other fields.

Git, for instance, use as a checker for each commit in a repository.

Programming languages use hash tables to generate symbolic tables between method names and other symbols. As an example, the C language uses during link stage among header files (.h) and C files (.c)

# Quick Big O Table

Generally, Hashtables offer an average of O(1) to all it's operation<sup>1</sup>

- Insert: O(1) amortized;
- Remove: O(1);
- Update: O(1);
- Search:
  - O(1) at average;
  - O(N) at worst;

<sup>1</sup> Collisions affect general performance due to how a hash function is based. The fewer collisions, the lesser extra processing and thus closer to O(1).

# Functionality

The overview of hashtable can be divided in three simple steps:

1. Get input data (our ``Value``);
2. Parse ``Value`` inside a Hash Function
3. Return the ``Key`` of the given ``Value``

However, the inner implementations vary from use case and need.

That means, different Hash Functions may be used focusing more on:

- Processing Performance
- Memory Performance
- Safety
- 

## Hash Function

The hash function is the core of the data structure. He basically takes any input (key), process, and returns an index to where it is storaged in memory.

## Storage

The storage is made using arrays, more commonly vectors (dynamic sized arrays).

For more details on Vectors, [see this note paper][Array Notes]

Since Hashtables can be based on Vectors, it's "size" is crucial to be calculated well to offer the best balance between collisions and memory usages.

The "size" is readjusted based on the *load factor*. 

## Dealing with Collisions



# Notes

1. Differently from other data structures, **Hashtables never care about order.**

# Questions Found

> Why use a Hashtable if Arrays can provide the same access Big-O notation in time processing?

Because, the main reason to use hashtables is that you **do not** have the index of wherever the data is stored, but rather the hash of it.

Second reason: Hashtables

# See also

[Wikipedia Hashtable](https://en.wikipedia.org/wiki/Hash_table);

[GNU Hashtable Resizing](https://www.gnu.org/software/mit-scheme/documentation/stable/mit-scheme-ref/Resizing-of-Hash-Tables.html#:~:text=Normally%2C%20hash%20tables%20automatically%20resize,which%20will%20be%20discussed%20below.);

[Meta F14 Hashtable](https://engineering.fb.com/2019/04/25/developer-tools/f14/)

[Array Notes]: ../Array/notes.md

