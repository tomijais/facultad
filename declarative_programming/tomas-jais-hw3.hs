{-
Submission rules:

- All text answers must be given in Haskell comment
  underneath the problem header.

- You must submit a single .hs file with the
  following name: firstName-lastName-hw3.hs.
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

- You will lose 10 points if you include a *main* function in your file.
-}


-- Problem 1

curry' :: ((a, b) -> c) -> a -> b -> c
curry' f x y = f (x, y)

uncurry' :: (a -> b -> c) -> (a, b) -> c
uncurry' f (x, y) = f x y

-- Problem 2
chop8 :: [a] -> [[a]]
chop8 = unfold null (take 8) (drop 8)

map' :: (a -> b) -> [a] -> [b]
map' f = unfold null (f . head) tail

iterate' :: (a -> a) -> a -> [a]
iterate' = unfold (const False) id

unfold :: (b -> Bool) -> (b -> a) -> (b -> b) -> b -> [a]
unfold p h t x
  | p x = []
  | otherwise = h x : unfold p h t (t x)


-- Problem 3
concatER :: [[a]] -> [a]
concatER [] = []
concatER (xs:xss) = xs ++ concatER xss


concatFR :: [[a]] -> [a]
concatFR = foldr (++) []

concatFL :: [[a]] -> [a]
concatFL = foldl (++) []


-- Problem 4
disjunction2 :: (a -> Bool) -> (a -> Bool) -> a -> Bool
disjunction2 p1 p2 x = p1 x || p2 x


-- Problem 5
disjunction :: [a -> Bool] -> a -> Bool
disjunction ps x = foldr (\a b -> a x || b) False ps

-- Problem 6
deleteDupes :: Eq a => [a] -> [a]
deleteDupes = foldr go []
  where
    go x recur = x : filter (/= x) recur


-- Problem 7
tally :: (a -> Bool) -> [a] -> Int
tally p = foldl (\count x -> if p x then count + 1 else count) 0

-- Problem 8
bangBang :: [a] -> Int -> a
bangBang xs n = snd $ foldr (\(i, x) (index, result) -> if index == i then (-1, x) else (index, result)) (n, head xs) (zip [0..] xs)

-- Problem 9
increasing :: Ord a => [a] -> Bool
increasing xs = foldr (\(a, b) c -> (a <= b) && c) True (zip xs (tail xs))

-- Problem 10
decimate :: [a] -> [a]
decimate xs = foldl (\b (a, c) -> if mod c 10 /= 0 then b ++ [a] else b) [] (zip xs [1..])

-- Problem 11
encipher :: Eq a => [a] -> [b] -> [a] -> [b]
encipher xs ys = map (\x -> snd (head (filter (\a -> fst a == x) (zip xs ys))))

-- Problem 12
prefixSum :: Num a => [a] -> [a]
prefixSum xs = tail (foldl (\b a -> b ++ [a + last b]) [0] xs)

-- Problem 13
minesweeper :: [String] -> [String]
minesweeper grid = [ [ getCellValue x y | x <- [0..length (head grid) - 1] ] | y <- [0..length grid - 1] ]
  where
    getCellValue :: Int -> Int -> Char
    getCellValue x y
      | grid !! y !! x == '*' = '*'  -- If it's a mine, return '*'
      | otherwise = let count = countMines x y in if count == 0 then '.' else intToDigit count

    countMines :: Int -> Int -> Int
    countMines x y = length [() | dx <- [-1..1], dy <- [-1..1], isMine (x + dx) (y + dy), not (dx == 0 && dy == 0)]

    isMine :: Int -> Int -> Bool
    isMine x y = x >= 0 && y >= 0 && y < length grid && x < length (head grid) && (grid !! y !! x) == '*'


-- Helper function provided
intToDigit :: Int -> Char
intToDigit 0 = '0'
intToDigit 1 = '1'
intToDigit 2 = '2'
intToDigit 3 = '3'
intToDigit 4 = '4'
intToDigit 5 = '5'
intToDigit 6 = '6'
intToDigit 7 = '7'
intToDigit 8 = '8'
intToDigit 9 = '9'
