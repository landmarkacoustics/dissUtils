\name{diss.index}
\alias{diss.index}
%- Also NEED an '\alias' for EACH other topic documented here.
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
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{index}{
    the position of the item in the distance object
}
  \item{N}{
    the Size of the distance object, the number of points it compares
  }
}
\references{
  %% ~put references to the literature/web site here ~
}
\author{
  Benjamin N. Taft \email{taftb@uwp.edu}
}
\note{
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
