# Solution Tutorial

## Key Insights

1. A cyclic shift of a string $s$ of length $n$ is obtained by choosing a start position $i$ $(1 \le i \le n)$ and forming $s[i..n] + s[1..i-1]$. 
   Let $T = s + s$ (concatenation). Then the cyclic shift starting at $i$ is exactly the length - $n$ substring $T[i..i+n-1]$.

2. If we choose $k$ cyclic shifts, their **Longest Common Prefix (LCP)** has length at least $L$ if and only if the first $L$ characters of all chosen shifts are identical.

3. Using $T = s + s$, the first $L$ characters of the shift starting at $i$ are exactly $T[i..i+L-1]$.

4. Therefore, there exists a choice of $k$ cyclic shifts with LCP at least $L$ if and only if there exists a length - $L$ substring among the substrings $t[i..i+L-1]$ for $1 \le i \le n$ that appears at least $k$ times.

5. The predicate “LCP at least $L$ is possible” is **monotonic**:  
   if it is possible for some $L$, then it is also possible for every $L' \le L$.  
   Hence, we can binary search the maximum feasible $L$.

6. To test feasibility for a given $L$, we must compare many substrings of `t` efficiently.  
   We use **double rolling hash**, so that each substring hash can be computed in $O(1)$ time, and equal hashes (under two moduli) indicate equal substrings with extremely high probability.

7. For a fixed $L$, compute the hash of each substring `t[i..i+L-1]` for $i = 1,2,\dots,n$, count frequencies, and check whether any hash count reaches $k$.


---

## Algorithm

1. Build $T = s + s$.

2. Precompute powers and inverse powers (for two moduli) to support normalized rolling hashes.

3. Build double prefix-hash arrays for $T$.

4. Define a feasibility check `ok(L)`:
   - For each $i = 1,2,\dots,n$, compute the (normalized) double-hash of $T[i..i+L-1]$.
   - Count occurrences of these hashes (e.g., using a hash table, or by sorting and scanning).
   - Return `true` if some hash occurs at least $k$ times; otherwise return `false`.

5. Binary search $L$ over $0 \le L \le n$:
   - If `ok(L)` is `true`, try larger $L$.
   - Otherwise, try smaller $L$.

---


## Complexity Analysis

- **Time Complexity:** typically $O(n \log n)$  
  Binary search performs $O(\log n)$ checks, and each check processes $n$ hashes (expected $O(n)$ with hashing, or $O(n \log n)$ if sorting is used).

- **Space Complexity:** $O(n)$  
  For prefix hashes and storing the $n$ substring hashes during a feasibility check.

---

## Edge Cases

1. **$k = 1$:**  
   Any single cyclic shift is valid, so the answer is $n$.

3. **No common prefix beyond $0$:**  
   If no character appears as the first character of at least $k$ shifts, the answer is $0$.

4. **Highly periodic strings:**  
   Duplicate cyclic shifts are handled naturally by frequency counting.

---

## Common Pitfalls

1. Forgetting to use $T = s + s$ (cyclic wrap-around is essential).
2. Off-by-one errors when extracting $T[i..i+L-1]$.
3. Using only one modulus (higher collision risk).
4. Forgetting that $L$ can be $0$ (always feasible).

---

## Alternate Solution (Suffix Array + LCP)

A deterministic alternative is to build a suffix array for $T = s + s$, keep only suffixes starting at positions $1..n$, and use the LCP array.  
The answer is the maximum, over all groups of $k$ such suffixes, of the minimum LCP within the group (can be done with a sliding window and RMQ).
