-- the easiese function to define es a function defined from existing functions


-- test is a fiven integer is even

even :: Integral a => a -> Bool
even n = n `mod` 2 == 0

-- split a list at the nth element

slipAt :: Int [a] => ([a],[a]) -> Bool
-- slipAt 


-- abs :: Int -> Int
-- abs n = if n >= 0 then n else -n

-- can this be improved?
-- greatherThan10 :: Int -> Bool
-- greatherThan10 n = n > 10


-- Guards
-- guards offer a syntactic sugar for conditional expression
abs :: Int -> Int
abs n
    | n >= 0 = n
    | otherwise = -n

greatherThan10 :: Int -> Bool
greatherThan10 n
    | n > 10 = True
    | otherwise = False


-- bool pattern matching

not :: Bool -> Bool
not True = False
not False = True

(||) :: Bool -> Bool -> Bool
False || False = False
_ || _ = True

-- Does this work? No, the last code is not gonna work
(||) :: Bool -> Bool -> Bool
_ || _ = True
False || False = False


(||) :: Bool -> Bool -> Bool
True || _ = True
False || b = False


-- touple pattern matching

fst :: (a,b) -> a
fst (x,_) = x



-- write a function fourth::[a] -> a that returnts the fourth element of a list using
-- head and tail
-- list indexing (!!)
-- pattern matching

findFourth :: [a] -> a
findFourth xs = xs !! 3