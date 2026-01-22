# Kth Minimum Value

## Description

You are given an array `arr` of length $n$ consisting of integers.

You may perform at most one operation, defined as follows:

- Choose a contiguous subarray of `arr` whose length is at most `l`, and delete it from the array.

After performing the operation, let the remaining array be `b`.  

If the length of `b` is less than `k`, the resulting array is considered invalid.

The score of a valid array is defined as the $k$-th smallest element of `b` (using 1-based indexing).  

The score of an invalid array is defined to be $0$.

Your task is to determine the maximum possible score that can be obtained over all possible choices of the deleted subarray.

## Input Format

Input is a JSON object with the following fields:

- `arr` (array of integers): the input array
- `k` (integer): the index (1-based) of the smallest element whose value defines the score
- `l` (integer): the maximum allowed length of the deleted subarray

Example input:

```json
{
  "arr": [5, 1, 3, 2, 4],
  "k": 2,
  "l": 2
}
```

## Output Format

Output is a JSON value (type: integer):

- the maximum score obtainable over all valid choices of the deleted subarray (including the option of deleting nothing).

Example output:

```json
4
```

## Constraints

- $1 \le n \le 10^5$
- $1 \le k \le n$
- $0 \le l \le n$
- $1 \le \text{arr}[i] \le 10^9$
- Time limit: $4000$ ms
- Memory limit: $256$ MB

## Examples

### Example 1

**Input:**

```json
{
  "arr": [5, 1, 3, 2, 4],
  "k": 2,
  "l": 2
}
```

**Output:**

```json
4
```

**Explanation:**

One optimal choice is to delete the subarray $[2,3] = [1,3]$, leaving the array:

$[5,2,4]$

The sorted remaining array is:

$[2,4,5]$

whose $2$-nd smallest element is $4$.  
No other valid deletion yields a higher score.

### Example 2

**Input:**

```json
{
  "arr": [1, 2, 3],
  "k": 3,
  "l": 1
}
```

**Output:**

```json
3
```

**Explanation:**

Since the deletion is allowed for at most $l = 1$ element, it is also valid to delete nothing.

If no elements are deleted, the remaining array is $[1,2,3]$, whose $3$-rd smallest element is $3$.

If a subarray of length $1$ is deleted, the remaining array has only $2$ elements, which is fewer than $k = 3$, and such a case is considered invalid with score $0$.

Among all valid choices (including deleting nothing), the maximum possible score is $3$.

## Notes

- The array is considered 1-indexed when describing subarrays.
- The deletion operation is optional; deleting nothing is allowed.
- The answer should be computed using 64-bit integers.
