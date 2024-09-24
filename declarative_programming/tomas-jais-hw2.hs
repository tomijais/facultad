{-
- You must submit a single .hs file with the
  following name: firstName-lastName-hw2.hs.
  Failure to do so will result in -10 points.

- You will lose 10 points if you put a module statement
  at the top of the file.

- You will lose 10 points for any import statements you have
  in your file and will automatically miss any problems you used
  an imported function on.

- If your file doesn't compile you will lose 10 points and miss any
  problems that were causing the compilation errors.

- This means that any function which is causing compiler errors should
  be commented out. There will be no partial credit.

- You must use the skeleton file provided and must not alter any type
  signature. If you alter a type signature you will automatically miss
  that problem.

- You will lose 10 points if you include a main function in your file.
-}


-- Extra points if we implement this
-- https://en.wikipedia.org/wiki/AKS_primality_test

-- Problem 1: Perfect Numbers
-- Define 'perfects' function as described in the homework
-- perfects :: Int -> [Int]
perfects :: Int -> [Int]
perfects n = [i | i <- [1 .. n], i == sum (factors i)]

factors :: Int -> [Int]
factors n
  | n <= 0 = []
  | otherwise = [i | i <- [1 .. n - 1], n `mod` i == 0]

-- Problem 2: Scalar Product
-- Define 'scalarproduct' function as described in the homework
scalarproduct :: [Int] -> [Int] -> Int
scalarproduct x y
  | length x /= length y = 0
  | null x || null y = 0
  | otherwise = (head x * head y) + scalarproduct (tail x) (tail y)

-- Problem 3: Top N
-- Define 'topN' function as described in the homework
topN :: Int -> [(String, Int)] -> [String]
topN n x
  | null x = []
  | otherwise = [name | (name, quantity) <- x, quantity >= n]

-- Problem 4: Riffle
-- Define 'riffle' function as described in the homework
riffle :: [a] -> [a] -> [a]
riffle [] [] = []
riffle xs [] = xs
riffle [] ys = ys
riffle (x: xs) (y: ys) = x :  y : riffle xs ys

-- Problem 5: Library Functions
-- Define 'and', 'concat', 'replicate', '!!!', and 'elem' functions as described in the homework
and' :: [Bool] -> Bool
and' [] = True
and' (x:xs)= x && and' xs

concat' :: [[a]] -> [a]
concat' [] = []
concat' (x:xs) = x ++ concat' xs

replicate' :: Int -> a -> [a]
replicate' n x
  | n <= 0 = []
  | otherwise = x : replicate' (n-1) x

(!!!) :: [a] -> Int -> a
(!!!) x 0 = head x
(!!!) x n
  | n < 0 = error "index out of bounds"
  | otherwise = (!!!) (tail x) (n-1)


elem' :: (Eq a) => a -> [a] -> Bool
elem' a [] = False
elem' a (x:xs)
  | a == x = True
  | otherwise = elem' a xs

-- Problem 6: Iota Iota
-- Define 'iotaIota' function without using list comprehension
iotaIota :: Int -> [(Int, Int)]
iotaIota n
  | n <= 0 = []
  |otherwise = foldr (\x acc -> (map (\y -> (x, y)) [1..n]) ++ acc) [] [1..n]

-- Problem 7: Matrix Map
-- Define 'matrixMap' using the 'map' function
matrixMap :: (a -> b) -> [[a]] -> [[b]]
matrixMap func [] = []
matrixMap func xss = map (map func) xss

-- Problem 8: Merge
-- Define 'merge' function for merging two sorted lists
merge :: (Ord a) => [a] -> [a] -> [a]
merge [] [] = []
merge x [] = x
merge [] y = y
merge xss@(x:xs) yss@(y:ys) 
  | x <= y = x : merge xs yss
  | otherwise = y : merge xss ys

-- Problem 9: Merge Sort
-- Define 'msort' using 'merge', and first define 'halve'
msort :: (Ord a) => [a] -> [a]
msort [] = []
msort [x] = [x]
msort x = merge (msort (fst (halve x))) (msort (snd (halve x)))

halve :: [a] -> ([a], [a])
halve [] = ([],[])
halve x = (take (length x `div` 2) x,drop (length x `div` 2) x)

-- Problem 10: Goldbach
-- Define 'goldbach' that returns all unique prime pairs summing to an even number
goldbach :: Int -> [(Int, Int)]
goldbach n
    | n <= 2 = []
    | otherwise = [(p1, p2) | p1 <- [2..n], p2 <- [p1..n], p1 + p2 == n, isPrime p1, isPrime p2]


isPrime :: Int -> Bool
isPrime n = null (factors n)



-- EXTRA CREDITS ----------



-- AKS primality test: determines if a number n is prime
primeAKS :: Int -> Bool
primeAKS n
    | n <= 1 = False
    | n == 2 = True
    | any (\a -> gcdInt a n > 1 && gcdInt a n < n) [2..n-1] = False
    | otherwise = all (\a -> (modExp a n n) == a) [1..n-1]


    -- Calculate (n^k) mod m efficiently
modExp :: Int -> Int -> Int -> Int
modExp n k m
    | k == 0 = 1
    | k `mod` 2 == 0 = (modExp (n * n `mod` m) (k `div` 2) m) `mod` m
    | otherwise = (n * modExp n (k - 1) m) `mod` m

-- Compute the greatest common divisor (GCD) of two numbers
gcdInt :: Int -> Int -> Int
gcdInt 0 b = b
gcdInt a 0 = a
gcdInt a b = gcdInt b (a `mod` b) 