\name{neighbors}
\alias{neighbors}

\title{
  Find Nearest Neighbor Distances
}
\description{
  Given one (or two) multivariate data sets, a difference method, and k
  neighbors to search for, \code{neighbors} finds the k points in the
  data set (or the second data set) that are closest to each point in
  the data set (or the first data set)
}
\usage{
neighbors(X, Y = NULL, method = "euclidean", n.neighbors = 1, init.info = NULL)
}

\arguments{
  \item{X}{
    a matrix of numeric values
  }
  \item{Y}{
    an optional second matrix that must have the same number of columns
    as \code{X}
  }
  \item{method}{
    one of the method choices from \code{\link{diss}}
  }
  \item{n.neighbors}{
    an integer between 1 and nrow(X) (or nrow(Y), if it is not null)
  }
  \item{init.info}{
    some difference methods require additional information. see
    \code{\link{diss}}
  }
}
\value{
  returns an \code{nrow(X)} by \code{n.neighbors} matrix of distances
}

\keyword{ multivariate }
