You are given an array `arr` of length $n$ consisting of integers.
You are also given $q$ queries.  
Each query specifies a subarray by two indices $l$ and $r$ $(1 \le l \le r \le n)$.

For each query, consider the subarray:

$$
\text{arr}[l..r]
$$

Let:

$$
x = \min(\text{arr}[l..r])
$$


$$
y = \max(\text{arr}[l..r]).
$$

The multiset of elements in `arr[l..r]` is said to form a **contiguous section** if and only if every integer from $x$ to $y$ appears **exactly once** in the subarray.

Formally, the subarray `arr[l..r]` is **valid** if:

- The number of elements in the subarray is exactly $y - x + 1$

- For every integer $v$ such that $x \le v \le y$
the value $v$ appears **exactly once** in `arr[l..r]`.

For each query, determine whether the given subarray forms a **contiguous section**.

## Input Format
The input is a JSON object with the following fields:

- `arr` (array of integers): the input array of length $n$.

- `queries` (array of arrays): each query is a pair `[l, r]` specifying a subarray  
  (1-based indices).

Let: $n = \text{len(arr)}$ and $q = \text{len(queries)}$
