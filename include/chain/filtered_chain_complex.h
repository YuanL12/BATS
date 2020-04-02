#pragma once

#include "chain_complex.h"
#include <filtration/filtration.h>

// template over filtration and matrix type
template <typename FT, typename MT>
struct FilteredChainComplex {
	std::vector<std::vector<FT>> val;
	ChainComplex<MT> C;

	FilteredChainComplex() {}

	template <typename CpxT>
	FilteredChainComplex(const Filtration<FT, CpxT> &F) : val(F.vals()), C(F.complex()) {}

	inline size_t dim(const size_t k) { return C.dim[k]; }

	inline const ChainComplex<MT>& complex() const {return C;}
	inline const std::vector<std::vector<FT>>& vals() const { return val; }

};

// defualt return
template <typename FT, typename T, typename CpxT>
inline auto __FilteredChainComplex(const Filtration<FT, CpxT> &F, T) {
	using VT = SparseVector<T, size_t>;
	using MT = ColumnMatrix<VT>;

	return FilteredChainComplex<FT, MT>(F);
}
