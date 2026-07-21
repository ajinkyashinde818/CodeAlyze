import Data.Array

main = do
  s <- getLine
  let ans = compute s
  print ans

{-
sを両側から突き合わせる。
両方同じ文字なら、消費する。
両方違う非x文字なら、失敗する。
片方がxでもう片方が違うなら、x入れたことにして消費する。
同じ文字にたどり着くか行きすぎたら成功。
-}

compute :: String -> Int
compute s = loop 0 1 n
  where
    n = length s
    arr = listArray (1,n) s
    loop cnt i j
      | i >= j = cnt
      | c == d = loop cnt (succ i) (pred j)
      | c == 'x' = loop (succ cnt) (succ i) j
      | d == 'x' = loop (succ cnt) i (pred j)
      | True   = -1
      where
        c = arr ! i
        d = arr ! j
