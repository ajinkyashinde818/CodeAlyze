import Data.Int

solve :: [Int64] -> Int64
solve rest =
    if f_ then s_ else s_ - m_ - m_
    where 
        func a (s,m,f) = 
            (s + a_, min m a_, (0 <= a) == f)
            where
                a_ = abs a
        (s_,m_,f_) = foldr func (0, maxBound,True) rest

main = interact $ show.solve.tail.map read.words
