\name{groupwise.density}
\alias{groupwise.density}
\title{
  Searches Subsets for Nearest Neighbor Densities
}
\description{
  In order to compare the distributions of different groups within the
  same multivariate space, calculates the nearest-neighbor densities of
  each point in the whole data set according to the distribution of each subset.
}
\usage{
groupwise.density(X, groups, method = "euclidean", p.neighbors = 0.01, init.info = NULL)
}
\arguments{
  \item{X}{
    a matrix of numeric data
  }
  \item{groups}{
    a factor or vector that can be coerced into a factor, specifying
    which group each row of \code{X} belongs to.
  }
  \item{method}{
    see \code{\link{diss}}
  }
  \item{p.neighbors}{
    the proportion of each groups neighbors that should be
    visited. Proportions are necessary when groups have different sizes
    because otherwise the densities aren't as comparable.
  }
  \item{init.info}{
    see \code{\link{diss}}
  }
}
\value{
  an \code{nrow(X)} by \code{nlevels(as.factor(groups))} matrix of
  nearest-neighbor density estimates.
}

\keyword{ multivariate }
