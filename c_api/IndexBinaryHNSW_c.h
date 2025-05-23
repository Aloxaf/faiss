/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c -*-

#ifndef FAISS_INDEX_BINARY_HNSW_C_H
#define FAISS_INDEX_BINARY_HNSW_C_H

#include "IndexBinary_c.h"
#include "Index_c.h"
#include "faiss_c.h"

#ifdef __cplusplus
extern "C" {
#endif

FAISS_DECLARE_CLASS_INHERITED(SearchParametersHNSW, SearchParameters)
FAISS_DECLARE_DESTRUCTOR(SearchParametersHNSW)
FAISS_DECLARE_SEARCH_PARAMETERS_DOWNCAST(SearchParametersHNSW)

int faiss_SearchParametersHNSW_new(FaissSearchParametersHNSW** p_sp);
int faiss_SearchParametersHNSW_new_with(
        FaissSearchParametersHNSW** p_sp,
        FaissIDSelector* sel,
        int efSearch);

FAISS_DECLARE_GETTER(SearchParametersHNSW, const FaissIDSelector*, sel)
FAISS_DECLARE_GETTER_SETTER(SearchParametersHNSW, int, efSearch)

/** The HNSW index is a normal random-access index with a HNSW
 * link structure built on top */
FAISS_DECLARE_CLASS(IndexBinaryHNSW)
FAISS_DECLARE_DESTRUCTOR(IndexBinaryHNSW)
FAISS_DECLARE_INDEX_BINARY_DOWNCAST(IndexBinaryHNSW)

/// the sequential storage
FAISS_DECLARE_GETTER(IndexBinaryHNSW, FaissIndexBinary*, storage)

/** Build IndexBinaryHNSW with an empty storage.
 *
 * @param d dimension of the vectors
 * @param M number of neighbors per node (M)
 */
int faiss_IndexBinaryHNSW_new(FaissIndexBinaryHNSW** p_index, int d, int M);

int faiss_IndexBinaryHNSW_set_efSearch(
        FaissIndexBinaryHNSW* index,
        int efSearch);

#ifdef __cplusplus
}
#endif

#endif
