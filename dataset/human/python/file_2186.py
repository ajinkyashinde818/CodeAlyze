import Control.Applicative
import Control.Monad
import Data.List
import Data.Ratio
import Data.Maybe

listToTuple2 [a,b] = (a,b)

main = do
  (d,g) <- listToTuple2 . map read . words <$> getLine :: IO (Int,Int)

  dat <- forM [1..d] $ \i -> do
    (p,c) <- listToTuple2 . map read . words  <$> getLine :: IO (Int,Int)

    return $ (i, p, c, 100*i*p+c)

  print $ minimum . catMaybes $ (flip map) (pset dat) $
    \(a,b) ->
      let
        psum = sum $ map (\(_,p,_,_) -> p) a
        score = sum $ map (\(_,_,_,s) -> s) a
      in
        case b of
          [] -> if score >= g then Just psum else Nothing
          _ ->
            let
              (i,p,c,_) = last b
              n = ceiling $ (g-score) % (i*100)
            in
              if score >= g then
                Just psum
              else
                if n < p then
                  Just (psum + n)
                else
                  Nothing

  where
    pset :: [a] -> [([a],[a])]
    pset [] = [([],[])]
    pset (x:xs) = concat [map (second (x:)) (pset xs), map (first (x:)) (pset xs)]

    first f (a,b) = (f a, b)
    second f (a,b) = (a, f b)
