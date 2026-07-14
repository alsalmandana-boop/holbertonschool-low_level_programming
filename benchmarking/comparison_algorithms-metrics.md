# Algorithmic Efficiency Comparison

| Run | Naive Time (s) | Single-pass Time (s) |
|-----:|---------------:|---------------------:|
| 1 | 2.790649 | 0.000106 |
| 2 | 2.796735 | 0.000107 |
| 3 | 2.769804 | 0.000106 |

## Average Execution Time

- Naive algorithm: **2.785729 seconds**
- Single-pass algorithm: **0.000106333 seconds**

## Relative Difference

The naive implementation was approximately **26,198 times slower** than the single-pass implementation.

## Observation

The single-pass algorithm is significantly faster because it traverses the array only once, while the naive algorithm repeatedly scans elements using nested loops, resulting in much higher computational cost.
