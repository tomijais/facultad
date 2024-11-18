{-
Submission rules:

- All text answers must be given in Haskell comment
  underneath the problem header.

- You must submit a single .hs file with the
  following name: firstName-lastName-hw4.hs.
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

-- Problem 1 (Exercise 8.1)

data Nat = Zero | Succ Nat
    deriving (Eq, Show)

nat2Int :: Nat -> Int
nat2Int Zero     = 0
nat2Int (Succ n) = 1 + nat2Int n

int2Nat :: Int -> Nat
int2Nat 0 = Zero
int2Nat n = Succ (int2Nat (n - 1))

add :: Nat -> Nat -> Nat
add Zero n2      = n2
add (Succ n1) n2 = Succ (add n1 n2)

mult :: Nat -> Nat -> Nat
mult Zero n2 = Zero
mult (Succ n1) n2 = add n2 (mult n1 n2)

-- Tests

-- >>> mult Zero (Succ Zero)
-- Zero

-- >>> mult (Succ (Succ Zero)) (Succ (Succ (Succ Zero)))
-- Succ (Succ (Succ (Succ (Succ (Succ Zero)))))

-- >>> mult (Succ (Succ (Succ Zero))) (Succ (Succ (Succ Zero)))
-- Prelude.undefined

-- The actual response is:
-- Succ (Succ (Succ (Succ (Succ (Succ (Succ (Succ (Succ Zero))))))))




-- Problem 2 (Exercise 8.3)

data Tree a = Leaf a | Node (Tree a) (Tree a)
    deriving (Eq, Show)


countLeaves :: Tree a-> Int
countLeaves (Leaf a) = 1
countLeaves (Node l r) = countLeaves l + countLeaves r

balanced :: Tree a -> Bool
balanced (Node l r)= abs diff >= 1
  where
      diff = countLeaves l - countLeaves r

-- Tests

-- >>> balanced (Node (Node (Leaf 1) (Leaf 2)) (Node (Leaf 3) (Node (Leaf 4) (Leaf 5))))
-- True

-- >>> balanced (Node (Node (Node (Leaf 1) (Leaf 1)) (Leaf 2)) (Node (Leaf 3) (Node (Leaf 4) (Leaf 5))))
-- True

-- >>> balanced (Node (Node (Node (Node (Leaf 1) (Leaf 1)) (Leaf 1)) (Leaf 2)) (Node (Leaf 3) (Node (Leaf 4) (Leaf 5))))
-- False

-- Problem 3 (Exercise 8.4) 


divideList :: [a] -> ([a], [a])
divideList [] = ([], [])
divideList xs = (firstHalf, lastHalf)
  where
    half = length xs `div` 2
    firstHalf = take half xs
    lastHalf = drop half xs



balance :: [a] -> Tree a
balance [] = undefined
balance [x] = Leaf x
balance xs = Node (balance l) (balance r)
  where
      (l, r) = divideList xs

-- Tests

-- >>> balance [1,2,3,4,5]
-- Node (Node (Leaf 1) (Leaf 2)) (Node (Leaf 3) (Node (Leaf 4) (Leaf 5)))

-- Problem 4 (Exercise 8.5)

data Expr = Val Int | Add Expr Expr

folde :: (Int -> a) -> (a -> a -> a) -> Expr -> a
folde f g (Val x) = f x
folde f g (Add x y) = g (folde f g x) (folde f g y)

-- Tests

-- >>> folde (+1) (*) (Add (Add (Val 1) (Val 2)) (Val 3))
-- 24

-- >>> folde (\i -> [i]) (++) (Add (Add (Val 1) (Val 2)) (Val 3))
-- [1,2,3]

-- Problem 5 (Exercise 8.6)

eval :: Expr -> Int
eval = folde id (+)

size :: Expr -> Int
size (Val x) = 1
size (Add x y) = l + r
  where
    l = size x
    r = size y

-- Tests

-- >>> eval (Add (Add (Val 1) (Val 2)) (Val 3))
-- 6

-- >>> size (Add (Add (Val 1) (Val 2)) (Val 3))
-- 3

-- Tests
-- >>> eval (Add (Add (Val 1) (Val 2)) (Val 3))
-- 6

-- >>> size (Add (Add (Val 1) (Val 2)) (Val 3))
-- 3

-- Problem 6

data ComplexInteger = ComplexInteger Int Int

real :: ComplexInteger -> Int
real (ComplexInteger r _)= r

imaginary :: ComplexInteger -> Int
imaginary (ComplexInteger _ i) = i

instance Eq ComplexInteger where
  (ComplexInteger r1 i1) == (ComplexInteger r2 i2) = r1 == r2 && i1 == i2

instance Show ComplexInteger where
    show (ComplexInteger r i)
        | i >= 0    = show r ++ "+" ++ show i ++ "i"
        | otherwise = show r ++ show i ++ "i"

instance Num ComplexInteger where
  (+) :: ComplexInteger -> ComplexInteger -> ComplexInteger
  (ComplexInteger r1 i1) + (ComplexInteger r2 i2) = ComplexInteger (r1 + r2) (i1 + i2)
  (ComplexInteger r1 i1) * (ComplexInteger r2 i2) = ComplexInteger (r1 * r2 - i1 * i2) (r1 * i2 + r2 * i1)

-- Tests

-- >>> real (ComplexInteger 1 2)
-- 1

-- >>> imaginary (ComplexInteger 1 2)
-- 2

-- >>> (ComplexInteger 1 2) == (ComplexInteger 3 4)
-- False

-- >>> ComplexInteger 1 2
-- 1+2i

-- >>> (ComplexInteger 1 2) * (ComplexInteger 3 4)
-- -5+10i

-- Problem 7

chopN :: Int -> [a] -> [[a]]
chopN n [] = []
chopN n xs
  | length xs < n = []
  | otherwise = take n xs : chopN n (drop n xs)
-- Tests

-- >>> chopN 4 [1..10]
-- [[1,2,3,4],[5,6,7,8]]

-- >>> chopN 8 [1..10]
-- [[1,2,3,4,5,6,7,8]]

-- >>> chopN 1 [1..10]
-- [[1],[2],[3],[4],[5],[6],[7],[8],[9],[10]]

-- >>> chopN 2 [1..10]
-- [[1,2],[3,4],[5,6],[7,8],[9,10]]

-- Problem 8  

subAlphabet :: (Eq a, Enum a) => a -> a -> [a] -> [a]
subAlphabet a z x = reverse ( nub ( reverse (x ++ enumFromTo a z)))
  where
    nub [] = []
    nub (x:xs)
      | x `elem` xs = nub xs
      | otherwise = x : nub xs


-- Tests

-- >>> subAlphabet 'A' 'Z' "ZEBRAS"
-- "ZEBRASCDFGHIJKLMNOPQTUVWXY"

-- >>> subAlphabet 1 26 [1,4,6,2,9,10,23,17]
-- [1,4,6,2,9,10,23,17,3,5,7,8,11,12,13,14,15,16,18,19,20,21,22,24,25,26]

-- Problem 9

data Polynomial = Constant Int | MoreTerms Int Polynomial

p = MoreTerms 3 (MoreTerms 4 (Constant 5))

-- instance Show

instance Show Polynomial where
  show p = showPolynomial p 0
    where
      showPolynomial (Constant c) exp
        | exp == 0  = show c
        | exp == 1  = show c ++ "x"
        | otherwise = show c ++ "x^" ++ show exp
      showPolynomial (MoreTerms a b) exp
        | exp == 0  = show a ++ " + " ++ showPolynomial b (exp + 1)
        | exp == 1  = show a ++ "x + " ++ showPolynomial b (exp + 1)
        | otherwise = show a ++ "x^" ++ show exp ++ " + " ++ showPolynomial b (exp + 1)

-- instance Num


instance Num Polynomial where
  (+) :: Polynomial -> Polynomial -> Polynomial
  (+) (Constant x1) (Constant y1) = Constant (x1+y1)
  (+) (Constant x1) (MoreTerms y1 y2) = MoreTerms y1 (y2 + Constant x1)
  (+) (MoreTerms x1 x2) (Constant y1) = MoreTerms x1 (x2 + Constant y1)
  (+) (MoreTerms x1 x2) (MoreTerms y1 y2) = MoreTerms (x1 + y1) (x2 + y2)

  (*) :: Polynomial -> Polynomial -> Polynomial
  (*) (Constant x1) (Constant y1) = Constant (x1*y1)
  (*) (Constant x1) (MoreTerms y1 y2) = MoreTerms (y1*x1) (y2 * Constant x1)
  (*) (MoreTerms x1 x2) (Constant y1) = MoreTerms (x1*y1) (x2 * Constant y1)
  (*) (MoreTerms x1 x2) (MoreTerms y1 y2) =
      let
          firstTerm = x1 * y1
          secondTerm = x2 * MoreTerms y1 y2
          thirdTerm = MoreTerms x1 (y2 * x2)
      in
          MoreTerms firstTerm (secondTerm + thirdTerm)

evalPoly :: Polynomial -> Int -> Int
evalPoly poly x = go poly 0
  where
    go (Constant c) exp = c * x ^ exp
    go (MoreTerms a b) exp = (a * x ^ exp) + go b (exp+1)


-- Tests

-- >>> p
-- 3 + 4x + 5x^2

-- >>> evalPoly p 2
-- 31

-- Problem 10

data Pair a b = Pair a b

instance (Eq a, Eq b) => Eq (Pair a b) where
  (Pair a b) == (Pair c d) = a == c && b == d

instance (Ord a, Ord b) => Ord (Pair a b) where
  (Pair a b) > (Pair c d) = a > c || (a == c && b > d)
  (Pair a b) < (Pair c d) = a < c || (a == c && b < d)

-- Tests

-- >>> Pair 1 2 == Pair 1 2
-- True

-- >>> Pair 1 2 == Pair 2 1
-- False


-- >>> Pair 1 2 < Pair 2 1
-- True

-- >>> Pair 1 2 > Pair 1 1
-- True

-- >>> Pair 1 2 > Pair 1 3
-- False


-- Problem 11

safeDivide :: Float -> Float -> Maybe Float
safeDivide x y = if y == 0 then Nothing else Just (x / y)

safeDivide' :: Maybe Float -> Maybe Float -> Maybe Float
safeDivide' Nothing Nothing = Nothing
safeDivide' Nothing (Just x) = Nothing
safeDivide' (Just x) (Just y) = safeDivide x y

hm :: [Float] -> Maybe Float
hm [] = Nothing
hm xs 
  | 0 `elem` xs = Nothing
  | otherwise = do
      x <- sequence [safeDivide 1 x | x <- xs]
      safeDivide (fromIntegral (length xs)) (sum x)
-- hm xs = safeDivide (length xs) (sum [safeDivide 1 x | x <- xs])



-- Tests

-- >>> hm [2.0, 2.0]
-- Just 2.0

-- >>> hm [1.0, 1.0]
-- Just 1.0

-- >>> hm [0.5, 0.5, 1.0]
-- Just 0.6

-- >>> hm [1.0, -1.0]
-- Nothing

-- >>> hm [1.0, -2.0, -2.0]
-- Nothing

-- >>> hm [1.0, -2.0]
-- Just 4.0
