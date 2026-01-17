# Prime Number Game

## Description

Arpa and Alfeh are playing a game on an array `nums` of length \(n\).
Before the game starts, Arpa chooses a subset of indices
\[
S \subseteq \{1,2,\dots,n\}.
\]
The game is then played **only** on the elements with indices in \(S\).

In one move, a player:

1. chooses an index \(i \in S\),
2. chooses a prime \(p\) and an integer \(k>0\) such that
   \[
   p^k \mid \texttt{nums}[i],
   \]
3. replaces \(\texttt{nums}[i]\) with
   \[
   \texttt{nums}[i] / p^k.
   \]

Players alternate moves, and Arpa plays first.
The player who cannot make a move loses.
Both players play optimally.


Now the array changes over time. You are given \(q\) update queries.
Each query gives an index \(i\) and a value \(x\), meaning:
\[
\texttt{nums}[i] \leftarrow x.
\]

After **each** update, consider the game played on the **current** array `nums`.
Compute how many different **non-empty** subsets \(S\) Arpa can choose initially so that Arpa wins.
Since the answer can be large, print it modulo \(998244353\).

> Indices in queries are **1-based**.

## Input Format

Input is a JSON object with the following fields:

- `nums` (array of integers): the initial array of length \(n\).
- `queries` (array of arrays): each query is a pair \([i,x]\), meaning set \(\texttt{nums}[i]\leftarrow x\).

Example input:

```json
{
  "nums": [2, 4, 8],
  "queries": [
    [1, 16],
    [3, 1]
  ]
}
```

## Output Format

Output is a JSON value (type: array of integers):

- Output an array `ans` of length \(q\),
  where `ans[t]` is the number of **non-empty** subsets \(S\) such that Arpa wins **after applying the \(t\)-th update**,
  is taken modulo \(998244353\).

Example output:

```json
[7, 6]
```

## Constraints

- \(1 \le n \le 10^5\)
- \(1 \le q \le 10^5\)
- \(1 \le \texttt{nums}[i] \le 65535\)
- For each query \([i,x]\): \(1 \le i \le n\) and \(1 \le x \le 65535\)
- Time limit: \(1000\text{ms}\)
- Memory limit: \(256\text{MB}\)

## Examples

### Example 1

**Input:**

```json
{
  "nums": [2, 4, 8],
  "queries": [
    [1, 16],
    [3, 1]
  ]
}
```

**Output:**

```json
[7, 6]
```

**Explanation:**

- After update \([1,16]\), the array becomes \([16,4,8]\).
  There are \(7\) non-empty subsets \(S \subseteq \{1,2,3\}\) for which Arpa wins:
  \[
  \{1\},\{2\},\{3\},\{1,2\},\{1,3\},\{2,3\},\{1,2,3\}.
  \]

- After update \([3,1]\), the array becomes \([16,4,1]\).
  There are \(6\) non-empty subsets \(S \subseteq \{1,2,3\}\) for which Arpa wins:
  \[
  \{1\},\{2\},\{1,2\},\{1,3\},\{2,3\},\{1,2,3\}.
  \]
