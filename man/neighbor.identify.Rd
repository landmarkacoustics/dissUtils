\name{neighbors.identify}
\alias{neighbors.identify}

\title{
  Find Neighbor Indices
}
\description{
  Uses a distance object and a vector of known distances to identify the
  neighbors that correspond to those distances.
}
\usage{
neighbors.identify(neighbor.matrix, all.dists)
}

\arguments{
  \item{neighbor.matrix}{
    a matrix of distances to neighbors
  }
  \item{all.dists}{
    either a distance object or a matrix of distances such as is
    produced by \code{diss}
  }
}
\value{
  a \code{dim(neighbor.matrix)} matrix of integer indices between 1 and \code{all.dists$Size} or \code{ncol(all.dists)}
}

\seealso{
  \code{\link{diss}}, \code{\link{dist}}
}
\keyword{ multivariate }