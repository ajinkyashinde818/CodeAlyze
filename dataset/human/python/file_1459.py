import Control.Monad( replicateM)
import Data.Array.IArray( listArray, (!))
import Data.Array.Unboxed( UArray)
main = do
    [n_, m_] <- return . map read . words =<< getLine
    alines_ <- replicateM n_ getLine
    blines_ <- replicateM m_ getLine
    let
	a2D, b2D::UArray (Int,Int) Char
	a2D = listArray ((1,1), (n_,n_)) $ concat alines_
	b2D = listArray ((1,1), (m_,m_)) $ concat blines_

	offset = [(k,l) | k<-[1..m_], l<-[1..m_]]
	verify (i,j) = all (checkFrom (i,j)) offset
	checkFrom (i,j) (k,l) = a2D!(i+k-1,j+l-1) == b2D!(k,l)

	bruteforceTopLeft = [(i,j) |	i<-[1..n_-m_+1],
					j<-[1..n_-m_+1]]
    putStr $ if	any verify bruteforceTopLeft
	then "Yes"
	else "No"
