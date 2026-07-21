import Data.List

solver::[Int]->Int
solver ls = let srtd = sort ls in
            let neg = takeWhile (0>) srtd in
            let swaps = (div (length neg) 2)* 2 in
            let a = ((-2)* (sum (take swaps srtd))) + (sum ls) in
            let b = ((-2)* (sum (take (swaps+2) srtd))) + (sum ls) in
            max a (if swaps+2 <= length ls then b else a)

main::IO()
main=do
  _<-getLine
  dat<-return.map read.words=<<getLine
  print (solver dat)
