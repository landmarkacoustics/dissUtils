\name{diss.index}
\alias{diss.index}
\title{
  Convert Indices from Distance Object to Matrix
}
\description{
  Given an index into a distance object of Size N, finds the coordinates
  of the same pairwise dissimilarity in an N by N matrix of dissimilarities
}

\usage{
diss.index(index, N)
}

\arguments{
  \item{index}{
    the position of the item in the distance object
  }
  \item{N}{
    the Size of the distance object, the number of points it compares
  }
}

\seealso{
  \code{\link{dist}}
}
\examples{
  ## The function is currently defined as
  function (index, N)
  {
    i <- floor(.raw.i(n, ix));

    return(c(i = i, j = .calc.j(i, n, ix)));
  }
}

\keyword{ multivariate }
