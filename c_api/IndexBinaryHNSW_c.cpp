/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// -*- c++ -*-

#include "IndexBinaryHNSW_c.h"
#include <faiss/IndexBinaryHNSW.h>
#include "macros_impl.h"

extern "C" {

using faiss::IndexBinaryHNSW;

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
