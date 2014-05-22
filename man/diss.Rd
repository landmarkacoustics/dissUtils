\name{diss}
\alias{diss}

\title{
  Many Different Ways to Quantify Dissimilarities Among
  Multivariate Data%%  ~~function to do ... ~~
}
\description{
  this function will create a distance object corresponding to the
  dissimilarities between rows in a matrix \code{X}, or a matrix of
  dissimilarities between the rows of matrices \code{X} and \code{Y}
}

\usage{
diss(X, Y = NULL, method = "euclidean", init.info = NULL)
}

\arguments{
  \item{X}{
    a matrix of numeric data
  }
  \item{Y}{
    a second matrix of numeric data, which must have the same number of
    columns as \code{X}
  }
  \item{method}{
    a character string that uniquely matches one of the following:
    \tabular{rl}{
      braycurtis \tab Bray-Curtis difference, should use proportions \cr
      canberra \tab Canberra difference, should use proportions \cr
      chebyshev \tab Largest difference in any one dimension, like in chess \cr
      covariance \tab You may want to transpose the data before using this \cr
      euclidean \tab multivariate 2-norm \cr
      equality \tab the sum of exactly equal elements in each row \cr
      hellinger \tab Hellinger difference \cr
      jaccard \tab Jaccard distance \cr
      mahalanobis \tab Euclidean distance after scaling and removing
      covariance, which you can supply with \code{init.info} \cr
      manhattan \tab The sum of each dimension, no diagonal movement allowed \cr
      minkowski \tab arbitrary n-norm, so that \code{init.info=2} yields
      "euclidean" and \code{init.info = Inf} yields "chebyshev" (but don't do the latter!) \cr
      pearson \tab Pearson product-moment correlation, you may want to
      transpose the data \cr
      procrustes \tab Doesn't scale or rotate, just treats the vectors
      as matrices with \code{init.info} columns and calculates total
      distance between homologous points \cr
    }
  }
  \item{init.info}{
    some \code{method}s require additional information. see above
  }
}
\value{
  if \code{is.null(Y)}, returns a distance object containing pairwise
  dissimilarities between the points in \code{X}.

  if \code{is.matrix(Y)}, returns a \code{nrow(X)} by \code{nrow(Y)}
  matrix containing pairwise dissimilarities between each point in \code{X}
  and each point in \code{Y}.
}
\keyword{ multivariate }