                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 typedef typename conditional<
      ( (int(traits<T>::Flags) & EvalBeforeNestingBit) ||
        int(CostEvalAsInteger) < int(CostNoEvalAsInteger)
      ),
      PlainObject,
      typename ref_selector<T>::type
  >::type type;
};

template<typename T>
inline T* const_cast_ptr(const T* ptr)
{
  return const_cast<T*>(ptr);
}

template<typename Derived, typename XprKind = typename traits<Derived>::XprKind>
struct dense_xpr_base
{
  /* dense_xpr_base should only ever be used on dense expressions, thus falling either into the MatrixXpr or into the ArrayXpr cases */
};

template<typename Derived>
struct dense_xpr_base<Derived, MatrixXpr>
{
  typedef MatrixBase<Derived> type;
};

template<typename Derived>
struct dense_xpr_base<Derived, ArrayXpr>
{
  typedef ArrayBase<Derived> type;
};

/** \internal Helper base class to add a scalar multiple operator
  * overloads for complex types */
template<typename Derived,typename Scalar,typename OtherScalar,
         bool EnableIt = !is_same<Scalar,OtherScalar>::value >
struct special_scalar_op_base : public DenseCoeffsBase<Derived>
{
  // dummy operator* so that the
  // "using special_scalar_op_base::operator*" compiles
  void operator*() const;
};

template<typename Derived,typename Scalar,typename OtherScalar>
struct special_scalar_op_base<Derived,Scalar,OtherScalar,true>  : public DenseCoeffsBase<Derived>
{
  const CwiseUnaryOp<scalar_multiple2_op<Scalar,OtherScalar>, Derived>
  operator*(const OtherScalar& scalar) const
  {
    return CwiseUnaryOp<scalar_multiple2_op<Scalar,OtherScalar>, Derived>
      (*static_cast<const Derived*>(this), scalar_multiple2_op<Scalar,OtherScalar>(scalar));
  }

  inline friend const CwiseUnaryOp<scalar_multiple2_op<Scalar,OtherScalar>, Derived>
  operator*(const OtherScalar& scalar, const Derived& matrix)
  { return static_cast<const special_scalar_op_base&>(matrix).operator*(scalar); }
};

template<typename XprType, typename CastType> struct cast_return_type
{
  typedef typename XprType::Scalar CurrentScalarType;
  typedef typename remove_all<CastType>::type _CastType;
  typedef typename _CastType::Scalar NewScalarType;
  typedef typename conditional<is_same<CurrentScalarType,NewScalarType>::value,
                              const XprType&,CastType>::type type;
};

template <typename A, typename B> struct promote_storage_type;

template <typename A> struct promote_storage_type<A,A>
{
  typedef A ret;
};

/** \internal gives the plain matrix or array type to store a row/column/diagonal of a matrix type.
  * \param Scalar optional parameter allowing to pass a different scalar type than the one of the MatrixType.
  */
template<typename ExpressionType, typename Scalar = typename ExpressionType::Scalar>
struct plain_row_type
{
  typedef Matrix<Scalar, 1, ExpressionType::ColsAtCompileTime,
                 ExpressionType::PlainObject::Options | RowMajor, 1, ExpressionType::MaxColsAtCompileTime> MatrixRowType;
  typedef Array<Scalar, 1, ExpressionType::ColsAtCompileTime,
                 ExpressionType::PlainObject::Options | RowMajor, 1, ExpressionType::MaxColsAtCompileTime> ArrayRowType;

  typedef typename conditional<
    is_same< typename traits<ExpressionType>::XprKind, MatrixXpr >::value,
    MatrixRowType,
    ArrayRowType 
  >::type type;
};

template<typename ExpressionType, typename Scalar = typename ExpressionType::Scalar>
struct plain_col_type
{
  typedef Matrix<Scalar, ExpressionType::RowsAtCompileTime, 1,
                 ExpressionType::PlainObject::Options & ~RowMajor, ExpressionType::MaxRowsAtCompileTime, 1> MatrixColType;
  typedef Array<Scalar, ExpressionType::RowsAtCompileTime, 1,
                 ExpressionType::PlainObject::Options & ~RowMajor, ExpressionType::MaxRowsAtCompileTime, 1> ArrayColType;

  typedef typename conditional<
    is_same< typename traits<ExpressionType>::XprKind, MatrixXpr >::value,
    MatrixColType,
    ArrayColType 
  >::type type;
};

template<typename ExpressionType, typename Scalar = typename ExpressionType::Scalar>
struct plain_diag_type
{
  enum { diag_size = EIGEN_SIZE_MIN_PREFER_DYNAMIC(ExpressionType::RowsAtCompileTime, ExpressionType::ColsAtCompileTime),
         max_diag_size = EIGEN_SIZE_MIN_PREFER_FIXED(ExpressionType::MaxRowsAtCompileTime, ExpressionType::MaxColsAtCompileTime)
  };
  typedef Matrix<Scalar, diag_size, 1, ExpressionType::PlainObject::Options & ~RowMajor, max_diag_size, 1> MatrixDiagType;
  typedef Array<Scalar, diag_size, 1, ExpressionType::PlainObject::Options & ~RowMajor, max_diag_size, 1> ArrayDiagType;

  typedef typename conditional<
    is_same< typename traits<ExpressionType>::XprKind, MatrixXpr >::value,
    MatrixDiagType,
    ArrayDiagType 
  >::type type;
};

template<typename ExpressionType>
struct is_lvalue
{
  enum { value = !bool(is_const<ExpressionType>::value) &&
                 bool(traits<ExpressionType>::Flags & LvalueBit) };
};

} // end namespace internal

} // end namespace Eigen

#endif // EIGEN_XPRHELPER_H
