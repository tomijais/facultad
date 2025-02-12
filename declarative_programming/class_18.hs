-- add

data Nat = Zero | Succ Nat

add :: Nat -> Nat -> Nat
add Zero n = n
add (Succ n1) n2 = add n1 n2


data List a = Nil | Cons a (List a)
foldrList :: (a -> b -> b) -> b -> List a -> b
foldrList _ z Nil = z
foldrList f z (Cons x xs) = f x (foldrList f z xs)



data Tree a = Leaf a | Node (Tree a) a (Tree a )
flatten :: Tree a -> [a]
flatten (Leaf a) = [a]
flatten (Node l x r) = flatten l ++ [x] ++ flatten r


occurs :: Eq a => a -> Tree a -> Bool
occurs x (Leaf y) = x == y
occurs x (Node l y r) =  x == y || occurs x l || occurs x r