import qualified Data.Vector.Unboxed as U
import qualified Data.Vector as V

-- editorial

r :: IO [Int]
r = map read . words <$> getLine

main = do
    [_R,_G,_B,_N] <- r
    let r = V.sum $ solve _R _G _B _N
    print r


solve :: Int -> Int -> Int -> Int -> V.Vector Int
solve _R _G _B _N = V.generate (_N+1) id >>= (\r ->
                    V.generate (_N+1) id >>= (\g ->
                        let b = fromIntegral (_N - r*_R - g*_G) / fromIntegral _B
                        in if b >= 0 && b == fromIntegral (floor b) then V.singleton 1 else V.empty))
