/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c++ -*-

#include "IndexBinaryFlat_c.h"
#include <faiss/IndexBinaryFlat.h>
#include "macros_impl.h"

extern "C" {

using faiss::IndexBinaryFlat;

DEFINE_DESTRUCTOR(IndexBinaryFlat)
DEFINE_INDEX_BINARY_DOWNCAST(IndexBinaryFlat)

DEFINE_GETTER(IndexBinaryFlat, int, use_heap)
DEFINE_SETTER(IndexBinaryFlat, int, use_heap)

DEFINE_GETTER(IndexBinaryFlat, size_t, query_batch_size)
DEFINE_SETTER(IndexBinaryFlat, size_t, query_batch_size)

int faiss_IndexBinaryFlat_new(FaissIndexBinaryFlat** p_index, int d) {
    try {
        IndexBinaryFlat* index = new IndexBinaryFlat(d);
        *p_index = reinterpret_cast<FaissIndexBinaryFlat*>(index);
    }
    CATCH_AND_HANDLE
}

int faiss_IndexBinaryFlat_xb(
        const FaissIndexBinaryFlat* index,
        uint8_t** xb_out) {
    try {
        auto& xb = reinterpret_cast<const IndexBinaryFlat*>(index)->xb;
        *xb_out = const_cast<uint8_t*>(xb.data());
    }
    CATCH_AND_HANDLE
}
}