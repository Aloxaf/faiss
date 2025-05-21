/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c++ -*-

#include "IndexBinaryHNSW_c.h"
#include <faiss/IndexBinaryHNSW.h>
#include <faiss/impl/HNSW.h>
#include "macros_impl.h"

extern "C" {

using faiss::IndexBinaryHNSW;
using faiss::SearchParametersHNSW;

DEFINE_DESTRUCTOR(SearchParametersHNSW)
DEFINE_SEARCH_PARAMETERS_DOWNCAST(SearchParametersHNSW)

int faiss_SearchParametersHNSW_new(FaissSearchParametersHNSW** p_sp) {
    try {
        SearchParametersHNSW* sp = new SearchParametersHNSW;
        *p_sp = reinterpret_cast<FaissSearchParametersHNSW*>(sp);
    }
    CATCH_AND_HANDLE
}

int faiss_SearchParametersHNSW_new_with(
        FaissSearchParametersHNSW** p_sp,
        FaissIDSelector* sel,
        int efSearch) {
    try {
        SearchParametersHNSW* sp = new SearchParametersHNSW;
        sp->sel = reinterpret_cast<faiss::IDSelector*>(sel);
        sp->efSearch = efSearch;
        *p_sp = reinterpret_cast<FaissSearchParametersHNSW*>(sp);
    }
    CATCH_AND_HANDLE
}

DEFINE_GETTER_PERMISSIVE(SearchParametersHNSW, const FaissIDSelector*, sel)

DEFINE_GETTER(SearchParametersHNSW, int, efSearch)
DEFINE_SETTER(SearchParametersHNSW, int, efSearch)

DEFINE_DESTRUCTOR(IndexBinaryHNSW)
DEFINE_INDEX_BINARY_DOWNCAST(IndexBinaryHNSW)

DEFINE_GETTER_PERMISSIVE(IndexBinaryHNSW, FaissIndexBinary*, storage)

int faiss_IndexBinaryHNSW_new(FaissIndexBinaryHNSW** p_index, int d, int M) {
    try {
        IndexBinaryHNSW* index = new IndexBinaryHNSW(d, M);
        *p_index = reinterpret_cast<FaissIndexBinaryHNSW*>(index);
    }
    CATCH_AND_HANDLE
}
}
