# Parity Cuts Game

## Description
Alice and Bob play a game on a string `s` of length $n$ consisting of:
- `.` : a token
- `#` : a wall

A segment is a maximal contiguous block of `.` characters. (So a segment is a substring `s[l..r]` such that every `s[i]='.'` for $l \le i \le r$, and either $l=1$ or `s[l-1]='#'`, and either $r=n$ or `s[r+1]='#'`.)

Alice moves first. Players alternate turns.

### Move

On your turn:

1. Pick any current segment of dots. Suppose this segment has length $L$.
2. Number the tokens inside that segment from left to right as $1, 2, \ldots, L$.
3. Choose an integer $k$ with $1 \le k \le L$ and perform exactly one of the following:
   - If $k$ is odd: remove only token $k$.
   - If $k$ is even: remove tokens $k$ and $k+1$ together. This move is legal only if $k < L$ (so token $k+1$ exists).

"Removing" a token means that position becomes a wall: `.` turns into `#`. After the removal, the chosen segment may shrink or split into up to two new segments.

If a player has no legal move on their turn, they lose.

### Updates

You are given $q$ update queries. Each query provides an index $p$ (1-based) and toggles `s[p]`:
- `.` becomes `#`
- `#` becomes `.`

After each toggle, assume the game starts fresh from the updated string with Alice to move first. For each query, output the winner (`"Alice"` or `"Bob"`) under optimal play.

## Input Format

Input is a JSON object with the following fields:

- `s` (string): the initial string of length $n$, containing only `.` and `#`.
- `queries` (array of integers): each query is a single integer $p$ (1-based), meaning toggle `s[p]`.

Let:
- $n = \texttt{len(s)}$
- $q = \texttt{len(queries)}$

Example input:
```json
{
  "s": "#..#....",
  "queries": [2, 4, 5, 8]
}
```

## Output Format

Output is a JSON value (type: array of strings):

- Output an array `ans` of length $q$, where `ans[t]` is `"Alice"` or `"Bob"` — the winner after applying the $t$-th toggle.

Example output:
```json
["Alice", "Bob", "Alice", "Bob"]
```

## Constraints

- $1 \le n \le 6000$
- $1 \le q \le 200000$
- `s[i]` $\in$ `{'.', '#'}`
- For each query $p$: $1 \le p \le n$

## Examples

### Example 1

**Input:**
```json
{
  "s": "#..#....",
  "queries": [2, 4, 5, 8]
}
```

**Output:**
```json
["Alice", "Bob", "Alice", "Bob"]
```
