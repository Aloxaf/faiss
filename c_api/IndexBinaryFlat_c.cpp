/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// Copyright 2004-present Facebook. All Rights Reserved.
// -*- c++ -*-

#include "IndexBinaryFlat_c.h"
#include <faiss/IndexBinaryFlat.h>
#include "macros_impl.h"

extern "C" {

using faiss::IndexBinaryFlat;

DEFINE_DESTRUCTOR(IndexBinaryFlat)
DEFINE_INDEX_BINARY_DOWNCAST(IndexBinaryFlat)

DEFINE_GETTER(IndexBinaryFlat, bool, use_heap);
DEFINE_SETTER(IndexBinaryFlat, bool, use_heap);

DEFINE_GETTER(IndexBinaryFlat, idx_t, query_batch_size);
DEFINE_SETTER(IndexBinaryFlat, idx_t, query_batch_size);

int faiss_IndexBinaryFlat_new(FaissIndexBinaryFlat** p_index, idx_t d) {
    try {
        auto index = new IndexBinaryFlat(d);
        *p_index = reinterpret_cast<FaissIndexBinaryFlat*>(index);
    }
    CATCH_AND_HANDLE
}

void faiss_IndexBinaryFlat_xb(
        FaissIndexBinaryFlat* index,
        uint8_t** p_xb,
        size_t* p_size) {
    auto& xb = reinterpret_cast<IndexBinaryFlat*>(index)->xb;
    *p_xb = xb.data();
    if (p_size) {
        *p_size = xb.size();
    }
}

}
