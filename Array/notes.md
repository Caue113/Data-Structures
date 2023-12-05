# Vectors

References on implementation and concepts from [https://github.com/jwasham/coding-interview-university#data-structures](this github repo).

Dynamic Arrays are useful and pretty much used in many higher level languages such as Java and C# ArrayList (or just List), Javascript and PHP - builtin array.

Their concept revolves around reallocating the current array into a new one that may fit our new capacity need.

Both increasing and decreasing capacity must be taken into account to provide enough memory to array as well as free unused memory.


Be watchful! On other contexts, vectors may aquire other meanings, such as shader programming or game development. Both heavily dependent on mathematics into matrices.

# Insert

# Possibly multiple inserts
It's possible we want to quickly insert many values at the same time. While accessing our resize function often is straightfoward, it may not be the most performatic.

Successive resizes costs O(n) each. That includes big jumps of insertion or deletion.

From a small Vector of capacity 8 to add 180 entries, it would take capacity to 256, or 5 resizes in sequence.

Predicting the next power of 2 (or other increasing ratio) for the ammount of insertions can low it to a single resize call.

