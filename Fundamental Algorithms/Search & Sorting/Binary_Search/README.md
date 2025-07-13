  # Binary Search Problems
  
  This folder contains binary search problems, including both classic and "binary search on the answer" (BSOA) patterns. Each file contains clean implementations of problems that utilize binary search to find optimal solutions.
  
  ## Topics Covered
  - Binary search on array
  - Binary search on the answer (integer range)
  - Lower/Upper bound tricks
  - Integration with LIS
  - Real-world modeling (recipes, factories, etc.)
  
  ---
  
  ### 📌 Binary Search on the Answer (BSOA)
  
  | File           | Codeforces Problem | Idea |
  |----------------|---------------------|------|
  | `Magic Powder-2.cpp`    | [670D2](https://codeforces.com/problemset/problem/670/D2) | Find max number of hamburgers we can produce given resources. Binary search on `m = number of hamburgers`. |
  | `Hamburgers.cpp`     | [371C](https://codeforces.com/problemset/problem/371/C) | Similar modeling to D2. Binary search on `m = number of sandwiches`. |
  | `Optical Experiment.cpp`      | [67D](https://codeforces.com/problemset/problem/67/D) | Transforming one array to another via LIS. Binary search used inside LIS function. |
  
  ---
  
  ## 🧠 Notes
  - `670D2.cpp` and `371C.cpp` are great examples of applying binary search on the *answer space* rather than a sorted array.
  - `67D.cpp` includes binary search via `lower_bound()` inside the LIS calculation, which is a classic optimization technique.
