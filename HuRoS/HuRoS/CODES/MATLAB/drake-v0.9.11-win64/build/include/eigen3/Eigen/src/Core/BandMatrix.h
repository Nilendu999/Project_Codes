// This file is part of Eigen, a lightweight C++ template library
// for linear algebra.
//
// Copyright (C) 2009 Gael Guennebaud <gael.guennebaud@inria.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_BANDMATRIX_H
#define EIGEN_BANDMATRIX_H

namespace Eigen { 

namespace internal {

template<typename Derived>
class BandMatrixBase : public EigenBase<Derived>
{
  public:

    enum {
      Flags = internal::traits<Derived>::Flags,
      CoeffReadCost = internal::traits<Derived>::CoeffReadCost,
      RowsAtCompileTime = internal::traits<Derived>::RowsAtCompileTime,
      ColsAtCompileTime = internal::traits<Derived>::ColsAtCompileTime,
      MaxRowsAtCompileTime = internal::traits<Derived>::MaxRowsAtCompileTime,
      MaxColsAtCompileTime = internal::traits<Derived>::MaxColsAtCompileTime,
      Supers = internal::traits<Derived>::Supers,
      Subs   = internal::traits<Derived>::Subs,
      Options = internal::traits<Derived>::Options
    };
    typedef typename internal::traits<Derived>::Scalar Scalar;
    typedef Matrix<Scalar,RowsAtCompileTime,ColsAtCompileTime> DenseMatrixType;
    typedef typename DenseMatrixType::Index Index;
    typedef typename internal::traits<Derived>::CoefficientsType CoefficientsType;
    typedef EigenBase<Derived> Base;

  protected:
    enum {
      DataRowsAtCompileTime = ((Supers!=Dynamic) && (Subs!=Dynamic))
                            ? 1 + Supers + Subs
                            : Dynamic,
      SizeAtCompileTime = EIGEN_SIZE_MIN_PREFER_DYNAMIC(RowsAtCompileTime,ColsAtCompileTime)
    };

  public:
    
    using Base::derived;
    using Base::rows;
    using Base::cols;

    /** \returns the number of super diagonals */
    inline Index supers() const { return derived().supers(); }

    /** \returns the number of sub diagonals */
    inline Index subs() const { return derived().subs(); }
    
    /** \returns an expression of the underlying coefficient matrix */
    inline const CoefficientsType& coeffs() const { return derived().coeffs(); }
    
    /** \returns an expression of the underlying coefficient matrix */
    inline CoefficientsType& coeffs() { return derived().coeffs(); }

    /** \returns a vector expression of the \a i -th column,
      * only the meaningful part is returned.
      * \warning the internal storage must be column major. */
    inline Block<CoefficientsType,Dynamic,1> col(Index i)
    {
      EIGEN_STATIC_ASSERT((Options&RowMajor)==0,THIS_METHOD_IS_ONLY_FOR_COLUMN_MAJOR_MATRICES);
      Index start = 0;
      Index len = coeffs().rows();
      if (i<=supers())
      {
        start = supers()-i;
        len = (std::min)(rows(),std::max<Index>(0,coeffs().rows() - (supers()-i)));
      }
      else if (i>=rows()-subs())
        len = std::max<Index>(0,coeffs().rows() - (i + 1 - rows() + subs()));
      return Block<CoefficientsType,Dynamic,1>(coeffs(), start, i, len, 1);
    }

    /** \returns a vector expression of the main diagonal */
    inline Block<CoefficientsType,1,SizeAtCompileTime> diagonal()
    { return Block<CoefficientsType,1,SizeAtCompileTime>(coeffs(),supers(),0,1,(std::min)(rows(),cols())); }

    /** \returns a vector expression of the main diagonal (const version) */
    inline const Block<const CoefficientsType,1,SizeAtCompileTime> diagonal() const
    { return Block<const CoefficientsType,1,SizeAtCompileTime>(coeffs(),supers(),0,1,(std::min)(rows(),cols())); }

    template<int Index> struct DiagonalIntReturnType {
      enum {
        ReturnOpposite = (Options&SelfAdjoint) && (((Index)>0 && Supers==0) || ((Index)<0 && Subs==0)),
        Conjugate = ReturnOpposite && NumTraits<Scalar>::IsComplex,
        ActualIndex = ReturnOpposite ? -Index : Index,
        DiagonalSize = (RowsAtCompileTime==Dynamic || ColsAtCompileTime==Dynamic)
                     ? Dynamic
                     : (ActualIndex<0
                     ? EIGEN_SIZE_MIN_PREFER_DYNAMIC(ColsAtCompileTime,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         