\name{dissUtils-package}
\alias{dissUtils-package}
\alias{dissUtils}
\docType{package}
\title{
  Utilities for making pairwise comparisons of multivariate data
}
\description{
  This package has extensible C++ code for computing dissimilarities between vectors. It also has a number of C++ functions for assembling collections of dissimilarities. In particular, it lets you find a matrix of dissimilarities between the rows of two input matrices. There are also functions for finding the nearest neighbors of each row of a matrix, either within the matrix itself or within another matrix.
}
\details{
  \tabular{ll}{
    Package: \tab dissUtils\cr
    Type: \tab Package\cr
    Version: \tab 0.1\cr
    Date: \tab 2012-12-06\cr
    License: \tab GPL (>= 2)\cr
  }
  \tabular{ll}{
    diss \tab Dissimilarities Between Vectors\cr

    diss.index \tab Convert Indices from Distance Object to Matrix\cr

    groupwise.density \tab Compare Spatial Densities Between Groups\cr

    neighbors.identify \tab Find Neighbor Indices\cr

    neighbor.density \tab N-Dimensional Neighbor Density\cr

    neighbors \tab Find Nearest Neighbor Distances\cr

    unit.hypersphere.volume \tab Helps When Calculating Densities\cr
  }
}

\keyword{ package }
\keyword{ multivariate }
